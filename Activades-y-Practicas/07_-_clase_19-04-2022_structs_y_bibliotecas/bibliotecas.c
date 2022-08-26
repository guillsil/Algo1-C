#include <stdio.h>
#include "culculadora.h"

int main(){

	int operando_1 = HOLA;
	int operando_2 = 5;

	int resultado_suma = suma(operando_1, operando_2);
	int resultado_resta = resta(operando_1, operando_2);
	int resultado_division = division(operando_1, operando_2);
	int resultado_multiplicacion = multiplicacion(operando_1, operando_2);

	printf("La suma es %i\n", resultado_suma);
	printf("La resta es %i\n", resultado_resta);
	printf("La division es %i\n", resultado_division);
	printf("La multiplicacion es %i\n", resultado_multiplicacion);
	return 0;
}
