/* Escreva um programa que lê uma lista de inteiros informados pelo usuário (um número a cada
linha) até que o usuário informe 0 como um valor sentinela. Quando o sentinela for digitado, seu
programa deve exibir o maior valor da lista.
*/

#include <stdio.h>

#define SENTINELA 0

void maiorLista();

int main(void){
	maiorLista();

	return 0;
}

void maiorLista(){
	int maior = -99999;
	int valor = -1;
	
	while(valor != SENTINELA){
		printf("\nInsira um novo valor: ");
	        scanf("%d^\n", &valor);
		if(valor>maior){
        	        maior = valor;
	        }
	}

	printf("O maior valor informado eh: %d", maior);
}
