// Copyright (c) 2016 Quenio Cesar Machado dos Santos. All rights reserved.

#include "min_unit.h"
#include "sponge.h"
#include <iostream>

using namespace std;

// All sizes in bits:
constexpr size_t state_size = 16;
constexpr size_t digest_size = state_size;
constexpr size_t rate_size = state_size / 2;

BitString<state_size> identity(BitString<state_size> bs)
{
    return bs;
}

const char * sponge_test()
{
    const char * str = "\x01\x01\x01\x01\x01"; // 5 * 8 = 40 bits

    stringstream message(str);

    string hash = sponge<state_size, rate_size, identity>(message, digest_size);

    mu_assert(hash == string("8080"));

    return NULL;
}

void all_tests()
{
    mu_test(sponge_test);
}
