//
// Created by Fabrice Beya on 2023/06/25.
//
#include "rv32i.h"

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

    } while(is_running == true);
}
