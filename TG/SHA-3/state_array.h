// Copyright (c) 2016 Quenio Cesar Machado dos Santos. All rights reserved.

#pragma once

#include <bitset>

template<size_t w>
struct state_array
{
    constexpr size_t row_size = 5;
    constexpr size_t column_size = row_size;
    constexpr size_t b = row_size * column_size * w;

    state_array(bitset<b> &s)
    {
        for (size_t x = 0; x < row_size; x++)
        {
            for (size_t y = 0; y < column_size; y++)
            {
                for (size_t z = 0; z < w; z++)
                {
                    matrix[x, y]->set(z, s[x * (5 * x) + z]);
                }
            }
        }
    }

private:
    bitset<w> matrix[row_size][column_size];
};
