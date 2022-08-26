/*
Como era de esperarse, la incontrolada fuerza de Hércules causó que algunas mancuernas salieran volando al bosque cercano, perdiéndose para siempre. Como a Phil le gusta mantener su almacén de equipamiento listo y preparado para el próximo héroe que toque su puerta, necesita reponer las mancuernas perdidas lo antes posible, por lo que se pide:

    Implementar una función que recorra el bosque (ahora representado por mancuernas “M” y pasto “P”) y devuelva la cantidad de mancuernas perdidas.

*/
#include <stdio.h>
#define MAX_FILAS 5
#define MAX_COLUMNAS 5
#define MANCUERNA 'M'


int mancuernas_perdidas(char bosque[MAX_FILAS][MAX_COLUMNAS], int topes){
    int cantidad= 0;
    for (int i = 0; i < topes; i++){
        for (int j = 0; j <  topes; j++){
            if(bosque[i][j] == MANCUERNA){
                cantidad++;
            }
        }
        
    }
    return cantidad;
    
}

int main(){
    int cantidad =0;
    char tablero[MAX_FILAS][MAX_COLUMNAS] = {
        {'P', 'P', 'P', 'P'},
        {'P', 'P', 'P', 'M'},
		{'M', 'M', 'P', 'P'},
        {'P', 'P', 'M', 'P'}
    };
    int topes= 4;
    cantidad= mancuernas_perdidas(tablero, topes);
    printf("%i", cantidad);
    return 0;
}

