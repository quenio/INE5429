// Copyright (c) 2016 Quenio Cesar Machado dos Santos. All rights reserved.

#pragma once

#include "state_array.h"
#include <algorithm>

#include <bitset>
#include <iostream>

using namespace std;

template <size_t W>
inline BitString<W> rotate(BitString<W> b, unsigned n)
{
    return b << n | b >> (W-n);
}

template<size_t W>
StateArray<W> theta(StateArray<W> & a)
{
    using SA = StateArray<W>;
    using Coord2D = typename SA::Coord2D;

    SA b { a.s() };

    for (Coord2D coord = SA::begin2D(); coord != SA::end2D(); coord.next())
    {
        Coord2D previous = coord;
        previous.p_cycle_y();

        Coord2D next = coord;
        next.cycle_y();

        b[coord] = a.column_xor(previous.y) ^ a[coord] ^ (rotate(a.column_xor(next.y), 1));
    }

    return b;
}
