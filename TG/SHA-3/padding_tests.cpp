// Copyright (c) 2016 Quenio Cesar Machado dos Santos. All rights reserved.

#include "min_unit.h"
#include "padding.h"
#include <iostream>

using namespace std;

using namespace std;

const char * pad101_partial_padding()
{
    constexpr size_t block_size = 16;
    constexpr size_t actual_size = 8;

    BitString<block_size> bs = hex_to_bs<block_size>("F100");

    pad101(bs, actual_size);

    mu_assert(bs.to_hex() == string("F181"));

    return NULL;
}

const char * pad101_full_padding()
{
    constexpr size_t block_size = 16;
    constexpr size_t actual_size = 0;

    BitString<block_size> bs = hex_to_bs<block_size>("0000");

    pad101(bs, actual_size);

    mu_assert(bs.to_hex() == string("8001"));

    return NULL;
}

const char * pad101_full_block__no_padding()
{
    constexpr size_t block_size = 16;
    constexpr size_t actual_size = block_size;

    BitString<block_size> bs = hex_to_bs<block_size>("F018");

    pad101(bs, actual_size);

    mu_assert(bs.to_hex() == string("F018"));

    return NULL;
}

void all_tests()
{
    mu_test(pad101_partial_padding);
    mu_test(pad101_full_padding);
    mu_test(pad101_full_block__no_padding);
}
