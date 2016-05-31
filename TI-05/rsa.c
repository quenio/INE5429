// Copyright (c) 2016 Quenio Cesar Machado dos Santos. All rights reserved.

#include "rsa.h"
#include "prime.h"
#include "phi.h"

//#define MIN_DEBUG
#include "min_debug.h"

void rsa_key_modulus(const size_t bit_count, mpz_t modulus, mpz_t p, mpz_t q)
{
    debug_start(rsa_key_modulus);
    debug_size_t(bit_count);

    find_prime(p, bit_count);
    debug_mpz_t(p);

    find_prime(q, bit_count);
    debug_mpz_t(q);

    mpz_mul(modulus, p, q);
    debug_mpz_t(modulus);

    debug_end(rsa_key_modulus);
}

void rsa_encrypting_exponent(const mpz_t p, const mpz_t q, mpz_t encrypting_exponent)
{
    debug_start(rsa_encrypting_exponent);
    debug_mpz_t(p);
    debug_mpz_t(q);

    mpz_t phi_modulus;
    mpz_init(phi_modulus);
    phi(phi_modulus, p, q);
    debug_mpz_t(phi_modulus);

    small_coprime(encrypting_exponent, phi_modulus);
    debug_mpz_t(encrypting_exponent);

    mpz_clear(phi_modulus);
    debug_end(rsa_encrypting_exponent);
}

void rsa_decrypting_exponent(const mpz_t p, const mpz_t q, const mpz_t encrypting_exponent, mpz_t decrypting_exponent)
{
    debug_start(rsa_decrypting_exponent);
    debug_mpz_t(encrypting_exponent);

    mpz_t a;
    mpz_init_set_si(a, -1);
    debug_mpz_t(a);

    mpz_t phi_modulus;
    mpz_init(phi_modulus);
    phi(phi_modulus, p, q);
    debug_mpz_t(phi_modulus);

    mpz_powm(decrypting_exponent, encrypting_exponent, a, phi_modulus);
    debug_mpz_t(decrypting_exponent);
}

void rsa_key_pair(const size_t bit_count, mpz_t modulus, mpz_t encrypting_exponent, mpz_t decrypting_exponent)
{
    debug_start(rsa_key_pair);
    debug_size_t(bit_count);

    mpz_t p, q;
    mpz_init(p);
    mpz_init(q);
    rsa_key_modulus(bit_count / 2, modulus, p, q);
    debug_mpz_t(modulus);

    rsa_encrypting_exponent(p, q, encrypting_exponent);
    debug_mpz_t(encrypting_exponent);

    rsa_decrypting_exponent(p, q, encrypting_exponent, decrypting_exponent);
    debug_mpz_t(decrypting_exponent);

    mpz_clear(p);
    mpz_clear(q);

    debug_end(rsa_key_pair);
}

void rsa_encrypt(const mpz_t modulus, const mpz_t encrypting_exponent, const mpz_t message, mpz_t encrypted_message)
{
    debug_start(rsa_encrypt);
    debug_mpz_t(modulus);
    debug_mpz_t(encrypting_exponent);
    debug_mpz_t(message);

    mpz_powm(encrypted_message, message, encrypting_exponent, modulus);
    debug_mpz_t(encrypted_message);

    debug_end(rsa_encrypt);
}

void rsa_decrypt(const mpz_t modulus, const mpz_t decrypting_exponent, const mpz_t encrypted_message, mpz_t decrypted_message)
{
    debug_start(rsa_decrypt);
    debug_mpz_t(modulus);
    debug_mpz_t(decrypting_exponent);
    debug_mpz_t(encrypted_message);

    mpz_powm(decrypted_message, encrypted_message, decrypting_exponent, modulus);
    debug_mpz_t(decrypted_message);

    debug_end(rsa_decrypt);
}