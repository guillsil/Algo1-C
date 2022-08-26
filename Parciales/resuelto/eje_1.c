/*
Enunciado

Estamos en guerra con monstruos!

Nos enteramos que una de sus debilidades, es la Hipopotomonstrosesquipedaliofobia, la fobia a las palabras largas, por lo que para detenerlos necesitamos obtener las palabras más grandes que podamos
Se pide

Dado un string de caracteres, eliminar todos los espacios que aparezcan, para que sea una palabra más larga y asi poder asustarlos.

Buuu!
*/
#include <stdio.h>
#include<string.h>
#define MAX_PALABRAS 1000
#define MAX_CARACTER 10
const char ESPACIO = ' ';
void remover_espacio_del_string(char frase[MAX_PALABRAS], char cadena_aux[MAX_PALABRAS]){
    int j;
    for (int i = 0; i < strlen(frase); i++){
        if(frase[i] != ESPACIO){
            cadena_aux[j] = frase[i];
            j++;
        }
    }
    cadena_aux[j] = '\0';
}
int main(){
    char frase[MAX_PALABRAS] = "aguante boca , el mas grande lejos, riber te fuiste a la vez";
    char cadena_aux[MAX_PALABRAS];
    remover_espacio_del_string(frase, cadena_aux);
    for (int i = 0; i <strlen(cadena_aux); i++){
        printf("%c", cadena_aux[i]);
    }
}

/*

*/
