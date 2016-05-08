// Copyright (c) 2016 Quenio Cesar Machado dos Santos. All rights reserved.

#include <stdio.h>
#include <gmp.h>
#include <time.h>

#include "prime.h"

int main()
{
    static const int base = 10;

    const clock_t start = clock();
    const size_t max_bit_count = 4096;
    const size_t bit_count_inc = 128;

    size_t bit_count = bit_count_inc;
    while (bit_count <= max_bit_count)
    {
        const clock_t s = clock();
        mpz_t n;
        find_prime(n, bit_count);
        const double t = (double) (clock() - s);

        printf("%-4lu (t = %10.6lf)", bit_count, t / CLOCKS_PER_SEC);
        printf(" -> ");
        mpz_out_str(NULL, base, n);
        printf("\n");

        bit_count += bit_count_inc;
    }

    const double time = (double) (clock() - start);
    printf("\nTotal Time: %lf\n", time / CLOCKS_PER_SEC);

    return 0;
}