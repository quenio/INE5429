// Copyright (c) 2016 Quenio Cesar Machado dos Santos. All rights reserved.

#include "min_unit.h"
#include "rho.h"
#include "samples.h"

const char * rho_SA2()
{
    using SA2 = StateArray<2>;
    using BS50 = BitString<50>;

    const char *s1 = "01100110011001100110011001100110011001100110011001";
    const char *s2 = "01010110101001101010101010011001100110100110101001";

    SA2 a { BS50 { s1 } };
    SA2 b = rho(a);

    mu_assert(b.to_string() == s2);

    return NULL;
}

const char * rho_SA64()
{
    using SA64 = StateArray<64>;

    SA64 a { hex_to_bs<1600>(MSG5_THETA) };
    SA64 b = rho(a);

    mu_assert(b.to_hex() == MSG5_RHO);

    return NULL;
}

void all_tests()
{
    mu_test(rho_SA2);
    mu_test(rho_SA64);
}
