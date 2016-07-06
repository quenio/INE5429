// Copyright (c) 2016 Quenio Cesar Machado dos Santos. All rights reserved.

#include "min_unit.h"
#include "theta.h"
#include "samples.h"

using namespace std;

const char * theta_SA2()
{
    using SA2 = StateArray<2>;
    using BS50 = BitString<50>;

    const char *s1 = "01100110011001100110011001100110011001100110011001";
    const char *s2 = "01011001011010011010010110010110100110100101100101";

    SA2 a { BS50 { s1 } };
    SA2 b = theta(a);

    mu_assert(b.to_string() == s2);

    return NULL;
}

const char * theta_SA64()
{
    using SA64 = StateArray<64>;

    SA64 a { hex_to_bs<1600>(MSG5_XOR) };
    SA64 b = theta(a);

    mu_assert(b.to_hex() == MSG5_THETA);

    return NULL;
}

void all_tests()
{
    mu_test(theta_SA2);
    mu_test(theta_SA64);
}
