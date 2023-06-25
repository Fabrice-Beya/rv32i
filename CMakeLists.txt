cmake_minimum_required(VERSION 3.22)
project(rv32i)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        rv32i
        main.cpp
        rv32i/rv32i.cpp
        rv32i/rv32i.h
        include/op_codes.h
        include/commands.h
        fetch/fetch.cpp
        fetch/fetch.h
        binaries/text_hello_world.hex
        decode/decode.cpp decode/decode.h include/type.h include/type.cpp include/immediate.h include/immediate.cpp disassemble/disassemble.h disassemble/disassemble.cpp print/print.h print/print.cpp config.h)
