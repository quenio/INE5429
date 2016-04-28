cmake_minimum_required(VERSION 3.5)
project(png)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11 -Wall -Werror")

set(SOURCE_FILES main.c)
add_executable(png ${SOURCE_FILES})
target_link_libraries(png gmp)