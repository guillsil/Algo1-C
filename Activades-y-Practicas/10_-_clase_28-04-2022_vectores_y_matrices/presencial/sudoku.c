#include <stdio.h>
#include <stdbool.h>


#define MAX_FILAS 3
#define MAX_COLUMNAS 3
const int MIN_VALOR = 1;
const int MAX_VALOR = 9;


bool cuadrante_valido(int sudoku[MAX_FILAS][MAX_COLUMNAS]){
	bool esta_dentro_rango = true;
	int sumatoria = 0;
	for (int i = 0; i<MAX_FILAS;i++){
		for (int j = 0; j<MAX_COLUMNAS;j++){
			if(!(sudoku[i][j] >= MIN_VALOR && sudoku[i][j] <= MAX_VALOR)){
				esta_dentro_rango = false;
			}
			sumatoria = sumatoria + sudoku[i][j];

			printf("[%i] ",sudoku[i][j]);
		}
		printf("\n");
	}
	return esta_dentro_rango;
}


int main(){
	
	int sudoku[MAX_FILAS][MAX_COLUMNAS] = {
			{1,2,3},
			{4,15,6},
			{7,-2,9}};

	bool es_valido = cuadrante_valido(sudoku);
	
	if(es_valido){
		printf("Yeyyy el cuadrante es valido\n");
	}else{
		printf("F por tontin\n");
	}


	return 0;
}