// Copyright (c) 2016 Quenio Cesar Machado dos Santos. All rights reserved.

#pragma once

#include "state_array.h"

template<size_t W>
StateArray<W> rho(const StateArray<W> & a)
{
    using SA = StateArray<W>;
    using Coord2D = typename SA::Coord2D;

    SA b;

    Coord2D coord { 0, 0 };
    b[coord] = a[coord];

    coord = Coord2D { 1, 0 };
    for (int t = 0; t < 24; t++)
    {
        const int offset = (t+1)*(t+2)/2;

        b[coord] = rotate(a[coord], offset);

        coord = Coord2D { coord.y, (2 * coord.x + 3 * coord.y) % 5 };
    }

    return b;
}
