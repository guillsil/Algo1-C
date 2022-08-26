#include <stdio.h>
/*
 *	PARA EJECUTAR UNA PARTE, "DESCOMENTARLA"
 *	(quitar el "/*" del principio y el "* /" del final)
 */


//Variante a
/*
const int DIVISOR = 2;

int main() {
	for(int i = 1; i<=10; i++) {
		if(i%2 == 0) {
			printf("El número %i es par!\n",i);
		} else {
			printf("El número %i es impar. :(\n",i);
		}
	}
	return 0;
}
*/

//Variante b
/*
int main() {
	int i = 1;
	while(i<=10) {
		if(i%DIVISOR == 0) {
			printf("El número %i es par!\n",i);
		} else {
			printf("El número %i es impar. :(\n",i);
		}
		i++;
	}
	return 0;
}
*/

//Variante c
/*
#define PAR 0
//No funciona si se utiliza "const"
//const int PAR = 0;

int main() {
	for(int i = 1; i<=10; i++) {
		int paridad = i%2;
		switch(paridad) {
			case PAR:
				printf("El número %i es par!\n",i);
				break;
			default:
				printf("El número %i es impar. :(\n",i);
				break;
		}
	}
	return 0;
}
*/