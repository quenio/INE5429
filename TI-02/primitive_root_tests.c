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

    mpz_clear(n);
    mpz_clear(g);

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

    mpz_clear(n);
    mpz_clear(g);

    return NULL;
}

char * is_primitive_root__1639197169_10()
{
    // n = 1639197169
    mpz_t n;
    mpz_init_set_ui(n, 1639197169);

    // g = 10
    mpz_t g;
    mpz_init_set_ui(g, 10);

    const bool result = is_primitive_root(n , g);
    mu_assert(result == true);

    mpz_clear(n);
    mpz_clear(g);

    return NULL;
}

char * least_primitive_root__list()
{
    static const size_t n_size = 5;
    static const uint32_t n_list[n_size] = { UINT32_C(761), UINT32_C(97), UINT32_C(2253127), UINT32_C(40487), UINT32_C(1639197169) };
    static const uint32_t root_list[n_size] = { UINT32_C(6), UINT32_C(5), UINT32_C(5), UINT32_C(5), UINT32_C(2) };

    for (size_t i = 0; i < n_size; i++)
    {
        // n = 761
        mpz_t n;
        mpz_init_set_ui(n, n_list[i]);

        // rop = 6
        mpz_t rop;
        mpz_init(rop);
        least_primitive_root(rop, n);

        mu_assert(mpz_cmp_ui(rop, root_list[i]) == 0);

        mpz_clear(n);
        mpz_clear(rop);
    }

    return NULL;
}

void all_tests()
{
    mu_test(is_primitive_root__761_6);
    mu_test(is_primitive_root__761_5);
    mu_test(is_primitive_root__1639197169_10);
    mu_test(least_primitive_root__list);
}
