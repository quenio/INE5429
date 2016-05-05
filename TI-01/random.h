// Copyright (c) 2016 Quenio Cesar Machado dos Santos. All rights reserved.

#pragma once

#include <stdint.h>

#include "mpz_int64.h"

uint64_t random_int64();

void random_mpz(mpz_t rop, size_t bit_count);