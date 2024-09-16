#include <stdio.h>

void torreHanoi(int n);
void moverPeca(int *origem, int Ox, int *destino, int Dx);
int pegarOrigem(int *origem, int n);
int pegarDestino(int *destino, int n);
int passo(int *origem, int *destino, int *auxiliar, int n, int ultimaPeca);
int tamanhoSemZeros(int *torre, int n);


int main(){
	
	int n;
	printf("Escolha o tamanho da torre de hanoi: ");
	scanf("%d", &n);
	torreHanoi(n);

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
	}
	
	int ultimaPeca = 0;
	while(destino[n - 1] == 0){	//destino[n-1] == 0
		
		ultimaPeca = passo(origem, destino, auxiliar, n, ultimaPeca);
		total++;
	}
	
	printf("\n\nTotal de passos para solucionar Hanoi(%d):	%d", n, total);
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

int passo(int *origem, int *destino, int *auxiliar, int n, int ultimaPeca){

		int Oo, Od, Oa;	// indices quando for origem
		int Do, Dd, Da;	// indices quando for destino
		
		Oo = pegarOrigem(origem, n);
		Dd = pegarDestino(destino, n);	//destino quando for para destino
		
		Od = pegarOrigem(destino, n);
		Da = pegarDestino(auxiliar, n);	//destino quando for para auxiliar
		
		Oa = pegarOrigem(auxiliar, n);
		Do = pegarDestino(origem, n);	//destino quando for para origem
		
		
		if(n % 2 == 1){
		
			//	A[topo] = 1 não passa quando tamanho de B e C for impar
			//	B[topo] = 1 não passa quando tamanho de A for zero
			
			
			if(origem[0] != 0 && origem[Oo] != ultimaPeca){		// tem algo para mover da pilha A?
			
				if(destino[0] == 0 || origem[Oo] < destino[Dd - 1]){	// move somente se o destino puder receber
					moverPeca(origem, Oo, destino, Dd);		// mover origem para destino
					printf("\nA -> B");
					return destino[Dd];
				} else if(auxiliar[0] == 0 || origem[Oo] < auxiliar[Da - 1]){
					moverPeca(origem, Oo, auxiliar, Da);	// mover origem para auxiliar
					printf("\nA -> C");
					return auxiliar[Da];
				}
			}		
			
			if(destino[0] != 0 && destino[Od] != ultimaPeca){	// tem algo para mover da pilha B? e é diferente da ultima peça movida?
				if(auxiliar[0] == 0 || destino[Od] < auxiliar[Da - 1]){
					printf("\nB -> C");
					moverPeca(destino, Od, auxiliar, Da);	//mover destino para auxiliar
					return auxiliar[Da];
				} else if(origem[0] == 0 || destino[Od] < origem[Do - 1]){
					printf("\nB -> A");
					moverPeca(destino, Od, origem, Do);		// mover destino para origem
					return origem[Do];
				}
				
			}
			
			if(auxiliar[0] != 0 && auxiliar[Oa] != ultimaPeca){	// tem algo para mover da pilha C? e é diferente da ultima peça movida?
				if(origem[0] == 0 || auxiliar[Oa] < origem[Do - 1]){
					printf("\nC -> A");
					moverPeca(auxiliar, Oa, origem, Do);	//mover auxiliar para origem
					return origem[Do];
				} else if(destino[0] == 0 || auxiliar[Oa] < destino[Dd - 1]){
					printf("\nC -> B");
					moverPeca(auxiliar, Oa, destino, Dd);	// mover auxiliar para destino
					return destino[Dd];
				}
			}
			
		} else{
		
			if(origem[0] != 0 && origem[Oo] != ultimaPeca){		// tem algo para mover da pilha A?
			
				if(auxiliar[0] == 0 || origem[Oo] < auxiliar[Da - 1]){
					moverPeca(origem, Oo, auxiliar, Da);	// mover origem para auxiliar
					printf("\nA -> C");
					return auxiliar[Da];
				} else if(destino[0] == 0 || origem[Oo] < destino[Dd - 1]){	// move somente se o destino puder receber
					moverPeca(origem, Oo, destino, Dd);		// mover origem para destino
					printf("\nA -> B");
					return destino[Dd];
				}
			}	
			
			if(destino[0] != 0 && destino[Od] != ultimaPeca){	// tem algo para mover da pilha B? e é diferente da ultima peça movida?
				if(origem[0] == 0 || destino[Od] < origem[Do - 1]){
					printf("\nB -> A");
					moverPeca(destino, Od, origem, Do);		// mover destino para origem
					return origem[Do];
				} else if(auxiliar[0] == 0 || destino[Od] < auxiliar[Da - 1]){
					printf("\nB -> C");
					moverPeca(destino, Od, auxiliar, Da);	//mover destino para auxiliar
					return auxiliar[Da];
				}
			}
			
			if(auxiliar[0] != 0 && auxiliar[Oa] != ultimaPeca){	// tem algo para mover da pilha C? e é diferente da ultima peça movida?
				if(destino[0] == 0 || auxiliar[Oa] < destino[Dd - 1]){
					printf("\nC -> B");
					moverPeca(auxiliar, Oa, destino, Dd);	// mover auxiliar para destino
					return destino[Dd];
				} else if(origem[0] == 0 || auxiliar[Oa] < origem[Do - 1]){
					printf("\nC -> A");
					moverPeca(auxiliar, Oa, origem, Do);	//mover auxiliar para origem
					return origem[Do];
				}
			}
		}
}

int tamanhoSemZeros(int *torre, int n){
	int soma = 0;
	
	for(int i = 0; i < n; i++){
		if(torre[i] != 0){
			soma++;
		}
	}
	return soma;
}
