// Copyright (c) 2016 Quenio Cesar Machado dos Santos. All rights reserved.

#pragma once

#include <gmp.h>

void rsa_key_modulus(mpz_t modulus, mpz_t p, mpz_t q, const size_t bit_count);
void rsa_encrypting_exponent(const mpz_t p, const mpz_t q, mpz_t encrypting_exponent);
void rsa_decrypting_exponent(const mpz_t p, const mpz_t q, const mpz_t encrypting_exponent, mpz_t decrypting_exponent);
void rsa_key_pair(mpz_t modulus, mpz_t encrypting_exponent, mpz_t decrypting_exponent, const size_t bit_count);
void rsa_encrypt(const mpz_t modulus, const mpz_t encrypting_exponent, const mpz_t message, mpz_t encrypted_message);
void rsa_decrypt(const mpz_t modulus, const mpz_t decrypting_exponent, const mpz_t encrypted_message, mpz_t decrypted_message);