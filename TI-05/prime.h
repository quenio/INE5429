// Copyright (c) 2016 Quenio Cesar Machado dos Santos. All rights reserved.

#pragma once

#include <stdbool.h>
#include <gmp.h>

bool is_probably_prime(const mpz_t rop);

void find_prime(mpz_t n, const size_t bit_count);

void next_prime(mpz_t rop, const mpz_t n);

void small_coprime(mpz_t rop, const mpz_t n);

bool next_prime_divisor(mpz_t rop, const mpz_t dividend, const mpz_t divisor);

bool next_dividend(mpz_t rop, const mpz_t dividend, const mpz_t divisor);



