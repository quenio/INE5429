// Copyright (c) 2016 Quenio Cesar Machado dos Santos. All rights reserved.

#pragma once

#include "keccak.h"

template<size_t D>
std::string sha3(std::istream & message)
{
    return keccak<D*2>(message, D);
}

std::string sha3_224(std::istream & message)
{
    return sha3<224>(message);
}

std::string sha3_256(std::istream & message)
{
    return sha3<256>(message);
}

std::string sha3_384(std::istream & message)
{
    return sha3<384>(message);
}

std::string sha3_512(std::istream & message)
{
    return sha3<256>(message);
}

template<size_t N>
std::string shake(std::istream & message, size_t digest_bit_size)
{
    return keccak<N*2>(message, digest_bit_size);
}

std::string shake_128(std::istream & message, size_t digest_bit_size)
{
    return shake<128>(message, digest_bit_size);
}

std::string shake_256(std::istream & message, size_t digest_bit_size)
{
    return shake<256>(message, digest_bit_size);
}
