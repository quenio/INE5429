cmake_minimum_required(VERSION 3.5)
project(SHA_3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Werror")

set(SOURCE_FILES
        timer.cpp timer.h
        state_array.h theta.h rho.h)
set(MIN_UNIT_FILES min_unit.cpp min_unit.h)

add_executable(sha3 main.cpp ${SOURCE_FILES})

add_executable(state_array_tests state_array_tests.cpp ${MIN_UNIT_FILES} ${SOURCE_FILES})
add_executable(theta_tests theta_tests.cpp ${MIN_UNIT_FILES} ${SOURCE_FILES})
add_executable(rho_tests rho_tests.cpp ${MIN_UNIT_FILES} ${SOURCE_FILES})
