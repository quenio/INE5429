// Copyright (c) 2016 Quenio Cesar Machado dos Santos. All rights reserved.

#include "mpz_int64.h"

static const int mswf = 1; // most significant word first
static const int host_endian = 0;
static const int nails = 0; // use all bits of each word

void mpz_set_int64(mpz_t rop, size_t count, const uint64_t *op)
{
    mpz_import(rop, count, mswf, sizeof(uint64_t), host_endian, nails, op);
}

uint64_t * mpz_export_int64(uint64_t *rop, size_t *countp, const mpz_t op)
{
    return mpz_export(rop, countp, mswf, sizeof(uint64_t), host_endian, nails, op);
}