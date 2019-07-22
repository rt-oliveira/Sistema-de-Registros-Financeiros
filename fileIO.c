#include <stdio.h>
#include <stdlib.h>
#include "tipos.h"

/*Cria arquivo contendo apenas um "0", para dizer que � um profile vazio, quando
  n�o consegue ler o arquivo de profile (ou porque n�o existe, ou porque cont�m uma
  quantidade inv�lida de registros (isto �, a primeira linha tem um n�mero
  abaixo de 0.
*/
void CriarArquivoDeProfile(){
		 FILE* F=fopen("profile.txt","w");
		 fprintf(F,"0");
		 fclose(F);
}

//Procedimento que l� os dados de um registro que est�o no arquivo TXT
void LerRegistroDoArquivo(NO_REGISTRO* No,FILE* F){
	REGISTRO r=No->reg;
	fscanf(F,"[%d;%d/%d/%d] ",&r.codigo,&r.data.dia,&r.data.mes,&r.data.ano);
	fgets(r.descricao,100,F);
	fscanf(F,"Valor: %lf\n",&r.valor);
	No->reg=r;
}

/*Procedimento que gravar� no arquivo txt os registros financeiros que est�o residentes
  na mem�ria*/
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
