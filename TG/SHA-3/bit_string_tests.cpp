// Copyright (c) 2016 Quenio Cesar Machado dos Santos. All rights reserved.

#include "min_unit.h"
#include "bit_string.h"

using namespace std;

const char * bit_string__from_hex()
{
    mu_assert(hex_to_bs<16>("F2F2").to_string() == string("1111001011110010"));
    mu_assert(hex_to_bs<16>("1E1E").to_string() == string("0001111000011110"));
    return NULL;
}


void all_tests()
{
    mu_test(bit_string__from_hex);
}
