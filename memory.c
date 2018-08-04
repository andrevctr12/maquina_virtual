#include <stdio.h>
#include <stdlib.h>
#include "memory.h"

#define MASK1   0b11111111000000000000000000000000
#define MASK2   0b00000000111111110000000000000000
#define MASK3   0b00000000000000001111111100000000
#define MASK4   0b00000000000000000000000011111111

/**
 * String de bits para inteiro unsigned 
 * 
 * @param s           string de bits
 * @return unsigned   inteiro convertido
 */
unsigned str2unsigned(char *s) {
  return (unsigned)strtoul(s, NULL, 2);
}

int fillInstructionMemory(uint8_t mem[], const char *filename) {
  FILE *f;
  fillMemory(mem, INST_MEM_SIZE);

  if ((f = fopen(filename, "r")) != NULL) {
    char in[33];
    unsigned *mem32;
    for (mem32 = (unsigned*) mem; !feof(f); mem32++) {
      fscanf(f, "%s\n", in);
      *mem32 = str2unsigned(in);
      printf("%08x\n", *mem32);
    }
    return 1;
  }
  else return 0;
}

void fillMemory(uint8_t mem[], int size) {
  for (int i = 0; i < size; i++) {
    mem[i] = 0;
  }
}

void printMemory(uint8_t mem[], int size) {
  unsigned *mem32;
  int i = 0;
  printf("Memória:\n");
  for (mem32 = (unsigned*) mem; *mem32 != 0 ; mem32++) {
    printf("[%2d]: %08x\n", i, *mem32);
    i += 4;
  }
}
