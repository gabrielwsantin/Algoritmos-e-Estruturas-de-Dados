#include <stdio.h>

int main(){
	//declaracao de variaveis
	int vetor[10];
	int i;
	int j;
	int temp;
	
	//entrada de dados
	for (i = 0; i < 10; i++) {
		printf("digite o valor do indice %d: ", i);
		scanf("%d", &vetor[i]);
		
	}

	//processamento
	for (i = 0; i < 9; i++) {
		for (j = (i + i) ; j < 10 ; j++) {
			if (vetor[i] > vetor[j]) {
				temp = vetor[i];
				vetor[i] = vetor[j];
				vetor[j] = temp;
			}
		}
	}
	
	//saida de dados
	for (i = 0; i < 10; i++) {
		printf("%d\n", vetor[i]);
	}
}
