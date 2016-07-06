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

const char * bit_string__to_hex__block_size()
{
    const char * hex_str = "27E2DDB00CC8F9EE";
    mu_assert(hex_to_bs<64>(hex_str).to_hex() == string(hex_str));
    return NULL;
}

const char * bit_string__to_hex__less_than_block_size()
{
    const char * hex_str = "0CC8F9EE";
    mu_assert(hex_to_bs<32>(hex_str).to_hex() == string(hex_str));
    return NULL;
}

const char * bit_string__to_hex__greater_than_block_size()
{
    const char * hex_str = "0CC8F9EE27E2DDB00CC8F9EE";
    mu_assert(hex_to_bs<64+32>(hex_str).to_hex() == string(hex_str));
    return NULL;
}

const char * bit_string__to_hex__multiple_of_block_size()
{
    const char * hex_str = "27E2DDB00CC8F9EE27E2DDB00CC8F9EE";
    mu_assert(hex_to_bs<64*2>(hex_str).to_hex() == string(hex_str));
    return NULL;
}

void all_tests()
{
    mu_test(bit_string__from_hex);
    mu_test(bit_string__to_hex__block_size);
    mu_test(bit_string__to_hex__less_than_block_size);
    mu_test(bit_string__to_hex__greater_than_block_size);
    mu_test(bit_string__to_hex__multiple_of_block_size);
}
