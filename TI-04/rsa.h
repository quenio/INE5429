// Copyright (c) 2016 Quenio Cesar Machado dos Santos. All rights reserved.

#pragma once

#include <gmp.h>

void rsa_key_modulus(mpz_t modulus, mpz_t p, mpz_t q, const size_t bit_count);