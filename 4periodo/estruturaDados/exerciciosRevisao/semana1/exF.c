/*
 matemático alemão Leibniz (1646–1716) descobriu um fato importante de que o número ir-
racional π pode ser calculado utilizando-se a seguinte equação:

A fórmula à direita do sinal de igualdade é uma série infinita; cada fração representa um termo
nessa série. Se você iniciar com 1, subtrair um terço, somar um quinto, subtrair um sétimo e
assim por diante, para cada um dos números ímpares, você obtém um número que é cada vez
mais próximo do valor de π/4.
Escreva um programa que calcule uma aproximação do valor de pi, utilizando os primeiros dez
mil termos na série de Leibniz. No final seu programa deve imprimir o valor aproximado de π
com 20 casas decimais.

*/


#include <stdio.h>
#include <math.h>

#define META 10000
float leibniz(int n);

int main(){

	printf("Série de Leibniz (n = %d):	%.20f", META, leibniz(META));

	return 0;
}



float leibniz(int n){
	float valor = 1.00;
	
	for(int i = 0; i < n; i++){
		if(i % 2 == 1){
			valor = valor - (1.0 / (2.0*i + 1.0));
		} else if(i != 0){
			valor = valor + (1.0 / (2.0*i + 1.0));
		}
	}
	
	valor *= 4;
	
	return valor;
	
}
