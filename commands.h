//
// Created by Fabrice Beya on 2023/06/25.
//

#ifndef RV32I_COMMANDS_H
#define RV32I_COMMANDS_H

/*
 * These are all the rv32i assembly commands.
 */

#define BEQ            0
#define BNE            1
#define BLT            4
#define BGE            5
#define BLTU           6
#define BGEU           7
#define ADD            0
#define SUB            0
#define SLL            1
#define SLT            2
#define SLTU           3
#define XOR            4
#define SRL            5
#define SRA            5
#define OR             6
#define AND            7
#define ADDI           0
#define SLLI           1
#define SLTI           2
#define SLTIU          3
#define XORI           4
#define SRLI           5
#define SRAI           5
#define ORI            6
#define ANDI           7
#define ECALL          0
#define EBREAK         1
#define LB             0
#define LH             1
#define LW             2
#define LBU            4
#define LHU            5
#define SB             0
#define SH             1
#define SW             2

#endif //RV32I_COMMANDS_H
