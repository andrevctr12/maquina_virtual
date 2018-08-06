# Maquina Virtual MIPS
## Linguagem
Foi utilizada a linguagem C para a execução do trabalho, essa linguagem possui boa integração com o baixo nível e é de grande ajuda na manipulação de bits, que era muito necessária para a execução deste trabalho.

## Estrutura de dados
Foram utilizadas as seguintes estruturas de dados:
- Struct: Tipo de instrução
          Unidade de Controle
          Registradores Utilitários
- Union:  Utilizado para melhor organização dos tipos de instruções
- Vetor:  Memória de dados
          Memória de instruções
          Banco de Registradores

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

## Documentação Técnica
A documentação técnica está em:
```bash
  ./doc/Documentacao.html
```