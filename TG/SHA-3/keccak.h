// Copyright (c) 2016 Quenio Cesar Machado dos Santos. All rights reserved.

#pragma once

#include "theta.h"
#include "rho.h"
#include "pi.h"
#include "chi.h"
#include "iota.h"

template<size_t W>
StateArray<W> rnd(StateArray<W> & a, int i)
{
    return iota(chi(pi(rho(theta(a)))), i);
}