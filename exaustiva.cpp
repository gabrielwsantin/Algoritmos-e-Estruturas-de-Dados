#include <stdio.h>
#include <stdlib.h>
#include <time.h>

	
int main() {
	//declaracao de variaveis
	int vetor[100000];
	int parametrodepesquisa;
	int i;
	
	//inicializacao do aleatoriedade
	
	srand(time(NULL));
	
	//construcao do vetor
	for(i = 0 ; i < 100000 ; i++) {
		vetor[i] = rand();
	}
	
	//realizacao de pesquisa
	while (parametrodepesquisa != -99) {
		printf("digite o parametro de pesquisa: ");
		scanf("%d", &parametrodepesquisa);
	
		for (i = 0 ; i < 100000 ; i++) {
			if(parametrodepesquisa == vetor[i]) {
				printf("achei no indice: %d\n", i);
				break;
			}
		}
	}
}
