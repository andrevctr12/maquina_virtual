#include <stdio.h>
#include "regis.h"

void initRegis(int32_t reg[], int size) {
  for (int i = 0; i < size; i++) {
    reg[i] = 0;
  }
}

void printRegUtil(RegUtil util) {
  printf("Registradores Utilitários:\n");
  printf("PC:           %u\n", util.PC);
  printf("ALUOutBranch: %u\n", util.ALUOutBranch);
  printf("JumpAdress:   %u\n", util.JumpAddress);
  printf("operation:    %u\n", util.operation);
  
  printf("ALUOut:       %d\n", util.ALUOut);
  printf("SignExtended: %d\n", util.signExtended);
  printf("MemoryData:   %d\n", util.MemoryData);

  printf("ReadReg1[%u]: %d\n", util.ReadReg1, util.ReadData1);
  printf("ReadReg2[%u]: %d\n", util.ReadReg2, util.ReadData2);
  printf("WriteReg[%u]: %d\n", util.WriteReg, *util.WriteData);
}

void printRegis(int32_t reg[], int size) {
  printf("Banco de registradores:\n");
  for (int i = 0; i < size; i++) {
    printf("$%2d:  %d\n", i, reg[i]);
  }
}
