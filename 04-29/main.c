#include <stdio.h>
#include <gmp.h>

const int base = 10;

int main()
{
    mpz_t pie;
    mpz_init_set_str(pie, "3141592653589793238462643383279502884", base);
    mpz_add_ui(pie, pie, 1);
    mpz_out_str(NULL, base, pie);
    mpz_clear(pie);
    return 0;
}