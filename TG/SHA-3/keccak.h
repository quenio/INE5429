// Copyright (c) 2016 Quenio Cesar Machado dos Santos. All rights reserved.

#pragma once

#include "theta.h"
#include "rho.h"
#include "pi.h"
#include "chi.h"
#include "iota.h"
#include "sponge.h"

template<size_t W>
StateArray<W> rnd(StateArray<W> & a, int i)
{
    return iota(chi(pi(rho(theta(a)))), i);
}

template<size_t B>
BitString<B> keccak_f(BitString<B> bs)
{
    StateArray<B/25> a { bs };

    for (int i = 0; i < 24; i++)
    {
        a = rnd(a, i);
    }

    return a.bs();
}

template<size_t C>
std::string keccak(std::istream & message, size_t digest_bit_size)
{
    return sponge<1600, 1600-C, keccak_f>(message, digest_bit_size);
}