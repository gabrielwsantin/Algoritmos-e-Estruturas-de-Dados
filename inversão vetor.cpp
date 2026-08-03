#include <stdio.h>

	int main(){
		//declaração de variável
		int vetorOriginal[5];
		int vetorInvertido[5];
		int i;
		
		//entrada de dados
		for (int i = 0 ; i < 5 ; i++) {
			printf("Digite o valor da posição %d: ", i);
			scanf("%d", &vetorOriginal[i]);
			
		}
		//processamneto
		for (int i = 0 ; i < 5 ; i++) {
			vetorInvertido[5 - 1 - i] = vetorOriginal[i]; //importante [5 - 1 - i]
		}
		
		//saída de dados
		for (int i = 0 ; i < 5 ; i++) {
		
		printf ("vetorInvertido[%d] = %d\n", i, vetorInvertido[i]);
		
		}
		//Conclusão
		return 0;
	}
