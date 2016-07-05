// Copyright (c) 2016 Quenio Cesar Machado dos Santos. All rights reserved.

#pragma once

#include <bitset>
#include <string>

// Non-inversed version of bitset.
template<size_t N>
struct BitString
{
    BitString() {}
    BitString(const char * s): bs(s) {}
    BitString(std::bitset<N> bs): bs(bs) {}

    std::string to_string() const { return bs.to_string(); }

    size_t count() const { return bs.count(); }
    size_t size() const { return bs.size(); }

    BitString& operator&=(const BitString& rhs) { bs &= rhs.bs; return *this; }
    BitString& operator|=(const BitString& rhs) { bs |= rhs.bs; return *this; }
    BitString& operator^=(const BitString& rhs) { bs ^= rhs.bs; return *this; }

    BitString& operator<<=(size_t pos) { bs >>= pos; return *this; }
    BitString& operator>>=(size_t pos) { bs <<= pos; return *this; }

    BitString& set() { bs.set(); return *this; }
    BitString& set(size_t pos, bool val = true) { bs.set(little_endian(pos), val); return *this; }

    BitString& reset() { bs.reset(); return *this; }
    BitString& reset(size_t pos) { bs.reset(little_endian(pos)); return *this; }

    BitString operator~() const { return BitString(~bs); }

    BitString& flip() { bs.flip(); return *this; }
    BitString& flip(size_t pos){ bs.flip(little_endian(pos)); return *this; }

    bool operator[](size_t pos) const { return bs[little_endian(pos)]; }

    bool operator==(const BitString& rhs) const { return bs == rhs.bs; }
    bool operator!=(const BitString& rhs) const { return bs != rhs.bs; }

    bool test(size_t pos) const { return bs.test(little_endian(pos)); }
    bool all() const { return bs.all(); }
    bool any() const { return bs.any(); }
    bool none() const { return bs.none(); }

    BitString operator<<(size_t pos) const { return BitString(bs >> pos); }
    BitString operator>>(size_t pos) const { return BitString(bs << pos); }

    friend inline BitString operator & (const BitString & lhs, const BitString & rhs) { return BitString(lhs.bs & rhs.bs); }
    friend inline BitString operator | (const BitString & lhs, const BitString & rhs) { return BitString(lhs.bs | rhs.bs); }
    friend inline BitString operator ^ (const BitString & lhs, const BitString & rhs) { return BitString(lhs.bs ^ rhs.bs); }

private:
    size_t little_endian(size_t pos) const { return N - pos - 1; }

    std::bitset<N> bs;
};

