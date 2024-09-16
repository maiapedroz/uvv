/*

Fazer um programa que liste os mnemonicos telefonicos de um numero

*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void listar_mnemonicos(char *str);
void mecanismo(char *str, int len);

int main(){

	listar_mnemonicos("723");

	return 0;
}

void listar_mnemonicos(char *str){
	
	char str2[50];
	
	strncpy(str2, str, sizeof(str2));	// criar array seguro para mexer

	for(int i = 0; i < strlen(str2); i++){	// inicialização
		str2[i] = 'A' + 3*(str2[i] - 50);
	}

	printf("\nstring inicial = %s\n", str2);
	
	mecanismo(str2, strlen(str2));
}

void mecanismo(char *str, int len){
	if(strlen(str) < 2){
		int i = 1;
		char aux = str[0];
		while(i < 4){		// precisa mudar 2x (pois a "3ª" é a de entrada)

			if(str[0] == 81 || str[0] == 90){		//pular Q e Z
				aux = str[0];
				str[0] = aux + i;
				printf("%s\n", str - (len - strlen(str)));
				i++;
			} else{
				printf("%s\n", str - (len - strlen(str)));
				str[0] = aux + i;
				i++;
			}
		}
		printf("\n");
		str[0] = aux;
		
		return;
	} else{
		mecanismo(str + 1, len);
		int i = 1;
		char aux = str[0];
		char aux2 = str[0];		// pra quando tiver Q ou Z
		while(i < 3){		// precisa mudar 2x (pois a "3ª" é a de entrada)

			if(str[0] == 80 || str[0] == 89){		//pular Q e Z
				aux2++;
				str[0] = aux2 + i;
				
				mecanismo(str + 1, len);
				
				i++;
			} else{
				str[0] = aux2 + i;
				mecanismo(str + 1, len);
				
				i++;
			}
		}
		str[0] = aux;
		return;
	}
}
