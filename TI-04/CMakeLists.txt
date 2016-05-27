cmake_minimum_required(VERSION 3.5)
project(TI_04)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11 -Wall -Werror")

set(SOURCE_FILES
        min_debug.h
        mpz_print.c mpz_print.h
        mpz_int64.c mpz_int64.h
        random.c random.h
        prime.c prime.h
        phi.c phi.h
        rsa.c rsa.h)

set(MIN_UNIT_FILES min_unit.c min_unit.h)

add_executable(prime_tests prime_tests.c ${MIN_UNIT_FILES} ${SOURCE_FILES})
target_link_libraries(prime_tests gmp)

add_executable(phi_tests phi_tests.c ${MIN_UNIT_FILES} ${SOURCE_FILES})
target_link_libraries(phi_tests gmp)

add_executable(rsa_tests rsa_tests.c ${MIN_UNIT_FILES} ${SOURCE_FILES})
target_link_libraries(rsa_tests gmp)
