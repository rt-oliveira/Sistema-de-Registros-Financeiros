#include <stdio.h>
#include <stdlib.h>
#include "userIO.h"
#include "fileIO.h"
#include "dao.h"

/*Função que mostrará todos os registros financeiros. Mostrará em partes de 60 registros,
para evitar perda de conteúdo da saída, por parte do terminal.*/
void ListarRegistros(PROFILE* p){
	if(p->n==0){
		printf("Não há registros para serem mostrados.\n\n");
	}else{
		int i,j;
		char c;
		NO_REGISTRO* No=p->cabeca;
		REGISTRO r;
		int qtde=p->n/60;
		printf("Modelo de saída:\n");
		printf("[<Código>;<Data>] <Descrição>\n");
		printf("Valor: <Valor do registro>\n\n");
		for(i=0;i<qtde;i++){
			for(j=0;j<60;j++){
				r=No->reg;
				printf("[%d;%d/%d/%d] %s",r.codigo,r.data.dia,r.data.mes,r.data.ano,r.descricao);
				printf("Valor: R$ %.2lf\n",r.valor);
				No=No->proximo_registro;
			}
			printf("[Enter] para continuar vendo os registros ou [p] para sair do modo de listagem: ");
			char c;
			while((c=getchar())!='\n');
			c=getchar();
			if(c=='p'){
				printf("\n");
				return;
			}
		}
		if(p->n%60!=0){
			while(No!=NULL){
				r=No->reg;
				printf("[%d;%d/%d/%d] %s",r.codigo,r.data.dia,r.data.mes,r.data.ano,r.descricao);
				printf("Valor: R$ %.2lf\n",r.valor);
				No=No->proximo_registro;
			}
		}
		printf("\n");
	}
}

/*Esta função faz todo o processo de adição de novo registro no programa.
	Lê os dados do registro, atribui um código a esse registro, conta esse
	novo elemento (isto é, N, que é a quantidade de registros, aumenta em 1) e
	o insere na lista de registros.
*/
void AdicionarRegistro(PROFILE* p,int* UltimoCodigo){
	NO_REGISTRO* No=(NO_REGISTRO*)malloc(sizeof(NO_REGISTRO));
	REGISTRO R=LerDadosDoRegistro(No->reg);
	(*UltimoCodigo)++;
	R.codigo=(*UltimoCodigo);
	No->reg=R;
	p->n++;
	p->valor+=No->reg.valor;
	InserirRegistroFinanceiroAoProfile(p,No,p->n==1);
	printf("Registro adicionado com sucesso!\n\n");
}

/*Grava no arquivo de acordo com a ordem que os registros estão,
	do último para o primeiro. Sem haver alterações no arquivo profile.txt
	isto significará que os registros serão gravados do mais antigo para o
	mais recente.
*/ 
void Sair(PROFILE* p){
	if(p->n!=0)
		EscreverRegistrosNoArquivo(p);
	exit(0);
}

/*Esta função terá o objetivo de editar um registro existente.
*/
void EditarRegistro(PROFILE* p){
	if(p->n==0)
		printf("Não há registros que possam ser editados.\n\n");
	else{
		NO_REGISTRO* No;
		int codigo;
		while(1){
			printf("Digite o código do registro que deseja editar: ");
			scanf("%d",&codigo);
			No=BuscarRegistro(p,codigo);
			if(No==NULL){
				printf("Não existe registro com o código %d. ",codigo);
				printf("Digite um código de registro válido.\n\n");
			}else
				break;
		}
		p->valor-=No->reg.valor;
		REGISTRO R=LerDadosDoRegistro(No->reg);
		No->reg=R;
		p->valor+=No->reg.valor;
		printf("Registro editado com sucesso!\n\n");
	}
}

//Esta função fará a remoção de um registro financeiro, dado o código do mesmo.
void RemoverRegistro(PROFILE* p){
	if(p->n==0)
		printf("Não há registros que possam ser removidos.\n\n");
	else{
		NO_REGISTRO* No;
		int codigo;
		while(1){
			printf("Digite o código do registro que deseja remover: ");
			scanf("%d",&codigo);
			No=BuscarRegistro(p,codigo);
			if(No==NULL){
				printf("Não existe registro com o código %d. ",codigo);
				printf("Digite um código de registro válido.\n\n");
			}else
				break;
		}
		Remover(p,No);
		printf("Registro removido com sucesso!\n\n");
	}
}
