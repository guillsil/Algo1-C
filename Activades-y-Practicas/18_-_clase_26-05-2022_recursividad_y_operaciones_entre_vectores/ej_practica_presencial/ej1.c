#include <stdio.h>
#include <stdbool.h>

#define MAX_FIL 3
#define MAX_COL 3
#define STITCH 'S'

/*bool esta_stitch(char terreno[MAX_FIL][MAX_COL], int tope_fila, int tope_columna){
	bool esta = false;
	
	for (int i = 0; i < tope_fila; i++){
		for (int j = 0; j < tope_columna; j++){
			if(terreno[i][j] == STITCH){
				esta = true;
			}
		}
	}

	return esta;
}*/


//CON WHILE CORTANDO CUANDO ENCUENTRA
/*bool esta_stitch(char terreno[MAX_FIL][MAX_COL], int tope_fila, int tope_columna){
	bool esta = false;
	int i = 0;
	int j = 0;

	while (i < tope_fila && !esta){
		j = 0;
		while (j < tope_columna && !esta){
			if(terreno[i][j] == STITCH){
				esta = true;
			}
			j++;
		}
		i++;
	}

	return esta;
}*/


//VERSION RECURSIVA
bool esta_stitch(char terreno[MAX_FIL][MAX_COL], int tope_fila, int tope_columna, int i, int j){
	//cond de corte
	if(i >= tope_fila){
		return false;
	}

	if(j >= tope_columna ){ //caso feo :( :salto a la prox fila
		//llamada recursiva en salto
		return esta_stitch(terreno, tope_fila, tope_columna, i+1, 0);
	}

	//cond de corte
	if(terreno[i][j] == STITCH){
		return true;
	}

	//llamada recursiva
	//caso lindo :) :nos movemos al de al lado
	return esta_stitch(terreno, tope_fila, tope_columna, i, j+1);
}

int main(){

	char terreno[MAX_FIL][MAX_COL] = {{' ', 'S'},
										{' ', ' '},
										{' ', ' '}};
	int tope_fila = 3; 
	int tope_columna = 2;
	bool se_encontro = esta_stitch(terreno, tope_fila, tope_columna, 0, 0);

	if(se_encontro){
		printf("Se encontro!\n");
	}
	else{
		printf("No se encontro buuu :(\n");	
	}
	return 0;
}; 