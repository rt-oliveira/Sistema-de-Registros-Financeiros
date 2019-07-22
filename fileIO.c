#include <stdio.h>
#include <stdlib.h>
#include "tipos.h"

/*Cria arquivo contendo apenas um "0", para dizer que é um profile vazio, quando
  não consegue ler o arquivo de profile (ou porque não existe, ou porque contém uma
  quantidade inválida de registros (isto é, a primeira linha tem um número
  abaixo de 0.
*/
void CriarArquivoDeProfile(){
		 FILE* F=fopen("profile.txt","w");
		 fprintf(F,"0");
		 fclose(F);
}

//Procedimento que lê os dados de um registro que estão no arquivo TXT
void LerRegistroDoArquivo(NO_REGISTRO* No,FILE* F){
	REGISTRO r=No->reg;
	fscanf(F,"[%d;%d/%d/%d] ",&r.codigo,&r.data.dia,&r.data.mes,&r.data.ano);
	fgets(r.descricao,100,F);
	fscanf(F,"Valor: %lf\n",&r.valor);
	No->reg=r;
}

/*Procedimento que gravará no arquivo txt os registros financeiros que estão residentes
  na memória*/
void EscreverRegistrosNoArquivo(PROFILE *p){
	NO_REGISTRO* No=p->fim;
	NO_REGISTRO* SucessorNo=No->registro_anterior;
	FILE* F=fopen("profile.txt","w");
	fprintf(F,"%d\n",p->n);
	while(1){
		REGISTRO r=No->reg;
		fprintf(F,"[%d;%d/%d/%d] ",r.codigo,r.data.dia,r.data.mes,r.data.ano);
		fputs(r.descricao,F);
		fprintf(F,"Valor: %.2lf\n",r.valor);
		free(No);
		if(SucessorNo==NULL)
			break;
		else{
			No=SucessorNo;
			SucessorNo=No->registro_anterior;
		}
	}
	fclose(F);
}
