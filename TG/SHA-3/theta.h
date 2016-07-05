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
StateArray<W> theta(const StateArray<W> & a)
{
    using SA = StateArray<W>;
    using Coord2D = typename SA::Coord2D;

    SA b;

    for (Coord2D coord = SA::begin2D(); coord != SA::end2D(); coord.next())
    {
        Coord2D previous_column = coord;
        previous_column.p_cycle_x();

        Coord2D next_column = coord;
        next_column.cycle_x();

        b[coord] = a.column_xor(previous_column.x) ^ a[coord] ^ (rotate(a.column_xor(next_column.x), 1));
    }

    return b;
}
