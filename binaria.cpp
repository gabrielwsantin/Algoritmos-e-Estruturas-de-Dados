#include <stdio.h> //binaria

int main() {
	//declaracao de variavel
	int i;
	int vetor[100000];
	int inicio;
	int meio;
	int fim;
	int parametropesquisa;
	int contador;
	
	//construcao do vetor
	for (i = 0 ; i < 100000 ; i++) {
		vetor[i] = i;
		
	}
	
	//realizacao de pesquisas
	while (parametropesquisa != -99) {
		printf("digite o parametro de pesquisa: ");
		scanf("%d", &parametropesquisa);
		
		inicio = 0;
		fim = 99999;
		contador = 0;
		
		while (inicio <= fim) {
			meio = ((inicio + fim) / 2);
			contador++;
			
			if (parametropesquisa == vetor[meio]) {
				printf("achei na tentativa e numero: %d\n", contador);
				break;
			} else if (parametropesquisa < vetor[meio]) {
		 		fim = (meio - 1);
			} else {
				inicio = (meio + 1);
			}
		}
		
	}
	
}
