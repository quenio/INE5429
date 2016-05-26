// Copyright (c) 2016 Quenio Cesar Machado dos Santos. All rights reserved.

#pragma once

#include <stdint.h>
#include <stdio.h>
#include <gmp.h>

void mpz_init_set_int64(mpz_t rop, size_t count, const uint64_t *op);
uint64_t * mpz_export_int64(uint64_t *rop, size_t *countp, const mpz_t op);
