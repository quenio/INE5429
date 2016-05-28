// Copyright (c) 2016 Quenio Cesar Machado dos Santos. All rights reserved.
// Original Code: http://www.jera.com/techinfo/jtns/jtn002.html#License

#include <stdio.h>

extern int tests_run;
extern int tests_failed;

#define mu_assert(test) do { if (!(test)) { return " - FAILED: " #test "\n"; } } while (0)
#define mu_test(test, ...) do { \
        char *message = test(__VA_ARGS__); \
        tests_run++; \
        printf("%s(%s)", #test, #__VA_ARGS__); \
        if (message) { tests_failed++; printf("%s", message); return; } \
        printf(" - PASSED\n"); \
    } while (0)


