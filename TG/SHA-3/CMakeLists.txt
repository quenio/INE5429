cmake_minimum_required(VERSION 3.5)
project(SHA_3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        timer.c timer.h
        state_array.h)
set(MIN_UNIT_FILES min_unit.c min_unit.h)

add_executable(SHA_3 main.cpp ${SOURCE_FILES})

add_executable(state_array_tests state_array_tests.c ${MIN_UNIT_FILES} ${SOURCE_FILES})
