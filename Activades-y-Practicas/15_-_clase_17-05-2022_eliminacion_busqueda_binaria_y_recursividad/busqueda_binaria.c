#include<stdio.h>
#include<stdbool.h>
#define MAX_COLORES 100
#define MAX_COLOR 100
#define MAX_NOMBRE 100
#define MAX_GATITOS 100

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


	int edad_buscada = 7;

	int inicio = 0;
	int fin = tope - 1;
	int centro = (inicio + fin) / 2;

	while (gatitos[centro].edad != edad_buscada && inicio <= fin){
		if (gatitos[centro].edad > edad_buscada){
			fin = centro - 1;
		} else if (gatitos[centro].edad < edad_buscada){
			inicio = centro + 1;
		}
		centro = (inicio + fin) / 2;
	}

	if (inicio <= fin) {
		printf("Hey!! Lo encontre en la posicion %i.\n", centro);
	}


	return 0;
}







