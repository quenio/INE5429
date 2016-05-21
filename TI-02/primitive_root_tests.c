// Copyright (c) 2016 Quenio Cesar Machado dos Santos. All rights reserved.

#include <stdlib.h>

#include "min_unit.h"
#include "primitive_root.h"

char * is_primitive_root__761_6()
{
    // n = 761
    mpz_t n;
    mpz_init_set_ui(n, 761);

    // g = 6
    mpz_t g;
    mpz_init_set_ui(g, 6);

    const bool result = is_primitive_root(n , g);
    mu_assert(result == true);

    return NULL;
}

char * is_primitive_root__761_5()
{
    // n = 761
    mpz_t n;
    mpz_init_set_ui(n, 761);

    // g = 5
    mpz_t g;
    mpz_init_set_ui(g, 5);

    const bool result = is_primitive_root(n , g);
    mu_assert(result == false);

    return NULL;
}

void all_tests()
{
    mu_test(is_primitive_root__761_6);
    mu_test(is_primitive_root__761_5);
}
