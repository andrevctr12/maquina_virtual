#ifndef THREAD_H
#define THREAD_H

#include "types.h"
#include "control_unit.h"
#include "regis.h"

/**
 * Primeira etapa do caminho de dados, busca de instrução
 * 
 * @param inst_mem  Memória de instruções
 * @param util      Registradores utilitários
 * @param IR        Registrador de instrução
 * @return int      Retorna se existe mais instruções ou se é o fim da memória
 */
int instructionFetch(uint8_t inst_mem[], RegUtil *util, Instruction *IR);

/**
 * Segunda etapa do caminho de dados, decodificação da instrução
 * 
 * @param reg   Banco de registradores
 * @param util  Registradores utilitários
 * @param IR    Registrador de instrução
 * @param CUNT  Unidade de Controle
 */
void instructionDecode(int32_t reg[], RegUtil *util, Instruction *IR, ControlUnit *CUNT);

void execution(int32_t reg[], RegUtil *util, ControlUnit CUNT);

void memoryAccess(int8_t data_mem[], RegUtil *util, ControlUnit CUNT);

void writeBack(int32_t reg[], RegUtil *util, ControlUnit CUNT);

#endif
