/*

Solucionar o triangulo de pascal

*/

#include <stdio.h>

int C(int n, int k);

int main(){

	printf("C(5,2) = %d", C(5, 2));

	return 0;
}

int C(int n, int k){
	if(k == 0 || n == k)
		return 1;
	else{
		return C(n-1, k - 1) + C(n - 1, k);
	}

}


