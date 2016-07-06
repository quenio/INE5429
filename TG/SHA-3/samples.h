// Copyright (c) 2016 Quenio Cesar Machado dos Santos. All rights reserved.

#pragma once

// SHA3-224 sample of 5-bit message:

const char *MSG5 = "11001";
const char *MSG5_XOR =
    "D3000000000000000000000000000000"
    "00000000000000000000000000000000"
    "00000000000000000000000000000000"
    "00000000000000000000000000000000"
    "00000000000000000000000000000000"
    "00000000000000000000000000000000"
    "00000000000000000000000000000000"
    "00000000000000000000000000000000"
    "00000000000000000000000000000080"
    "00000000000000000000000000000000"
    "00000000000000000000000000000000"
    "00000000000000000000000000000000"
    "0000000000000000";
const char *MSG5_THETA =
    "D300000000000000D200000000000000"
    "00000000000000000000000000000080"
    "A6010000000000000000000000000000"
    "D2000000000000000000000000000000"
    "0000000000000080A601000000000000"
    "0000000000000000D200000000000000"
    "00000000000000000000000000000080"
    "A6010000000000000000000000000000"
    "D2000000000000000000000000000080"
    "0000000000000080A601000000000000"
    "0000000000000000D200000000000000"
    "00000000000000000000000000000080"
    "A601000000000000";
const char *MSG5_RHO =
    "D300000000000000A401000000000000"
    "00000000000000000000000800000000"
    "000000300D0000000000000000000000"
    "0000000000200D000000000000000000"
    "00000000000040000000601A00000000"
    "00000000000000000048030000000000"
    "00000000000000000000000100000000"
    "0000000000D300000000000000000000"
    "0000000000401A000040000000000000"
    "000010000000000000A6010000000000"
    "00000000000000004803000000000000"
    "00000000000000000000000000008000"
    "0080690000000000";
const char *MSG5_PI =
    "D3000000000000000000000000200D00"
    "00000000000000000000100000000000"
    "00806900000000000000000800000000"
    "0000601A000000000000000000000000"
    "0000000000401A000000000000000000"
    "A4010000000000000000000000000000"
    "000000010000000000A6010000000000"
    "0000000000000000000000300D000000"
    "00000000000000000048030000000000"
    "00400000000000000000000000008000"
    "00000000000000000000000000004000"
    "0000000000D300000000000000000000"
    "4803000000000000";
const char *MSG5_CHI =
    "D3000000000000000000100000200D00"
    "0080690000000000D300100000000000"
    "0080690000200D000000000800000000"
    "0000601A00401A000000000000000000"
    "0000000800401A000000601200000000"
    "A40100010000000000A6010000000000"
    "0000000100000000A4A7010000000000"
    "0000000000000000004803300D000000"
    "00000000000000000048030000008000"
    "004000300D0000000000000000008000"
    "0000000000D300000000000000004000"
    "4803000000D300000000000000000000"
    "4803000000004000";
