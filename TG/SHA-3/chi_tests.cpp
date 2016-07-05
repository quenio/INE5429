// Copyright (c) 2016 Quenio Cesar Machado dos Santos. All rights reserved.

#include "min_unit.h"
#include "chi.h"

const char *s1 = "01100110011001100110011001100110011001100110011001";
const char *s2 = "00000010110000000111000000101100000001110000001011";

using SA2 = StateArray<2>;
using BS50 = BitString<50>;

const char * chi_test()
{
    SA2 a { BS50 { s1 } };
    SA2 b = chi(a);
    mu_assert(b.to_string() == s2);
    return NULL;
}

void all_tests()
{
    mu_test(chi_test);
}
