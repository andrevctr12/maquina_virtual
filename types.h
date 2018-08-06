#ifndef TYPES_H
#define TYPES_H

#define TYPE_R 0
#define TYPE_I 1
#define TYPE_J 2

#define LI      15
#define LW      35
#define SW      43
#define BEQ     4
#define BNE     5
#define FUNCTJR 0b001000

typedef struct typeR_t {
    unsigned funct    : 6;
    unsigned shamt    : 5;
    unsigned rd       : 5;
    unsigned rt       : 5;
    unsigned rs       : 5;
    unsigned opcode   : 6;
} typeR;

typedef struct typeI_t {
    int      offset   : 16;
    unsigned rt       : 5;
    unsigned rs       : 5;
    unsigned opcode   : 6;
} typeI;

typedef struct typeJ_t {
    unsigned jump     : 26;
    unsigned opcode   : 6;
} typeJ;

typedef union Instruction {
    typeR R;
    typeI I;
    typeJ J;
    unsigned raw;
} Instruction;

void printInstructionType(Instruction IR);

#endif
