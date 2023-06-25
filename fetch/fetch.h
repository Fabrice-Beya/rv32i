//
// Created by Fabrice Beya on 2023/06/25.
//

#ifndef RV32I_FETCH_H
#define RV32I_FETCH_H
#include "../rv32i/rv32i.h"

void fetch(
        code_address_t pc,
        instruction_t * code_ram,
        instruction_t *instruction);

#endif //RV32I_FETCH_H
