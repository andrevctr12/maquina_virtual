#include <stdio.h>
#include "ALU.h"

unsigned ALUControlUnit(unsigned funct, unsigned ALUOp) {
  printf("funct: %u\n", funct);
  printf("ALUOp: %u\n", ALUOp);
  unsigned ALUOp0 = (ALUOp & 0b1);
  unsigned ALUOp1 = ((ALUOp & 0b10) >> 1);

  unsigned funct0 = (funct & 0b1);
  unsigned funct1 = ((funct & 0b10) >> 1);
  unsigned funct2 = ((funct & 0b100) >> 2);
  unsigned funct3 = ((funct & 0b1000) >> 3);

  unsigned operation0 = ALUOp1 & (funct0 | funct3);
  unsigned operation1 = !(ALUOp1) | !(funct2);
  unsigned operation2 = (funct1 & ALUOp1) | (ALUOp0);

  unsigned operation = (operation0) | (operation1 << 1) | (operation2 << 2);

  return operation;
}

int ALUResult(int a, int b, unsigned op) {
  switch (op) {
  case 0b010: ///< add
    return a + b;
  case 0b110: ///< sub
    return a - b;
  case 0b001: ///< or
    return a | b;
  case 0b000: ///< and
    return a & b;
  }
  return 0;
}
