// Copyright (c) 2016 Quenio Cesar Machado dos Santos. All rights reserved.

#include <stdio.h>
#include <gmp.h>

#include "random.h"

const int base = 10;

int main()
{
    for (int64_t i = 0; i < UINT64_C(1000000); i++)
    {
        mpz_t bn1, bn2;
        random_mpz(bn1, 2048);
        random_mpz(bn2, 2048);

        if (mpz_cmp(bn1, bn2) == 0) {
            printf("equals = ");
            mpz_out_str(NULL, base, bn1);
            printf("\n");
            return 1;
        }

        mpz_clear(bn1);
        mpz_clear(bn2);
    }

    mpz_t bn1;
    random_mpz(bn1, 2048);
    mpz_out_str(NULL, base, bn1);
    printf("\n");

    printf("No repeats");

    return 0;
}