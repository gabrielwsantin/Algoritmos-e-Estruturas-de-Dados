#include <stdio.h> //lista duplamente encadeada
#include <stdlib.h>

//declaracao da estrutura

struct no {
	int numero;
	struct no *anterior;
	struct no *proximo;
};

//funcao que insere um no na lista

struct no *inserir(struct no *cabeca, int numero) {
//numa funcao o que esta escrito antes eh o que ela entrega e depois eh o que ela devolve

	//criacao do novo no
	struct no *novoNo = (struct no *) malloc(sizeof(struct no));
	novoNo -> numero = numero; //o da esquerda esta dentro do novo no e o posterior o argumento
	novoNo -> anterior = NULL;
	novoNo -> proximo = cabeca;
	
	//ajuste do apontamento da cabeca
	cabeca = novoNo;
	
	//ajuste do ponteiro anterior do segundo no
	if (cabeca -> proximo != NULL) {
		cabeca -> proximo -> anterior = cabeca; //	cabeca -> proximo (segundo) -> anterior = cabeca (primeiro);
	}
	
	
	//retorno da cabeca atualizada
	return cabeca;

}

//funcao que exclui um no da lista
struct no *excluir(struct no *cabeca, int numero) {
	
	//cenario facil (lista vazia)
	if (cabeca == NULL) {
		return NULL;

	}
	
	//cenario facil (exclui o unico)
	if (cabeca -> numero == numero) {
		struct no *limpa = cabeca;
		cabeca = cabeca -> proximo;
		free(limpa); //alem do free tem que corrigir o ponteiro
		if (cabeca != NULL) { //cenario facil (exclui o NAO unico)
			cabeca -> anterior = NULL;
		}
		return cabeca;
	}
	
	//procura do no a ser excluido
	struct no *ponteiro = cabeca;
	while ((ponteiro != NULL) && (ponteiro -> numero != numero)) {
		ponteiro = ponteiro -> proximo;
	}
	
	//cenario dificil (nao encontrei o numero na lista)
	if (ponteiro == NULL) {
		return cabeca;
		
	}
	
	//cenario dificil (excluir o ultimo)
	ponteiro -> anterior -> proximo = ponteiro -> proximo;
	if (ponteiro -> proximo != NULL) {	//cenario dificil (excluir o do meio)
		ponteiro -> proximo -> anterior = ponteiro -> anterior;
	}
	free(ponteiro);
	
	//retorno da cabeca atualizada
	return cabeca;
}

//funcao que imprime a lista
void imprimir (struct no *cabeca) {
	struct no *ponteiro = cabeca;
	while (ponteiro != NULL) {
		printf("%d\n", ponteiro -> numero);
		ponteiro = ponteiro -> proximo;
	}	
}

//funcao principal de execucao do programa
int main() {
	struct no *cabeca = NULL;
	
	//primeiro teste
	imprimir(cabeca);
	cabeca = excluir(cabeca, 0);
	
	cabeca = inserir(cabeca, 1);
	cabeca = inserir(cabeca, 2);
	cabeca = inserir(cabeca, 3);
	cabeca = inserir(cabeca, 4);
	cabeca = inserir(cabeca, 5);
	imprimir(cabeca);
	
	printf("\n");
	
	cabeca = excluir(cabeca, 0);
	cabeca = excluir(cabeca, 1);
	cabeca = excluir(cabeca, 3);
	cabeca = excluir(cabeca, 5);
	imprimir(cabeca);
	
	cabeca = excluir(cabeca, 2);
	cabeca = excluir(cabeca, 4);
	imprimir(cabeca);
}
