// Copyright (c) 2016 Quenio Cesar Machado dos Santos. All rights reserved.

#pragma once

#include <cassert>
#include "state_array.h"

bool rc_bit(int t)
{
    int n = t % 255;
    if (n == 0) return 1;

    BitString<9> r { "100000000" };
    for (int i = 0; i < n; i++)
    {
        r >>= 1;
        r.set(0, r[0] ^ r[8]);
        r.set(4, r[4] ^ r[8]);
        r.set(5, r[5] ^ r[8]);
        r.set(6, r[6] ^ r[8]);
    }

    return r[0];
}

template<size_t W>
BitString<W> rc(int round_index)
{
    BitString<W> word;

    const int offset = 7 * round_index;
    size_t i = 1;
    for(int j = 0; i <= W; j++)
    {
        word.set(i - 1, rc_bit(j + offset));
        i *= 2;
    }

    return word;
};

template<size_t W>
StateArray<W> iota(const StateArray<W> & a, int round_index)
{
    assert(round_index >= 0 && round_index < 24);

    using SA = StateArray<W>;
    using Coord2D = typename SA::Coord2D;

    const Coord2D target = { 0, 0 };

    SA b = a;
    b[target] = a[target] ^ rc<W>(round_index);

    return b;
}
