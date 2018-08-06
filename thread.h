/*!
 @header thread.h
 
 @brief Caminho de dados, Thread de execução
 
 @author André Lopes
 @copyright  2018 André Lopes
 @version    0.1
 */

#ifndef THREAD_H
#define THREAD_H

#include "types.h"
#include "control_unit.h"
#include "regis.h"

/*!
 * @brief Primeira etapa do caminho de dados, busca de instrução
 * 
 * @param inst_mem  Memória de instruções
 * @param util      Registradores utilitários
 * @param IR        Registrador de instrução
 * @return int      Retorna se existe mais instruções ou se é o fim da memória
 */
int instructionFetch(uint8_t inst_mem[], RegUtil *util, Instruction *IR);

/*!
 * @brief Segunda etapa do caminho de dados, decodificação da instrução
 * 
 * @param reg   Banco de registradores
 * @param util  Registradores utilitários
 * @param IR    Registrador de instrução
 * @param CUNT  Unidade de Controle
 */
void instructionDecode(int32_t reg[], RegUtil *util, Instruction *IR, ControlUnit *CUNT);

/*!
 * @brief Terceira etapa do caminho de dados, execução da instrução
 * 
 * @param reg   Banco de registradores
 * @param util  Registradores utilitários
 * @param CUNT  Unidade de Controle
 */
void execution(int32_t reg[], RegUtil *util, ControlUnit CUNT);

/*!
 * @brief Quarta etapa do caminho de dados, acesso a memória de dados, caso necessário
 * 
 * @param data_mem  Memória de dados
 * @param util      Registradores utilitários
 * @param CUNT      Unidade de Controle
 */
void memoryAccess(int8_t data_mem[], RegUtil *util, ControlUnit CUNT);

/*!
 * @brief Quinta etapa do caminho de dados, escrever no registrador, caso necessário
 * 
 * @param reg   Banco de registradores
 * @param util  Registradores utilitários
 * @param CUNT  Unidade de Controle
 */
void writeBack(int32_t reg[], RegUtil *util, ControlUnit CUNT);

#endif
