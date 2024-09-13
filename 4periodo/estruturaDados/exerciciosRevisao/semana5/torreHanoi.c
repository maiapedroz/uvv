#include <stdio.h>

void torreHanoi(int n);
void moverPeca(int *origem, int Ox, int *destino, int Dx);
int pegarOrigem(int *origem, int n);
int pegarDestino(int *destino, int n);
void passo(int *origem, int *destino, int *auxiliar, int n);
void qualDestino(int *origem, int *destino, int *auxiliar, int n);


int main(){

	torreHanoi(1);

	

	return 0;
}


void torreHanoi(int n){
	int origem[n];			
	int destino[n];
	int auxiliar[n];
	int total = 0;

	for(int i = 0; i < n; i++){		// inicialização
		origem[i] = n - i;
		destino[i] = 0;
		auxiliar[i] = 0;
		printf("\norigem[%d] = %d", i, origem[i]);
		printf("\ndestino[%d] = %d", i, destino[i]);
		printf("\nauxiliar[%d] = %d\n", i, auxiliar[i]);
	}
	
	
	while(destino[n-1] == 0){
		
		passo(origem, destino, auxiliar, n);
		
		total++;
		
	}
	printf("\ntotal = %d", total);
	
	for(int i = 0; i < 3; i++){
		printf("\norigem[%d] = %d", i, origem[i]);
		printf("\ndestino[%d] = %d", i, destino[i]);
		printf("\nauxiliar[%d] = %d\n", i, auxiliar[i]);
	}
	
}


void moverPeca(int *origem, int Ox, int *destino, int Dx){

	destino[Dx] = origem[Ox];
	origem[Ox] = 0;
}

int pegarOrigem(int *origem, int n){
	for(int i = n - 1; i >= 0; i--){
		if(origem[i] != 0){
			return i;
		}
	}

}
int pegarDestino(int *destino, int n){

	for(int i = 0; i < n; i++){
		if(destino[i] == 1){
			//printf("\nERRO");
			return -1;
		}
		if(destino[i] == 0){
			return i;
		}
	}
	
	
}

void passo(int *origem, int *destino, int *auxiliar, int n){

		int Oo, Od, Oa;	// indices quando for origem
		int Do, Dd, Da;	// indices quando for destino
		
		Oo = pegarOrigem(origem, n);
		Dd = pegarDestino(destino, n);	//destino quando for de origem para destino
		//printf("\nOo = %d\nDd = %d", Oo, Dd);
		
		Od = pegarOrigem(destino, n);
		Da = pegarDestino(auxiliar, n);	//destino quando for de destino para auxiliar
		//printf("\nOd = %d\nDa = %d", Od, Da);
		
		Oa = pegarOrigem(auxiliar, n);
		Do = pegarDestino(origem, n);	//destino quando for de auxiliar para origem
		//printf("\nOa = %d\nDo = %d", Oa, Do);		
		
		if(Dd != -1){
			if(origem[Oo] < destino[Dd] || destino[0] == 0){
				moverPeca(origem, Oo, destino, Dd);
			} else if(Da != -1){
				if(destino[Od] < auxiliar[Da] || auxiliar[0] == 0){
					moverPeca(destino, Od, auxiliar, Da);
				} else if(Do != -1){
					if(auxiliar[Oa] < origem[Do] || origem[0] == 0){
						moverPeca(auxiliar, Oa, origem, Do);
					}
				}
			}
		}
		
}
