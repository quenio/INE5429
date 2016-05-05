// Copyright (c) 2016 Quenio Cesar Machado dos Santos. All rights reserved.

#include <stdio.h>
#include <gmp.h>

#include "random.h"

const int base = 10;

int main()
{
    for (int i = 0; i < 10; i++)
    {
        mpz_t bn;
        random_mpz(bn, 128);

        uint64_t m[2];
        size_t new_count;
        mpz_export_int64(m, &new_count, bn);

        printf("bn = ");
        mpz_out_str(NULL, base, bn);
        printf("\n");
        printf("m  = ");
        for (int j = 0; j < 2; j++) printf("%llu ", m[j]);
        printf("\n");

        printf("count  = %lu\n", new_count);

        mpz_clear(bn);
    }

    return 0;
}