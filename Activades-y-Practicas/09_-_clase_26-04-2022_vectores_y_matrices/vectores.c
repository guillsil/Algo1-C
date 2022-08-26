#include <stdio.h>

#define MAX_EDADES 200

void inicializar_vector(int edades[MAX_EDADES], int* ref_tope){

	edades[*ref_tope] = 19;
	(*ref_tope)++;

	edades[*ref_tope] = 21;
	(*ref_tope)++;

}

void mostrar_vector(int edades[MAX_EDADES], int tope){

	for (int i = 0; i < tope; i++) {
		printf("La edad del alumnos %i es %i.\n", i, edades[i]);
	}

}

void calcular_promedio(int edades[MAX_EDADES], int tope){
	int sumatoria = 0;
	for (int i = 0; i < tope; i++) {
		sumatoria = sumatoria + edades[i];
	}

	int promedio = sumatoria / tope;

	printf("El promedio de edad es: %i\n", promedio);
}

int main() {

	int edades[MAX_EDADES];
	int tope_edades = 0;

	inicializar_vector(edades, &tope_edades);
	mostrar_vector(edades, tope_edades);
	calcular_promedio(edades, tope_edades);

	return 0;
}













