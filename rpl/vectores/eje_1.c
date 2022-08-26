/*  
Kuzco, el emperador Inca, está buscando desesperadamente un antídoto para convertirse en humano. El problema es que Yzma tiene una enorme colección de pociones, y Kuzco no sabe por dónde empezar. Considerando la colección de pociones como un vector, se pide:

    Encontrar el antídoto para Kuzco, sabiendo que este está representado por el caracter “A”, y devolver la posición del vector en la que se encuentra. Se puede asumir que siempre se va a encontrar el antidoto.

Ejemplos

    Si se recibe un vector [T,R,P,A,L,E,S,B], se debe devolver la posición 3.
    Si se recibe un vector [A,L,M,S,W,Q], se debe devolver la posición 0.


*/

#include <stdio.h>
#define MAX_LETRAS 5


int buscar_letra(char letras[MAX_LETRAS], int tope){
    int pos; 
    for (int i = 0; i < tope; i++){
        if(letras[i] == 'A'){
            pos = i;
        }
    }
    return pos;
}
int main(){
    char letras[MAX_LETRAS];
    letras[0] = 'J';
    letras[1] = 'K';
    letras[2] = 'A';
    letras[3] = 'R';

    int tope_letras = 4, pos;
    pos = buscar_letra(letras, tope_letras);
    printf("la pos es: %i", pos);

    return 0;
}
