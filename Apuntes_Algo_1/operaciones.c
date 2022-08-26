#include <stdio.h>

#define MAX_ELEMENTOS 100

// Pre: tope debe ser mayor o igual a 0.
// Pos: Imprime por pantalla los elementos del vector.
void imprimir_vector(int* vector, int tope) {
	for (int i = 0; i < tope-1; i++) {
		printf("%i, ", vector[i]);
	}
	printf("%i\n", vector[tope-1]);
}


// Pre: vector1 y vector2 tienen que estar ordenados. tope1 y tope2 tienen que ser >= 0
// Pos: Llena vector_resultado con la mezcla de vector1 y vector2 y establece su tope.
void mezclar_vectores(int vector1[MAX_ELEMENTOS], int tope1,
					  int vector2[MAX_ELEMENTOS], int tope2,
					  int vector_resultado[2*MAX_ELEMENTOS], int* tope_resultado) {
	int i = 0;
	int j = 0;
	*tope_resultado = 0;

	while (i < tope1 && j < tope2) {
		if (vector1[i] < vector2[j]) {
			vector_resultado[*tope_resultado] = vector1[i];
			i++;
		} else {
			vector_resultado[*tope_resultado] = vector2[j];
			j++;
		}
		(*tope_resultado)++;
	}

	while (i < tope1) {
		vector_resultado[*tope_resultado] = vector1[i];
		(*tope_resultado)++;
		i++;
	}

	while (j < tope2) {
		vector_resultado[*tope_resultado] = vector2[j];
		(*tope_resultado)++;
		j++;
	}
}


// Pre: vector1 y vector2 tienen que estar ordenados y no deben tener elementos repetidos
// 		dentro del mismo vector. tope1 y tope2 deben ser >= 0.
// Pos: Llena vector_resultado con la unión de ambos vectores (sin repetidos) y establece su tope.
void unir_vectores(int vector1[MAX_ELEMENTOS], int tope1,
				   int vector2[MAX_ELEMENTOS], int tope2,
				   int vector_resultado[2*MAX_ELEMENTOS], int* tope_resultado) {
	int i = 0;
	int j = 0;
	*tope_resultado = 0;

	while (i < tope1 && j < tope2) {
		if (vector1[i] < vector2[j]) {
			vector_resultado[*tope_resultado] = vector1[i];
			i++;
		} else if (vector2[j] < vector1[i]) {
			vector_resultado[*tope_resultado] = vector2[j];
			j++;
		} else {
			vector_resultado[*tope_resultado] = vector1[i];
			i++;
			j++;
		}
		(*tope_resultado)++;
	}

	while (i < tope1) {
		vector_resultado[*tope_resultado] = vector1[i];
		(*tope_resultado)++;
		i++;
	}

	while (j < tope2) {
		vector_resultado[*tope_resultado] = vector2[j];
		(*tope_resultado)++;
		j++;
	}
}


// Pre: vector1 y vector2 tienen que estar ordenados. tope1 y tope2 deben ser >= 0.
// Pos: Llena vector_resultado con los elementos de vector1 que NO estén en vector2
//      y establece su tope
void restar_vectores(int vector1[MAX_ELEMENTOS], int tope1,
					 int vector2[MAX_ELEMENTOS], int tope2,
					 int vector_resultado[MAX_ELEMENTOS], int* tope_resultado) {
	int i = 0;
	int j = 0;
	*tope_resultado = 0;

	while (i < tope1 && j < tope2) {
		if (vector1[i] < vector2[j]) {
			vector_resultado[*tope_resultado] = vector1[i];
			(*tope_resultado)++;
			i++;
		} else if (vector2[j] < vector1[i]) {
			j++;
		} else {
			i++;
			j++;
		}
	}

	while (i < tope1) {
		vector_resultado[*tope_resultado] = vector1[i];
		(*tope_resultado)++;
		i++;
	}
}


// Pre: vector1 y vector2 tienen que estar ordenados. tope1 y tope2 deben ser >= 0.
// Pos: Llena vector_resultado con los elementos que están en ambos vectores (sin repetir)
// 		y establece su tope
void intersectar_vectores(int vector1[MAX_ELEMENTOS], int tope1,
						  int vector2[MAX_ELEMENTOS], int tope2,
						  int vector_resultado[MAX_ELEMENTOS], int* tope_resultado) {
	int i = 0;
	int j = 0;
	*tope_resultado = 0;

	while (i < tope1 && i < tope2) {
		if (vector1[i] < vector2[j]) {
			i++;
		} else if (vector2[j] < vector1[i]) {
			j++;
		} else {
			vector_resultado[*tope_resultado] = vector1[i];
			(*tope_resultado)++;
			i++;
			j++;
		}
	}
}


int main() {
	int vector_primos[MAX_ELEMENTOS] = {1, 2, 3, 5, 7, 11, 13, 17, 19, 23};
	int vector_impares[MAX_ELEMENTOS] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23};

	int tope_primos = 10;
	int tope_impares = 12;


	// Mezcla
	int vector_mezcla[2*MAX_ELEMENTOS];
	int tope_mezcla;

	mezclar_vectores(vector_primos, tope_primos, vector_impares,
					 tope_impares, vector_mezcla, &tope_mezcla);
	printf("Mezcla:\n");
	imprimir_vector(vector_mezcla, tope_mezcla);


	// Unión
	int vector_union[2*MAX_ELEMENTOS];
	int tope_union;

	unir_vectores(vector_primos, tope_primos, vector_impares,
				  tope_impares, vector_union, &tope_union);
	printf("\nUnión:\n");
	imprimir_vector(vector_union, tope_union);


	// Diferencia
	int vector_diferencia[MAX_ELEMENTOS];
	int tope_diferencia;

	restar_vectores(vector_impares, tope_impares, vector_primos,
					tope_primos, vector_diferencia, &tope_diferencia);
	printf("\nDiferencia:\n");
	imprimir_vector(vector_diferencia, tope_diferencia);


	// Intersección
	int vector_interseccion[MAX_ELEMENTOS];
	int tope_interseccion;

	intersectar_vectores(vector_impares, tope_impares, vector_primos,
						 tope_primos, vector_interseccion, &tope_interseccion);
	printf("\nIntersección:\n");
	imprimir_vector(vector_interseccion, tope_interseccion);

	return 0;
}