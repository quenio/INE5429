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
    BitString(uint64_t val): _bs(val) {}
    BitString(const std::string & s): _bs(s.c_str()) {}
    BitString(const char * s): _bs(s) {}
    BitString(std::bitset<N> bs): _bs(bs) {}

    std::string to_string() const { return _bs.to_string(); }

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

    size_t count() const { return _bs.count(); }
    size_t size() const { return _bs.size(); }

    BitString& operator &= (const BitString& rhs) { _bs &= rhs._bs; return *this; }
    BitString& operator |= (const BitString& rhs) { _bs |= rhs._bs; return *this; }
    BitString& operator ^= (const BitString& rhs) { _bs ^= rhs._bs; return *this; }

    BitString& operator <<= (size_t pos) { _bs <<= pos; return *this; }
    BitString& operator >>= (size_t pos) { _bs >>= pos; return *this; }

    BitString& set() { _bs.set(); return *this; }
    BitString& set(size_t pos, bool val = true) { _bs.set(reversed(pos), val); return *this; }

    BitString& reset() { _bs.reset(); return *this; }
    BitString& reset(size_t pos) { _bs.reset(reversed(pos)); return *this; }

    BitString operator~() const { return BitString(~_bs); }

    BitString& flip() { _bs.flip(); return *this; }
    BitString& flip(size_t pos){ _bs.flip(reversed(pos)); return *this; }

    bool operator [] (size_t pos) { return _bs[reversed(pos)]; }
    const bool operator [] (size_t pos) const { return _bs[reversed(pos)]; }

    bool operator == (const BitString& rhs) const { return _bs == rhs._bs; }
    bool operator != (const BitString& rhs) const { return _bs != rhs._bs; }

    bool test(size_t pos) const { return _bs.test(reversed(pos)); }
    bool all() const { return _bs.all(); }
    bool any() const { return _bs.any(); }
    bool none() const { return _bs.none(); }

    BitString operator << (size_t pos) const { return BitString(_bs << pos); }
    BitString operator >> (size_t pos) const { return BitString(_bs >> pos); }

    BitString reversed() const
    {
        std::string str = to_string();
        std::reverse(str.begin(), str.end());
        return BitString(str.c_str());
    }

    void swap_endian()
    {
        if (_bs.size() % byte_size == 0)
        {
            _bs = ::swap_endian(_bs.to_ullong());
        }
    }

    friend inline BitString operator & (const BitString & lhs, const BitString & rhs) { return BitString(lhs._bs & rhs._bs); }
    friend inline BitString operator | (const BitString & lhs, const BitString & rhs) { return BitString(lhs._bs | rhs._bs); }
    friend inline BitString operator ^ (const BitString & lhs, const BitString & rhs) { return BitString(lhs._bs ^ rhs._bs); }

    template <size_t L, size_t R>
    friend inline BitString<L+R> operator + (const BitString<L> & lhs, const BitString<R> & rhs)
    {
        return BitString<L+R>(lhs._bs.to_string() + rhs._bs.to_string());
    }

    template<size_t O, size_t I>
    friend BitString<O> truncate(const BitString<I> & input);

    friend inline std::istream & operator >> (std::istream & is, BitString & bstr)
    {
        constexpr size_t byte_size = 8;
        constexpr size_t block_size = N / byte_size;

        std::stringstream ss;

        bstr._bits_read = 0;
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
                bstr._bits_read += byte_size;
            }
        }

        bstr._bs = std::bitset<N> { ss.str() };

        return is;
    }

    size_t bits_read() { return _bits_read; }

private:
    size_t reversed(size_t pos) const { return N - pos - 1; }

    std::bitset<N> _bs;
    size_t _bits_read;
};

template<size_t O, size_t I>
inline BitString<O> truncate(const BitString<I> & input)
{
    return BitString<O>(input.to_string());
}

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
