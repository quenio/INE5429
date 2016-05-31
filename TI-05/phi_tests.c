// Copyright (c) 2016 Quenio Cesar Machado dos Santos. All rights reserved.

#include "min_unit.h"
#include "phi.h"

char * phi__small_primes()
{
    // p = 3
    mpz_t p;
    mpz_init_set_ui(p, 3);

    // p = 5
    mpz_t q;
    mpz_init_set_ui(q, 5);

    // m = (p - 1)(q - 1) = 2 x 4 = 8
    mpz_t m;
    mpz_init(m);
    phi(m, p, q);

    mu_assert(mpz_cmp_ui(m, 8) == 0);

    mpz_clear(p);
    mpz_clear(q);
    mpz_clear(m);

    return NULL;
}

void all_tests()
{
    mu_test(phi__small_primes);
}
