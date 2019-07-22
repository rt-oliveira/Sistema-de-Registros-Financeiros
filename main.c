#include <locale.h>
#include <stdlib.h>
#include "inicio.h"
#include "menu.h"

//Este arquivo é a main do programa.
int main(){
	int UltimoCodigo=0;
	setlocale(LC_ALL,""); // Permite acentos, já que a língua portuguesa tem.
	PROFILE p=LerRegistrosDoArquivoTxt(&UltimoCodigo);
  	// Abertura do programa.
	printf("*****************************************************************\n");
	printf("*                                                               *\n");
 	printf("*        Bem-vindo ao Sistema de Gerenciamento de Finanças      *\n");
 	printf("*                                                               *\n");
  	printf("*****************************************************************\n");
  	while(1){
    /*A cada tentativa de operação, o menu é aberto perguntando se deseja
      fazer algo. Além disso, mostra, a cada momentos, o total dos registros
      financeiros contabilizados.
    */
  	printf("Seus registros financeiros totalizam R$ %.2lf\n",p.valor);
  	Menu(&p,&UltimoCodigo);
  	}
}

