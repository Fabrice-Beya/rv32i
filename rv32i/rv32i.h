//
// Created by Fabrice Beya on 2023/06/25.
//

#ifndef RV32I_RV32I_H
#define RV32I_RV32I_H

#include "../include/ap_int.h"
using namespace std;

/*
 * RAM data types
 * So we have separate ram access for code and data. This allows simultaneous access ie fetch instructions can run in parallel with operations
 * that need to update memory.
 *
 * Notes:
 * We want to store 2^14 32bit instructions in our ram.
 * 2^14 = 16384 words.
 * 16384 words * 4bytes each = 65536Bytes. 65536/1024 = 64Kb
 * log(base 2) (65536) = 16 ie 2^16 = 65536Bytes
 * Thus we need 16 bits to store 65536Bytes
 *
 * We use the above template to compute the total number of bits needed to store a specific quantity so that we minimise the amount of
 * space used by all data types.
 */

// Total define total ram size for code 2^14 = 16384 words
#define LOG_CODE_RAM_SIZE 14
#define CODE_RAM_SIZE (1<<LOG_CODE_RAM_SIZE)

// Total define total ram size for data 2^14 = 16384 words
#define LOG_DATA_RAM_SIZE 14
#define DATA_RAM_SIZE (1<<LOG_DATA_RAM_SIZE)

// Total define total number of registers 2^5 = 32 words
#define LOG_REG_FILE_SIZE 5
#define NB_REGISTER (1<<LOG_REG_FILE_SIZE)

// Include all the rv32i instruction op codes
#include "../include/op_codes.h"

// Include all rev32i commands
#include "../include/commands.h"

// Each instruction must be an unsigned 32bit value
typedef unsigned int instruction_t;

// Each address in memory needs to be at most LOG_CODE_RAM_SIZE wide ie all code address will be in the
// range of [0 - 2^LOG_CODE_RAM_SIZE] thus we only need a data type that stores up to LOG_CODE_RAM_SIZE bits.
typedef ap_uint<LOG_CODE_RAM_SIZE> code_address_t;

// Similarly with word referenced data address
typedef ap_uint<LOG_CODE_RAM_SIZE> w_data_address_t;

// Half words referenced addressed will need a range of 2 times that of the range for words. ie half word = 2 * words
// In binary increasing a bit width by 1 is the same as multiplying by 2
typedef ap_uint<LOG_CODE_RAM_SIZE+1> h_data_address_t;

// Similarly increasing bit width by 2 is same as multiplying by 4 ie byte referenced addressed need 4 times that of the range for words.
typedef ap_uint<LOG_CODE_RAM_SIZE+2> b_data_address_t;

// Instruction type definitions all opcodes are mapped to one of the types below
#define UNDEFINED_TYPE 0
#define R_TYPE         1
#define I_TYPE         2
#define S_TYPE         3
#define B_TYPE         4
#define U_TYPE         5
#define J_TYPE         6
#define OTHER_TYPE     7

// Used to capture the instruction type, there are up to 8, thus 3 bits is needed to capture than all.
typedef ap_uint<3> type_t;

// All immediate values can have up to 20 bits(eg U-TYPES). A right shift can be done to accommodate small sizes.
typedef ap_int<20> immediate_t;

// Each instruction type will have different sizes for immediate values accordingly.
typedef ap_int<12> i_immediate_t;
typedef ap_int<12> s_immediate_t;
typedef ap_int<12> b_immediate_t;
typedef ap_int<20> u_immediate_t;
typedef ap_int<20> j_immediate_t;

// All op codes will have 5 bits ie bits 2-7 of any instruction
typedef ap_uint<5> opcode_t;

// This type will capture all register values inside an instruction they are always LOG_REG_FILE_SIZE wide
// ie this will be a value between 0 - 31
typedef ap_uint<LOG_REG_FILE_SIZE> reg_num_t;

// This type will capture the function 3 bits of an instruction
typedef ap_uint<3> func3_t;

// This type will capture the function 7 bits of an instruction
typedef ap_uint<7> func7_t;

// This type will capture any single bit value in an instruction
typedef ap_uint<1> bit_t;

/*
 * This type captures all possible data that cab be extracted from a 32 bit instruction.
 * is_* properties are added to reduce the number of (decoded_instruction.type == R_TYPE)
 * instruction type checks across the code, allowing us to retrieve an instruction type with single
 * boolean check as apposed to a comparison of two values.
 */
typedef struct decoded_instruction_t {
    opcode_t opcode;
    reg_num_t rd;
    func3_t func3;
    reg_num_t rs1;
    reg_num_t rs2;
    func7_t func7;
    type_t type;
    immediate_t imm;
    bit_t is_load;
    bit_t is_store;
    bit_t is_branch;
    bit_t is_jalr;
    bit_t is_op_imm;
    bit_t is_lui;
    bit_t is_ret;
    bit_t is_r_type;
} decoded_instruction_t;

/*
 * This type defines properties which extract different bit ranges from a 32 bit instruction
 * the idea is after all these ranges are extracted from any instruction we can then reconstruct
 * the needed immediate value for each instruction type according to which segments are used.
 * eg S-TYPE imm = inst_31 || inst_30_25 || inst_11_8 ||  inst_7
 */
typedef struct decoded_immediate_t {
    bit_t inst_31;
    ap_uint<6> inst_30_25;
    ap_uint<4> inst_24_21;
    bit_t inst_20;
    ap_uint<8> inst_19_12;
    ap_uint<4> inst_11_8;
    bit_t inst_7;
} decoded_immediate_t;

void rv32i(
        unsigned int start_pc,
        unsigned int code_ram[CODE_RAM_SIZE],
        int data_ram[DATA_RAM_SIZE],
        unsigned int *nb_instructions);

#endif //RV32I_RV32I_H
