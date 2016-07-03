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

    struct Coord3D
    {
        size_t x, y, z;

        Coord3D(size_t x, size_t y, size_t z): x(x), y(y), z(z) {}

        void cycle_x() { x = (x + 1) % row_size; }
        void cycle_y() { y = (y + 1) % column_size; }
        void cycle_z() { z = (z + 1) % w; }

        void next()
        {
            cycle_z();
            if (z == 0) cycle_y();
            if (y == 0 && z == 0) x++;
        }

        void cycle()
        {
            cycle_z();
            if (z == 0) cycle_y();
            if (y == 0 && z == 0) cycle_x();
        }

        bool operator !=(const Coord3D & other) const
        {
            return x != other.x || y != other.y || z != other.z;
        }

        size_t linear_index() const
        {
            return w * ((5 * y) + x) + z;
        }

        // bitset is little-endian:
        // - first bit in position b - 1
        // - last bit in position zero
        size_t little_endian_index() const
        {
            return b - linear_index() - 1;
        }

        // bitset is little-endian:
        // - first bit in position w - 1
        // - last bit in position zero
        size_t little_endian_z() const
        {
            return w - z - 1;
        }
    };

    static Coord3D begin()
    {
        return { 0, 0, 0 };
    }

    static Coord3D end()
    {
        return { row_size, 0, 0 };
    }

    StateArray(BitString<b> s)
    {
        for (Coord3D coord = begin(); coord != end(); coord.next())
        {
            this->set(coord, s[coord.little_endian_index()]);
        }
    }

    BitString<b> s()
    {
        BitString<b> s;

        for (Coord3D coord = begin(); coord != end(); coord.next())
        {
            s.set(coord.little_endian_index(), (*this)[coord]);
        }

        return s;
    }

    bool operator [](const Coord3D & coord) const
    {
        return matrix[coord.x][coord.y][coord.little_endian_z()];
    }

    void set(const Coord3D & coord, const bool & bit)
    {
        matrix[coord.x][coord.y].set(coord.little_endian_z(), bit);
    }

private:
    BitString<w> matrix[row_size][column_size];
};


