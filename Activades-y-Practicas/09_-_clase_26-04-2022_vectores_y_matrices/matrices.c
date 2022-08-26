#include <stdio.h>

#define MAX_FILAS 3
#define MAX_COLUMNAS 4


int main() {


	int carton[MAX_FILAS][MAX_COLUMNAS];

	carton[0][0] = 23;
	carton[0][1] = 56;
	carton[0][2] = 34;
	carton[0][3] = 54;
	carton[1][0] = 12;
	carton[1][1] = 45;
	carton[1][2] = 54;
	carton[1][3] = 23;
	carton[2][0] = 98;
	carton[2][1] = 67;
	carton[2][2] = 45;
	carton[2][3] = 10;


	for (int i = 0; i < MAX_FILAS; i++) {
		for (int j = 0; j < MAX_COLUMNAS; j++) {
			printf("%i ", carton[i][j]);
		}
		printf("\n");
	}

	return 0;
}
