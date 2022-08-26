#include <stdio.h>
#include <stdbool.h>

#define MAX_NOTAS 100
const int APROBADO = 4;
const int MAX_APROBADO = 10;
const int NOTA_BUSCADA = 10;
const int NO_ENCONTRADO = -1;

void sacar_promedio(int notas[MAX_NOTAS], int tope_notas){
	int promedio_aplazos = 0;
	int promedio_sin_aplazos = 0;
	int contador_sin_aplazos = 0;

	for(int i = 0; i < tope_notas; i++){
		promedio_aplazos += notas[i];
		if(notas[i] >= APROBADO && notas[i] <= MAX_APROBADO){
			promedio_sin_aplazos += notas[i];
			contador_sin_aplazos ++;
		}
	}
	
	promedio_aplazos = promedio_aplazos / tope_notas;
	promedio_sin_aplazos = promedio_sin_aplazos / contador_sin_aplazos;

	printf("promedio con aplazos: %i, promedio sin aplazos: %i\n", promedio_aplazos, promedio_sin_aplazos);
}

int posicion_diez(int notas[MAX_NOTAS], int tope_notas){
	bool encontrado = false;
	int i = 0;
	while(i < tope_notas && !encontrado){
		if(notas[i] == NOTA_BUSCADA){
			encontrado = true;
		}else{
			i++;			
		}
	}

	if(encontrado == false){
		i = NO_ENCONTRADO;
	}

	return i;
}

int main(){
	int notas[MAX_NOTAS] = {2, 5, 6};
	int tope_notas = 4;

	int pos = posicion_diez(notas, tope_notas);
	printf("%i\n", pos );

	return 0;
}