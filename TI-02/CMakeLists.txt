cmake_minimum_required(VERSION 3.5)
project(png)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11 -Wall -Werror")

set(SOURCE_FILES
        random.c random.h
        mpz_debug.h
        mpz_int64.c mpz_int64.h
        mpz_print.c mpz_print.h
        prime.c prime.h
        timer.c timer.h
        primitive_root.c primitive_root.h)

set(MIN_UNIT_FILES min_unit.c min_unit.h)

#add_definitions(-DMPZ_DEBUG)

add_executable(random random_main.c ${SOURCE_FILES})
target_link_libraries(random gmp)

add_executable(primitive_root primitive_root_main.c ${SOURCE_FILES})
target_link_libraries(primitive_root gmp)

add_executable(prime prime_main.c ${SOURCE_FILES})
target_link_libraries(prime gmp)

add_executable(prime_tests prime_tests.c ${MIN_UNIT_FILES} ${SOURCE_FILES})
target_link_libraries(prime_tests gmp)

add_executable(primitive_root_tests primitive_root_tests.c ${MIN_UNIT_FILES} ${SOURCE_FILES})
target_link_libraries(primitive_root_tests gmp)
