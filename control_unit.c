#include <stdio.h>
#include <stdlib.h>

#include "control_unit.h"

void initTypeR(ControlUnit *CUNT);

void initJR(ControlUnit *CUNT);

void initJUMP(ControlUnit *CUNT);

void initLI(ControlUnit *CUNT);

void initLW(ControlUnit *CUNT);

void initSW(ControlUnit *CUNT);

void initBEQ(ControlUnit *CUNT);

void initBNE(ControlUnit *CUNT);

ControlUnit initializeControlUnit(Instruction i) {
  ControlUnit CUNT;
  switch (i.R.opcode) {
  case TYPE_R:
    if (i.R.funct == 0b001000)
      initJR(&CUNT);
    else
      initTypeR(&CUNT);
    break;
  case LI:
    initLI(&CUNT);
    break;
  case LW:
    initLW(&CUNT);
    break;
  case SW:
    initSW(&CUNT);
    break;
  case BEQ:
    initBEQ(&CUNT);
    break;
  case BNE:
    initBNE(&CUNT);
    break;
  case TYPE_J:
    initJUMP(&CUNT);
    break;
  default: 
    printf("Tipo não especificado pelo desenvolvedor!\n"); 
    exit(404);
  }
  return CUNT;
}

void printControlUnit(ControlUnit CUNT) {
  printf("RegDst:   %d\n", CUNT.RegDst);
  printf("Jump:     %d\n", CUNT.Jump);
  printf("ALUSrc:   %d\n", CUNT.ALUSrc);
  printf("MemToReg: %d\n", CUNT.MemToReg);
  printf("RegWrite: %d\n", CUNT.RegWrite);
  printf("MemRead:  %d\n", CUNT.MemRead);
  printf("MemWrite: %d\n", CUNT.MemWrite);
  printf("Branch:   %d\n", CUNT.Branch);
  printf("ALUOp:    %d\n", CUNT.ALUOp);
}

void initTypeR(ControlUnit *CUNT) {
  CUNT->RegDst   = 1;
  CUNT->Jump     = 0;
  CUNT->ALUSrc   = 0;
  CUNT->MemToReg = 0;
  CUNT->RegWrite = 1;
  CUNT->MemRead  = 0;
  CUNT->MemWrite = 0;
  CUNT->Branch   = 0;
  CUNT->ALUOp    = 2;
  CUNT->Bne      = 0;
}

void initJR(ControlUnit *CUNT) {
  CUNT->RegDst   = 0;
  CUNT->Jump     = 2;
  CUNT->ALUSrc   = 0;
  CUNT->MemToReg = 0;
  CUNT->RegWrite = 0;
  CUNT->MemRead  = 0;
  CUNT->MemWrite = 0;
  CUNT->Branch   = 0;
  CUNT->ALUOp    = 0;
  CUNT->Bne      = 0;
}

void initJUMP(ControlUnit *CUNT) {
  CUNT->RegDst   = 0;
  CUNT->Jump     = 1;
  CUNT->ALUSrc   = 0;
  CUNT->MemToReg = 0;
  CUNT->RegWrite = 0;
  CUNT->MemRead  = 0;
  CUNT->MemWrite = 0;
  CUNT->Branch   = 0;
  CUNT->ALUOp    = 0;
  CUNT->Bne      = 0;
}

void initLI(ControlUnit *CUNT) {
  CUNT->RegDst   = 0;
  CUNT->Jump     = 0;
  CUNT->ALUSrc   = 1;
  CUNT->MemToReg = 2;
  CUNT->RegWrite = 1;
  CUNT->MemRead  = 0;
  CUNT->MemWrite = 0;
  CUNT->Branch   = 0;
  CUNT->ALUOp    = 0;
  CUNT->Bne      = 0;
}

void initLW(ControlUnit *CUNT) {
  CUNT->RegDst   = 0;
  CUNT->Jump     = 0;
  CUNT->ALUSrc   = 1;
  CUNT->MemToReg = 1;
  CUNT->RegWrite = 1;
  CUNT->MemRead  = 1;
  CUNT->MemWrite = 0;
  CUNT->Branch   = 0;
  CUNT->ALUOp    = 0;
  CUNT->Bne      = 0;
}

void initSW(ControlUnit *CUNT) {
  CUNT->RegDst   = 0; // X
  CUNT->Jump     = 0;
  CUNT->ALUSrc   = 1;
  CUNT->MemToReg = 0; // X
  CUNT->RegWrite = 0;
  CUNT->MemRead  = 0;
  CUNT->MemWrite = 1;
  CUNT->Branch   = 0;
  CUNT->ALUOp    = 0;
  CUNT->Bne      = 0;
}

void initBEQ(ControlUnit *CUNT) {
  CUNT->RegDst   = 0; // X
  CUNT->Jump     = 0;
  CUNT->ALUSrc   = 0;
  CUNT->MemToReg = 0; // X
  CUNT->RegWrite = 0;
  CUNT->MemRead  = 0;
  CUNT->MemWrite = 0;
  CUNT->Branch   = 1;
  CUNT->ALUOp    = 1;
  CUNT->Bne      = 0;
}

void initBNE(ControlUnit *CUNT) {
  CUNT->RegDst   = 0; // X
  CUNT->Jump     = 0;
  CUNT->ALUSrc   = 0;
  CUNT->MemToReg = 0; // X
  CUNT->RegWrite = 0;
  CUNT->MemRead  = 0;
  CUNT->MemWrite = 0;
  CUNT->Branch   = 0;
  CUNT->ALUOp    = 1;
  CUNT->Bne      = 1;
}

