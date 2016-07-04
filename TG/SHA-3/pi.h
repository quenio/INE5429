// Copyright (c) 2016 Quenio Cesar Machado dos Santos. All rights reserved.

#pragma once

#include "state_array.h"

template<size_t W>
StateArray<W> pi(StateArray<W> & a)
{
    using SA = StateArray<W>;
    using Coord2D = typename SA::Coord2D;

    SA b;

    for (Coord2D target { 0, 0 }; target != SA::end2D(); target.next())
    {
        const Coord2D source { (target.x + 3 * target.y) % 5, target.x };
        b[target] = a[source];
    }

    return b;
}
