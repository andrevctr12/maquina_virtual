/*!
 @header ALU.h
 
 @brief Codigos da ALU
 
 @author André Lopes
 @copyright  2018 André Lopes
 @version    0.1
 */

#ifndef ALU_H
#define ALU_H

/*!
 * @brief Unidade de Controle da ALU
 * 
 * @param funct       funct da instrução
 * @param ALUOp       Sinal de Controle ALUOp
 * @return unsigned   Valor da operação
 */
unsigned ALUControlUnit(unsigned funct, unsigned ALUOp);

/*!
 * @brief Resultado da ALU utilizando como entrada operação e dois numeros
 * 
 * @param a     Primeiro número
 * @param b     Segundo número
 * @param op    operação
 * @return int  resultado da oepração na ALU
 */
int ALUResult(int a, int b, unsigned op);

#endif