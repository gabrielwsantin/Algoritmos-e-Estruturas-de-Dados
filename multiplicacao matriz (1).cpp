#include <stdio.h>

#define LINHA  2
#define COLUNA  2
#define SOMATORIO  3

int main(){
	// declaração de variaveis
	int operando1[LINHA][SOMATORIO];
	int operando2[SOMATORIO][COLUNA];
	int resultado[LINHA][COLUNA];
	int i;
	int j;
	int k;	
	
	//entrada de dados
	for (i = 0; i < LINHA ; i++) {
		for (j = 0 ; j < SOMATORIO ; j++) {
			printf("operando1[%d][%d] = ", i, j);
			scanf("%d", &operando1[i][j]);	
		}
	}
	for (i = 0; i < SOMATORIO; i++) {
		for (j = 0 ; j < COLUNA ; j++) {
			printf("operando2[%d][%d] = ", i, j);
			scanf("%d", &operando2[i][j]);
		
		}
	}
	//processamento
	for (i = 0 ; i < LINHA; i++) {
		for (j = 0 ; j < COLUNA ; j++) {
			resultado[i][j] = 0;
			for (k = 0 ; k < SOMATORIO ; k++) {
				resultado[i][j] += (operando1[i][k] * operando2[k][j]);
			}	
		}
	}
	//saida de dados
	for (i = 0 ; i < LINHA; i++) {
		for (j = 0 ; j < COLUNA ; j++) {
			printf("%d\t", resultado[i][j]);
		}
		printf("\n");
	}
	//conclusao
	return 0;
}
