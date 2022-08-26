/*
Dunbroch, ella puede participar en los juegos de las Tierras Altas con el fin de disputar su propia mano en matrimonio. Quién puede casarse con Mérida se determina a partir de una competencia de tiro con arco. Si el blanco al que se debe tirar es representado por una matriz, se pide:

    Implementar una función que dada una matriz que representa un blanco, devuelva el puntaje de ese tiro. El puntaje está dado dependiendo de en qué posición de éste fue el tiro:
        Amarillo: 10 puntos.
        Rojo: 5 puntos.
        Negro: 2 puntos.
        Por afuera del blanco: 0 puntos.

Tener en cuenta:

    La matriz es de caracteres, donde cada posición puede representar un color:
        Amarillo (A).
        Rojo (R).
        Negro (N).

    La matriz no es necesariamente cuadrada y tiene sus respectivos topes. Por lo que se toma al tiro por fuera del blanco cuando éste está por fuera de los límites definidos por los topes de la matriz.

Ejemplo:

Con la matriz de 5x5:

N N R N N
N R A R N
N R N R N
N R A R N
N N R N N

Y el tiro:

fila = 2
columna = 1

El resultado esperado de la función es 5 ya que da en uno rojo.
*/
#define MAX_FILAS 10
#define MAX_COLUMNAS 23
#define ROJO 'R'
#define AMARILLO 'A'
#define NEGRO 'N'

int calcular_puntaje_tiro(char blanco[MAX_FILAS][MAX_COLUMNAS], int tope_filas, int tope_columnas, int fila_tiro, int columna_tiro) {
    char color_tiro;
    for(int i= 0;i<tope_filas;i++){
        for(int j=0;j<tope_columnas;j++){
            if(blanco[i][j] == blanco[fila_tiro][columna_tiro]){
                color_tiro = blanco[fila_tiro][columna_tiro];
            }
        }
    }

    if(color_tiro == ROJO){
        return 5;
    }else if(color_tiro == AMARILLO){
        return 10;
    }else if(color_tiro == NEGRO){
        return 2;
    }else{
        return 0;
    }

}