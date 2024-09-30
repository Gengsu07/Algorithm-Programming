cmake_minimum_required(VERSION 3.16)
project(belajar C)

set(CMAKE_C_STANDARD 99)

# Recursively find all .c files in the current directory and subdirectories
file(GLOB_RECURSE SOURCES "${CMAKE_SOURCE_DIR}/*.c")

add_executable(belajar ${SOURCES})
