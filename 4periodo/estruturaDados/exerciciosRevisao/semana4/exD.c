/*

Para cada uma das duas implementações da função “fib(n)” que estudamos nesse capítulo
(uma primeira implementação que não era eficiente e uma segunda implementação mais efici-
ente), escreva funções recursivas chamadas de “contagem_fib1” e “contagem_fib2”
que conta o número de chamadas recursivas feitas durante a execução de cada função na obtenção
de um determinado número de Fibonacci. Escreva um programa que utiliza essas funções para
mostar uma tabela com o número de chamadas recursivas que cada algoritmo faz para diversos
valores de n, conforme ilustrado abaixo:

*/

#include <stdio.h>

#define N 16

int fib_rec(int n);
int seq_adit(int n, int t0, int t1);
int fib(int n);
int contagem_fib1(int n);
int mecanismo(int n);
int contagem_fib2(int n);


int main(void){

	printf("Número de chamadas recursivas:\n N	Fib1	Fib2\n--	----	----");

	for(int i = 0; i < N; i++){
		printf("\n%2d	%4d	%4d", i, contagem_fib1(i), contagem_fib2(i));
	}

	return 0;
}

int contagem_fib1(int n){
	if(n == 0){
		return 1;
	} else if(n == 1){
		return 1;
	}else {
		return mecanismo(n) + contagem_fib1(n - 1); //recursividade para somar
	}
}

int mecanismo(int n){
	
	if(n < 0) return -1;
	if(n < 4) return 2;
	return seq_adit(n - 2, 2, 2);
}

int seq_adit(int n, int t0, int t1){
	if (n < 0)	return -1;
	if (n == 0)	return t0;
	if (n == 1)	return t1;
	return seq_adit(n - 1, t1, t0 + t1);
}


int contagem_fib2(int n){
	
	if(n == 0 || n == 1){
		return 2;
	} else {
		return contagem_fib2(n-1) + 1;
	}
}








int fib_rec(int n){
	if (n < 0)
		return -1;
	else if (n < 2)
		return n;
	else
		return fib_rec(n - 1) + fib_rec(n - 2);
}



int fib(int n){
	if (n < 0) return -1;
	return seq_adit(n, 0, 1);
}
