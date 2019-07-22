#include <stdio.h>
#include "tipos.h"
#include "check.h"

/*Procedimento que tem o objetivo de ler especificamente datas de novos registros
	ou daqueles que estão sendo editados.*/
void LerData(REGISTRO* R){
	while(1){
		printf("Digite a data do registro [dd/mm/aaaa]: ");
		scanf(" %d/%d/%d",&R->data.dia,&R->data.mes,&R->data.ano);
		if(!ehDataValida(R->data.dia,R->data.mes,R->data.ano)){
			printf("%d/%d/%d não é uma data válida! ",R->data.dia,R->data.mes,R->data.ano);
			printf("Digite uma data válida.\n\n");
		}else
			break;
	}
}

/*Esta função terá o objetivo de ler os dados de um registro (data,descrição e valor)
da entrada padrão*/
REGISTRO LerDadosDoRegistro(REGISTRO R){
	LerData(&R);
	char c;
	while((c=getchar())!='\n');
	printf("Digite a descrição do registro (máx 100 caracteres): ");
	fgets(R.descricao,100,stdin);
	printf("Digite o valor deste registro: R$ ");
	scanf("%lf",&R.valor);
	return R;
}
