// Copyright (c) 2016 Quenio Cesar Machado dos Santos. All rights reserved.

#include "phi.h"

#define MIN_DEBUG
#include "min_debug.h"

void phi(mpz_t m, const mpz_t p, const mpz_t q)
{
    debug_start(phi);

    mpz_t a;
    mpz_init_set(a, p);
    mpz_sub_ui(a, a, 1);
    debug_mpz_t(a);

    mpz_t b;
    mpz_init_set(b, q);
    mpz_sub_ui(b, b, 1);
    debug_mpz_t(b);

    mpz_mul(m, a, b);
    debug_mpz_t(m);

    mpz_clear(a);
    mpz_clear(b);
}
