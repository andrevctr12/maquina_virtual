#include <stdio.h>

#include "types.h"

//      opcode    funct
// add  000000    100000  R
// sub  000000    100010  R
// and  000000    100100  R
// or   000000    100101  R
// li   001111            I
// lw   100011            I
// sw   101011            I
// beq  000100            I
// bne  000101            I
// j    000010            J
// jr   000000    001000  R

void printInstructionType(Instruction IR) {
  switch(IR.I.opcode) {
  case TYPE_R:
    switch (IR.R.funct) {
      case 0b100000: printf("add"); break;
      case 0b100010: printf("sub"); break;
      case 0b100100: printf("and"); break;
      case 0b100101: printf("or "); break;
    }
    if (IR.R.funct == FUNCTJR) printf("jr    $%u\n", IR.R.rs);
    else printf("   $%u, $%u, $%u\n", IR.R.rd, IR.R.rs, IR.R.rt);
    break;
  case LI:
    printf("li    $%u, %d\n", IR.I.rt, IR.I.offset);
    break;
  case LW:
    printf("lw    $%u, %d(%u)\n", IR.I.rt, IR.I.rs, IR.I.offset);
    break;
  case SW:
    printf("sw    $%u, %d(%u)\n", IR.I.rt, IR.I.rs, IR.I.offset);
    break;
  case BEQ:
    printf("beq   $%u, $%u, %d\n", IR.I.rs, IR.I.rt, IR.I.offset);
    break;
  case BNE:
    printf("bne   $%u, $%u, %d\n", IR.I.rs, IR.I.rt, IR.I.offset);
    break;
  case TYPE_J:
    printf("jump  %d\n", IR.J.jump);
    break;
  default: 
    printf("%08x\n", IR.raw);
  }
}
