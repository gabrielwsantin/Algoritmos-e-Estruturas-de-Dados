//Árvore
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//declaracao da estrutura

struct no {
	int numero;
	struct no *filho1;
	struct no *filho2;
	struct no *filho3;
	struct no *filho4;
	struct no *filho5;
};

//funcao que insere um no na arvore

struct no *inserir(struct no *raiz, int numero) {
	// cenario facil: arvore vazia
	if (raiz == NULL) {
		struct no *folha = (struct no *) malloc(sizeof(struct no));
		folha -> numero = numero;
		folha -> filho1 = NULL;
		folha -> filho2 = NULL;
		folha -> filho3 = NULL;
		folha -> filho4 = NULL;
		folha -> filho5 = NULL;
		return folha;
	}
	//cenario difícil: arvore NAO vazia
	int sorteio = (1 + (rand() % 5));
	
	if (sorteio == 1) {
		raiz -> filho1 = inserir(raiz -> filho1, numero);
	} else if (sorteio == 2) {
		raiz -> filho2 = inserir(raiz ->filho2, numero);
	} else if (sorteio == 3) {
		raiz -> filho3 = inserir(raiz ->filho3, numero);
	} else if (sorteio == 4) {
		raiz -> filho4 = inserir(raiz ->filho4, numero);
	} else {
		raiz -> filho5 = inserir(raiz ->filho5, numero);
	}
	return raiz;
}
// funcao que imprime a arvore na tela

void imprimir(struct no *raiz, char *indentacao) {
	if (raiz == NULL) return;
	
	printf("%s%d\n", indentacao, raiz -> numero);
	
	char *temp = (char *) malloc (1024 *sizeof(char));
	strcpy(temp, indentacao);
	strcat(temp, "---");
	
	imprimir(raiz -> filho1, temp);
	imprimir(raiz -> filho2, temp);
	imprimir(raiz -> filho3, temp);
	imprimir(raiz -> filho4, temp);
	imprimir(raiz -> filho5, temp);
}
//funcao principal de execucao do programa
int main () {
	//declaarcao de variaveis
	struct no *raiz = NULL;
	int i;
	
	//inicializacao da aleatoriedade
	time_t t;
	srand(time(&t));
	
	//insercao de nos na arvore
	for (i = 0 ; i < 10 ; i++) {
		raiz = inserir(raiz, i);
	}
	
	//impressao da arvore
	char *indentacao = (char *) malloc (1024 * sizeof(char));
	strcpy(indentacao, "");
	imprimir(raiz, indentacao);
}

