#include <stdio.h>

void torreHanoi(int n);


int main(){

	torreHanoi(3);

	return 0;
}


void torreHanoi(int n){
	int torreA[n];
	int torreB[n];
	int torreC[n];

	for(int i = 0; i < n; i++){		// inicialização
		torreA[i] = n - i;
		printf("\ntorreA[%d] = %d", i, torreA[i]);
	}
	
	
	

}
