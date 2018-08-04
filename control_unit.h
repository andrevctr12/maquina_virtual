#ifndef CONTROL_UNIT_H
#define CONTROL_UNIT_H

#include "types.h"

typedef struct ControlUnit {
  unsigned RegDst;
  unsigned Jump;
  unsigned Branch;
  unsigned MemRead;
  unsigned MemToReg;
  unsigned ALUOp;
  unsigned MemWrite;
  unsigned ALUSrc;
  unsigned RegWrite;
  unsigned Bne;
} ControlUnit;

ControlUnit initializeControlUnit(Instruction i);

void printControlUnit(ControlUnit CUNT);

#endif