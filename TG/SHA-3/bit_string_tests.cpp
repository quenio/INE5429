// Copyright (c) 2016 Quenio Cesar Machado dos Santos. All rights reserved.

#include "bit_string.h"
#include "min_unit.h"
#include "iostream"

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

const char * bit_string__istream()
{
    const char * str = "12345"; // five bytes

    stringstream ss(str);
    BitString<2*8> bs; // blocks of two bytes

    // Reads first two bytes:
    ss >> bs;
    mu_assert(bs.to_hex() == string("3132"));

    // Reads next two bytes:
    ss >> bs;
    mu_assert(bs.to_hex() == string("3334"));

    // Reads last byte:
    ss >> bs;
    mu_assert(bs.to_hex() == string("3500")); // padded second byte of block since stream had only one byte

    return NULL;
}

const char * bit_string__concatenation()
{
    const char * str = "11111"; // five bytes

    BitString<5> bs { str };
    BitString<3> pad;

    BitString<8> padded = bs + pad;

    mu_assert(bs.to_string() == string("11111"));
    mu_assert(pad.to_string() == string("000"));
    mu_assert(padded.to_string() == string("11111000"));

    return NULL;
}

const char * bit_string__truncation()
{
    const char * str = "11000"; // five bytes

    BitString<3> bs { str };

    mu_assert(bs.to_string() == string("110"));

    return NULL;
}

void all_tests()
{
    mu_test(bit_string__from_hex);
    mu_test(bit_string__to_hex__block_size);
    mu_test(bit_string__to_hex__less_than_block_size);
    mu_test(bit_string__to_hex__greater_than_block_size);
    mu_test(bit_string__to_hex__multiple_of_block_size);
    mu_test(bit_string__istream);
    mu_test(bit_string__concatenation);
    mu_test(bit_string__truncation);
}
