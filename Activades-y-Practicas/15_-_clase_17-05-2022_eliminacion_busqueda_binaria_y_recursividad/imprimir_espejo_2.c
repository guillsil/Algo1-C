#include<stdio.h>


void imprimir_numeros_rec(int actual, int n){

	if (actual > n) return;

	printf("%i\n", actual);
	imprimir_numeros_rec(actual+1, n);
	printf("%i\n", actual);
}

void imprimir_numeros(int n) {
	imprimir_numeros_rec(1, n);
}


int main(){
	
	imprimir_numeros(6);

	return 0;
}







