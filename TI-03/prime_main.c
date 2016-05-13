// Copyright (c) 2016 Quenio Cesar Machado dos Santos. All rights reserved.

#include <stdio.h>
#include <gmp.h>
#include <time.h>

#include "prime.h"
#include "timer.h"

int main()
{
    static const int base = 10;
    static const size_t max_bit_count = 4096;
    static const size_t bit_count_inc = 128;

    const clock_t start = clock();

    size_t bit_count = bit_count_inc;
    while (bit_count <= max_bit_count)
    {
        const clock_t s = clock();

        mpz_t n;
        find_prime(n, bit_count);

        printf("%-4lu (t = %10.6lf)", bit_count, elapsed_secs(s));
        printf(" -> ");
        mpz_out_str(NULL, base, n);
        printf("\n");

        bit_count += bit_count_inc;
    }

    printf("\nTotal Time: %lf\n", elapsed_secs(start));

    return 0;
}