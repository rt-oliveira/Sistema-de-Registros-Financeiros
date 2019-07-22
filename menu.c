#include <stdio.h>
#include "operacoes.h"

// Fun��o que gere toda essa parte das op��es do menu
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
			/*Caso n�o seja op��o v�lida, o programa alerta e permitir� a leitura
			de uma nova op��o.*/
			printf("%d n�o � uma op��o v�lida. Digite uma op��o v�lida\n\n",op);
	}
}
