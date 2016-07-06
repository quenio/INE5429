// Copyright (c) 2016 Quenio Cesar Machado dos Santos. All rights reserved.

#pragma once

#include <bitset>
#include <string>
#include <istream>
#include <sstream>
#include <iomanip>
#include <cassert>

template <typename T>
T swap_endian(T u)
{
    static_assert (CHAR_BIT == 8, "CHAR_BIT != 8");

    union
    {
        T u;
        unsigned char u8[sizeof(T)];
    } source, dest;

    source.u = u;

    for (size_t k = 0; k < sizeof(T); k++)
        dest.u8[k] = source.u8[sizeof(T) - k - 1];

    return dest.u;
}

// Non-reversed version of bitset.
template<size_t N>
struct BitString
{
    static constexpr size_t byte_size = 8;

    BitString() {}
    BitString(uint64_t val): bs(val) {}
    BitString(const std::string & s): bs(s.c_str()) {}
    BitString(const char * s): bs(s) {}
    BitString(std::bitset<N> bs): bs(bs) {}

    std::string to_string() const { return bs.to_string(); }

    std::string to_hex() const
    {
        constexpr size_t block_size = 64;
        const std::string bin_str = to_string();

        std::stringstream ss;
        for (int i = 0; i < size(); i += block_size)
        {
            std::bitset<block_size> bs64 { bin_str.substr(i, block_size).c_str() };
            const size_t bit_width = (i + block_size) > size() ? size() - i : block_size;
            ss << std::setfill('0') << std::setw(bit_width/4) << std::uppercase << std::hex << bs64.to_ulong();
        }

        return ss.str();
    }

    size_t count() const { return bs.count(); }
    size_t size() const { return bs.size(); }

    BitString& operator &= (const BitString& rhs) { bs &= rhs.bs; return *this; }
    BitString& operator |= (const BitString& rhs) { bs |= rhs.bs; return *this; }
    BitString& operator ^= (const BitString& rhs) { bs ^= rhs.bs; return *this; }

    BitString& operator <<= (size_t pos) { bs <<= pos; return *this; }
    BitString& operator >>= (size_t pos) { bs >>= pos; return *this; }

    BitString& set() { bs.set(); return *this; }
    BitString& set(size_t pos, bool val = true) { bs.set(reversed(pos), val); return *this; }

    BitString& reset() { bs.reset(); return *this; }
    BitString& reset(size_t pos) { bs.reset(reversed(pos)); return *this; }

    BitString operator~() const { return BitString(~bs); }

    BitString& flip() { bs.flip(); return *this; }
    BitString& flip(size_t pos){ bs.flip(reversed(pos)); return *this; }

    bool operator [] (size_t pos) { return bs[reversed(pos)]; }
    const bool operator [] (size_t pos) const { return bs[reversed(pos)]; }

    bool operator == (const BitString& rhs) const { return bs == rhs.bs; }
    bool operator != (const BitString& rhs) const { return bs != rhs.bs; }

    bool test(size_t pos) const { return bs.test(reversed(pos)); }
    bool all() const { return bs.all(); }
    bool any() const { return bs.any(); }
    bool none() const { return bs.none(); }

    BitString operator << (size_t pos) const { return BitString(bs << pos); }
    BitString operator >> (size_t pos) const { return BitString(bs >> pos); }

    BitString reversed() const
    {
        std::string str = to_string();
        std::reverse(str.begin(), str.end());
        return BitString(str.c_str());
    }

    void swap_endian()
    {
        if (bs.size() % byte_size == 0)
        {
            bs = ::swap_endian(bs.to_ullong());
        }
    }

    friend inline BitString operator & (const BitString & lhs, const BitString & rhs) { return BitString(lhs.bs & rhs.bs); }
    friend inline BitString operator | (const BitString & lhs, const BitString & rhs) { return BitString(lhs.bs | rhs.bs); }
    friend inline BitString operator ^ (const BitString & lhs, const BitString & rhs) { return BitString(lhs.bs ^ rhs.bs); }

    template <size_t L, size_t R>
    friend inline BitString<L+R> operator + (const BitString<L> & lhs, const BitString<R> & rhs)
    {
        return BitString<L+R>(lhs.bs.to_string() + rhs.bs.to_string());
    }

    friend inline std::istream & operator >> (std::istream & is, BitString & bstr)
    {
        constexpr size_t byte_size = 8;
        constexpr size_t block_size = N / byte_size;

        std::stringstream ss;

        for (size_t i = 0; i < block_size; i++)
        {
            unsigned char value;
            is >> value;
            if (is.eof())
            {
                ss << "00000000"; // one byte
            }
            else
            {
                std::bitset<byte_size> bs = value;
                ss << bs.to_string();
            }
        }

        bstr.bs = std::bitset<N> { ss.str() };

        return is;
    }

private:
    size_t reversed(size_t pos) const { return N - pos - 1; }

    std::bitset<N> bs;
};


inline std::string hex_to_bin(std::string hex_str)
{
    constexpr int byte_size = 2;

    assert(hex_str.size() % byte_size == 0);

    std::string bin_str;
    for (int i = 0; i < hex_str.size(); i += byte_size)
    {
        std::stringstream ss(hex_str.substr(i, byte_size));

        unsigned int value;
        ss >> std::hex >> value;
        std::bitset<8> bs = value;

        bin_str += bs.to_string();
    }

    return bin_str;
}

template<size_t N>
inline BitString<N> hex_to_bs(std::string hex_str)
{
    return BitString<N>(hex_to_bin(hex_str).c_str());
}

template <size_t N>
inline BitString<N> rotate(BitString<N> b, int n)
{
    return b << (n % N) | b >> ((N-n) % N);
}
