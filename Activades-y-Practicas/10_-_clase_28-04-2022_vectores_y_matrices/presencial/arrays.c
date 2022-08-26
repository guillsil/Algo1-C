#include <stdio.h>
#include <stdbool.h>

#define MAX_NOTAS 5
const int APLAZO = 2;
const int NO_EXISTE = -1;

//pre: tope con valor mayor o igual a 0, notas con valor 2, o de 4 a 10.
//post: imprime por pantalla el promedio
void calcular_promedio(int notas[MAX_NOTAS],int tope){
	int sumatoria = 0;
	int cant_aplazos =0;

	for(int i=0; i<tope; i++){
		if(notas[i] != APLAZO){
			sumatoria = sumatoria + notas[i];
			//sumatoria += notas[i];
		}else{
			cant_aplazos = cant_aplazos +1;
		}
	}
	int promedio_con_aplazo = 0;
	int promedio_sin_aplazo = 0;

	promedio_con_aplazo = (sumatoria + (cant_aplazos*APLAZO)) / tope;
	promedio_sin_aplazo = sumatoria/( tope - cant_aplazos);
	
	printf("Querido usuario, con todo mi amor te doy el promedio con aplazo %i\n",promedio_con_aplazo);
	printf("Bueno y aca sin aplazo %i\n",promedio_sin_aplazo);
}

int posicion_nota_10(int notas[MAX_NOTAS], int tope){
	int posicion = NO_EXISTE;
	for(int i=0; i<tope; i++){
		if(notas[i] == 10){
			posicion = i;
		}
	}
	return posicion;
}


int main(){

	int notas[MAX_NOTAS];
	int tope;
	//ESTO ES UN EJEMPLO. NO HACER A MENOS QUE SEA PARA PROBAR!!!!
	notas[0] = 2;
	notas[1] = 4;
	notas[2] = 10;
	notas[3] = 7;
	tope = 4;



	//calcular_promedio(notas,tope);

	int posicion = posicion_nota_10(notas,tope);
	printf("Reyyy la posicion es %i\n",posicion);
	
	return 0;
}