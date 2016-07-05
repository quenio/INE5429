// Copyright (c) 2016 Quenio Cesar Machado dos Santos. All rights reserved.

#include "min_unit.h"
#include "iota.h"
#include <iostream>

using namespace std;

constexpr int ROUND_COUNT = 24;
const char * RC[ROUND_COUNT] =
{
    "0000000000000001",
    "0000000000008082",
    "800000000000808A",
    "8000000080008000",
    "000000000000808B",
    "0000000080000001",
    "8000000080008081",
    "8000000000008009",
    "000000000000008A",
    "0000000000000088",
    "0000000080008009",
    "000000008000000A",
    "000000008000808B",
    "800000000000008B",
    "8000000000008089",
    "8000000000008003",
    "8000000000008002",
    "8000000000000080",
    "000000000000800A",
    "800000008000000A",
    "8000000080008081",
    "8000000000008080",
    "0000000080000001",
    "8000000080008008"
};

const char * rc_test()
{
    constexpr size_t W = 64;
    for (int i = 0; i < ROUND_COUNT; i++)
    {
        const BitString<W> & bs = rc<W>(i).reverse();
        mu_assert(bs.to_hex() == string(RC[i]));
    }

    return NULL;
}

const char *s1 = "01100110011001100110011001100110011001100110011001";
const char *s2 = "01010101011010010101101010100101101010100101011010";

using SA2 = StateArray<2>;
using BS50 = BitString<50>;

const char * iota_test()
{
    BitString<4> b { "1010" };

    for (size_t i = 0; i < b.size(); i++)
    {
        cout << b[i] << endl;
    }

//    SA2 a { BS50 { s1 } };
//    SA2 b = iota(a, 0);
//    mu_assert(b.to_string() == s2);
    return NULL;
}

void all_tests()
{
    mu_test(rc_test);
//    mu_test(iota_test);
}
