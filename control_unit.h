/*!
 @header control_unit.h
 
 @brief Unidade de Controle
 
 @author André Lopes
 @copyright  2018 André Lopes
 @version    0.1
 */

#ifndef CONTROL_UNIT_H
#define CONTROL_UNIT_H

#include "types.h"

/*!
 * @brief Estrutura de Unidade de Controle
 */
typedef struct ControlUnit {
  unsigned RegDst;
  unsigned Jump;
  unsigned Branch;
  unsigned MemRead;
  unsigned MemToReg;
  unsigned ALUOp;
  unsigned MemWrite;
  unsigned ALUSrc;
  unsigned RegWrite;
  unsigned Bne;
} ControlUnit;

/*!
 * @brief Inicializa a estrutura de Unidade de Controle a partir de uma instrução e do seu opcode
 * 
 * @param i             Instrução
 * @return ControlUnit  Unidade de controle inicializada
 */
ControlUnit initializeControlUnit(Instruction i);

/*!
 * @brief Imprime Unidade de Controle
 * 
 * @param CUNT Unidade de Controle
 */
void printControlUnit(ControlUnit CUNT);

#endif