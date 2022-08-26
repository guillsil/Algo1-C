/*
Ya convertido Hércules en un galán y aspirante a héroe, Phil lo llevó a la ciudad de Tebas, una de las más problemáticas de Grecia para ayudar a su población. Hércules, en su afán de ayudar a todos, empieza a recorrer los pasillos de la ciudad de forma errática sin tener en cuenta que podría dejar a gente sin ayudar.

Es por esto que Phil lo reta, y lo obliga a pasearse por la ciudad una segunda vez, buscando aunque sea a un ciudadano al que Hércules no ayudó por apurado. Se pide:
    Implementar una función que, dada una matriz que representa a Tebas y en la cual cada posición es un ciudadano (“C”), recorra la ciudad en busca de alguna persona en peligro (“P”). La función debe devolver true si se encontró a al menos un ciudadano sin ayudar.

Tener en cuenta:

    La matriz está llena (topes iguales a sus máximos).

*/

#include <stdbool.h>
#include <stdio.h>

#define MAX_FILAS 5
#define MAX_COLUMNAS 5
// Aqui van las constantes

bool quedan_ciudadanos_en_peligro(char tebas[MAX_FILAS][MAX_COLUMNAS]) {
    bool encontrado = false;
    for (int i = 0; i < MAX_FILAS; i++){
        for (int j = 0; j < MAX_COLUMNAS; j++){
            if(tebas[i][j] == 'P'){
                encontrado = true;
            }
        }
        
    }
    return encontrado;
    
}

int main(){
    bool encontrado;
    char tablero[MAX_FILAS][MAX_COLUMNAS] = {
        {'C', 'C', 'C', 'C', 'C'},
        {'C', 'C', 'P', 'C', 'C'},
		{'C', 'C', 'C', 'C', 'C'},
        {'C', 'C', 'C', 'P', 'C'},
        {'C', 'C', 'C', 'C', 'C'}
    };
    encontrado = quedan_ciudadanos_en_peligro(tablero);

    if (encontrado == true){
        printf("true");
    }else{
        printf("false");
    }
    

    
    return 0;
}