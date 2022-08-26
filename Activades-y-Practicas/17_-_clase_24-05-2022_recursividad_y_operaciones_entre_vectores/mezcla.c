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

mezclar_vectores(int vector_1[MAX_ELEMENTOS], int tope_vector_1, int vector_2[MAX_ELEMENTOS], int tope_vector_2, int vector_resultado[2*MAX_ELEMENTOS], int *tope_vector_resultado){
    int j = 0;
    int i = 0;
    *tope_vector_resultado = 0;
    while (i < tope_vector_1 && j < tope_vector_2){
        if(vector_1[i] < vector_2[j]){
            vector_resultado[*tope_vector_resultado] = vector_1[i];
            i++;
        }else if(vector_1[i] > vector_2[j]){
            vector_resultado[*tope_vector_resultado] = vector_1[j];
            j++;
        }
        (*tope_vector_resultado)++;
    }
    while (i < tope_vector_1) {
		vector_resultado[*tope_vector_resultado] = vector_1[i];
		(*tope_vector_resultado)++;
		i++;
	}

	while (j < tope_vector_2) {
		vector_resultado[*tope_vector_resultado] = vector_2[j];
		(*tope_vector_resultado)++;
		j++;
	}
    
}

int main(){
    int vector_primos[MAX_ELEMENTOS] = {1, 2, 3, 5, 7, 11, 13, 17, 19, 23};
	int vector_impares[MAX_ELEMENTOS] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23};

	int tope_primos = 10;
	int tope_impares = 12;

    // Mezcla
	int vector_mezcla[2*MAX_ELEMENTOS];
	int tope_mezcla;

	mezclar_vectores(vector_primos, tope_primos, vector_impares,tope_impares, vector_mezcla, &tope_mezcla);
	printf("Mezcla:\n");
	imprimir_vector(vector_mezcla, tope_mezcla);

}