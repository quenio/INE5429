// Copyright (c) 2016 Quenio Cesar Machado dos Santos. All rights reserved.

#include "min_unit.h"
#include "pi.h"

const char *s1 = "01100110011001100110011001100110011001100110011001";
const char *s2 = "01010101011010010101101010100101101010100101011010";

using SA2 = StateArray<2>;
using BS50 = BitString<50>;

const char * pi_test()
{
    SA2 a { BS50 { s1 } };
    SA2 b = pi(a);
    mu_assert(b.to_string() == s2);
    return NULL;
}

void all_tests()
{
    mu_test(pi_test);
}
