


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *reverter (char *str);
char *trocar_letra(char *str, int n);

int main(){

	printf("%s", reverter("programa"));
	
	return 0;
}

char *reverter (char *str){
	char str2[strlen(str)];
	char temp = str[0];
	
	
	
	if(strlen(str) == 1){
		return str;
	}else{
	
		strcpy(str2,str);
		
		for(int i = 0; i < strlen(str2) - 1; i++){
			trocar_letra(str2, i);
		}
		
		if(strlen(str2) > 1){
			str2[strlen(str) - 1] = '\0';
		}
		str = reverter(str2);
		
		str[strlen(str)] = temp;
		str[strlen(str) + 1] = '\0';
		
		return str;
	}
}

char *trocar_letra(char *str, int n){
	char temp;
	if(strlen(str) == 1){
		return str;
	}
	if(n < strlen(str) - 1){
		temp = str[n];
		str[n] = str[n+1];
		str[n+1] = temp;
	}
	return str;
}
