# Maquina Virtual MIPS
## Linguagem
Foi utilizada a linguagem C para a execução do trabalho, essa linguagem possui boa integração com o baixo nível e é de grande ajuda na manipulação de bits, que era muito necessária para a execução deste trabalho.

## Estrutura de dados
Foram utilizadas as seguintes estruturas de dados:
- Struct: Utilizada para mapear os bits de uma instrução
- Union:  Utilizado para melhor organização dos tipos de instruções

## Como utilizar a MV:
Abra o terminal:
```bash
$ gcc main.c thread.c memory.c control_unit.c ALU.c regis.c types.c -o mv.out  # Se quiser compilar
# Debug 
# -printUtil      imprime os Registradores auxiliares como PC, JumpAdress e outros
# -printReg       imprime os Registradores do Banco de Regs
# -printMemories  imprime as memorias de instruções e de dados
$ ./mv.out "caminho do arquivo" [-printUtil] [-printReg] [-printMemories]
```
