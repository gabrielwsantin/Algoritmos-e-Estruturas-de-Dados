#include <stdio.h>

int main(){
	//declaração de variáveis
	int vetor[10];
	int i;
	//entrada de dados
	for (i = 0 ; i <10 ; i++) {
		printf("digite o valor do indice %d: ", i);
		scanf("%d", &vetor[i]);
	
	}
	//saída de dados
	for (i = 0; i < 10 ; i++) {
			printf("vetor[%d] = %d\n", i, vetor[i]);
	}
	//conclusão
	return 0;
}
