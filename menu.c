#include <stdio.h>
#include "operacoes.h"

// Função que gere toda essa parte das opções do menu
void Menu(PROFILE* p,int* UltimoCodigo){
	int op;
	printf("O que deseja fazer?\n");
	printf("[1] Listar todos os registros financeiros\n");
	printf("[2] Adicionar um novo registro financeiro\n");
	printf("[3] Editar um registro financeiro\n");
	printf("[4] Remover um registro financeiro\n");	
	printf("[5] Sair do programa\n");
	scanf("%d",&op);
	switch(op){
		case 1:
			ListarRegistros(p);
			break;
		case 2:
			AdicionarRegistro(p,UltimoCodigo);
			break;
		case 3:
			EditarRegistro(p);
			break;
		case 4:
			RemoverRegistro(p);
			break;
		case 5:
			Sair(p);
		default:
			/*Caso não seja opção válida, o programa alerta e permitirá a leitura
			de uma nova opção.*/
			printf("%d não é uma opção válida. Digite uma opção válida\n\n",op);
	}
}
