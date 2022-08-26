#include <stdio.h>
#include <stdbool.h>

#define MAX_FILAS 9
#define MAX_COLUMNAS 9

const int SUMA_CORRECTA = 45;
const int LARGO_CUADRANTE = 3;
const int ANCHO_CUADRANTE = 3;

bool es_cuadrante_correcto(int tablero[MAX_FILAS][MAX_COLUMNAS], int fila_inicial, int col_inicial) {
	int suma_valores = 0;
	for (int i = fila_inicial; i < fila_inicial + LARGO_CUADRANTE; i++) {
		for (int j = col_inicial; j < col_inicial + ANCHO_CUADRANTE; j++) {
			suma_valores += tablero[i][j];
		}
	}

	return suma_valores == SUMA_CORRECTA;
}

int main() {
	int tablero[MAX_FILAS][MAX_COLUMNAS] = {
		{1, 2, 3,	4, 5, 6, 	7, 8, 9},
		{4, 5, 6, 	7, 8, 9, 	1, 2, 3},
		{7, 8, 9, 	1, 2, 3, 	4, 5, 6},

		{2, 3, 4, 	5, 6, 7, 	8, 9, 1},
		{3, 4, 5, 	6, 7, 8, 	9, 1, 2},
		{5, 6, 7, 	8, 9, 1, 	2, 3, 4},

		{6, 7, 8, 	9, 1, 2, 	3, 4, 5},
		{8, 9, 1, 	2, 3, 4, 	5, 6, 7},
		{9, 1, 2, 	3, 4, 5, 	6, 7, 8}
	};

	if (es_cuadrante_correcto(tablero, 3, 0)) {
		printf("Cuadrante correcto\n");
	} else {
		printf("Cuadrante incorrecto\n");
	}

	return 0;
}