/*
 Objetos esféricos, como bolas de canhão, podem ser empilhadas em uma pirâmide com 1 bola
no topo, sobre uma base quadrada composta de 4 bolas, sobre uma base quadrada composta de 9
bolas, e assim por diante. Escreva uma função recursiva chamada de “bolas_de_canhao”
que recebe como argumento a altura a da pirâmide e retorna o número de bolas de canhão que
essa pirâmide contém.

*/

#include <stdio.h>

int bolas_de_canhao(int h);

int main(){


	for(int i = 0; i < 5; i++){
		printf("\npiramide (h = %d) = %d", i, bolas_de_canhao(i));
	}

	return 0;
}

int bolas_de_canhao(int h){
	
	if(h == 0){
		return 0;
	} else if(h == 1){
		return 1;
	}else{
		return (h * h) + bolas_de_canhao(h - 1);
	}
	
}

