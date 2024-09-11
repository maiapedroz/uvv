/*
 * Criar a função IntegerToString recursivamente
*/

#include <stdio.h>
#include <string.h>

#define MaxDigits 30
#define Base 10


char *IntegerToString(int n);
int resto(int n);
int divisao(int n);

int main(){
	
	
	printf("\n30 para string: %s", IntegerToString(200));


	return 0;
}

char *IntegerToString(int n){
	static char str[30];
	char str2[30];
	
	if(n < 10){
		char temp2[1];
		temp2[0] = (char) (n + 48);
		printf("\nstr = %s", str2);
		strcat(str2, temp2);
		printf("\ntemp2 = %c", temp2[0]);
		printf("\nstr = %s", str2);
		printf("\nn = %d", n);
		
		strcpy(str, str2);
		return str;
	}else{
		
		char temp[1];
		temp[0] = (char) (divisao(n) + 48);
		strcat(str2, temp);
		printf("\nstr = %s", str2);
		printf("\nn = %d", n);
		printf("\nn %% 10 = %d", n% 10);
		printf("\nn / 10 = %d", n / 10);
		printf("\ndivisao(n) = %d", divisao(n));
		
		strcat(str2, IntegerToString(n / 10));
		if((n/10) * 10 != n){
			printf("oi");
			strcat(str2, IntegerToString(n % 10));
		}
		strcpy(str, str2);
		return str;
	}
	
}

int divisao(int n){

	if(n < 10){
		return n;
	}else{
		return divisao(n / 10);
	}
}
