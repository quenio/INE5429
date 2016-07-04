// Copyright (c) 2016 Quenio Cesar Machado dos Santos. All rights reserved.

#pragma once

#include <bitset>
#include <string>

template<size_t B>
using BitString = std::bitset<B>;

template<size_t W>
struct StateArray
{
    static constexpr size_t row_count = 5;
    static constexpr size_t column_count = row_count;
    static constexpr size_t lane_count = row_count * column_count;
    static constexpr size_t lane_size = W;
    static constexpr size_t string_size = lane_count * lane_size;

    using Lane = BitString<lane_size>;

    struct Coord2D
    {
        size_t x, y;

        Coord2D(size_t x, size_t y): x(x), y(y) {}

        bool operator !=(const Coord2D & other) const
        {
            return x != other.x || y != other.y;
        }

        void p_cycle_x() { x = (x == 0 ? row_count : x) - 1; }
        void p_cycle_y() { y = (y == 0 ? column_count : y) - 1; }

        void previous()
        {
            p_cycle_y();
            if (y == (column_count - 1)) x--;
        }

        void p_cycle()
        {
            p_cycle_y();
            if (y == (column_count - 1)) p_cycle_x();
        }

        void cycle_x() { x = (x + 1) % row_count; }
        void cycle_y() { y = (y + 1) % column_count; }

        void next()
        {
            cycle_y();
            if (y == 0) x++;
        }

        void cycle()
        {
            cycle_y();
            if (y == 0) cycle_x();
        }

        size_t linear_index() const
        {
            return (x * column_count) + y;
        }

    };

    struct Coord3D
    {
        size_t x, y, z;

        Coord3D(size_t x, size_t y, size_t z): x(x), y(y), z(z) {}

        void p_cycle_x() { x = (x == 0 ? row_count : x) - 1; }
        void p_cycle_y() { y = (y == 0 ? column_count : y) - 1; }
        void p_cycle_z() { z = (z == 0 ? lane_size : z) - 1; }

        void previous()
        {
            p_cycle_z();
            if (z == (lane_size - 1)) p_cycle_y();
            if (y == (column_count - 1) && z == (lane_size - 1)) x--;
        }

        void p_cycle()
        {
            p_cycle_z();
            if (z == (lane_size - 1)) p_cycle_y();
            if (y == (column_count - 1) && z == (lane_size - 1)) p_cycle_x();
        }

        void cycle_x() { x = (x + 1) % row_count; }
        void cycle_y() { y = (y + 1) % column_count; }
        void cycle_z() { z = (z + 1) % lane_size; }

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
            return lane_size * ((x * column_count) + y) + z;
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
            return lane_size - z - 1;
        }
    };

    static Coord3D begin()
    {
        return { 0, 0, 0 };
    }

    static Coord3D end()
    {
        return { row_count, 0, 0 };
    }

    static Coord2D begin2D()
    {
        return { 0, 0 };
    }

    static Coord2D end2D()
    {
        return { row_count, 0 };
    }

    StateArray(BitString<string_size> s)
    {
        for (Coord3D coord = begin(); coord != end(); coord.next())
        {
            this->set(coord, s[coord.little_endian_index()]);
        }
    }

    BitString<string_size> s() const
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

    Lane & operator [](const Coord2D & coord)
    {
        return matrix[coord.x][coord.y];
    }

    void set(const Coord3D & coord, const bool & bit)
    {
        matrix[coord.x][coord.y].set(coord.little_endian_z(), bit);
    }

    void XOR(const Coord3D & left_coord, const Coord3D & right_coord)
    {
        set(left_coord, (*this)[left_coord] xor (*this)[right_coord]);
    }

    Lane column_xor(size_t columnIndex)
    {
        Coord2D coord = { 0, columnIndex };
        Lane result = (*this)[coord];

        while (++coord.x < row_count)
        {
            result ^= (*this)[coord];
        }

        return result;
    }

    std::string to_string() const
    {
        return this->s().to_string();
    }

private:
    Lane matrix[row_count][column_count];
};




