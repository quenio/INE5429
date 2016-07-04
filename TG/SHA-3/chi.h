// Copyright (c) 2016 Quenio Cesar Machado dos Santos. All rights reserved.

#pragma once

#include "state_array.h"

template<size_t W>
StateArray<W> chi(StateArray<W> & a)
{
    using SA = StateArray<W>;
    using Coord2D = typename SA::Coord2D;

    SA b;

    for (Coord2D target { 0, 0 }; target != SA::end2D(); target.next())
    {
        Coord2D plus_one = target;
        plus_one.cycle_x();

        Coord2D plus_two = plus_one;
        plus_two.cycle_x();

        b[target] = a[target] ^ (~a[plus_one] & a[plus_two]);
    }

    return b;
}
