#include <stdio.h>
#include "biblio.h"

int main(){
	int numero_lilo = 0;

	pedir_numerito(&numero_lilo);
	imprimir_divisores(numero_lilo);
	

	return 0;
}