#include <stdio.h>
#include <stdbool.h>
#include "biblio.h"

const int STITCH = 720;

void imprimir_divisores(int numero_lilo){
	for(int i=1;i<=numero_lilo;i++){
		if(STITCH%i == 0){
			printf("Yeyy %i es divisor\n",i);
		}
	}
}

//pre:
//post:devuelve true si numero_lilo es valido (entre 0 y STITCH). False, en caso contrario.
bool es_numero_valido(int numero_lilo){
	return (numero_lilo > 0 && numero_lilo < STITCH);
}

void pedir_numerito(int* numero_lilo){
	printf("Lilo decime un numero!!\n");
	scanf("%i",numero_lilo);
	while(!es_numero_valido(*numero_lilo)){
		printf("Lilo decime un numero!!\n");
		scanf("%i",numero_lilo);
	}
}