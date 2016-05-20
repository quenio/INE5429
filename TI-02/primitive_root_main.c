// Copyright (c) 2016 Quenio Cesar Machado dos Santos. All rights reserved.

#include <stdio.h>

#include "primitive_root.h"
#include "timer.h"

int main()
{
    static const int base = 10;
    mpz_t n;
    mpz_init_set_ui(n, 761);

    const clock_t start = clock();

    mpz_t pr;
    primitive_root(pr, n);

    printf("t = %8.6lf", elapsed_secs(start));
    printf(" -> ");
    mpz_out_str(NULL, base, pr);
    printf("\n");

    return 0;
}