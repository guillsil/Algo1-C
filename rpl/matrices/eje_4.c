/*
Hércules se está enfrentando a Medusa, a quien no puede mirar a los ojos ya que sino se convertiría en piedra. Phil se dio cuenta de que el comportamiento de las serpientes de la cabeza de Medusa son un buen indicio para saber cuándo es conveniente atacar. Si el comportamiento de las serpientes se puede representar como números, y cada serpiente supone una posición en la matriz de serpientes, se pide:

    Implementar una función que sume los comportamientos de cada una de las serpientes, y devuelva true si la cantidad total sumada es menor a 0, o false en caso contrario.

Ejemplo:

    Si se recibe la matriz de 3x4:

 5  4 -2  1
-4  5  2  2
-2 -5  3  7

Como el total suma 16, se debería devolver false.
*/
#include <stdio.h>
#include <stdbool.h>
#define MAX_FILAS 5
#define MAX_COLUMNAS 5

bool conviene_atacar(int serpientes[MAX_FILAS][MAX_COLUMNAS], int tope_fila, int tope_columna) {
    int sumatoria = 0, elemento_actual = 0;
    for (int i = 0; i < tope_fila; i++){
        for (int j = 0; j < tope_columna; j++){
            elemento_actual = serpientes[i][j];
            sumatoria = sumatoria + elemento_actual;
        }
    }
    if (sumatoria < 0){
        return true;
    }else{
        return false;
    }   
}

int main(){
    bool encontrado;
    int tablero[MAX_FILAS][MAX_COLUMNAS] = {
        {4, 6,-6, 8, -9},
        {4, 0,-6, 8,-9 },
		{-7, 6,-6, 9,-9},
        {4, 6,-6, -8,-9},
        {-4, 5,-6, 8, 0}
    };
    int tope_fil = 5, tope_col = 5;
    encontrado = conviene_atacar(tablero, tope_fil, tope_col);
    if(encontrado == true){
        printf("true");
    }else{
        printf("false");
    }

    return 0;
}