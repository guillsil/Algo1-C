#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include"tp1.h"
#include"utiles.h"
#include"papeleo.h"


int main(){
    srand((unsigned)time(NULL));

    char personaje; 
    juego_t juego;

    programa_tp1(&personaje);
    system("clear");
   

    inicializar_juego(&juego, personaje);

    imprimir_terreno(juego); 

    return 0;  

}