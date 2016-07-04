// Copyright (c) 2016 Quenio Cesar Machado dos Santos. All rights reserved.

#include "min_unit.h"
#include "rho.h"

const char *s1 = "01100110011001100110011001100110011001100110011001";
const char *s2 = "01010110101001101010101010011001100110100110101001";

using SA2 = StateArray<2>;
using BS50 = BitString<50>;

const char * rho_test()
{
    SA2 a { BS50 { s1 } };
    SA2 b = rho(a);
    mu_assert(b.to_string() == s2);
    return NULL;
}

void all_tests()
{
    mu_test(rho_test);
}
