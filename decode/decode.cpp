//
// Created by Fabrice Beya on 2023/06/25.
//
#include "decode.h"
#include "../include/type.h"
#include "../include/immediate.h"

static void decode_instruction(
        instruction_t instruction,
        decoded_instruction_t *d_i) {
    // First two bits determine the base instruction ISA for rv32i it will always be 11
    d_i->opcode     = instruction>>2;               // extracting OPCODE: bits 2-6
    d_i->rd         = instruction>>7;               // extracting DESTINATION REGISTER: bits 7-11
    d_i->func3      = instruction>>12;              // extracting FUNCTION 3: bits 12-14
    d_i->rs1        = instruction>>15;              // extracting SOURCE REGISTER 1: bits 15-19
    d_i->rs2        = instruction>>20;              // extracting SOURCE REGISTER 2: bits 20-24
    d_i->func7      = instruction>>25;              // extracting FUNCTION 7: bits 25-31
    d_i->type       = type(d_i->opcode);    // extract instruction type from opcode
    // Set instruction type props to reduce comparison operations during execution
    d_i->is_branch  = (d_i->opcode == BRANCH);
    d_i->is_jalr    = (d_i->opcode == JALR);
    d_i->is_load    = (d_i->opcode == LOAD);
    d_i->is_lui     = (d_i->opcode == LUI);
    d_i->is_op_imm  = (d_i->opcode == OP_IMM);
    d_i->is_r_type  = (d_i->opcode == R_TYPE);
    d_i->is_store   = (d_i->opcode == STORE);
    d_i->is_ret     = (d_i->opcode == RET);
}

static void decode_immediates(
        instruction_t instruction,
        decoded_instruction_t *d_i) {
    decoded_immediate_t d_imm;
    d_imm.inst_31    = (instruction >> 31);
    d_imm.inst_30_25 = (instruction >> 25);
    d_imm.inst_24_21 = (instruction >> 21);
    d_imm.inst_20    = (instruction >> 20);
    d_imm.inst_19_12 = (instruction >> 12);
    d_imm.inst_11_8  = (instruction >>  8);
    d_imm.inst_7     = (instruction >>  7);

    switch (d_i->type) {
        case UNDEFINED_TYPE: d_i->imm = 0; break;
        case R_TYPE:         d_i->imm = 0; break;
        case I_TYPE:         d_i->imm = i_immediate(d_imm); break;
        case S_TYPE:         d_i->imm = s_immediate(d_imm); break;
        case B_TYPE:         d_i->imm = b_immediate(d_imm); break;
        case U_TYPE:         d_i->imm = u_immediate(d_imm); break;
        case J_TYPE:         d_i->imm = j_immediate(d_imm); break;
        case OTHER_TYPE:     d_i->imm = 0; break;
    }
}

void decode(
        instruction_t instruction,
        decoded_instruction_t *d_i) {
    decode_instruction(instruction, d_i);
    decode_immediates(instruction, d_i);
}