#include<stdio.h>

typedef struct gatito {
	int edad;
	char colores[MAX_COLORES][MAX_COLOR];
	char nombre[MAX_NOMBRE];
	bool esta;
} gatito_t;

int main(){
	
	gatito_t gatitos[MAX_GATITOS];
	int tope = 0;
	// Acá se llena de gatitos...


	int posicion = posicion_gatito(gatitos, tope);

	/* Eliminación lógica */
	if (posicion > NO_EXISTE) {
		gatitos[posicion].esta = false;
	}

	/* Eliminación física (no ordenada) */
	if (posicion > NO_EXISTE) {
		gatitos[posicion] = gatitos[tope-1];
		tope--;
	}

	/* Eliminación física (ordenada) */
	if (posicion > NO_EXISTE) {
		for (int i = posicion; i < tope-1; i++){
			gatitos[i] = gatitos[i+1];
		}
		tope--;
	}

	return 0;
}







