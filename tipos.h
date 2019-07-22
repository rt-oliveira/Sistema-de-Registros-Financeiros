#ifndef TIPOS_H
#define TIPOS_H

// Estrutura que conter� os dados de uma data, isto �, o dia, o m�s e o ano.
typedef struct{
    int dia;
    int mes;
    int ano;
} DATA;

/* Estrutura que guardar� um registro financeiro. Um registro ter�:
- 1 c�digo, que ser� usado para ach�-lo nos procedimentos de remo��o e edi��o;
- 1 data, que ser� informada pelo usu�rio quando inseri-lo, que significar� quando aquela movimenta��o financeira aconteceu;
- 1 descri��o, para ajudar a entender o que quer dizer aquela receita/despesa, como por exemplo: "Conta de luz", "Escola de idiomas do m�s de agosto", ..., e;
- 1 valor, que significa o valor daquela receita/despesa.
 */
typedef struct{
    int codigo;
    DATA data;
    char descricao[100];
    double valor;
} REGISTRO;

/* Os registros, quando o programa iniciar, ser�o lidos do arquivo TXT, e ficar�o na mem�ria, at� o momento em que a aplica��o for finalizada. Ao ler os registros pela primeira vez no programa, eles ser�o organizados de maneira similar a uma lista duplamente encadeada. Toda e qualquer opera��o feita neles (remo��o, edi��o, inser��o) ficar� na mem�ria at� a aplica��o ser finalizada. Quando for o momento de fechar a aplica��o, os dados residentes na mem�ria ser�o gracados de volta no arquivo TXT, j� com suas devidas altera��es.*/
typedef struct no_reg{
    REGISTRO reg;
    struct no_reg* proximo_registro;
    struct no_reg* registro_anterior;
} NO_REGISTRO;

/*Como foi dito antes, os registros ficar�o organizados na mem�ria como uma
lista duplamente encadeada. Al�m disso, ter� a informa��o de quantos registros tem, e do valor total desses registros somados.*/
typedef struct profile{
	NO_REGISTRO* cabeca;
	NO_REGISTRO* fim;
	long int n;
	double valor;
} PROFILE;

#endif
