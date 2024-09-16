/*

(a) O número mínimo de movimentos para solucionar a Torre de Hanoi é dado por 2n − 1, onde n
é o número de discos na torre. Escreva um procedimento recursio que calcula esse número de
movimentos individuais para a solução da Torre de Hanoi. Lembre-se: seu procedimento deve
ser recursivo!

*/


#include <stdio.h>

int torreHanoi(int n);


int main(){

	int n;

	printf("Insira o tamanho da torre de Hanoi: "); scanf("%d", &n); 
	printf("\n\nPassos para solucionar a torre de Hanoi(n = %d): %d\n", n, 
	torreHanoi(n));



	return 0;
}


int torreHanoi(int n){

	if(n == 1){
		return 1;
	} else{
		return (2*torreHanoi(n - 1)) + 1;
	}
}
