#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include"tp1.h"
#include"utiles.h"
#include"papeleo.h"

void guia_jugador(){
    printf("Que empiece el Desafio\n");
    printf("tendras que responder una serie de preguntas para arrancar con un obsequio\n");
    printf("el cual te permitira atrbezar los obstaculos y recoger los papeleos\n");
    printf("para haci poder ir avanzando en los niveles y poder llevarte el trofeo\n");
}



int main(){
    
    srand((unsigned)time(NULL));

    char personaje; 
    juego_t juego;

    guia_jugador();

    programa_tp1(&personaje);

    system("clear");
   
    inicializar_juego(&juego, personaje);

    imprimir_terreno(juego); 
    
    return 0;  

}