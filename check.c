// Teste para saber se uma determinada data é válida
int ehDataValida(int d,int m,int a){
	switch(m){
		case 1://Janeiro
		case 3://Março
		case 5://Maio
		case 7://Julho
		case 8://Agosto
		case 10://Outubro
		case 12://Dezembro
			return d<=31;
		case 4://Abril
		case 6://Junho
		case 9://Setembro
		case 11://Novembro
			return d<=30;
		case 2://Fevereiro
			if(a%4==0)
				return d<=29;
			else
				return d<=28;
	}
}
