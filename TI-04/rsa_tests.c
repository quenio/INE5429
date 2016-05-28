// Copyright (c) 2016 Quenio Cesar Machado dos Santos. All rights reserved.

#include <stdint.h>
#include "min_unit.h"
#include "phi.h"
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

char * rsa_encrypting_exponent__of(uint64_t some_p, uint64_t some_q, uint64_t expected_result)
{
    mpz_t p;
    mpz_init_set_ui(p, some_p);
    debug_mpz_t(p);

    mpz_t q;
    mpz_init_set_ui(q, some_q);
    debug_mpz_t(q);

    mpz_t encrypting_exponent;
    mpz_init(encrypting_exponent);

    rsa_encrypting_exponent(p, q, encrypting_exponent);
    debug_mpz_t(encrypting_exponent);

    debug_uint64_t(expected_result);
    mu_assert(mpz_cmp_ui(encrypting_exponent, expected_result) == 0);

    mpz_clear(p);
    mpz_clear(q);
    mpz_clear(encrypting_exponent);

    return NULL;
}

char * rsa_decrypting_exponent__of(const uint64_t some_p, const uint64_t some_q, const uint64_t encrypting_exp)
{
    debug_start(rsa_decrypting_exponent__of);

    mpz_t p;
    mpz_init_set_ui(p, some_p);
    debug_mpz_t(p);

    mpz_t q;
    mpz_init_set_ui(q, some_q);
    debug_mpz_t(q);

    mpz_t encrypting_exponent;
    mpz_init_set_ui(encrypting_exponent, encrypting_exp);
    debug_mpz_t(encrypting_exponent);

    mpz_t decrypting_exponent;
    mpz_init(decrypting_exponent);
    rsa_decrypting_exponent(p, q, encrypting_exponent, decrypting_exponent);
    debug_mpz_t(decrypting_exponent);

    mpz_t phi_modulus;
    mpz_init(phi_modulus);
    phi(phi_modulus, p, q);
    debug_mpz_t(phi_modulus);

    mpz_t expected_result;
    mpz_init(expected_result);
    mpz_mul(expected_result, encrypting_exponent, decrypting_exponent);
    debug_mpz_t(expected_result);

    mpz_mod(expected_result, expected_result, phi_modulus);
    debug_mpz_t(expected_result);

    mu_assert(mpz_cmp_ui(expected_result, 1) == 0);

    mpz_clear(p);
    mpz_clear(q);
    mpz_clear(encrypting_exponent);
    mpz_clear(decrypting_exponent);

    return NULL;
}

void all_tests()
{
    mu_test(rsa_key_modulus__small_primes);
    mu_test(rsa_encrypting_exponent__of, 11, 13, 7);
    mu_test(rsa_decrypting_exponent__of, 2803, 113, 5);
    mu_test(rsa_decrypting_exponent__of, 11, 13, 7);
    mu_test(rsa_decrypting_exponent__of, 2803, 113, 5);
}