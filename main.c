#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "control_unit.h"
#include "thread.h"
#include "regis.h"
#include "memory.h"

int main (int argc, char const *argv[]) {
  //Variáveis da maquina virtual
  ControlUnit CUNT;                 ///< Unidade de Controle
  Instruction IR;                   ///< Registrador de Instrução
  RegUtil util;                     ///< Registadores globais utilitários
  int32_t reg[32];                 ///< Banco de registradores
  uint8_t inst_mem[INST_MEM_SIZE];  ///< Memória de instruções
  int8_t data_mem[DATA_MEM_SIZE];  ///< Memória de Dados

  fillMemory((uint8_t*)data_mem, DATA_MEM_SIZE);

  if (fillInstructionMemory(inst_mem, "testeexemplo2.txt")) {
    printMemory(inst_mem, INST_MEM_SIZE);
    
    util.PC = 0; ///< PC começa no endereço 0
    initRegis(reg, 32);

    while (instructionFetch(inst_mem, &util, &IR)) {
      instructionDecode(reg, &util, &IR, &CUNT);
      execution(reg, &util, CUNT);
      memoryAccess(data_mem, &util, CUNT);
      writeBack(reg, &util, CUNT);
    }
  }
  else {
    printf("Memória inválida!\n");
  }

  return 0;
}
