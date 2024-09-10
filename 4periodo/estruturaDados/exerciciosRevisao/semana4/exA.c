/*
Ao contrário de muitas linguagens, C não possui um operador primário para calcular a potência
de algum número, por exemplo, calcular nk. Como uma solução parcial para o problema, defina
a função recursiva cuja declaração é
int potencia (int n, int k);
e que calcula nk. Talvez seja útil você se lembrar da propriedade matemática de que

*/

#include <stdio.h>


int potencia(int n, int k);

int main(){
	int n;
	int k;
	
	printf("Informe n: ");
	scanf("%d", &n);
	printf("Informe k: ");
	scanf("%d", &k);
	
	printf("resultado = %d", potencia(n, k));
	
	return 0;
}

int potencia(int n, int k){
	
	if(k == 0){
		return 1;
	} else{
		return (n * potencia(n, k-1));
	}
}

