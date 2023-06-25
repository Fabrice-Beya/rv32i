//
// Created by Fabrice Beya on 2023/06/25.
//
#include "rv32i.h"
#include "fetch.h"
static void running_cond_update(
        instruction_t  instruction,
        code_address_t pc,
        bit_t         *is_running){
    *is_running = (instruction != RET );
}

void rv32i(
        unsigned int start_pc,
        unsigned int code_ram[CODE_RAM_SIZE],
        int data_ram[DATA_RAM_SIZE],
        unsigned int *nb_instructions) {
    // Define processor state variables
    bit_t is_running;
    code_address_t pc;
    int reg_file[NB_REGISTER];
    instruction_t instruction;
    unsigned int nbi;
    decoded_immediate_t d_i;

    // Initialise states
    pc = start_pc;
    for (int i=0; i<NB_REGISTER; i++) reg_file[i] = 0;
    nbi = 0;
    do {
        fetch(pc, code_ram, &instruction);
        running_cond_update(instruction, pc, &is_running);
        pc++;
    } while(is_running);
}
