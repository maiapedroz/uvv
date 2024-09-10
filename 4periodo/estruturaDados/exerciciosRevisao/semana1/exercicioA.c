/*Escreva um programa que lê um número inteiro positivo N e então calcule e exiba na tela a soma
dos primeiros N inteiros ímpares. Por exemplo: se N = 4, seu programa deve exibir 16, que é
1 + 3 + 5 + 7.
*/

#include <stdio.h>

void somaImpar(int n);

int main(void){
	somaImpar(1);
	somaImpar(2);
	somaImpar(3);
	somaImpar(4);
	return 0;
}


void somaImpar(int n){
	int i = 0;
	int soma = 0;
	int valor = 1;
	while(i<n){
		if(valor % 2 == 1){
			soma = soma + valor;
			i++;
		}

		valor = valor + 2;
	}
	printf("Soma de %i inteiros impares: %i\n\n", n, soma);
}
	
