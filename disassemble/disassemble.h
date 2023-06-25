//
// Created by Fabrice Beya on 2023/06/25.
//

#ifndef RV32I_DISASSEMBLE_H
#define RV32I_DISASSEMBLE_H
#include "../rv32i/rv32i.h"
#include "../print/print.h"

void disassemble(
        code_address_t        pc,
        instruction_t         i,
        decoded_instruction_t d_i);
#endif //RV32I_DISASSEMBLE_H
