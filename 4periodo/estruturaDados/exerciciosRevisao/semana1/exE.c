/*

Cada número inteiro positivo maior do que 1 pode ser expresso como o produto de números
primos. Essa fatoração é única e é chamada de decomposição em fatores primos (prime facto-
rization). Por exemplo, o número 60 pode ser decomposto nos fatores 2 × 2 × 3 × 5, cada um
dos quais é primo. Note que o mesmo número primo pode aparecer mais de uma vez em uma
fatoração.
Escreva um programa que recebe um número inteiro N > 1 informado pelo usuário, e retorne a
fatoração desse número. Seu programa deve imprimir a fatoração completa, utilizando asteriscos
para indicar a multiplicação. Por exemplo, se o usuário informar 60, seu programa deve exibir:

*/

#include <stdio.h>

#define MAX_FATORES 10

void fatoracao(int n, int *ptr);


int main(void){
    int fatores[MAX_FATORES];

	fatoracao(60, fatores);

    return 0;
}


void fatoracao(int n, int *ptr){
	int i = 0;      // quantidade de fatores

	while(n % 2 == 0){
		*(ptr + i) = 2;
		i++;
		n /= 2;
	}

	for(int j = 3; j * j <= n; j += 2){
		while(n % j == 0){
		    if(i < MAX_FATORES) {
			    *(ptr + i) = j;
    			i++;
    			n /= j;
    		}
		}
	}


	if (n > 2 && i < MAX_FATORES) {
        	*(ptr + i) = n;
        	i++;
	}
	
	for (int k = 0; k < i; k++) {
		if(k==0){
			printf("%d", ptr[k]);
		}else{
			printf(" %d", ptr[k]);
		}
		if(k != i - 1){
			printf(" *");
		}
    }
}
