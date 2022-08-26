#include "culculadora.h"


typedef struct edad {
	int anios;
	int meses;
} edad_t;


int suma(int operando_1, int operando_2){
	//la formula de la cola coca;
	return operando_1 + operando_2;
}

int resta(int operando_1, int operando_2){
	return operando_1 - operando_2;
}

int division(int operando_1, int operando_2){
	return operando_1 / operando_2;
}

/*
 * Pre:
 * Post:
 */
int resultado_multipicacion(int operando_1, int operando_2){
	return operando_1 * operando_2;
}

int multiplicacion(int operando_1, int operando_2){
	return resultado_multipicacion(operando_1, operando_2);
}
