// Copyright (c) 2016 Quenio Cesar Machado dos Santos. All rights reserved.

#include "phi.h"

#define MPZ_DEBUG

#include "mpz_debug.h"

void phi(mpz_t m, mpz_t p, mpz_t q)
{
    debug_section(phi);

    mpz_t a;
    mpz_init_set(a, p);
    mpz_sub_ui(a, a, 1);
    debug_var(a);

    mpz_t b;
    mpz_init_set(b, q);
    mpz_sub_ui(b, b, 1);
    debug_var(b);

    mpz_mul(m, a, b);
    debug_var(m);

    mpz_clear(a);
    mpz_clear(b);
}
