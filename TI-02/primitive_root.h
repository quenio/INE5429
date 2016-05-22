// Copyright (c) 2016 Quenio Cesar Machado dos Santos. All rights reserved.

#pragma once

#include <stdbool.h>
#include <gmp.h>

bool is_primitive_root(const mpz_t n, const mpz_t g);

void least_primitive_root(mpz_t rop, const mpz_t n);
