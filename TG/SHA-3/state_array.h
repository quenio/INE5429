// Copyright (c) 2016 Quenio Cesar Machado dos Santos. All rights reserved.

#pragma once

#include <bitset>

template<size_t b>
using bit_string = std::bitset<b>;

template<size_t w>
struct state_array
{
    static constexpr size_t row_size = 5;
    static constexpr size_t column_size = row_size;
    static constexpr size_t b = row_size * column_size * w;

    inline size_t i(size_t x, size_t y, size_t z)
    {
        return w * ((5 * y) + x) + z;
    }

    state_array(bit_string<b> s)
    {
        for (size_t x = 0; x < row_size; x++)
        {
            for (size_t y = 0; y < column_size; y++)
            {
                for (size_t z = 0; z < w; z++)
                {
                    matrix[x][y].set(z, s[i(x, y, z)]);
                }
            }
        }
    }

    bit_string <b> s()
    {
        bit_string<b> s;

        for (size_t x = 0; x < row_size; x++)
        {
            for (size_t y = 0; y < column_size; y++)
            {
                for (size_t z = 0; z < w; z++)
                {
                    s.set(i(x, y, z), matrix[x][y][z]);
                }
            }
        }

        return s;
    }

private:
    bit_string<w> matrix[row_size][column_size];
};


