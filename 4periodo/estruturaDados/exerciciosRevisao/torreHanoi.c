#include <stdio.h>

void torreHanoi(int n);
void moverPeca(int *origem, int tamanho, int *destino);

int main(){

	torreHanoi(3);

	return 0;
}


void torreHanoi(int n){
	int torreA[n] = {0};
	int torreB[n] = {0};
	int torreC[n] = {0};
	int k = 0;

	for(int i = 0; i < n; i++){		// inicialização
		torreA[i] = n - i;
		//printf("\ntorreA[%d] = %d", i, torreA[i]);
	}
	
	
	
	

}


void moverPeca(int *origem, int tamanho, int *destino){
	for(int i = 0; i < tamanho; i++){
		//if (origem[i] != 0)
	}

}
