// Copyright (c) 2016 Quenio Cesar Machado dos Santos. All rights reserved.

#include <stdlib.h>

#include "min_unit.h"
#include "prime.h"

char * next_dividend__main_scenario()
{
    // dividend = 12
    mpz_t dividend;
    mpz_init_set_ui(dividend, 12);

    // divisor = 2
    mpz_t divisor;
    mpz_init_set_ui(divisor, 2);

    // rop = (p/d)/d = (12/2)/2 = 3
    mpz_t rop;
    const bool result = next_dividend(rop, dividend, divisor);

    mu_assert(mpz_cmp_ui(rop, 3) == 0);
    mu_assert(result == true); // rop != dividend

    return NULL;
}

char * next_dividend__no_more_divisors()
{
    // dividend = 3
    mpz_t dividend;
    mpz_init_set_ui(dividend, 3);

    // divisor = 3
    mpz_t divisor;
    mpz_init_set_ui(divisor, 3);

    // rop = 3 <- 3/3 = 1
    mpz_t rop;
    const bool result = next_dividend(rop, dividend, divisor);

    mu_assert(mpz_cmp_ui(rop, 3) == 0);
    mu_assert(result == false); // rop == dividend

    return NULL;
}

char * next_dividend__not_divisor()
{
    // dividend = 9
    mpz_t dividend;
    mpz_init_set_ui(dividend, 9);

    // divisor = 2
    mpz_t divisor;
    mpz_init_set_ui(divisor, 2);

    // rop = 9 <- 9 mod 2 > 0
    mpz_t rop;
    const bool result = next_dividend(rop, dividend, divisor);

    mu_assert(mpz_cmp_ui(rop, 9) == 0);
    mu_assert(result == false); // rop == dividend

    return NULL;
}

char * next_prime_divisor__small_divisors()
{
    // dividend = 12
    mpz_t dividend;
    mpz_init_set_ui(dividend, 12);

    // divisor = 2
    mpz_t divisor;
    mpz_init_set_ui(divisor, 2);

    // rop = 3 <- 2 x 2 x 3 = 12
    mpz_t rop;
    const bool result = next_prime_divisor(rop, dividend, divisor);

    mu_assert(mpz_cmp_ui(rop, 3) == 0);
    mu_assert(result == true); // rop != divisor

    return NULL;
}

char * next_prime_divisor__bigger_divisors()
{
    // dividend = 95
    mpz_t dividend;
    mpz_init_set_ui(dividend, 95);

    // divisor = 5
    mpz_t divisor;
    mpz_init_set_ui(divisor, 5);

    // rop = 19 <- 5 x 19 = 95
    mpz_t rop;
    const bool result = next_prime_divisor(rop, dividend, divisor);

    mu_assert(mpz_cmp_ui(rop, 19) == 0);
    mu_assert(result == true); // rop != divisor

    return NULL;
}

char * next_prime_divisor__last_divisor()
{
    // dividend = 19
    mpz_t dividend;
    mpz_init_set_ui(dividend, 19);

    // divisor = 19
    mpz_t divisor;
    mpz_init_set_ui(divisor, 19);

    // rop = 19 <- 1 x 19 = 19
    mpz_t rop;
    const bool result = next_prime_divisor(rop, dividend, divisor);

    mu_assert(mpz_cmp_ui(rop, 19) == 0);
    mu_assert(result == false); // rop == divisor

    return NULL;
}

void all_tests()
{
    mu_test(next_dividend__main_scenario);
    mu_test(next_dividend__no_more_divisors);
    mu_test(next_dividend__not_divisor);
    mu_test(next_prime_divisor__small_divisors);
    mu_test(next_prime_divisor__bigger_divisors);
    mu_test(next_prime_divisor__last_divisor);
}

