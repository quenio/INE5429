// Copyright (c) 2016 Quenio Cesar Machado dos Santos. All rights reserved.

#include "min_unit.h"
#include "state_array.h"
#include <iostream>

using namespace std;

const char *s1 = "01100110011001100110011001100110011001100110011001";
const char *s2 = "11001100110011001100110011001100110011001100110011";

using ST2 = StateArray<2>;
using BS50 = BitString<50>;

const char * state_array__in_and_out()
{
    ST2 a { BS50 { s1 } };
    mu_assert(a.s().to_string() == string(s1));
    return NULL;
}

const char * state_array__assignment()
{
    ST2 a { BS50 { s1 } };

    for (size_t x = 0; x < ST2::row_size; x++)
    {
        for (size_t y = 0; y < ST2::column_size; y++)
        {
            for (size_t z = 0; z < ST2::w; z++)
            {
                a.set(x, y, z, a.get(x, y, (z + 1) % ST2::w));
            }
        }
    }

    mu_assert(a.s().to_string() == string(s2));

    return NULL;
}

void all_tests()
{
    mu_test(state_array__in_and_out);
    mu_test(state_array__assignment);
}
