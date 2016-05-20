// Copyright (c) 2016 Quenio Cesar Machado dos Santos. All rights reserved.

#pragma once

#include <stdbool.h>
#include <gmp.h>

bool is_probably_prime(mpz_t rop);

void find_prime(mpz_t rop, size_t bit_count);

void next_prime(mpz_t rop, mpz_t n);

bool next_prime_factor(mpz_t rop, const mpz_t f, const mpz_t n);

bool next_dividend(mpz_t rop, const mpz_t p, const mpz_t d);

