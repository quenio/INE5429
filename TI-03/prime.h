// Copyright (c) 2016 Quenio Cesar Machado dos Santos. All rights reserved.

#pragma once

#include <stdbool.h>
#include <gmp.h>

bool is_probably_prime(mpz_t rop);

void find_prime(mpz_t rop, size_t bit_count);
