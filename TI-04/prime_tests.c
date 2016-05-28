// Copyright (c) 2016 Quenio Cesar Machado dos Santos. All rights reserved.

#include <stdlib.h>

#include "min_unit.h"
#include "prime.h"

//#define MIN_DEBUG
#include "min_debug.h"

char * next_dividend__small_numbers()
{
    // dividend = 12
    mpz_t dividend;
    mpz_init_set_ui(dividend, 12);

    // divisor = 2
    mpz_t divisor;
    mpz_init_set_ui(divisor, 2);

    // rop = (p/d)/d = (12/2)/2 = 3
    mpz_t rop;
    mpz_init(rop);
    const bool result = next_dividend(rop, dividend, divisor);

    mu_assert(mpz_cmp_ui(rop, 3) == 0);
    mu_assert(result == true); // rop != dividend

    mpz_clear(dividend);
    mpz_clear(divisor);
    mpz_clear(rop);

    return NULL;
}

char * next_dividend__larger_numbers()
{
    // dividend = 760
    mpz_t dividend;
    mpz_init_set_ui(dividend, 760);

    // divisor = 2
    mpz_t divisor;
    mpz_init_set_ui(divisor, 2);

    // rop = (p/d)/d = ((760/2)/2)/2 = 95
    mpz_t rop;
    mpz_init(rop);
    const bool result = next_dividend(rop, dividend, divisor);

    mu_assert(mpz_cmp_ui(rop, 95) == 0);
    mu_assert(result == true); // rop != dividend

    mpz_clear(dividend);
    mpz_clear(divisor);
    mpz_clear(rop);

    return NULL;
}

char * next_dividend__same_var_for_result()
{
    // dividend = 760
    mpz_t dividend;
    mpz_init_set_ui(dividend, 760);

    // divisor = 2
    mpz_t divisor;
    mpz_init_set_ui(divisor, 2);

    // rop = (p/d)/d = ((760/2)/2)/2 = 95
    const bool result = next_dividend(dividend, dividend, divisor);

    mu_assert(mpz_cmp_ui(dividend, 95) == 0);
    mu_assert(result == true); // rop != dividend

    mpz_clear(dividend);
    mpz_clear(divisor);

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
    mpz_init(rop);
    const bool result = next_dividend(rop, dividend, divisor);

    mu_assert(mpz_cmp_ui(rop, 3) == 0);
    mu_assert(result == false); // rop == dividend

    mpz_clear(dividend);
    mpz_clear(divisor);
    mpz_clear(rop);

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
    mpz_init(rop);
    const bool result = next_dividend(rop, dividend, divisor);

    mu_assert(mpz_cmp_ui(rop, 9) == 0);
    mu_assert(result == false); // rop == dividend

    mpz_clear(dividend);
    mpz_clear(divisor);
    mpz_clear(rop);

    return NULL;
}

char * next_dividend__one_as_divisor()
{
    // dividend = 2
    mpz_t dividend;
    mpz_init_set_ui(dividend, 2);

    // divisor = 1
    mpz_t divisor;
    mpz_init_set_ui(divisor, 1);

    // rop = 2 <- 2 / 1 = 2
    mpz_t rop;
    mpz_init(rop);
    const bool result = next_dividend(rop, dividend, divisor);

    mu_assert(mpz_cmp_ui(rop, 2) == 0);
    mu_assert(result == false); // rop == dividend

    mpz_clear(dividend);
    mpz_clear(divisor);
    mpz_clear(rop);

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
    mpz_init(rop);
    const bool result = next_prime_divisor(rop, dividend, divisor);

    mu_assert(mpz_cmp_ui(rop, 3) == 0);
    mu_assert(result == true); // rop != divisor

    mpz_clear(dividend);
    mpz_clear(divisor);
    mpz_clear(rop);

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
    mpz_init(rop);
    const bool result = next_prime_divisor(rop, dividend, divisor);

    mu_assert(mpz_cmp_ui(rop, 19) == 0);
    mu_assert(result == true); // rop != divisor

    mpz_clear(dividend);
    mpz_clear(divisor);
    mpz_clear(rop);

    return NULL;
}

char * next_prime_divisor__very_large_dividend()
{
    // dividend = 95
    mpz_t dividend;
    mpz_init_set_ui(dividend, 1639197169);

    // divisor = 1
    mpz_t divisor;
    mpz_init_set_ui(divisor, 1);

    // rop = 40487 <- 40487 x 40487 = 1639197169
    mpz_t rop;
    mpz_init(rop);
    const bool result = next_prime_divisor(rop, dividend, divisor);

    mu_assert(mpz_cmp_ui(rop, 40487) == 0);
    mu_assert(result == true); // rop != divisor

    mpz_clear(dividend);
    mpz_clear(divisor);
    mpz_clear(rop);

    return NULL;
}

char * next_prime_divisor__prime_number()
{
    // dividend = 95
    mpz_t dividend;
    mpz_init_set_ui(dividend, 40487);

    // divisor = 1
    mpz_t divisor;
    mpz_init_set_ui(divisor, 1);

    // rop = 40487
    mpz_t rop;
    mpz_init(rop);
    const bool result = next_prime_divisor(rop, dividend, divisor);

    mu_assert(mpz_cmp_ui(rop, 40487) == 0);
    mu_assert(result == true); // rop != divisor

    mpz_clear(dividend);
    mpz_clear(divisor);
    mpz_clear(rop);

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
    mpz_init(rop);
    const bool result = next_prime_divisor(rop, dividend, divisor);

    mu_assert(mpz_cmp_ui(rop, 19) == 0);
    mu_assert(result == false); // rop == divisor

    mpz_clear(dividend);
    mpz_clear(divisor);
    mpz_clear(rop);

    return NULL;
}

char * next_prime_divisor__one_as_divisor()
{
    // dividend = x
    mpz_t dividend;
    mpz_init_set_ui(dividend, 95);

    // divisor = 1
    mpz_t divisor;
    mpz_init_set_ui(divisor, 1);

    // rop = 5 <- 5 x 19 = 95
    mpz_t rop;
    mpz_init(rop);
    const bool result = next_prime_divisor(rop, dividend, divisor);

    mu_assert(mpz_cmp_ui(rop, 5) == 0);
    mu_assert(result == true); // rop != divisor

    mpz_clear(dividend);
    mpz_clear(divisor);
    mpz_clear(rop);

    return NULL;
}

char * small_coprime__of_number_is(uint16_t number, uint16_t expected_result)
{
    mpz_t n;
    mpz_init_set_ui(n, number);

    mpz_t coprime;
    mpz_init(coprime);

    small_coprime(coprime, n);
    debug_mpz_t(coprime);

    mu_assert(mpz_cmp_ui(coprime, expected_result) == 0);

    return NULL;
}

void all_tests()
{
    mu_test(next_dividend__small_numbers);
    mu_test(next_dividend__larger_numbers);
    mu_test(next_dividend__same_var_for_result);
    mu_test(next_dividend__no_more_divisors);
    mu_test(next_dividend__not_divisor);
    mu_test(next_dividend__one_as_divisor);
    mu_test(next_prime_divisor__small_divisors);
    mu_test(next_prime_divisor__bigger_divisors);
    mu_test(next_prime_divisor__very_large_dividend);
    mu_test(next_prime_divisor__prime_number);
    mu_test(next_prime_divisor__last_divisor);
    mu_test(next_prime_divisor__one_as_divisor);
    mu_test(small_coprime__of_number_is, 1, 1);
    mu_test(small_coprime__of_number_is, 2, 1);
    mu_test(small_coprime__of_number_is, 3, 2);
    mu_test(small_coprime__of_number_is, 4, 3);
    mu_test(small_coprime__of_number_is, 5, 2);
    mu_test(small_coprime__of_number_is, 6, 5);
    mu_test(small_coprime__of_number_is, 7, 2);
    mu_test(small_coprime__of_number_is, 8, 3);
    mu_test(small_coprime__of_number_is, 9, 2);
    mu_test(small_coprime__of_number_is, 10, 3);
    mu_test(small_coprime__of_number_is, 11, 2);
    mu_test(small_coprime__of_number_is, 12, 5);
    mu_test(small_coprime__of_number_is, 100, 3);
    mu_test(small_coprime__of_number_is, 112, 3);
    mu_test(small_coprime__of_number_is, 2802, 5);
}

