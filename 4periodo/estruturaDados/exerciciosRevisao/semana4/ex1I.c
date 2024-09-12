/*
 * Criar a função IntegerToString recursivamente
*/

#include <stdio.h>
#include <string.h>
#include <math.h>

#define MaxDigits 30
#define Base 10


char *IntegerToString(int n);
int resto(int n);
int divisao(int n);
int digito(int n);

int main(){
	
	char str3[MaxDigits];
	
	for(int i = 0; i < 2000; i++){
		strcpy(str3, IntegerToString(i));
		printf("\n%d para string:  %s", i, str3);
	}
	return 0;
}

char *IntegerToString(int n){
	static char str[30];
	char str2[30] = "";
	
	if(n < 10){
		char temp2[2];
		temp2[0] = (char) (n + 48);
		temp2[1] = '\0';
		strcat(str2, temp2);
		
		strcpy(str, str2);
		return str;
	}else{
		char temp[30];
		temp[0] = (char) (digito(n) + 48);
		temp[1] = '\0';
		strcat(str2, temp);
		
		if(divisao(n - digito(n)*(int) pow(10, divisao(n))) != divisao(n) - 1){
			int i;
			for(i = 0; i < divisao(n) - 1 - divisao(n - digito(n)*(int) pow(10, divisao(n))); i++){
				temp[i] = '0';
			}
			temp[i + 1] = '\0';
			strcat(str2, temp);
		}
		
		strcat(str2, IntegerToString(n - digito(n)*(int) pow(10, divisao(n))));
		strcpy(str, str2);
		
		
		return str;
	}
	
}

int divisao(int n){

	if(n < 10){
		return 0;
	}else{
		return 1 + divisao(n / 10);
	}
}

int digito(int n){

	if(n < 10){
		return n;
	}else{
		return digito(n / 10);
	}
}
