#include <stdio.h>

const int PI = 3;

int main(){
	
	int numero = 10;

	while(numero > 5){
		printf("%i\n", numero);
		numero--;
	}

	char letra = 'R';

	if (numero > 5){
		int otro_numero = 8;
		printf("numero vale %i\n", numero);
	} else {
		int otro_numero = 8;
		printf("letra vale %c\n", letra);
	}

	return 0;
}