// Copyright (c) 2016 Quenio Cesar Machado dos Santos. All rights reserved.

#pragma once

#include "bit_string.h"

using namespace std;

#include <climits>

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
        int x, y;

        Coord2D(int x, int y): x(x), y(y) {}

        bool operator !=(const Coord2D & other) const
        {
            return x != other.x || y != other.y;
        }

        void p_cycle_x() { x = (x == 0 ? column_count : x) - 1; }
        void p_cycle_y() { y = (y == 0 ? row_count : y) - 1; }

        void previous()
        {
            p_cycle_x();
            if (x == (column_count - 1)) y--;
        }

        void p_cycle()
        {
            p_cycle_x();
            if (x == (column_count - 1)) p_cycle_y();
        }

        void cycle_x() { x = (x + 1) % column_count; }
        void cycle_y() { y = (y + 1) % row_count; }

        void next()
        {
            cycle_x();
            if (x == 0) y++;
        }

        void cycle()
        {
            cycle_x();
            if (x == 0) cycle_y();
        }

        int linear_index() const
        {
            return (y * column_count) + x;
        }

        friend inline ostream & operator << (ostream & os, const Coord2D & coord)
        {
            return os << "(" << coord.x << "," << coord.y << ")";
        }

    };

    struct Coord3D
    {
        int x, y, z;

        Coord3D(int x, int y, int z): x(x), y(y), z(z) {}

        void p_cycle_x() { x = (x == 0 ? column_count : x) - 1; }
        void p_cycle_y() { y = (y == 0 ? row_count : y) - 1; }
        void p_cycle_z() { z = (z == 0 ? lane_size : z) - 1; }

        void previous()
        {
            p_cycle_z();
            if (z == (lane_size - 1)) p_cycle_x();
            if (x == (column_count - 1) && z == (lane_size - 1)) y--;
        }

        void p_cycle()
        {
            p_cycle_z();
            if (z == (lane_size - 1)) p_cycle_x();
            if (x == (column_count - 1) && z == (lane_size - 1)) p_cycle_y();
        }

        void cycle_x() { x = (x + 1) % column_count; }
        void cycle_y() { y = (y + 1) % row_count; }
        void cycle_z() { z = (z + 1) % lane_size; }

        void next()
        {
            cycle_z();
            if (z == 0) cycle_x();
            if (x == 0 && z == 0) y++;
        }

        void cycle()
        {
            cycle_z();
            if (z == 0) cycle_x();
            if (x == 0 && z == 0) cycle_y();
        }

        bool operator !=(const Coord3D & other) const
        {
            return x != other.x || y != other.y || z != other.z;
        }

        int linear_index() const
        {
            return lane_size * ((y * column_count) + x) + z;
        }

        friend inline ostream & operator << (ostream & os, const Coord3D & coord)
        {
            return os << "(" << coord.x << "," << coord.y << "," << coord.z << ")";
        }

    };

    static Coord3D begin()
    {
        return { 0, 0, 0 };
    }

    static Coord3D end()
    {
        return { 0, row_count, 0 };
    }

    static Coord2D begin2D()
    {
        return { 0, 0 };
    }

    static Coord2D end2D()
    {
        return { 0, row_count };
    }

    StateArray() {}

    StateArray(BitString<string_size> s)
    {
        for (Coord3D coord = begin(); coord != end(); coord.next())
        {
            this->set(coord, s[coord.linear_index()]);
        }

        swap_endian();
    }

    BitString<string_size> s() const
    {
        StateArray st = *this;
        st.swap_endian();

        BitString<string_size> s;
        for (Coord3D coord = begin(); coord != end(); coord.next())
        {
            s.set(coord.linear_index(), st[coord]);
        }

        return s;
    }

    bool operator [](const Coord3D & coord)
    {
        return matrix[coord.x][coord.y][coord.z];
    }

    const bool operator [](const Coord3D & coord) const
    {
        return matrix[coord.x][coord.y][coord.z];
    }

    Lane & operator [](const Coord2D & coord)
    {
        return matrix[coord.x][coord.y];
    }

    const Lane & operator [](const Coord2D & coord) const
    {
        return matrix[coord.x][coord.y];
    }

    void set(const Coord3D & coord, const bool & bit)
    {
        matrix[coord.x][coord.y].set(coord.z, bit);
    }

    void XOR(const Coord3D & left_coord, const Coord3D & right_coord)
    {
        set(left_coord, (*this)[left_coord] xor (*this)[right_coord]);
    }

    Lane column_xor(int column_index) const
    {
        Coord2D coord = { column_index, 0 };
        Lane result = (*this)[coord];

        while (++coord.y < row_count)
        {
            result ^= (*this)[coord];
        }

        return result;
    }

    std::string to_string() const
    {
        return s().to_string();
    }

    std::string to_hex() const
    {
        StateArray st = *this;
        st.swap_endian();

        std::string str;
        for (Coord2D coord = begin2D(); coord != end2D(); coord.next())
        {
            str += st[coord].to_hex();
        }

        return str;
    }

private:

    void swap_endian()
    {
        if (lane_size % BitString<W>::byte_size == 0)
        {
            for (Coord2D coord = begin2D(); coord != end2D(); coord.next())
            {
                (*this)[coord].swap_endian();
            }
        }
    }

    Lane matrix[column_count][row_count];
};




