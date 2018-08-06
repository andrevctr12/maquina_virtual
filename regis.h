/*!
 @header regis.h
 
 @brief Banco de Registradores e Registradores Utilitários
 
 @author André Lopes
 @copyright  2018 André Lopes
 @version    0.1
 */

#ifndef REGIS_H
#define REGIS_H

#include <stdlib.h>

/*!
 * @brief Defines do numero do registrado com algo mais ludico
 */
#define ZERO 0
#define AT 1
//$2 - $3	$v0, $v1	Return values from functions
//$4 - $7	$a0 - $a3	Arguments to functions - not preserved by subprograms
#define T0 8
#define T1 9
#define T2 10
#define T3 11
#define T4 12
#define T5 13
#define T6 14
#define T7 15
#define T8 24
#define T9 25

/*!
 * @brief Inicia o vetor de registradores
 * 
 * @param reg   Banco de registradores
 * @param size  tamanho do vetor
 */
void initRegis(int32_t reg[], int size);

/*!
 * @brief Imprime os registradores do Banco de registradores
 * 
 * @param reg   Banco de registradores
 * @param size  tamanho do vetor
 */
void printRegis(int32_t reg[], int size);

/*!
 * @brief Registradores utilitários
 */
typedef struct RegUtil {
  uint32_t PC;
  uint32_t ALUOutBranch;
  uint32_t JumpAddress;
  uint32_t operation;
  
  int32_t ALUOut;
  int32_t signExtended;
  int32_t MemoryData;

  uint32_t ReadReg1;
  uint32_t ReadReg2;
  uint32_t WriteReg;
  int32_t ReadData1;
  int32_t ReadData2;
  int32_t *WriteData;
} RegUtil;

/*!
 * @brief Imprime o Registradores Utilitários
 * 
 * @param util  Registradores utilitários
 */
void printRegUtil(RegUtil util);

#endif
