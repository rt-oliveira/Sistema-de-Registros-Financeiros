#include <stdio.h>
#include <stdlib.h>
#include "tipos.h"

/*Faz a inserção do novo registros na lista de registros que fica na memória 
	durante toda a execução do programa.
	*/
void InserirRegistroFinanceiroAoProfile(PROFILE* p,NO_REGISTRO* n,int primeiro){
	n->proximo_registro=p->cabeca;
	p->cabeca=n;
	if(primeiro){
		p->fim=n;
		n->registro_anterior=NULL;
	}else
		n->proximo_registro->registro_anterior=n;
}

//Esta função procurará pelo registro que contém o código informado.
NO_REGISTRO* BuscarRegistro(PROFILE* p,int codigo){
	NO_REGISTRO* No=p->cabeca;
	while(No!=NULL){
		if(No->reg.codigo==codigo)
			return No;
		else
			No=No->proximo_registro;
	}
	return NULL;
}

void Remover(PROFILE* p,NO_REGISTRO* No){
	if(p->n==1){
		p->cabeca=NULL;
		p->fim=NULL;
	}else{
		if(No->proximo_registro!=NULL)
			No->proximo_registro->registro_anterior=No->registro_anterior;
		if(No->registro_anterior!=NULL)
			No->registro_anterior->proximo_registro=No->proximo_registro;
		if(No==p->cabeca)
			p->cabeca=No->proximo_registro;
		if(No==p->fim)
			p->fim=No->registro_anterior;
	}
	p->valor-=No->reg.valor;
	p->n--;
	free(No);
}
