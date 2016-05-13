cmake_minimum_required(VERSION 3.5)
project(png)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11 -Wall -Werror")

set(SOURCE_FILES random.c random.h mpz_int64.c mpz_int64.h prime.c prime.h timer.c timer.h)
add_executable(random random_main.c ${SOURCE_FILES})
add_executable(prime prime_main.c ${SOURCE_FILES})
target_link_libraries(random gmp)
target_link_libraries(prime gmp)