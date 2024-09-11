/*

A raiz digital de um número inteiro não negativo n é definida como o resultado de somar repe-
tidamente seus dígitos, até que um único dígito seja obtido. Por exemplo: a raiz digital de 1729
pode ser obtida seguindo-se os passos a seguir:
1: 1 + 7 + 2 + 9 = 19
2: 1 + 9 = 10
3: 1 + 0 = 1
Como o total ao final do terceiro passo foi o único dígito “1”, esse é o valor da raiz digital.
Escreva a função “int raiz_digital (int n);”, que recebe como argumento um nú-
mero inteiro não negativo e retorna sua raiz digital. Embora seja fácil implementar a função
raiz_digital usando a função somar_digitos do exercício anterior e um loop while,
lembre-se de que você não pode utilizar nenhum loop em seus programas e, portanto, parte do
desafio neste problema é escrever esta função em termos totalmente recursivos, sem usar ne-
nhuma estrutura de repetição em seu programa.

*/

#include <stdio.h>

int raiz_digital (int n);
int somar_digitos(int n);

int main(){


	printf("raiz_digital(1723) = %d", raiz_digital(1723));

	return 0;
}

int raiz_digital (int n){

	if(n < 0)
		return -1;
	else if(n < 10)
		return n;
	else
		return raiz_digital(somar_digitos(n));
}


int somar_digitos(int n){

	if(n < 10){
		return n;
	} else {
		return (n % 10) + somar_digitos(n / 10);
	}
}
