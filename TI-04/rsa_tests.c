// Copyright (c) 2016 Quenio Cesar Machado dos Santos. All rights reserved.

#include "min_unit.h"
#include "rsa.h"

#define MIN_DEBUG
#include "min_debug.h"

char * rsa_key_modulus__small_primes()
{
    mpz_t modulus;
    mpz_init(modulus);

    mpz_t p;
    mpz_init(p);

    mpz_t q;
    mpz_init(q);

    const size_t bit_count = sizeof(__uint64_t) * 8;
    rsa_key_modulus(modulus, p, q, bit_count);

    debug_size_t(mpz_sizeinbase(p, 2));
    debug_size_t(mpz_sizeinbase(q, 2));
    debug_size_t(mpz_sizeinbase(modulus, 2));

    mu_assert(mpz_sizeinbase(p, 2) <= bit_count);
    mu_assert(mpz_sizeinbase(q, 2) <= bit_count);
    mu_assert(mpz_sizeinbase(modulus, 2)  <= 2 * bit_count);
    mu_assert(mpz_probab_prime_p(p, 15) >= 1);
    mu_assert(mpz_probab_prime_p(q, 15) >= 1);
    mu_assert(mpz_divisible_p(modulus, p) != 0);
    mu_assert(mpz_divisible_p(modulus, q) != 0);

    mpz_clear(modulus);
    mpz_clear(p);
    mpz_clear(q);

    return NULL;
}

void all_tests()
{
    mu_test(rsa_key_modulus__small_primes);
}
