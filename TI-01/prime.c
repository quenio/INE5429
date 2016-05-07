// Copyright (c) 2016 Quenio Cesar Machado dos Santos. All rights reserved.

#include "prime.h"
#include "random.h"

// Fermat
bool is_probably_prime(mpz_t op)
{
    mpz_t n;
    mpz_init_set(n, op);
    mpz_abs(n, n);

    if (mpz_cmp_ui(n, 3) <= 0) return true;

    mpz_t min;
    mpz_init_set_ui(min, 2);

    mpz_t max;
    mpz_init_set(max, n);
    mpz_sub_ui(max, max, 2);

    mpz_t exp;
    mpz_init_set(exp, n);
    mpz_sub_ui(exp, exp, 1);

    static const int k = 1000;
    for (int i = 0; i < k; i++)
    {
        mpz_t a;
        random_mpz_interval(a, min, max);

        mpz_t r;
        mpz_init(r);
        mpz_powm(r, a, exp, n);

        if (mpz_cmp_ui(r, 1) != 0) return false;
    }

    return true;
}