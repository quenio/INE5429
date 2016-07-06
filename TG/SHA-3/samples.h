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
