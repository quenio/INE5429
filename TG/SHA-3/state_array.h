// Copyright (c) 2016 Quenio Cesar Machado dos Santos. All rights reserved.

#pragma once

#include <bitset>

template<size_t B>
using BitString = std::bitset<B>;

template<size_t W>
struct StateArray
{
    static constexpr size_t row_size = 5;
    static constexpr size_t column_size = row_size;
    static constexpr size_t w = W;
    static constexpr size_t b = row_size * column_size * w;

    size_t linear_index(size_t x, size_t y, size_t z) const
    {
        return w * ((5 * y) + x) + z;
    }

    // bitset is little-endian:
    // - first bit in position b - 1
    // - last bit in position zero
    size_t little_endian_index(size_t x, size_t y, size_t z) const
    {
        return b - linear_index(x, y, z) - 1;
    }

    StateArray(BitString<b> s)
    {
        for (size_t x = 0; x < row_size; x++)
        {
            for (size_t y = 0; y < column_size; y++)
            {
                for (size_t z = 0; z < w; z++)
                {
                    set(x, y, z, s[little_endian_index(x, y, z)]);
                }
            }
        }
    }

    BitString<b> s()
    {
        BitString<b> s;

        for (size_t x = 0; x < row_size; x++)
        {
            for (size_t y = 0; y < column_size; y++)
            {
                for (size_t z = 0; z < w; z++)
                {
                    s.set(little_endian_index(x, y, z), get(x, y, z));
                }
            }
        }

        return s;
    }

    // bitset is little-endian:
    // - first bit in position w - 1
    // - last bit in position zero
    size_t little_endian_z(size_t z) const
    {
        return w - z - 1;
    }

    bool get(const size_t & x, const size_t & y, const size_t & z) const
    {
        return matrix[x][y][little_endian_z(z)];
    }

    void set(const size_t & x, const size_t & y, const size_t & z, const bool & bit)
    {
        matrix[x][y].set(little_endian_z(z), bit);
    }

private:
    BitString<w> matrix[row_size][column_size];
};


