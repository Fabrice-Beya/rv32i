//
// Created by Fabrice Beya on 2023/06/25.
//

#ifndef RV32I_EXECUTE_H
#define RV32I_EXECUTE_H
#include "../rv32i/rv32i.h"

void execute(
        code_address_t pc,
        int *reg_file,
        int *data_ram,
        decoded_instruction_t d_i,
        code_address_t *next_pc);
#endif //RV32I_EXECUTE_H
