// Copyright (c) 2016 Quenio Cesar Machado dos Santos. All rights reserved.

#include <stdio.h>
#include <gmp.h>

#include "prime.h"
#include "random.h"

#define MIN_DEBUG
#include "min_debug.h"

// Fermat
bool is_probably_prime(const mpz_t op)
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

    mpz_t a;
    mpz_init(a);

    static const int k = 5;
    for (int i = 0; i < k; i++)
    {
        random_mpz_interval(a, min, max);

        mpz_t r;
        mpz_init(r);
        mpz_powm(r, a, exp, n);

        if (mpz_cmp_ui(r, 1) != 0) return false;
    }

    mpz_clear(n);
    mpz_clear(min);
    mpz_clear(max);
    mpz_clear(exp);
    mpz_clear(a);

    return true;
}

void find_prime(mpz_t n, const size_t bit_count)
{
    debug_start(find_prime);
    debug_size_t(bit_count);

    do
    {
        random_mpz_t(n, bit_count);
        if (mpz_even_p(n)) mpz_sub_ui(n, n, 1);
    }
    while (!is_probably_prime(n));

    debug_mpz_t(n);
    debug_end(find_prime);
}

void next_odd(mpz_t rop, const mpz_t odd)
{
    mpz_set(rop, odd);
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
    debug_start(next_dividend);
    debug_mpz_t(dividend);
    debug_mpz_t(divisor);

    mpz_t original_dividend;
    mpz_init_set(original_dividend, dividend);
    debug_mpz_t(original_dividend);

    // Initial dividend:
    mpz_set(rop, dividend);
    debug_mpz_t(rop);

    if (mpz_cmp_ui(divisor, 1) == 0) return false;

    mpz_t quotient;
    mpz_init(quotient);

    // Remainder:
    mpz_t remainder;
    mpz_init(remainder);

    // Find next dividend:
    debug_start(loop);
    do
    {
        mpz_divmod(quotient, remainder, rop, divisor);
        debug_mpz_t(quotient);
        debug_mpz_t(remainder);

        if (mpz_cmp_ui(remainder, 0) == 0 && mpz_cmp_ui(quotient, 1) != 0) mpz_set(rop, quotient);
        debug_mpz_t(rop);
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
    debug_start(next_prime_divisor);
    debug_mpz_t(dividend);
    debug_mpz_t(divisor);

    mpz_t original_divisor;
    mpz_init_set(original_divisor, divisor);
    debug_mpz_t(original_divisor);

    mpz_t quotient;
    mpz_init(quotient);

    mpz_t remainder;
    mpz_init_set_ui(remainder, 1);
    debug_mpz_t(remainder);

    mpz_t n;
    mpz_init(n);
    next_dividend(n, dividend, divisor);
    debug_mpz_t(n);

    mpz_t d;
    mpz_init_set(d, divisor);
    debug_mpz_t(d);

    debug_start(next_prime_divisor__loop);
    while ((mpz_cmp(d, n) < 0) && (mpz_cmp_ui(remainder, 0) != 0))
    {
        next_prime(d, d);
        debug_mpz_t(d);

        mpz_divmod(quotient, remainder, n, d);
        debug_mpz_t(quotient);
        debug_mpz_t(remainder);
    }

    debug_start(next_prime_divisor__result);
    mpz_set(rop, d);
    debug_mpz_t(rop);

    const bool result = mpz_cmp(rop, original_divisor) != 0;

    mpz_clear(original_divisor);
    mpz_clear(quotient);
    mpz_clear(remainder);
    mpz_clear(n);
    mpz_clear(d);

    return result;
}

void smallest_coprime(mpz_t rop, const mpz_t n)
{

}


