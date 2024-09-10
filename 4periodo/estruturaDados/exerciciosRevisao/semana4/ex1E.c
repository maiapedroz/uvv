#include <stdio.h>


int somar_digitos(int n);

int main(){

	printf("somatoria dos digitos de 1729 : %d", somar_digitos(1729));	
	
	return 0;
}

int somar_digitos(int n){

	if(n < 10){
		return n;
	} else {
		return (n % 10) + somar_digitos(n / 10);
	}
}
