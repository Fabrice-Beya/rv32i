#include <iostream>
#include "rv32i/rv32i.h"
int data_ram[DATA_RAM_SIZE];
unsigned int code_ram[CODE_RAM_SIZE] = {
#include "binaries/text_hello_world.hex"
};
int main() {
    unsigned int nbi = 0;
    rv32i(0, code_ram, data_ram, &nbi);
    printf("%d fetched instructions\n", nbi);
    return 0;
}
