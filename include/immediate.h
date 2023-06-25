//
// Created by Fabrice Beya on 2023/06/25.
//

#ifndef RV32I_IMMEDIATE_H
#define RV32I_IMMEDIATE_H
#include "../rv32i/rv32i.h"
i_immediate_t i_immediate(decoded_immediate_t d_imm);
s_immediate_t s_immediate(decoded_immediate_t d_imm);
b_immediate_t b_immediate(decoded_immediate_t d_imm);
u_immediate_t u_immediate(decoded_immediate_t d_imm);
j_immediate_t j_immediate(decoded_immediate_t d_imm);

#endif //RV32I_IMMEDIATE_H
