#include <stdio.h>


void intercambiar(int un_numero, int otro_numero){
	int numero_tres = un_numero;
	un_numero = otro_numero;
	otro_numero = numero_tres;
	printf("en intercambiar un_numero vale %i, otro_numero vale %i.\n", un_numero, otro_numero);
}

int main(){
	
	int numero_1 = 20;
	int numero_2 = 23;

	printf("en el main 1 numero_1 vale %i, numero_2 vale %i.\n", numero_1, numero_2);
	// numero_1 vale 20, numero_2 vale 23.
	intercambiar(numero_1, numero_2); 
	printf("en el main 2 numero_1 vale %i, numero_2 vale %i.\n", numero_1, numero_2);
	// numero_1 vale 23, numero_2 vale 20.

	return 0;
}