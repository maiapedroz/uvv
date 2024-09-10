#include <stdio.h>

int mecanismo(int n);
int seq_adit(int n, int t0, int t1);


int main(void){

	for(int i = 0; i < 10; i++){
		printf("\nContagem fib1(%d) = %d", i, mecanismo(i));
	}

	return 0;
}

int mecanismo(int n){

	if(n < 0) return -1;
	if(n == 0) return 1;
	if(n == 1) return 1;
	if(n < 4) return 2;
	return seq_adit(n - 2, 2, 2);
}

int seq_adit(int n, int t0, int t1){
	if (n < 0)	return -1;
	if (n == 0)	return t0;
	if (n == 1)	return t1;
	return seq_adit(n - 1, t1, t0 + t1);
}
