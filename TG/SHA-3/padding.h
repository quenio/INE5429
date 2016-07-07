// Copyright (c) 2016 Quenio Cesar Machado dos Santos. All rights reserved.

#pragma once

#include "bit_string.h"

template<size_t R>
void pad101(BitString<R> & block, size_t actual_size)
{
    if (block.size() > actual_size)
    {
        block.set(actual_size, 1);
        block.set(R - 1, 1);
    }
}
