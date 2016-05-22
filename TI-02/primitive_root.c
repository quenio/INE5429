// Copyright (c) 2016 Quenio Cesar Machado dos Santos. All rights reserved.

#include <gmp.h>

//#define MPZ_DEBUG

#include "primitive_root.h"
#include "prime.h"
#include "mpz_debug.h"

bool is_primitive_root(const mpz_t n, const mpz_t g)
{
    debug_section(is_primitive_root);
    debug_var(n);
    debug_var(g);

    // q = n
    mpz_t q;
    mpz_init_set(q, n);
    debug_var(q);

    // p = n - 1
    mpz_t p;
    mpz_init_set(p, n);
    mpz_sub_ui(p, p, 1);
    debug_var(p);

    // divisor = 1
    mpz_t divisor;
    mpz_init_set_ui(divisor, 1);
    debug_var(divisor);

    // dividend = p
    mpz_t dividend;
    mpz_init_set(dividend, p);

    mpz_t d;
    mpz_init(d);

    mpz_t a;
    mpz_init(a);

    // f = 2, 3, 5, ...
    while (next_prime_divisor(divisor, dividend, divisor))
    {
        debug_section(is_primitive_root__loop)
        debug_var(dividend);
        debug_var(divisor);

        // d = p / divisor
        mpz_div(d, p, divisor);
        debug_var(d);

        // a = g ^ d (mod n)
        mpz_powm(a, g, d, n);
        debug_var(a);

        if (mpz_cmp_ui(a, 1) == 0) return false;

        next_dividend(dividend, dividend, divisor);
    }

    mpz_clear(q);
    mpz_clear(p);
    mpz_clear(divisor);
    mpz_clear(dividend);
    mpz_clear(d);
    mpz_clear(a);

    debug_section(is_primitive_root__result);
    debug_var(g);

    return true;
}

void least_primitive_root(mpz_t rop, const mpz_t n)
{
    debug_section(least_primitive_root);
    debug_var(n);

    // g = 2
    mpz_t g;
    mpz_init_set_ui(g, 2);
    debug_var(g);

    while (!is_primitive_root(n, g))
    {
        debug_section(primitive_root__loop);

        // g++
        mpz_add_ui(g, g, 1);
        debug_var(g);
    }

    debug_section(primitive_root__result);
    mpz_set(rop, g);
    debug_var(rop);

    mpz_clear(g);
}