// Copyright (c) 2016 Quenio Cesar Machado dos Santos. All rights reserved.

#pragma once

#include "mpz_print.h"

#ifdef MPZ_DEBUG
    #define debug_section(name) printf("\n>>> %s:\n", #name);
    #define debug_var(var) print_var(#var, var);
#else
    #define debug_section(name)
    #define debug_var(var)
#endif

