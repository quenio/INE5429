// Copyright (c) 2016 Quenio Cesar Machado dos Santos. All rights reserved.

#include <stdio.h>
#include <gmp.h>

#include "mpz_int64.h"
#include "prime.h"
#include "random.h"

const int base = 10;

int main()
{
    for (uint64_t i = 1; i <= UINT64_C(1000); i++)
    {
        mpz_t bn;
        random_mpz(bn, 256);

        if (is_probably_prime(bn))
        {
            printf("prime: ");
            mpz_out_str(NULL, base, bn);
            printf("\n");
        }
    }

    return 0;
}