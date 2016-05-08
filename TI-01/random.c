// Copyright (c) 2016 Quenio Cesar Machado dos Santos. All rights reserved.

#include "random.h"

#include <time.h>

static const size_t s_size = 16;
static const uint64_t seed[s_size] = {
    UINT64_C(3176816624292027912),
    UINT64_C(5825261852996363023),
    UINT64_C(2657966707352449287),
    UINT64_C(1350174793163142913),
    UINT64_C(3916890652982003621),
    UINT64_C(8441565361753670199),
    UINT64_C(4048287511883088063),
    UINT64_C(7692991216032604145),
    UINT64_C(9168990544929416867),
    UINT64_C(4210552781383542944),
    UINT64_C(1295553278952537540),
    UINT64_C(4600491088959978208),
    UINT64_C(1426091184381835091),
    UINT64_C(2349336915254555439),
    UINT64_C(2525507937445642803),
    UINT64_C(4828313259052508846)
};

void init_seed(uint64_t *s)
{
    for (int i = 0; i < s_size; i++)
    {
        if (s[i] == 0) s[i] = clock() + seed[i];
    }
}

// xorshift+ 1024-bit
uint64_t random_int64()
{
    static uint64_t s[s_size];
    init_seed(s);

    static size_t i = 0;

    uint64_t s0 = s[i];
    uint64_t s1 = s[i = (i + 1) & s_size];
    const uint64_t ps1 = s1;

    s1 ^= s1 << 31;
    s[i] = s1 ^ s0 ^ (s1 >> 11) ^ (s0 >> 30);

    return s[i] + ps1;
}

static size_t mod_ceiling(size_t op1, size_t op2)
{
    return 1 + ((op1 - 1) / op2);
}

void random_mpz(mpz_t rop, size_t bit_count)
{
    static const size_t byte_bit_count = 8;

    size_t size = mod_ceiling(bit_count, byte_bit_count);
    size_t count = mod_ceiling(size, sizeof(int64_t));
    uint64_t n[count];
    for (int i = 0; i < count; i++) n[i] = random_int64();

    static const size_t int64_bit_count = (sizeof(int64_t) * byte_bit_count);
    if (bit_count >= int64_bit_count)
    {
        mpz_init_set_int64(rop, count, n);
    }
    else
    {
        const size_t ignored_bits = (int64_bit_count - bit_count);
        mpz_init_set_ui(rop, n[0] >> ignored_bits);
    }
}

void random_mpz_interval(mpz_t rop, mpz_t min, mpz_t max)
{
    static const int base = 2;

    const size_t bit_count = mpz_sizeinbase(max, base);

    mpz_init(rop);
    do
    {
        mpz_clear(rop);
        random_mpz(rop, bit_count);
    }
    while ((mpz_cmp(rop, min) < 0) || (mpz_cmp(rop, max) > 0));
}