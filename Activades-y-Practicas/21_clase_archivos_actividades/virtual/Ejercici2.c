#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define ERROR -1
#define MAX_TESOROS 100
const int COINCIDENCIAS_NECESARIAS = 2;

typedef struct tesoro {
	char metal; // Oro, Plata, Bronce
	int gramos;
	int precio_por_gramo;
	bool tiene_piedras_preciosas;
} tesoro_t;

// Para poder probar imprimir_tesoros_importantes.
void cargar_tesoros(tesoro_t tesoros[MAX_TESOROS], int* tope) {
	tesoros[0].metal = 'P';
	tesoros[0].gramos = 200;
	tesoros[0].precio_por_gramo = 15;
	tesoros[0].tiene_piedras_preciosas = true;

	tesoros[1].metal = 'O';
	tesoros[1].gramos = 200;
	tesoros[1].precio_por_gramo = 15;
	tesoros[1].tiene_piedras_preciosas = false;

	tesoros[2].metal = 'O';
	tesoros[2].gramos = 50;
	tesoros[2].precio_por_gramo = 4;
	tesoros[2].tiene_piedras_preciosas = false;

	*tope = 3;
}

// Pre: tope_tesoros tiene que ser >= 0. tesoro_ideal debe tener todos sus campos inicializados.
// Pos: Imprime por pantalla el número del tesoro que coincida en 2 o más campos con el ideal.
void imprimir_tesoros_importantes(tesoro_t tesoros[MAX_TESOROS], int tope_tesoros, tesoro_t tesoro_ideal) {
	printf("\nTesoros importantes:\n");

	for (int i = 0; i < tope_tesoros; i++) {
		int coincidencias = 0;

		if (tesoros[i].metal == tesoro_ideal.metal) {
			coincidencias++;
		}
		if (tesoros[i].gramos == tesoro_ideal.gramos) {
			coincidencias++;
		}
		if (tesoros[i].precio_por_gramo >= tesoro_ideal.precio_por_gramo) {
			coincidencias++;
		}
		if (tesoros[i].tiene_piedras_preciosas == tesoro_ideal.tiene_piedras_preciosas) {
			coincidencias++;
		}

		if (coincidencias >= COINCIDENCIAS_NECESARIAS) {
			printf("Tesoro #%i\n", i);
		}
	}
}

int main(int argc, char const *argv[]) {
	if (argc != 2) {
		printf("Cantidad de argumentos inesperada\n");
		return ERROR;
	}

	tesoro_t tesoros[MAX_TESOROS];
	int tope_tesoros = 0;
	cargar_tesoros(tesoros, &tope_tesoros);

	FILE* archivo_config = fopen(argv[1], "r");

	if (!archivo_config) {
		printf("Error al abrir el archivo\n");
		return ERROR;
	}

	tesoro_t tesoro_ideal;
	char lectura_tiene_piedra[4];

	fscanf(archivo_config, "%*[^=]=%c", &tesoro_ideal.metal);
	fscanf(archivo_config, "%*[^=]=%i", &tesoro_ideal.gramos);
	fscanf(archivo_config, "%*[^=]=%i", &tesoro_ideal.precio_por_gramo);
	fscanf(archivo_config, "%*[^=]=%s", lectura_tiene_piedra);

	tesoro_ideal.tiene_piedras_preciosas = (strcmp(lectura_tiene_piedra, "Sí") == 0);

	printf("Tesoro ideal:\n");
	printf("Metal: %c\n", tesoro_ideal.metal);
	printf("Gramos: %i\n", tesoro_ideal.gramos);
	printf("Precio por gramo: %i\n", tesoro_ideal.precio_por_gramo);
	printf("Tiene piedra: %i\n", tesoro_ideal.tiene_piedras_preciosas);

	imprimir_tesoros_importantes(tesoros, tope_tesoros, tesoro_ideal);

	fclose(archivo_config);

	return 0;
}