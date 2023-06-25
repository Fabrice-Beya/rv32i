//
// Created by Fabrice Beya on 2023/06/25.
//
#include "fetch.h"
void fetch(
        code_address_t pc,
        instruction_t *code_ram,
        instruction_t *instruction) {
    *instruction = code_ram[pc];
    printf("%04d: %08x      \n", (int)(pc<<2), *instruction);
}
