#include <stdio.h>
#include <stdlib.h>
#include "dao.h"
#include "fileIO.h"

//Esta função regula todo o processo de leitura dos registros vindos do arquivo TXT
PROFILE LerRegistrosDoArquivoTxt(int* UltimoCodigo){
	NO_REGISTRO* No;
	PROFILE P={.cabeca=NULL, .valor=0, .fim=NULL};
	FILE* F=fopen("profile.txt","r");
	if(F==NULL){
    	CriarArquivoDeProfile();
		printf("O arquivo não pôde ser aberto.");
		getchar();
		exit(1);
	}else{
		fscanf(F,"%d\n",&P.n);
		if(P.n>0){
			int i;
			for(i=0;i<P.n;i++){
				No=(NO_REGISTRO*)malloc(sizeof(NO_REGISTRO));
				LerRegistroDoArquivo(No,F);
				P.valor+=No->reg.valor;
				InserirRegistroFinanceiroAoProfile(&P,No,i==0);
				(*UltimoCodigo)=No->reg.codigo;
			}
		}else
        	CriarArquivoDeProfile();
	}	
	fclose(F);
	return P;
}
