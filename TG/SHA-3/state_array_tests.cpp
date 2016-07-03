// Copyright (c) 2016 Quenio Cesar Machado dos Santos. All rights reserved.

#include "min_unit.h"
#include "state_array.h"
#include <iostream>

using namespace std;

const char *s = "01010101010101010101010101010101010101010101010101";

const char * state_array__constructor()
{
    state_array<2> a { bit_string<50> { s } };
    mu_assert(a.s().to_string() == string(s));
    cout << a.s().to_string().c_str() << "\n";
    return NULL;
}

void all_tests()
{
    mu_test(state_array__constructor);
}
