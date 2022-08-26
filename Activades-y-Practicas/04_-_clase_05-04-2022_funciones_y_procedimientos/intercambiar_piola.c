#include <stdio.h>


void intercambiar(int* ref_numero_1, int* ref_numero_2){

	int numero_3 = (*ref_numero_1);
	(*ref_numero_1) = (*ref_numero_2);
	(*ref_numero_2) = numero_3;


	printf("en intercambiar numero_1 vale %i, numero_2 vale %i.\n", *ref_numero_1, *ref_numero_2);
}

int main(){
	
	int numero_1 = 20;
	int numero_2 = 23;

	printf("en el main 1 numero_1 vale %i, numero_2 vale %i.\n", numero_1, numero_2);
	// numero_1 vale 20, numero_2 vale 23.
	intercambiar(&numero_1, &numero_2); 
	printf("en el main 2 numero_1 vale %i, numero_2 vale %i.\n", numero_1, numero_2);
	// numero_1 vale 23, numero_2 vale 20.

	return 0;
}