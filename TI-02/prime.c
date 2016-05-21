// Copyright (c) 2016 Quenio Cesar Machado dos Santos. All rights reserved.

#include <stdio.h>
#include <gmp.h>

#include "prime.h"
#include "random.h"
#include "mpz_print.h"

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
    // Quotient:
    mpz_t q;
    mpz_init(q);

    // Remainder:
    mpz_t r;
    mpz_init(r);

    // Initial dividend:
    mpz_init_set(rop, dividend);

    // Find next dividend:
    do
    {
        mpz_divmod(q, r, rop, divisor);

        if (mpz_cmp_ui(r, 0) == 0 && mpz_cmp_ui(q, 1) != 0) mpz_set(rop, q);
    }
    while (mpz_cmp_ui(r, 0) == 0 && mpz_cmp_ui(q, 1) != 0);

    return mpz_cmp(rop, dividend) != 0;
}

bool next_prime_divisor(mpz_t rop, const mpz_t dividend, const mpz_t divisor)
{
    mpz_t quotient;
    mpz_init(quotient);

    mpz_t remainder;
    mpz_init_set_ui(remainder, 1);

    mpz_t n;
    next_dividend(n, dividend, divisor);

    mpz_t d;
    mpz_init_set(d, divisor);

    while ((mpz_cmp(d, n) < 0) && (mpz_cmp_ui(remainder, 0) != 0))
    {
        next_prime(d, d);
        mpz_divmod(quotient, remainder, n, d);
    }

    mpz_set(rop, d);

    return mpz_cmp(rop, divisor) != 0;
}


