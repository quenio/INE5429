// Copyright (c) 2016 Quenio Cesar Machado dos Santos. All rights reserved.

#include "min_unit.h"
#include "theta.h"

using namespace std;

const char *s1 = "01100110011001100110011001100110011001100110011001";
const char *s2 = "01011001011010011010010110010110100110100101100101";

using SA2 = StateArray<2>;
using BS50 = BitString<50>;

const char * theta_test()
{
    SA2 a { BS50 { s1 } };

    SA2 b = theta(a);

    mu_assert(b.to_string() == s2);

    return NULL;
}

void all_tests()
{
    mu_test(theta_test);
}
