// Copyright (c) 2016 Quenio Cesar Machado dos Santos. All rights reserved.

#include <stdio.h>
#include <gmp.h>

#include "prime.h"
#include "primitive_root.h"

bool is_primitive_root(mpz_t n, mpz_t g)
{
    // q = n
    mpz_t q;
    mpz_init_set(q, n);

    // p = n - 1
    mpz_t p;
    mpz_init_set(p, n);
    mpz_sub_ui(p, p, 1);

    // f = 1
    mpz_t f;
    mpz_init_set_ui(f, 1);

    // f = 2, 3, 5, ...
    while (next_prime_factor(f, f, q))
    {
        printf("f = ");
        mpz_out_str(NULL, 10, f);
        printf("\n");

        printf("q = ");
        mpz_out_str(NULL, 10, q);
        printf("\n");

        // d = p / f
        mpz_t d;
        mpz_init(d);
        mpz_div(d, p, f);

        printf("d: ");
        mpz_out_str(NULL, 10, d);
        printf("\n");

        // a = g ^ d (mod n)
        mpz_t a;
        mpz_init(a);
        mpz_powm(a, g, d, n);

        printf("a: ");
        mpz_out_str(NULL, 10, a);
        printf("\n");

        if (mpz_cmp_ui(a, 1) == 0) return false;
    }

    mpz_clear(f);
    mpz_clear(p);

    return true;
}

void primitive_root(mpz_t rop, mpz_t n)
{
    // g = 2
    mpz_t g;
    mpz_init_set_ui(g, 2);

    printf("initial g = ");
    mpz_out_str(NULL, 10, g);
    printf("\n");

    while (!is_primitive_root(n, g))
    {
        printf("not primitive_root: ");
        mpz_out_str(NULL, 10, g);
        printf("\n");
        printf("\n");

        // g++
        mpz_add_ui(g, g, 1);

        printf("next g = ");
        mpz_out_str(NULL, 10, g);
        printf("\n");
    }

    mpz_init_set(rop, g);

    mpz_clear(g);
}