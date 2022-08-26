#include<stdio.h>

typedef struct heladera {
	int kilos_carne;
	int litros_lacteos;
	int latas_birra;
	int cantidad_huevo;
	char eficiencia;
} heladera_t;

void mostrar_heladera(heladera_t heladera){
	printf("La eficiencia de la heladera es: %c.\n", heladera.eficiencia);
}

void cargar_heladera(heladera_t* ref_heladera){

	(*ref_heladera).latas_birra = 2;
	(*ref_heladera).cantidad_huevo = 12;
	(*ref_heladera).kilos_carne = 3;
	(*ref_heladera).litros_lacteos = 2;

	printf("Cuál es la eficiencia?\n");
	scanf(" %c", &(*ref_heladera).eficiencia);
	
}

int main(){

	heladera_t heladera_daniel;

	cargar_heladera(&heladera_daniel);

	mostrar_heladera(heladera_daniel);

	return 0;
}



