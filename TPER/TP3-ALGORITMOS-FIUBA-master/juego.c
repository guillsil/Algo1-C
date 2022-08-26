#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "utiles.h"
#include "papeleo.h"
#include "dia_en_la_uni.h"
#include "controlador.h"

const char QUIERE_VER_TUTORIAL = 'S';

/*
 * POST-CONDICIONES: Muestra el objetivo y las teclas del juego
 */
void tutorial_juego()
{
    printf("Bienvenido jugador! \n");

    printf("Se te haran un par de preguntas para decidir que personaje va a ayudarte en este desafio! \n");

    printf("Va a generarse un mapa aleatorio, en total hay 3. En los mapas los + son las paredes. \n");

    printf("Las F y las M son obstaculos, mientras que T e I son herramientas utiles. \n");

    printf("Tu jugador es la W, tu objetivo es conseguir todos los papeleos P. \n");

    printf("Las teclas que realizan acciones son: \n");

    printf("'D' movimiento a la derecha \n");

    printf("'A' movimiento a la izquierda \n");

    printf("'E' movimiento rotacional horario \n");

    printf("'Q' movimiento rotacional anti-horario \n");

    printf("'Z' utilizar un martillo para eliminar una pared cercana\n");

    printf("'C' utilizar un extintor para apagar un fuego cercano \n");

    printf("¡Buena suerte! \n")
        // ZAWARUDO
        detener_el_tiempo(10);
}

/*
 * POST-CONDICIONES: Muestra una introduccion a la historia del juego
 */
void contar_historia()
{
    printf("Mike: ¡Buenos dias Roz! Mi suculento caracol de jardin, ¿A quien vamos a asustar hoy? \n");

    detener_el_tiempo(1);

    printf("Roz: Wazowski, no ordenaste tu papeleo anoche... \n");

    detener_el_tiempo(1);

    printf("Mike: ugh, ese papeleo, no seria mejor mandarlo a... volaaaar. \n");

    detener_el_tiempo(1);

    printf("Roz: Me canse de tu impertinencia Wazowski, ahora encargate TU de buscar el papeleo. \n");

    detener_el_tiempo(1);

    printf("Mike: Pero Roz ¡no puedes hacerme esto! \n");

    detener_el_tiempo(1);

    printf("Roz: Si quieres que firme esa libreta, primero consigue TODOS los papeleos. Te estare vigilando... cuidado Wazowski, cuidadito... \n");

    detener_el_tiempo(1);

    printf("Mike: Es mejor que me ponga manos a la obra, si no mi amigo no me dara mi obsequio! digo, no podre ayudarlo. \n");

    detener_el_tiempo(3);
}

int main()
{
    // inicializar_controlador();

    juego_t juego;

    char quiere_ver_tutorial;

    srand((unsigned)time(NULL));

    printf("Quieres leer el tutorial y la historia? S para si, cualquier otra tecla no");

    scanf("%c", &quiere_ver_tutorial);

    if (quiere_ver_tutorial == QUIERE_VER_TUTORIAL)
    {
        contar_historia();

        tutorial_juego();
    }

    // char personaje_tp1 = decidir_personaje_tp1();

    char personaje_tp1 = 'J';

    inicializar_juego(&juego, personaje_tp1);

    if (estado_juego(juego) == GANADO)
    {
        printf("Felicidades!!! Conseguiste todos los papeleos");
    }
    else
    {
        printf("Tristeza, no lograste conseguir todos los papeleos :C");
    }
    // terminar_controlador();
    return 0;
}
