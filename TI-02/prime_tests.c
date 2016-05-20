// Copyright (c) 2016 Quenio Cesar Machado dos Santos. All rights reserved.

#include <stdlib.h>

#include "min_unit.h"
#include "prime.h"

char * next_dividend__main_scenario()
{
    // p = 12 - initial dividend
    mpz_t p;
    mpz_init_set_ui(p, 12);

    // d = 2 - divisor
    mpz_t d;
    mpz_init_set_ui(d, 2);

    // rop = (p/d)/d = (12/2)/2 = 3 because remainder of division is zero
    mpz_t rop;
    const bool result = next_dividend(rop, p, d);

    mu_assert(mpz_cmp_ui(rop, 3) == 0);
    mu_assert(result == true); // dividend changed

    return NULL;
}

char * next_dividend__no_more_divisors()
{
    // p = 3 - initial dividend
    mpz_t p;
    mpz_init_set_ui(p, 3);

    // d = 3 - divisor
    mpz_t d;
    mpz_init_set_ui(d, 3);

    // rop = 3 because reached the last divisor
    mpz_t rop;
    const bool result = next_dividend(rop, p, d);

    mu_assert(mpz_cmp_ui(rop, 3) == 0);
    mu_assert(result == false); // dividend did not change

    return NULL;
}

char * next_dividend__not_divisor()
{
    // p = 9 - initial dividend
    mpz_t p;
    mpz_init_set_ui(p, 9);

    // d = 2 - not a divisor of 9
    mpz_t d;
    mpz_init_set_ui(d, 2);

    // rop = 9 still because 2 is not a divisor of 9
    mpz_t rop;
    const bool result = next_dividend(rop, p, d);

    mu_assert(mpz_cmp_ui(rop, 9) == 0);
    mu_assert(result == false); // dividend did not change

    return NULL;
}

void all_tests()
{
    mu_test(next_dividend__main_scenario);
    mu_test(next_dividend__no_more_divisors);
    mu_test(next_dividend__not_divisor);
}

