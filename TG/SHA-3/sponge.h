// Copyright (c) 2016 Quenio Cesar Machado dos Santos. All rights reserved.

#pragma once

#include "bit_string.h"

template<size_t B>
using SpongeF = BitString<B>(*)(BitString<B>);

template<size_t B, size_t R, SpongeF<B> F>
std::string sponge(std::istream & message, size_t digest_bit_size)
{
    static_assert(R >= 8, "Rate must have at least one byte.");
    static_assert(B > R, "State size must be greater than rate.");

    BitString<B> state;
    BitString<R> block;
    BitString<B-R> capacity;

    while (!message.eof())
    {
        message >> block;
        state = F(state ^ (block + capacity));
    }

    constexpr size_t hex_bit_size = 4;

    std::string digest = truncate<R>(state).to_hex();
    while (digest_bit_size > (digest.size() * hex_bit_size))
    {
        state = F(state);
        digest += truncate<R>(state).to_hex();
    }

    return digest.substr(0, digest_bit_size / hex_bit_size);
}