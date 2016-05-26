// Copyright (c) 2016 Quenio Cesar Machado dos Santos. All rights reserved.

#include <stdio.h>
#include <gmp.h>

#include "mpz_print.h"

void print_var(const char * varName, const mpz_t var)
{
    printf("%s = ", varName);
    mpz_out_str(NULL, 10, var);
    printf("\n");
}