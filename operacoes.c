#include <stdio.h>
#include <stdlib.h>
#include "userIO.h"
#include "fileIO.h"
#include "dao.h"

/*Fun��o que mostrar� todos os registros financeiros. Mostrar� em partes de 60 registros,
para evitar perda de conte�do da sa�da, por parte do terminal.*/
void ListarRegistros(PROFILE* p){
	if(p->n==0){
		printf("N�o h� registros para serem mostrados.\n\n");
	}else{
		int i,j;
		char c;
		NO_REGISTRO* No=p->cabeca;
		REGISTRO r;
		int qtde=p->n/60;
		printf("Modelo de sa�da:\n");
		printf("[<C�digo>;<Data>] <Descri��o>\n");
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

/*Esta fun��o faz todo o processo de adi��o de novo registro no programa.
	L� os dados do registro, atribui um c�digo a esse registro, conta esse
	novo elemento (isto �, N, que � a quantidade de registros, aumenta em 1) e
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

/*Grava no arquivo de acordo com a ordem que os registros est�o,
	do �ltimo para o primeiro. Sem haver altera��es no arquivo profile.txt
	isto significar� que os registros ser�o gravados do mais antigo para o
	mais recente.
*/ 
void Sair(PROFILE* p){
	if(p->n!=0)
		EscreverRegistrosNoArquivo(p);
	exit(0);
}

/*Esta fun��o ter� o objetivo de editar um registro existente.
*/
void EditarRegistro(PROFILE* p){
	if(p->n==0)
		printf("N�o h� registros que possam ser editados.\n\n");
	else{
		NO_REGISTRO* No;
		int codigo;
		while(1){
			printf("Digite o c�digo do registro que deseja editar: ");
			scanf("%d",&codigo);
			No=BuscarRegistro(p,codigo);
			if(No==NULL){
				printf("N�o existe registro com o c�digo %d. ",codigo);
				printf("Digite um c�digo de registro v�lido.\n\n");
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

//Esta fun��o far� a remo��o de um registro financeiro, dado o c�digo do mesmo.
void RemoverRegistro(PROFILE* p){
	if(p->n==0)
		printf("N�o h� registros que possam ser removidos.\n\n");
	else{
		NO_REGISTRO* No;
		int codigo;
		while(1){
			printf("Digite o c�digo do registro que deseja remover: ");
			scanf("%d",&codigo);
			No=BuscarRegistro(p,codigo);
			if(No==NULL){
				printf("N�o existe registro com o c�digo %d. ",codigo);
				printf("Digite um c�digo de registro v�lido.\n\n");
			}else
				break;
		}
		Remover(p,No);
		printf("Registro removido com sucesso!\n\n");
	}
}
