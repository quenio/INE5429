// Copyright (c) 2016 Quenio Cesar Machado dos Santos. All rights reserved.

#include "min_unit.h"
#include "chi.h"
#include "samples.h"

const char * chi_SA2()
{
    using SA2 = StateArray<2>;
    using BS50 = BitString<50>;

    const char *s1 = "01100110011001100110011001100110011001100110011001";
    const char *s2 = "00000010110000000111000000101100000001110000001011";

    SA2 a { BS50 { s1 } };
    SA2 b = chi(a);

    mu_assert(b.to_string() == s2);

    return NULL;
}

const char * chi_SA64()
{
    using SA64 = StateArray<64>;

    SA64 a { hex_to_bs<1600>(MSG5_PI) };
    SA64 b = chi(a);

    mu_assert(b.to_hex() == MSG5_CHI0);

    return NULL;
}

void all_tests()
{
    mu_test(chi_SA2);
    mu_test(chi_SA64);
}
