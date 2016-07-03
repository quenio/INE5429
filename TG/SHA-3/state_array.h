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
    static constexpr size_t word_size = W;
    static constexpr size_t string_size = row_size * column_size * word_size;

    struct Coord3D
    {
        size_t x, y, z;

        Coord3D(size_t x, size_t y, size_t z): x(x), y(y), z(z) {}

        void p_cycle_x() { x = (x == 0 ? row_size : x) - 1; }
        void p_cycle_y() { y = (y == 0 ? column_size : y) - 1; }
        void p_cycle_z() { z = (z == 0 ? word_size : z) - 1; }

        void previous()
        {
            p_cycle_z();
            if (z == (word_size - 1)) p_cycle_y();
            if (y == (column_size - 1) && z == (word_size - 1)) x--;
        }

        void p_cycle()
        {
            p_cycle_z();
            if (z == (word_size - 1)) p_cycle_y();
            if (y == (column_size - 1) && z == (word_size - 1)) p_cycle_x();
        }

        void cycle_x() { x = (x + 1) % row_size; }
        void cycle_y() { y = (y + 1) % column_size; }
        void cycle_z() { z = (z + 1) % word_size; }

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
            return word_size * ((5 * y) + x) + z;
        }

        // bitset is little-endian:
        // - first bit in position b - 1
        // - last bit in position zero
        size_t little_endian_index() const
        {
            return string_size - linear_index() - 1;
        }

        // bitset is little-endian:
        // - first bit in position w - 1
        // - last bit in position zero
        size_t little_endian_z() const
        {
            return word_size - z - 1;
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

    StateArray(BitString<string_size> s)
    {
        for (Coord3D coord = begin(); coord != end(); coord.next())
        {
            this->set(coord, s[coord.little_endian_index()]);
        }
    }

    BitString<string_size> s()
    {
        BitString<string_size> s;

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

    void XOR(const Coord3D & left_coord, const Coord3D & right_coord)
    {
        set(left_coord, (*this)[left_coord] xor (*this)[right_coord]);
    }

private:
    BitString<word_size> matrix[row_size][column_size];
};


