#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include"tp1.h"
#include "controlador.h"
#include"utiles.h"
#include"papeleo.h"

#define JUEGO_PERDIDO -1
#define JUEGO_GANADO 1
#define JUGANDO 0

void guia_jugador(){
    printf("Que empiece el Desafio\n");
    detener_el_tiempo(1);
    printf("tendras que responder una serie de preguntas para arrancar con un obsequio\n");
    detener_el_tiempo(1);
    printf("el cual te permitira atrbezar los obstaculos y recoger los papeleos\n");
    detener_el_tiempo(1);
    printf("para haci poder ir avanzando en los niveles y poder llevarte el trofeo\n");
    detener_el_tiempo(1);
}



int main(){
    
    srand((unsigned)time(NULL));

    char personaje = 'J'; 
    juego_t juego;

    //guia_jugador();

    //programa_tp1(&personaje);

    inicializar_controlador();
    
    inicializar_juego(&juego, personaje);
    

    while(estado_juego(juego) == JUGANDO){
        realizar_jugada(&juego);
        if((estado_nivel(juego.niveles[juego.nivel_actual-1].papeleos, juego.niveles[juego.nivel_actual-1].tope_papeleos) == JUEGO_GANADO) && (juego.nivel_actual < MAX_NIVELES)){
            juego.nivel_actual ++;
        }
    }
    /* 
    if(estado_juego(juego) == JUEGO_GANADO){
        printf(" \
     ######      ###    ##    ##    ###     ######  ######## ########          \n \
    ##    ##    ## ##   ###   ##   ## ##   ##    ##    ##    ##                \n \
    ##         ##   ##  ####  ##  ##   ##  ##          ##    ##                \n \
    ##   #### ##     ## ## ## ## ##     ##  ######     ##    ######            \n \
    ##    ##  ######### ##  #### #########       ##    ##    ##                \n \
    ##    ##  ##     ## ##   ### ##     ## ##    ##    ##    ##       ####     \n \
     ######   ##     ## ##    ## ##     ##  ######     ##    ######## ####     \n \
                                                                       ##      \n \
                                                                      ##       \n \
                                                                               \n \
    ######## ######## ##       ####  ######  #### ########     ###    ########  ########  ######  \n \
    ##       ##       ##        ##  ##    ##  ##  ##     ##   ## ##   ##     ## ##       ##    ## \n \
    ##       ##       ##        ##  ##        ##  ##     ##  ##   ##  ##     ## ##       ##       \n \
    ######   ######   ##        ##  ##        ##  ##     ## ##     ## ##     ## ######    ######  \n \
    ##       ##       ##        ##  ##        ##  ##     ## ######### ##     ## ##             ## \n \
    ##       ##       ##        ##  ##    ##  ##  ##     ## ##     ## ##     ## ##       ##    ## \n \
    ##       ######## ######## ####  ######  #### ########  ##     ## ########  ########  ######  \n \
                                                                                                  \n");
    
    }else{

        printf("Que pena, Vete a llonar a otro lado");
    }
    terminar_controlador();
   */  
    return 0;  

}