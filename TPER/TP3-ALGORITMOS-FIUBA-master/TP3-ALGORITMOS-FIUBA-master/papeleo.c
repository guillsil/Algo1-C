#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "utiles.h"
#include "papeleo.h"
#include "enums.h"
#include "cargar_mapa.h"

const int PAPELEOS_NIVEL_1 = 2, PAPELEOS_NIVEL_2 = 3, PAPELEOS_NIVEL_3 = 4;
const int FUEGOS_NIVEL_1 = 10, FUEGOS_NIVEL_2 = 5, FUEGOS_NIVEL_3 = 3;
const int MEDIAS_NIVEL_1 = 5, MEDIAS_NIVEL_2 = 4, MEDIAS_NIVEL_3 = 3;
const int ELIMINA_FUEGOS_OLAF_1 = 2, ELIMINA_FUEGOS_OLAF_2 = 1, PAPELEO_ELIMINADO_STITCH = 1;
const int BOTELLAS_GRITOS_NIVEL_1 = 4, BOTELLAS_GRITOS_NIVEL_2 = 3, BOTELLAS_GRITOS_NIVEL_3 = 2;
const int INTERRUPTORES_AHUYENTA_RANDALL_NIVEL_1 = 1, INTERRUPTORES_AHUYENTA_RANDALL_NIVEL_2 = 1, INTERRUPTORES_AHUYENTA_RANDALL_NIVEL_3 = 0;

/*
 * PRE-CONDICIONES: Los valores de las coordenadas de la posicion no deben ser numeros negativos
 * POST-CONDICIONES: Primero verifica que la posicion recibida se encuentre en un lugar vacio, luego si arriba, abajo, izquierda o derecha tiene una pared, si es asi, devuelve verdadero, si no falso.
 */
bool esta_al_lado_pared(char mapa_juego[MAX_FIL_MAPA][MAX_COL_MAPA], coordenada_t posicion)
{
    return hay_espacio_libre(mapa_juego, posicion) && ((mapa_juego[posicion.fil - 1][posicion.col] == PARED) || (mapa_juego[posicion.fil + 1][posicion.col] == PARED) || (mapa_juego[posicion.fil][posicion.col - 1] == PARED) || (mapa_juego[posicion.fil][posicion.col + 1] == PARED));
}

/*
 * PRE-CONDICIONES: El nivel_actual deberia estar entre los posibles (3 en este caso)
 * POST-CONDICIONES: Define una posicion aleatoria y el tipo a un objeto
 */
void crear_objeto(objeto_t *objeto, char tipo, int nivel_actual)
{
    objeto->posicion = coordenada_aleatoria(nivel_actual);

    objeto->tipo = tipo;
}

/*
 * PRE-CONDICIONES: El nivel_actual deberia estar entre los posibles (3 en este caso)
 * POST-CONDICIONES: Crea los objetos obstaculos y los coloca en el mapa, verificando que la posicion que ocupen sea correcta, ademas de recibir al personaje del tp1 para obtener un beneficio
 */
void inicializar_obstaculos(objeto_t obstaculos[MAX_OBSTACULOS], int *tope_obstaculo, int nivel_actual, char mapa_juego[MAX_FIL_MAPA][MAX_COL_MAPA], char amigo)
{
    int cantidad_fuegos, cantidad_medias;

    int obstaculos_a_crear;

    if (nivel_actual == 1)
    {
        cantidad_fuegos = FUEGOS_NIVEL_1;
        cantidad_medias = MEDIAS_NIVEL_1;
    }
    else if (nivel_actual == 2)
    {
        cantidad_fuegos = FUEGOS_NIVEL_2;
        cantidad_medias = MEDIAS_NIVEL_2;
    }
    else
    {
        cantidad_fuegos = FUEGOS_NIVEL_3;
        cantidad_medias = MEDIAS_NIVEL_3;
    }

    if (amigo == OLAF && nivel_actual == 1)
    {
        cantidad_fuegos = FUEGOS_NIVEL_1 - ELIMINA_FUEGOS_OLAF_1;
    }
    else if (amigo == OLAF && nivel_actual == 2)
    {
        cantidad_fuegos = FUEGOS_NIVEL_2 - ELIMINA_FUEGOS_OLAF_2;
    }

    obstaculos_a_crear = cantidad_fuegos + (*tope_obstaculo);
    for (int i = (*tope_obstaculo); i < obstaculos_a_crear; i++)
    {
        do
        {
            crear_objeto(&obstaculos[i], FUEGOS, nivel_actual);
        } while (!esta_al_lado_pared(mapa_juego, obstaculos[i].posicion));

        (*tope_obstaculo)++;
        mapa_juego[obstaculos[i].posicion.fil][obstaculos[i].posicion.col] = obstaculos[i].tipo;
    }

    obstaculos_a_crear = cantidad_medias + (*tope_obstaculo);
    for (int i = (*tope_obstaculo); i < obstaculos_a_crear; i++)
    {
        do
        {
            crear_objeto(&obstaculos[i], MEDIAS, nivel_actual);
        } while (!hay_espacio_libre(mapa_juego, obstaculos[i].posicion));

        (*tope_obstaculo)++;
        mapa_juego[obstaculos[i].posicion.fil][obstaculos[i].posicion.col] = obstaculos[i].tipo;
    }
}

/*
 * PRE-CONDICIONES: El nivel_actual deberia estar entre los posibles (3 en este caso)
 * POST-CONDICIONES: Crea los objetos herramientas y los coloca en el mapa, verificando que la posicion que ocupen sea correcta.
 */
void inicializar_herramientas(objeto_t herramientas[MAX_HERRAMIENTAS], int *tope_herramientas, int nivel_actual, char mapa_juego[MAX_FIL_MAPA][MAX_COL_MAPA])
{
    int cantidad_interruptores_ahuyenta_randall, cantidad_botellas_grito;
    int herramientas_a_crear;

    if (nivel_actual == 1)
    {
        cantidad_interruptores_ahuyenta_randall = INTERRUPTORES_AHUYENTA_RANDALL_NIVEL_1;
        cantidad_botellas_grito = BOTELLAS_GRITOS_NIVEL_1;
    }
    else if (nivel_actual == 2)
    {
        cantidad_interruptores_ahuyenta_randall = INTERRUPTORES_AHUYENTA_RANDALL_NIVEL_2;
        cantidad_botellas_grito = BOTELLAS_GRITOS_NIVEL_2;
    }
    else
    {
        cantidad_interruptores_ahuyenta_randall = INTERRUPTORES_AHUYENTA_RANDALL_NIVEL_3;
        cantidad_botellas_grito = BOTELLAS_GRITOS_NIVEL_3;
    }

    herramientas_a_crear = cantidad_interruptores_ahuyenta_randall + (*tope_herramientas);
    for (int i = (*tope_herramientas); i < herramientas_a_crear; i++)
    {
        do
        {
            crear_objeto(&herramientas[i], INTERRUPTORES_AHUYENTA_RANDALL, nivel_actual);
        } while (!hay_espacio_libre(mapa_juego, herramientas[i].posicion));

        (*tope_herramientas)++;
        mapa_juego[herramientas[i].posicion.fil][herramientas[i].posicion.col] = herramientas[i].tipo;
    }

    herramientas_a_crear = cantidad_botellas_grito + (*tope_herramientas);
    for (int i = (*tope_herramientas); i < herramientas_a_crear; i++)
    {
        do
        {
            crear_objeto(&herramientas[i], BOTELLAS_DE_GRITOS, nivel_actual);
        } while (!hay_espacio_libre(mapa_juego, herramientas[i].posicion));

        (*tope_herramientas)++;
        mapa_juego[herramientas[i].posicion.fil][herramientas[i].posicion.col] = herramientas[i].tipo;
    }
}

/*
 * PRE-CONDICIONES: El nivel_actual deberia estar entre los posibles (3 en este caso)
 * POST-CONDICIONES: Crea los papeleos y los coloca en el mapa, verificando que la posicion que ocupen sea correcta, ademas de recibir al personaje del tp1 para obtener un beneficio
 */
void inicializar_papeleos(papeleo_t papeleos[MAX_PAPELEOS], int *tope_papeleos, int nivel_actual, char mapa_juego[MAX_FIL_MAPA][MAX_COL_MAPA], char amigo)
{
    int papeleos_a_crear;
    if (nivel_actual == 1)
    {
        papeleos_a_crear = PAPELEOS_NIVEL_1;
    }
    else if (nivel_actual == 2)
    {
        papeleos_a_crear = PAPELEOS_NIVEL_2;
    }
    else
    {
        papeleos_a_crear = PAPELEOS_NIVEL_3;
    }

    if (amigo == STITCH && nivel_actual == 3)
    {
        papeleos_a_crear = PAPELEOS_NIVEL_3 - PAPELEO_ELIMINADO_STITCH;
    }

    for (int i = 0; i < papeleos_a_crear; i++)
    {
        do
        {
            crear_papeleo(&papeleos[i], i, nivel_actual);
        } while (!hay_espacio_libre(mapa_juego, papeleos[i].posicion));

        (*tope_papeleos)++;
        mapa_juego[papeleos[i].posicion.fil][papeleos[i].posicion.col] = (char)(papeleos[i].id_papeleo + ASCII_DEL_0);
    }
}

/*
 * PRE-CONDICIONES: El nivel_actual deberia estar entre los posibles (3 en este caso)
 * POST-CONDICIONES: Llama a todos los procedimientos para cargar los valores en nivel
 */
void inicializar_nivel(nivel_t *nivel, int numero_nivel, char personaje_tp1)
{
    char mapa_juego[MAX_FIL_MAPA][MAX_COL_MAPA];

    nivel->tope_paredes = 0;
    nivel->tope_herramientas = 0;
    nivel->tope_obstaculos = 0;
    nivel->tope_papeleos = 0;

    obtener_paredes(numero_nivel, nivel->paredes, &nivel->tope_paredes, &nivel->pos_inicial_jugador);

    cargar_piso_juego(mapa_juego, numero_nivel);

    cargar_paredes_juego(nivel->paredes, mapa_juego, nivel->tope_paredes);

    cargar_posicion_inicial_jugador_juego(nivel->pos_inicial_jugador, mapa_juego);

    inicializar_obstaculos(nivel->obstaculos, &nivel->tope_obstaculos, numero_nivel, mapa_juego, personaje_tp1);

    inicializar_herramientas(nivel->herramientas, &nivel->tope_herramientas, numero_nivel, mapa_juego);

    inicializar_papeleos(nivel->papeleos, &nivel->tope_papeleos, numero_nivel, mapa_juego, personaje_tp1);
}

/*
 * POST-CONDICIONES: Inicializa todos los niveles del juego
 */
void inicializar_todos_los_niveles(juego_t *juego)
{
    for (int i = 1; i <= NIVELES_TOTALES; i++)
    {
        juego->nivel_actual = i;

        inicializar_nivel(&juego->niveles[juego->nivel_actual - 1], juego->nivel_actual, juego->personaje_tp1);
    }
}

/*
 * PRE-CONDICIONES: El nivel_actual deberia estar entre los posibles (3 en este caso)
 * POST-CONDICIONES: Carga todos los valores del nivel pasado como parametro al mapa del juego
 */
void cargar_terreno(nivel_t *nivel, char mapa_juego[MAX_FIL_MAPA][MAX_COL_MAPA], int nivel_actual)
{
    cargar_piso_juego(mapa_juego, nivel_actual);

    cargar_paredes_juego(nivel->paredes, mapa_juego, nivel->tope_paredes);

    cargar_posicion_inicial_jugador_juego(nivel->pos_inicial_jugador, mapa_juego);

    cargar_herramientas(nivel->herramientas, mapa_juego, nivel->tope_herramientas);

    cargar_obstaculos(nivel->obstaculos, mapa_juego, nivel->tope_obstaculos);

    cargar_papeleos(nivel->papeleos, mapa_juego, nivel->tope_papeleos);
}

/*
 * PRE-CONDICIONES: La variable juego ya deberia tener los valores cargados
 * POST-CONDICIONES: Llama a todos los procedimientos para llenar el mapa verdadero, y mostrarlo por pantalla
 */
void imprimir_terreno(juego_t juego)
{
    char mapa_juego[MAX_FIL_MAPA][MAX_COL_MAPA];

    cargar_terreno(&juego.niveles[juego.nivel_actual - 1], mapa_juego, juego.nivel_actual);

    mostrar_mapa(mapa_juego, juego.nivel_actual);
}

/*
 * POST-CONDICIONES: procedimiento principal que al llamarse se inicializan los campo del juego, ademas de llamar al procedimiento imprimir_terreno
 */
void inicializar_juego(juego_t *juego, char personaje_tp1)
{
    juego->personaje_tp1 = personaje_tp1;

    inicializar_todos_los_niveles(juego);

    juego->nivel_actual = 1;

    inicializar_jugador(&juego->jugador, juego->nivel_actual, juego->niveles[juego->nivel_actual - 1].pos_inicial_jugador, personaje_tp1);

    // imprimir_terreno((*juego));

    realizar_jugada(juego);
}