// Copyright (c) 2016 Quenio Cesar Machado dos Santos. All rights reserved.

#pragma once

#include "state_array.h"

template<size_t W>
StateArray<W> rho(const StateArray<W> & a)
{
    using SA = StateArray<W>;
    using Coord3D = typename SA::Coord3D;

    SA b;

    for (Coord3D coord { 0, 0, 0 }; coord.z < SA::lane_size; coord.z++)
    {
        b.set(coord, a[coord]);
    }

    Coord3D coord { 1, 0, 0 };
    for (int t = 0; t < 24; t++)
    {
        for (;coord.z < SA::lane_size; coord.z++)
        {
            // shift with "sum"; not "subtraction"? deviating from documentation
            const int offset_z = (coord.z + (t+1)*(t+2)/2) % SA::lane_size;
            const Coord3D offset { coord.x, coord.y, offset_z };

            b.set(coord, a[offset]);
        }
        coord = Coord3D { coord.y, (2 * coord.x + 3 * coord.y) % 5, 0 };
    }

    return b;
}
