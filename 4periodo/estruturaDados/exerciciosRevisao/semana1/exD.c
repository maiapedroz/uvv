/*
Os matemáticos gregos tinham um interesse especial em números que eram iguais à soma de
seus divisores próprios (um divisor próprio de N é qualquer divisor menor do que o próprio N ).
Eles chamavam esses números de números perfeitos. Por exemplo, 6 é um número perfeito
pois ele é a soma de 1, 2 e 3, que são os inteiros menores do que 6 que também são divisores de
6. So mesmo modo, 28 é um número perfeito pois é a soma de 1, 2, 4, 7 e 14.
Escreva o predicado e_perfeito que recebe um inteiro n e retorna TRUE se n for perfeito,
e FALSE caso contrário. Teste sua implementação utilizando esse predicado na função main
de seu programa, fazendo uma busca por números perfeitos entre 1 e 9999. Quando um número
perfeito for encontrado, seu programa deve imprimir esse número na tela (um número por linha).
As primeiras duas linhas que seu programa exibirá devem mostrar o número 6 e o número 28.
Seu programa deve encontrar outros dois números perfeitos entre 1 e 9999.
*/

#include <stdio.h>
#include <stdbool.h>



#define MAX_FATORES 100
#define MAX_DIVISORES 500
#define META 9999

bool e_perfeito(int n);
int fatoracao(int n, int *ptr);
int acharDivisores(int *fatores, int nfat, int *divisores);
void bubbleSort(int *arr, int n);


int main(){




    for(int i = 1; i < META; i++){
        if(e_perfeito(i)){
            printf("\n%d eh um numero perfeito", i);
        }
    }
	
	return 0;
}

bool e_perfeito(int n){

    int divisores[MAX_DIVISORES] = {0};
    int fatores[MAX_FATORES];
    
    int numFat = fatoracao(n, fatores);
    int numdivisores = acharDivisores(fatores, numFat, divisores);

    int soma = 0;
	bubbleSort(divisores, numdivisores);
    for(int i = 0; i < numdivisores - 1; i++){
	    //printf("\n n = %d   numdivisores = %d   i = %d", n, numdivisores, i);
	    soma = soma + divisores[i];
	}
	
	//printf("soma = %d", soma);
	return (soma == n);
}

int fatoracao(int n, int *ptr){
	int i = 0;      // quantidade de fatores

	while(n % 2 == 0){
		*(ptr + i) = 2;
		i++;
		n /= 2;
	}

	for(int j = 3; j * j <= n; j += 2){
		while(n % j == 0){
		    if(i < MAX_FATORES) {
			    *(ptr + i) = j;
    			i++;
    			n /= j;
    		}
		}
	}


	if (n > 2 && i < MAX_FATORES) {
        	*(ptr + i) = n;
        	i++;
	}
	
	for (int k = i; k < MAX_FATORES; k++) {
        ptr[k] = 0;
    }
	
    return i;
}

int acharDivisores(int *fatores, int nfat, int *divisores){
    int contagem = 0;
	int multiplicacao = 1;                  //total de divisores do numero
    int numDivisores = 1;
	
	for(int j=0; j<=nfat; j++){             //total de divisores do numero
	    if(j==0 ||fatores[j] == fatores[j-1]){
	        contagem++;
	    }
	    else{
	        multiplicacao = (contagem + 1) * multiplicacao;
	        contagem = 1;
	    }
	}
    divisores[0] = 1;
    
	while(numDivisores < multiplicacao){
        for(int i = 0; i < nfat; i++){          // for para ler o array fatores
            int tempNumDiv = numDivisores;
            for(int j = 0; j < tempNumDiv; j++){                 // for para ler o array de divisores descobertos até agora
                int FLAG = 0;
                for(int l = 0; l < multiplicacao; l++){                 //for para ler se no array de divisores descobertos existe o numero que achamos
                    if(fatores[i] * divisores[j] == divisores[l] && (numDivisores +j) < multiplicacao){
                        FLAG = 1;
                    }
                }
                if(FLAG == 0){
                    if(numDivisores < multiplicacao){
                        divisores[numDivisores] = fatores[i] * divisores[j];
                        numDivisores++;
                    }
                }
            }
        }
    }
    return numDivisores;
}


void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Troca arr[j] e arr[j+1]
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
