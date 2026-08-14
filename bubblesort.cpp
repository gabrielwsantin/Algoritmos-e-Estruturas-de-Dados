#include <stdio.h> //bubblesort

int main(){
	//declaracao de variaveis
	int vetor[10];
	int i;
	int continuar;
	int temp;
	
	//entrada de dados
	for(i = 0 ; i < 10 ; i++) {
		printf("digite o valor da posicao %d: ", i);
		scanf("%d", &vetor[i]);
		
	}
	//processamento
	continuar = 1;
	while (continuar) {
		continuar = 0;

		for(i = 0 ; i < 9 ; i++) {
			if (vetor[i] > vetor[i + 1]) {
				temp = vetor[i];
				vetor[i] = vetor[i + 1];
				vetor [i + 1] = temp;
				continuar = 1;
			
			}
		}
	}
	
	//saida de dados
	for (i = 0 ; i < 10 ; i++) {
		printf("%d\n", vetor[i]);
	}
}
