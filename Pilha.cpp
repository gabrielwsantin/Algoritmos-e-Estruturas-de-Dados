//programa que implementa uma pilha: politica FILO
#include <stdio.h>
#include <stdlib.h>

//declaração da estrutura do nó
struct no {
	int numero;
	struct no *proximo;
};

//funcao que insere um no na pilha
struct no *push(struct no *cabeca, int numero) {
	//criacao de um novo no
	struct no *novoNo = (struct no *) malloc(sizeof(struct no));
	novoNo -> numero = numero;
	novoNo -> proximo = cabeca;
	
	return novoNo;
}

//funcao que remove um no na pilha
struct no *pop(struct no *cabeca) {
	//caso muito facil: pilha vazia
	if (cabeca == NULL) {
		return NULL;
	}

	//caso muito facil: pilha NAO vazia
	printf("%d\n", cabeca -> numero);
	struct no *limpa = cabeca;
	cabeca = cabeca -> proximo;
	free(limpa);
	return cabeca;
}

//funcao principal de execucao do programa
int main() {
	
	//declaracao de variaveis
	struct no *cabeca = NULL;
	int i = 0;
	
	//processamento
	for (i = 0 ; i < 1000 ; i++) {
		cabeca = push(cabeca, i);
	}
	
	for (i = 0 ; i < 1000 ; i++) {
		cabeca = pop(cabeca);
	}
}

//obs: a pilha eh mais rapida
