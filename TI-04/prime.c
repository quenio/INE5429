// Copyright (c) 2016 Quenio Cesar Machado dos Santos. All rights reserved.

#include <stdio.h>
#include <gmp.h>

//#define MPZ_DEBUG

#include "prime.h"
#include "random.h"
#include "mpz_debug.h"

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

    static const int k = 5;
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

void find_prime(mpz_t rop, size_t bit_count)
{
    do
    {
        random_mpz(rop, bit_count);
        if (mpz_even_p(rop)) mpz_sub_ui(rop, rop, 1);
    }
    while (!is_probably_prime(rop));
}

void next_odd(mpz_t rop, const mpz_t n)
{
    if (rop != n) mpz_init_set(rop, n);
    mpz_add_ui(rop, rop, (mpz_even_p(rop) || mpz_cmp_ui(rop, 2) <= 0) ? 1 : 2);
}

void next_prime(mpz_t rop, const mpz_t n)
{
    next_odd(rop, n);

    while (!is_probably_prime(rop))
    {
        next_odd(rop, rop);
    }
}

bool next_dividend(mpz_t rop, const mpz_t dividend, const mpz_t divisor)
{
    debug_section(next_dividend);
    debug_var(dividend);
    debug_var(divisor);

    mpz_t original_dividend;
    mpz_init_set(original_dividend, dividend);
    debug_var(original_dividend);

    // Initial dividend:
    mpz_set(rop, dividend);
    debug_var(rop);

    if (mpz_cmp_ui(divisor, 1) == 0) return false;

    mpz_t quotient;
    mpz_init(quotient);

    // Remainder:
    mpz_t remainder;
    mpz_init(remainder);

    // Find next dividend:
    debug_section(loop);
    do
    {
        mpz_divmod(quotient, remainder, rop, divisor);
        debug_var(quotient);
        debug_var(remainder);

        if (mpz_cmp_ui(remainder, 0) == 0 && mpz_cmp_ui(quotient, 1) != 0) mpz_set(rop, quotient);
        debug_var(rop);
    }
    while (mpz_cmp_ui(remainder, 0) == 0 && mpz_cmp_ui(quotient, 1) != 0);

    const bool result = mpz_cmp(rop, original_dividend) != 0;

    mpz_clear(original_dividend);
    mpz_clear(quotient);
    mpz_clear(remainder);

    return result;
}

bool next_prime_divisor(mpz_t rop, const mpz_t dividend, const mpz_t divisor)
{
    debug_section(next_prime_divisor);
    debug_var(dividend);
    debug_var(divisor);

    mpz_t original_divisor;
    mpz_init_set(original_divisor, divisor);
    debug_var(original_divisor);

    mpz_t quotient;
    mpz_init(quotient);

    mpz_t remainder;
    mpz_init_set_ui(remainder, 1);
    debug_var(remainder);

    mpz_t n;
    mpz_init(n);
    next_dividend(n, dividend, divisor);
    debug_var(n);

    mpz_t d;
    mpz_init_set(d, divisor);
    debug_var(d);

    debug_section(next_prime_divisor__loop);
    while ((mpz_cmp(d, n) < 0) && (mpz_cmp_ui(remainder, 0) != 0))
    {
        next_prime(d, d);
        debug_var(d);

        mpz_divmod(quotient, remainder, n, d);
        debug_var(quotient);
        debug_var(remainder);
    }

    debug_section(next_prime_divisor__result);
    mpz_set(rop, d);
    debug_var(rop);

    const bool result = mpz_cmp(rop, original_divisor) != 0;

    mpz_clear(original_divisor);
    mpz_clear(quotient);
    mpz_clear(remainder);
    mpz_clear(n);
    mpz_clear(d);

    return result;
}


