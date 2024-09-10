/*
Escreva um programa que lê um número inteiro informado pelo usuário e imprime um número
inteiro com a mesma quantidade de algarismos, mas em ordem reversa. Se o usuário informar
“1234567890”, seu programa deve imprimir “0987654321”. Note que zeros à esquerda devem
ser impressos.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void intToString(int num, char* str, size_t size);
int recursivaNotacao(int n);
int inverte(int n);



int main(void){
	int x;
	int y;
	printf("Insira um inteiro: ");
	scanf("%d", &x);
	y = x;
	x = inverte(x);

	printf("\n%0*d", recursivaNotacao(y), x);

	return 0;
}




int inverte(int n){
	int qtd = recursivaNotacao(n);
	char str[qtd];
	char str2[qtd];
	int retorno;

	intToString(n, str, qtd + 1);
	strcpy(str2, str);

	for(int i = 0; i < qtd; i++){
		str2[qtd - i - 1] = str[i];
	}
	
	retorno = atoi(str2);

	return retorno;
}

int recursivaNotacao(int n){
	
	if(n<10){
		return 1;
	}
	else{
		return 1 + recursivaNotacao(n / 10);
	}
}

void intToString(int num, char* str, size_t size){
	snprintf(str, size, "%d", num);
}

