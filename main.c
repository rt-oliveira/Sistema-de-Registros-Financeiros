#include <locale.h>
#include <stdlib.h>
#include "inicio.h"
#include "menu.h"

//Este arquivo � a main do programa.
int main(){
	int UltimoCodigo=0;
	setlocale(LC_ALL,""); // Permite acentos, j� que a l�ngua portuguesa tem.
	PROFILE p=LerRegistrosDoArquivoTxt(&UltimoCodigo);
  	// Abertura do programa.
	printf("*****************************************************************\n");
	printf("*                                                               *\n");
 	printf("*        Bem-vindo ao Sistema de Gerenciamento de Finan�as      *\n");
 	printf("*                                                               *\n");
  	printf("*****************************************************************\n");
  	while(1){
    /*A cada tentativa de opera��o, o menu � aberto perguntando se deseja
      fazer algo. Al�m disso, mostra, a cada momentos, o total dos registros
      financeiros contabilizados.
    */
  	printf("Seus registros financeiros totalizam R$ %.2lf\n",p.valor);
  	Menu(&p,&UltimoCodigo);
  	}
}

