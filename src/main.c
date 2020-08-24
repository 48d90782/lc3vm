#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <signal.h>
/* unix */
#include <unistd.h>
#include <fcntl.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/termios.h>
#include <sys/mman.h>


/*
 * The R_COND register stores condition flags which provide information about the most recently executed calculation.
 * This allows programs to check logical conditions such as `if (x > 0) {...}`
 * Each CPU has a variety of cond flags to signal various situation. The LC-3 uses only 3
 */

enum {
    FL_POS = 1u << 0u, // P - 1
    FL_ZRO = 1u << 1u, // Z - 2
    FL_NEG = 1u << 2u, // N - 4
};


enum {
    R_R0 = 0,
    R_R1,
    R_R2,
    R_R3,
    R_R4,
    R_R5,
    R_R6,
    R_R7,
    R_PC, /*Program counter*/
    R_COND,
    R_COUNT,
};

/*
 * Instruction is a command which tells the CPU to do some fundamental task, such as add two numbers.
 * Instruction have both an opcode which indicates the kind of task to perform and set of parameters which provide inputs to the task being performed.
 *
 * Each opcode represents one task that the CPU knows how to do. LC-3 has 16 opcodes.
 */

// OPCODES
enum {
    OP_BR = 0, // branch
    OP_ADD, // add
    OP_LD, // load
    OP_JSR, // jump register
    OP_AND, // bitwise and
    OP_LDR, // load register
    OP_STR, // store register
    OP_RTI, // unused
    OP_NOT, // bitwise not
    OP_LDI, // load indirect
    OP_JMP, // jump
    OP_RES, // reserved
    OP_LEA, // load effective address
    OP_TRAP // execute trap
};


u_int16_t memory[UINT16_MAX];
uint16_t reg[R_COUNT];


int main() {
    enum {
        PC_START = 0x3000
    };
    reg[R_PC] = PC_START;
    int running = 1;
    while (running) {
        
    }
    return EXIT_SUCCESS;
}