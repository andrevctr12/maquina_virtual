#include <stdio.h>
#include <stdlib.h>

#include "thread.h"
#include "masks.h"
#include "ALU.h"

int instructionFetch(uint8_t inst_mem[], RegUtil *util, Instruction *IR) {
  uint32_t *mem32 = (uint32_t*) &inst_mem[util->PC];
  if (!*mem32) return 0; ///< retorn 0 caso não tem mais instruções na memória
  // Inicializa o Registrador de Instrução com seu valor de 32bits
  IR->raw = *mem32;
  printf("[%2d] ", util->PC);  // debug
  printInstructionType(*IR);   // debug
  // Incrementa PC
  util->PC += 4;
  return 1;
}

void instructionDecode(int32_t reg[], RegUtil *util, Instruction *IR, ControlUnit *CUNT) {
  //Calcula o endereço do Jump
  unsigned PC_31_28 = (util->PC & PCJUMPMASK);
  util->JumpAddress = ((IR->J.jump) << 2) | PC_31_28;

  // Armazena RS e RT em registradores temporareos
  util->ReadReg1 = IR->R.rs;
  util->ReadReg2 = IR->R.rt;

  //Inicializa Sinais da Unidade de Controle dependendo do opCode
  *CUNT = initializeControlUnit(*IR);
  //printControlUnit(*CUNT); // debug

  // Armazena RD ou RT em endereço temporareo, dependendo do sinal RegDST
  if (CUNT->RegDst) util->WriteReg = IR->R.rd;
  else              util->WriteReg = IR->R.rt;

  // Calcula a operation da ALU de acordo com a funct e o ALUOp
  util->operation = ALUControlUnit(IR->R.funct, CUNT->ALUOp);

  // Calcula o sinal extendido do offset
  util->signExtended = (int) IR->I.offset;
  
  // Calcula o endereço de saida para caso seja Branch ou BNE
  util->ALUOutBranch = util->PC + (util->signExtended << 2);
}


void execution(int32_t reg[], RegUtil *util, ControlUnit CUNT) {
  // Saída do banco de registradores
  util->ReadData1 = reg[util->ReadReg1];
  util->ReadData2 = reg[util->ReadReg2];
  util->WriteData = &reg[util->WriteReg];

  // referencia a memoria (load/store)
  if (CUNT.ALUSrc) {
    util->ALUOut = ALUResult((int)util->ReadData1, (int)util->signExtended, util->operation);
  }
  // tipo R
  else {
    util->ALUOut = ALUResult((int)util->ReadData1, (int)util->ReadData2, util->operation);
  }
  // Jump
  if (CUNT.Jump == 1) util->PC = util->JumpAddress;
  // JR
  else if (CUNT.Jump == 2) util->PC = util->ReadData1;
  else {
    // Branch
    if (util->ReadData1 == util->ReadData2) reg[ZERO] = 1;
    else reg[ZERO] = 0;
    if (CUNT.Branch & reg[ZERO]) util->PC = util->ALUOutBranch;
    //BNE
    if (CUNT.Bne & !reg[ZERO]) util->PC = util->ALUOutBranch;
  }
}

void memoryAccess(int8_t data_mem[], RegUtil *util, ControlUnit CUNT) {
  // Inicializa memória 32 bits
  if (CUNT.MemRead || CUNT.MemWrite) {
    int32_t *mem32 = (int32_t*) &data_mem[util->ALUOut];
    // Load
    if (CUNT.MemRead) util->MemoryData = *mem32;
    // Store
    if (CUNT.MemWrite) *mem32 = util->ReadData2;
  }
}

void writeBack(int32_t reg[], RegUtil *util, ControlUnit CUNT) {
  if (CUNT.RegWrite) {
    switch (CUNT.MemToReg) {
      case 0:
        *util->WriteData = util->ALUOut;
        break;
      case 1:
        *util->WriteData = util->MemoryData;
        break;
      case 2:
        *util->WriteData = util->signExtended;
        break;
        
    }
  }

}
