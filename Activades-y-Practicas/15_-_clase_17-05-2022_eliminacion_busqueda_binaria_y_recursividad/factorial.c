#include<stdio.h>

/*
int factorial(int n){
	int resultado = 1;
	for (int i = 2; i < n; i++) {
		resultado = resultado * i;
	}
	return resultado;
}
*/

int factorial(int n){

	/* 1ro: Caso base */
	if (n == 0) {
		return 1;
	}

	/* 2do y 3ro: Llamada recursiva y un proceso */
	return (n * factorial(n-1));
}

int main(){
	
	int fact = factorial(6);
	

	return 0;
}







