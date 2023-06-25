//
// Created by Fabrice Beya on 2023/06/25.
//

#ifndef RV32I_DECODE_H
#define RV32I_DECODE_H
#include "../rv32i/rv32i.h"
void decode(
        instruction_t instruction,
        decoded_instruction_t *d_i);
#endif //RV32I_DECODE_H
