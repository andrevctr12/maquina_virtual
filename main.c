#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "control_unit.h"
#include "thread.h"
#include "regis.h"
#include "memory.h"

int printReg;
int printMemories;
int printUtil;

int main (int argc, char const *argv[]) {
  for (int i = 2; i < argc; i++) {
    if (strcmp(argv[i], "-printReg") == 0) printReg = 1;
    if (strcmp(argv[i], "-printMemories") == 0) printMemories = 1;
    if (strcmp(argv[i], "-printUtil") == 0) printUtil = 1;
  }
  
  //Variáveis da maquina virtual
  ControlUnit CUNT;                 ///< Unidade de Controle
  Instruction IR;                   ///< Registrador de Instrução
  RegUtil util;                     ///< Registadores globais utilitários
  int32_t reg[32];                  ///< Banco de registradores
  uint8_t inst_mem[INST_MEM_SIZE];  ///< Memória de instruções
  int8_t data_mem[DATA_MEM_SIZE];   ///< Memória de Dados
  
  if (fillInstructionMemory(inst_mem, argv[1])) {
    util.PC = 0; ///< PC começa no endereço 0
    fillMemory((uint8_t *)data_mem, DATA_MEM_SIZE);
    initRegis(reg, 32);
    int contJump = 0;

    while (instructionFetch(inst_mem, &util, &IR)) {
      instructionDecode(reg, &util, &IR, &CUNT);
      execution(reg, &util, CUNT);
      memoryAccess(data_mem, &util, CUNT);
      writeBack(reg, &util, CUNT);
      
      if (printUtil) printRegUtil(util);
      if (printReg) printRegis(reg, 32);
      
      if (IR.J.opcode == TYPE_J || IR.R.funct == FUNCTJR) contJump++;
      if (contJump == 25) {
        contJump = 0;
        char c;
        printf("Deseja para o loop? [S/N]\n");
        scanf("%c%*c", &c);
        if (c == 's' || c == 'S') break;
      }
    }
    if (printMemories) {
      printMemory(inst_mem, INST_MEM_SIZE); 
      printDataMemory(data_mem, DATA_MEM_SIZE);
    }
  }
  else {
    printf("Memória inválida!\n");
  }

  return 0;
}
