// Copyright (c) 2016 Quenio Cesar Machado dos Santos. All rights reserved.

#pragma once

#include "mpz_print.h"

#ifdef MIN_DEBUG
    #define debug_start(name) printf("\n>>> %s:\n", #name);
    #define debug_end(name) printf(">>> end: %s\n\n", #name);
    #define debug_mpz_t(var) print_mpz_t(#var, var);
    #define debug_size_t(var) printf("%s = %lu\n", #var, var);
    #define debug_uint64_t(var) printf("%s = %llu\n", #var, var);
#else
    #define debug_start(name)
    #define debug_end(name)
    #define debug_mpz_t(var)
    #define debug_size_t(var)
    #define debug_uint64_t(var)
#endif

