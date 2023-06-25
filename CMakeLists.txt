cmake_minimum_required(VERSION 3.22)
project(rv32i)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        rv32i
        main.cpp
        rv32i.cpp
        rv32i.h
        op_codes.h
        commands.h
        fetch.cpp
        fetch.h
        binaries/text_hello_world.hex
)
