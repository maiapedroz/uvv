#include <stdio.h>

void torreHanoi(int n);
void moverPeca(int *origem, int Ox, int *destino, int Dx);
int pegarOrigem(int *origem, int n);
int pegarDestino(int *destino, int n);
void passo(int *origem, int *destino, int *auxiliar, int n);
void qualDestino(int *origem, int *destino, int *auxiliar, int n);


int main(){

	torreHanoi(3);

	

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
		
		//printf("oi");
		passo(origem, destino, auxiliar, n);
		total++;
		//destino[n-1] = 1;
		
		for(int i = 0; i < n; i++){
			printf("\n\norigem[%d] = %d", i, origem[i]);
			printf("\ndestino[%d] = %d", i, destino[i]);
			printf("\nauxiliar[%d] = %d\n", i, auxiliar[i]);
		}
	}
	printf("\ntotal = %d", total);
	
	for(int i = 0; i < n; i++){
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
			//printf("\nn = %d", n);
			//printf("\ni = %d", i);
			return i;
		}
	}
	return 0;
}
int pegarDestino(int *destino, int n){

	for(int i = 0; i < n; i++){
		if(destino[i] == 0){
			return i;
		}
	}
	
	return 0;
	
	
}

void passo(int *origem, int *destino, int *auxiliar, int n){

		int Oo, Od, Oa;	// indices quando for origem
		int Do, Dd, Da;	// indices quando for destino
		
		Oo = pegarOrigem(origem, n);
		Dd = pegarDestino(destino, n);	//destino quando for para destino
		//printf("\nOo = %d\nDd = %d", Oo, Dd);
		
		Od = pegarOrigem(destino, n);
		Da = pegarDestino(auxiliar, n);	//destino quando for para auxiliar
		//printf("\nOd = %d\nDa = %d", Od, Da);
		
		Oa = pegarOrigem(auxiliar, n);
		Do = pegarDestino(origem, n);	//destino quando for para origem
		//printf("\nOa = %d\nDo = %d", Oa, Do);		
		if(n % 2 == 1){
			if(origem[0] != 0){
				if(destino[0] == 0 || origem[Oo] < destino[Dd - 1]){	// A PORRA DO ERRO TA AQUI
					moverPeca(origem, Oo, destino, Dd);		// mover origem para destino
					printf("\norigem para destino");
					return;
				} else if(auxiliar[0] == 0 || origem[Oo] < auxiliar[Da - 1]){
					moverPeca(origem, Oo, auxiliar, Da);	// mover origem para auxiliar
					printf("\norigem para auxiliar");
					return;
				}
			}
			
			if(auxiliar[Oa] != 0 && auxiliar[Oa] < destino[Dd - 1]){
				printf("\nAuxiliar -> Destino 2");
				moverPeca(auxiliar, Oa, destino, Dd);
				return;
			}
			
			if(destino[0] != 0 && destino[Od] != n - Od){
				printf("\nDa = %d",Da);
				printf("\nOd = %d",Od);
				if(auxiliar[0] == 0 || destino[Od] < auxiliar[Da - 1]){
					printf("\nDestino -> Auxiliar");
					moverPeca(destino, Od, auxiliar, Da);	//mover destino para auxiliar
					return;
				} else if(origem[0] == 0 || destino[Od] < origem[Do - 1]){
					printf("\nDestino -> Origem");
					moverPeca(destino, Od, origem, Do);		// mover destino para origem
					return;
				}
			}
			printf("\ncontinua?");
			if(auxiliar[0] != 0){
				if(origem[0] == 0 || auxiliar[Oa] < origem[Do - 1]){
					printf("\nAuxiliar -> Origem");
					moverPeca(auxiliar, Oa, origem, Do);	//mover auxiliar para origem
					return;
				} else if(destino[0] == 0 || auxiliar[Oa] < destino[Dd - 1]){
					printf("\nAuxiliar -> Destino");
					moverPeca(auxiliar, Oa, destino, Dd);	// mover auxiliar para destino
					return;
				}
			}
		} else{
			if(origem[0] != 0){
				if(destino[0] == 0 || origem[Oo] < destino[Dd]){	// A PORRA DO ERRO TA AQUI
					moverPeca(origem, Oo, destino, Dd);		// mover origem para destino
					return;
				} else if(auxiliar[0] == 0 || origem[Oo] < auxiliar[Da]){
					moverPeca(origem, Oo, auxiliar, Da);	// mover origem para auxiliar
					return;
				}
			}
			
			if(destino[0] != 0){
				if(auxiliar[Da] == 0 && destino[Od] < auxiliar[Da - 1]){
					moverPeca(destino, Od, auxiliar, Da);	//mover destino para auxiliar
					return;
				} else if(origem[Do] == 0 && destino[Od] < origem[Do - 1]){
					moverPeca(destino, Od, origem, Do);		// mover destino para origem
					return;
				}
			}
			// quando auxiliar[0] != 0
			if(origem[Do] == 0 && auxiliar[Oa] < origem[Do - 1]){
				printf("Auxiliar -> Origem");
				moverPeca(auxiliar, Oa, origem, Do);	//mover auxiliar para origem
				return;
			} else if(destino[Dd] == 0 && auxiliar[Oa] < destino[Dd - 1]){
				moverPeca(auxiliar, Oa, destino, Dd);	// mover auxiliar para destino
				return;
			}
		}
}
