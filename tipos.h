#ifndef TIPOS_H
#define TIPOS_H

// Estrutura que conterá os dados de uma data, isto é, o dia, o mês e o ano.
typedef struct{
    int dia;
    int mes;
    int ano;
} DATA;

/* Estrutura que guardará um registro financeiro. Um registro terá:
- 1 código, que será usado para achá-lo nos procedimentos de remoção e edição;
- 1 data, que será informada pelo usuário quando inseri-lo, que significará quando aquela movimentação financeira aconteceu;
- 1 descrição, para ajudar a entender o que quer dizer aquela receita/despesa, como por exemplo: "Conta de luz", "Escola de idiomas do mês de agosto", ..., e;
- 1 valor, que significa o valor daquela receita/despesa.
 */
typedef struct{
    int codigo;
    DATA data;
    char descricao[100];
    double valor;
} REGISTRO;

/* Os registros, quando o programa iniciar, serão lidos do arquivo TXT, e ficarão na memória, até o momento em que a aplicação for finalizada. Ao ler os registros pela primeira vez no programa, eles serão organizados de maneira similar a uma lista duplamente encadeada. Toda e qualquer operação feita neles (remoção, edição, inserção) ficará na memória até a aplicação ser finalizada. Quando for o momento de fechar a aplicação, os dados residentes na memória serão gracados de volta no arquivo TXT, já com suas devidas alterações.*/
typedef struct no_reg{
    REGISTRO reg;
    struct no_reg* proximo_registro;
    struct no_reg* registro_anterior;
} NO_REGISTRO;

/*Como foi dito antes, os registros ficarão organizados na memória como uma
lista duplamente encadeada. Além disso, terá a informação de quantos registros tem, e do valor total desses registros somados.*/
typedef struct profile{
	NO_REGISTRO* cabeca;
	NO_REGISTRO* fim;
	long int n;
	double valor;
} PROFILE;

#endif
