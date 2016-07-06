// Copyright (c) 2016 Quenio Cesar Machado dos Santos. All rights reserved.

#include "min_unit.h"
#include "keccak.h"
#include "samples.h"

const char * rnd_SA2()
{
    using SA2 = StateArray<2>;
    using BS50 = BitString<50>;

    const char *s1 = "01100110011001100110011001100110011001100110011001";
    const char *s2 = "01100101110111100111000111000011000000010000101100";

    SA2 a { BS50 { s1 } };
    SA2 b = rnd(a, 0);

    mu_assert(b.to_string() == s2);

    return NULL;
}

const char * rnd_SA64()
{
    using SA64 = StateArray<64>;

    SA64 a { hex_to_bs<1600>(MSG5_XOR) };
    SA64 b = rnd(a, 0);
    mu_assert(b.to_hex() == MSG5_IOTA0);

    SA64 c { hex_to_bs<1600>(MSG5_IOTA9) };
    SA64 d = rnd(c, 10);
    mu_assert(d.to_hex() == MSG5_IOTA10);

    return NULL;
}

const char * keccak_f_SA64()
{
    using BS1600 = BitString<1600>;

    BS1600 input = hex_to_bs<1600>(MSG5_XOR);
    BS1600 output = keccak_f(input);

    mu_assert(output.to_hex() == MSG5_IOTA23);

    return NULL;
}

void all_tests()
{
    mu_test(rnd_SA2);
    mu_test(rnd_SA64);
    mu_test(keccak_f_SA64);
}
