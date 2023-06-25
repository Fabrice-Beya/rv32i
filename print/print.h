//
// Created by Fabrice Beya on 2023/06/25.
//

#ifndef RV32I_PRINT_H
#define RV32I_PRINT_H
#include "../rv32i/rv32i.h"

void print_reg_name(reg_num_t r);
void print_op(func3_t func3, func7_t func7);
void print_op_imm(func3_t func3, func7_t func7);
void print_msize(func3_t func3);
void print_branch(func3_t func3);
void print_reg(int *reg_file);
#endif //RV32I_PRINT_H
