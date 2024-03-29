cmake_minimum_required(VERSION 3.5)
project(SHA_3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Werror")

set(SOURCE_FILES
        timer.cpp timer.h
        bit_string.h state_array.h
        theta.h rho.h pi.h chi.h iota.h
        sha3.h keccak.h padding.h sponge.h
        samples.h)
set(MIN_UNIT_FILES min_unit.cpp min_unit.h)

add_executable(sha3 main.cpp ${SOURCE_FILES})

add_executable(bit_string_tests bit_string_tests.cpp ${MIN_UNIT_FILES} ${SOURCE_FILES})
add_executable(padding_tests padding_tests.cpp ${MIN_UNIT_FILES} ${SOURCE_FILES})
add_executable(state_array_tests state_array_tests.cpp ${MIN_UNIT_FILES} ${SOURCE_FILES})
add_executable(theta_tests theta_tests.cpp ${MIN_UNIT_FILES} ${SOURCE_FILES})
add_executable(rho_tests rho_tests.cpp ${MIN_UNIT_FILES} ${SOURCE_FILES})
add_executable(pi_tests pi_tests.cpp ${MIN_UNIT_FILES} ${SOURCE_FILES})
add_executable(chi_tests chi_tests.cpp ${MIN_UNIT_FILES} ${SOURCE_FILES})
add_executable(iota_tests iota_tests.cpp ${MIN_UNIT_FILES} ${SOURCE_FILES})
add_executable(keccak_tests keccak_tests.cpp ${MIN_UNIT_FILES} ${SOURCE_FILES})
add_executable(sponge_tests sponge_tests.cpp ${MIN_UNIT_FILES} ${SOURCE_FILES})
