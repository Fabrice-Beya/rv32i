# RiscV Processor
A C/C++ RiscV 32bit processor implementation based on Guide to Computer ProcessorArchitecture By Bernard Goossens.

1. Place riscv machine code in .hex file in the /binaries folder
2. Import that .hex file in the main application as such:

   `unsigned int code_ram[CODE_RAM_SIZE] = {
      <#include "binaries/text_hello_world.hex">
    }`

3. After running the main application you'll see your disassembled application along with register. Below is sample Hello World application:
   _0000: 00500593      
   li x11, 5
   0004: 00158613      
   addi x12, x11, 1
   0008: 00c67693      
   andi x13, x12, 12
   0012: fff68713      
   addi x14, x13, -1
   0016: 00576793      
   ori x15, x14, 5
   0020: 00c7c813      
   xori x16, x15, 12
   0024: 00d83893      
   sltiu x17, x16, 13
   0028: 00b83293      
   sltiu x5, x16, 11
   0032: 01c81313      
   slli x6, x16, 28
   0036: ff632393      
   slti x7, x6, -10
   0040: 7e633e13      
   sltiu x28, x6, 2022
   0044: 01c35e93      
   srli x29, x6, 28
   0048: 41c35f13      
   srai x30, x6, 28
   0052: 00008067      
   ret
   x1  =                0 (       0)
   x2  =                0 (       0)
   x3  =                0 (       0)
   x4  =                0 (       0)
   x5  =                0 (       0)
   x6  =      -1342177280 (b0000000)
   x7  =                1 (       1)
   x8  =                0 (       0)
   x9  =                0 (       0)
   x10 =                0 (       0)
   x11 =                5 (       5)
   x12 =                6 (       6)
   x13 =                4 (       4)
   x14 =                3 (       3)
   x15 =                7 (       7)
   x16 =               11 (       b)
   x17 =                1 (       1)
   x18 =                0 (       0)
   x19 =                0 (       0)
   x20 =                0 (       0)
   x21 =                0 (       0)
   x22 =                0 (       0)
   x23 =                0 (       0)
   x24 =                0 (       0)
   x25 =                0 (       0)
   x26 =                0 (       0)
   x27 =                0 (       0)
   x28 =                0 (       0)
   x29 =               11 (       b)
   x30 =               11 (       b)
   x31 =                0 (       0)
   14 fetched instructions_
