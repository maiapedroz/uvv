/*
O maior divisor comum (mdc) de dois números inteiros não negativos é o maior número inteiro
que divide uniformemente os outros dois números. Em 300 a.C. o matemático grego Euclides
descobriu que o mdc de x e y poderia ser obtido da maneira como se segue:
• Se x for uniformemente divisível por y, então y é o mdc;
• Caso contrário, o mdc entre x e y será sempre igual ao mdc entre y e o resto da divisão de
x por y.
Utilize o método de Euclides para definir a função “int gcd (int x, int y);”, que
calcula o maior divisor comum entre x e y.
*/

#include <stdio.h>


int mdc(int x, int y);

int main(){
	
	printf("mdc 35, 10 = %d", mdc(35, 10));
	
	return 0;
}

int mdc(int x, int y){
	
	int resto = x % y;
	
	if(x % y == 0){
		return y;
	} else {
		return mdc(y, resto);
	}
}
