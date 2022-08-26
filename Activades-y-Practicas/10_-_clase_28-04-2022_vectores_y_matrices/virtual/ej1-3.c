#include<stdio.h>
#include<stdbool.h>

#define MAX_PRUEBAS 100

const int NO_ENCOTRADO = -1;
const int NOTA_BUSCADA = 10;

typedef struct prueba {
	char letra_lilo;
	char letra_final_stitch;
	int intentos;
} prueba_t;


// Pre: notas debe tener tope_notas elementos inicializados.
//		tope_notas debe ser positivo y menor a MAX_PRUEBAS
// Pos: Devuelve el índice del vector donde se encuentra el valor NOTA_BUSCADA,
//		o NO_ENCONTRADO si no se encuentra.
int posicion_buscada(int notas[MAX_PRUEBAS], int tope_notas) {
	int i = 0;
	bool encontrado = false;

	while (i < tope_notas && !encontrado) {
		if (notas[i] == NOTA_BUSCADA) {
			encontrado = true;
		} else {
			i++;
		}
	}

	if (!encontrado) {
		i = NO_ENCOTRADO;
	}

	return i;
}

// Pre: El índice de la nota corresponde con el índice de la prueba.
//		tope_pruebas es positivo y menor a MAX_PRUEBAS. posicion_nota es positivo.
// Pos: Imprime los datos de la prueba en la posicion posicion_nota.
void imprimir_prueba(prueba_t pruebas[MAX_PRUEBAS], int tope_pruebas, int posicion_nota) {
	if (posicion_nota >= tope_pruebas) {
		printf("¡Error! La posición no puede exceder el tope\n");
		return;
	}

	printf("Letra de Lilo: %c\nLetra de Stitch: %c\nIntentos: %i\n",
			pruebas[posicion_nota].letra_lilo,
			pruebas[posicion_nota].letra_final_stitch,
			pruebas[posicion_nota].intentos);
}

int main() {
	int notas[MAX_PRUEBAS] = {4, 9, 5};
	int tope_notas = 3;

	/*
		Esto es solo para demostración en clase.
		NO usar nombres del tipo prueba1, pregunta3, etc.
	*/
	prueba_t prueba1;
	prueba1.letra_lilo = 'A';
	prueba1.letra_final_stitch = 'B';
	prueba1.intentos = 6;

	prueba_t prueba2;
	prueba2.letra_lilo = 'G';
	prueba2.letra_final_stitch = 'H';
	prueba2.intentos = 1;

	prueba_t prueba3;
	prueba3.letra_lilo = 'M';
	prueba3.letra_final_stitch = 'N';
	prueba3.intentos = 5;
	
	prueba_t pruebas[MAX_PRUEBAS] = {prueba1, prueba2, prueba3};
	int tope_pruebas = 3;

	int indice_nota_buscada = posicion_buscada(notas, tope_notas);

	imprimir_prueba(pruebas, tope_pruebas, indice_nota_buscada);
}