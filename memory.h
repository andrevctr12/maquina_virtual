#ifndef MEMORY_H
#define MEMORY_H

#define DATA_MEM_SIZE 100
#define INST_MEM_SIZE 100

/**
 * Preenche os espaços da memória de instruções com a entrada do arquivo ou com 0
 * 
 * @param mem       Memória de instruções
 * @param filename  nome do arquivo
 * @return int      retorna sucesso
 */
int fillInstructionMemory(uint8_t mem[], const char *filename);

/**
 * Preenche os espaços da memória com 0
 * 
 * @param mem       Memória
 * @param size      Tamanho da memória
 */
void fillMemory(uint8_t mem[], int size);

/**
 * Imprime o que tem na memoria de instruções em hexadecimal
 * 
 * @param mem       Memória a ser impressa
 * @param size      Tamanho da memória
 */
void printMemory(uint8_t mem[], int size);

/**
 * Imprime o que tem na memoria de dados em decimal
 * 
 * @param mem     Memória a ser impressa
 * @param size    Tamanho da memória
 */
void printDataMemory(int8_t mem[], int size);

#endif