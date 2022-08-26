#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "utiles.h"
#include "papeleo.h"
#include "dia_en_la_uni.h"

void tutorial_juego()
{
    printf("Bienvenido jugador! \n");
    printf("Se te haran un par de preguntas para decidir que personaje va a ayudarte en este desafio! \n");
    printf("Va a generarse un mapa aleatorio, en total hay 3. En los mapas los + son las paredes. \n");
    printf("Las F y las M son obstaculos, mientras que T e I son herramientas utiles. \n");
    printf("Tu jugador es la W, tu objetivo es conseguir todos los papeleos P, buena suerte! \n");
}

int main()
{
    srand((unsigned)time(NULL));

    juego_t juego;

    tutorial_juego();

    char personaje_tp1 = decidir_personaje_tp1();

    inicializar_juego(&juego, personaje_tp1);

    return 0;
}
