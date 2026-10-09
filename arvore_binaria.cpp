#include <stdio.h> // arvore binaria
#include <stdlib.h>
#include <time.h>

struct no { // declaracao da estrutura do no
	int numero;
	struct no *esquerda;
	struct no *direita;
};

struct no *inserir(struct no *raiz, int numero) {
	// cenario facil: arvore vazia
	if (raiz == NULL) {
		// criacao do novo no
		struct no *novoNo = (struct no *) malloc(sizeof(struct no));
		novoNo -> numero = numero;
		novoNo -> esquerda = NULL;
		novoNo -> direita = NULL;
		
		return novoNo;
	}
	
	// cenario dificil: arvore nao vazia
	int sorteio = (rand() % 2);
	if (sorteio) {
		raiz -> esquerda = inserir(raiz -> esquerda, numero);
	} else {
		raiz -> direita = inserir(raiz -> direita, numero);
	}
	
	return raiz;
}

// funcao que faz a navegacao pre-ordem
void navegarPreOrdem(struct no *raiz) {
	if (raiz == NULL) return; //protecao
	
	printf("%d", raiz -> numero);
	navegarPreOrdem(raiz -> esquerda);
	navegarPreOrdem(raiz -> direita);
}

void navegarEmOrdem(struct no *raiz) {
	if (raiz == NULL) return; //protecao
	
	navegarEmOrdem(raiz -> esquerda);
	printf("%d", raiz -> numero);
	navegarEmOrdem(raiz -> direita);
}

void navegarPosOrdem(struct no *raiz) {
	if (raiz == NULL) return; //protecao
	
	navegarPosOrdem(raiz -> esquerda);
	navegarPosOrdem(raiz -> direita);
	printf("%d", raiz -> numero);
}

int main() {
	// declaracao de variaveis
	int i = 0;
	struct no *raiz = NULL;
	
	//inicializacao da aleatoriedade
	time_t t;
	srand(time(&t));
	
	//inclusao de nos na arvore
	for (i = 0 ; i < 10 ; i++) {
		raiz = inserir(raiz, i);
	}

	//navegacoes
	printf("Pre-Ordem; ");
	navegarPreOrdem(raiz);
	printf("\n");
	printf("Em-Ordem; ");
	navegarEmOrdem(raiz);
	printf("\n");
	printf("Pos-Ordem; ");
	navegarPosOrdem(raiz);
	printf("\n");

}




