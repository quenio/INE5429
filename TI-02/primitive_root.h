// Copyright (c) 2016 Quenio Cesar Machado dos Santos. All rights reserved.

#pragma once

#include <stdbool.h>
#include <gmp.h>

bool is_primitive_root(mpz_t n, mpz_t g);

void primitive_root(mpz_t rop, mpz_t n);
