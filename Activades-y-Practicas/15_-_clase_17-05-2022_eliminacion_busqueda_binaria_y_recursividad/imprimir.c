#include<stdio.h>

/*
void imprimir_numeros(int n){
	for (int i = n; i > 0; i--){
		printf("%i\n", i);
	}
}
*/

void imprimir_numeros(int n) {

	/* Caso base */
	if (n == 0) {
		return;
	}

	/* Proceso */
	printf("%i\n", n);

	/* Llamado recursivo */
	imprimir_numeros(n-1);

	/* Proceso */
	printf("%i\n", n);
}


int main(){
	
	imprimir_numeros(6);

	return 0;
}







