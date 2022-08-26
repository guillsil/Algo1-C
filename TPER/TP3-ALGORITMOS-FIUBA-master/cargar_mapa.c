#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "utiles.h"
#include "papeleo.h"
#include "enums.h"
#include "cargar_mapa.h"

const int MARTILLOS_NIVEL_1 = 4, MARTILLOS_NIVEL_2 = 5, MARTILLOS_NIVEL_3 = 6;
const int EXTINTORES_NIVEL_1 = 4, EXTINTORES_NIVEL_2 = 2, EXTINTORES_NIVEL_3 = 2;
const int MOVIMIENTOS_INICIALES_NIVEL_1 = 40, MOVIMIENTOS_INICIALES_NIVEL_2 = 30, MOVIMIENTOS_INICIALES_NIVEL_3 = 20;
const int MOVIMIENTOS_EXTRA_RAYO = 10, MARTILLOS_EXTRA_JASMIN = 1;

/*
 * PRE-CONDICIONES: Los valores de las coordenadas de la posicion no deben ser numeros negativos
 * POST-CONDICIONES: Verifica que la posicion recibida se encuentre en un lugar vacio, si es asi devuelve verdadero, cualquier otro caso falso
 */
bool hay_espacio_libre(char mapa_juego[MAX_FIL_MAPA][MAX_COL_MAPA], coordenada_t posicion)
{
    return mapa_juego[posicion.fil][posicion.col] == VACIO;
}

/*
 * PRE-CONDICIONES: El nivel_actual deberia estar entre los posibles (3 en este caso)
 * POST-CONDICIONES: Devuelve una coordenada aleatoria sin verificar que exista algo ya en esa posicion
 */
coordenada_t coordenada_aleatoria(int nivel_actual)
{
    int columnas, filas;
    if (nivel_actual == 1)
    {
        filas = FILAS_NIVEL_1;
        columnas = COLUMNAS_NIVEL_1;
    }
    else if (nivel_actual == 2)
    {
        filas = FILAS_NIVEL_2;
        columnas = COLUMNAS_NIVEL_2;
    }
    else
    {
        filas = FILAS_NIVEL_3;
        columnas = COLUMNAS_NIVEL_3;
    }

    coordenada_t coordenada;

    coordenada.fil = rand() % filas;

    coordenada.col = rand() % columnas;

    return coordenada;
}

/*
 * PRE-CONDICIONES: El nivel_actual deberia estar entre los posibles (3 en este caso)
 * POST-CONDICIONES: Rellena el mapa con el piso vacio
 */
void cargar_piso_juego(char mapa_juego[MAX_FIL_MAPA][MAX_COL_MAPA], int nivel_actual)
{
    int columnas_juego, filas_juego;
    if (nivel_actual == 1)
    {
        columnas_juego = COLUMNAS_NIVEL_1;
        filas_juego = FILAS_NIVEL_1;
    }
    else if (nivel_actual == 2)
    {
        columnas_juego = COLUMNAS_NIVEL_2;
        filas_juego = FILAS_NIVEL_2;
    }
    else
    {
        columnas_juego = COLUMNAS_NIVEL_3;
        filas_juego = FILAS_NIVEL_3;
    }

    for (int i = 0; i < columnas_juego; i++)
    {
        for (int j = 0; j < filas_juego; j++)
        {
            mapa_juego[i][j] = VACIO;
        }
    }
}

/*
 * PRE-CONDICIONES: Las paredes deben estar inicializadas (no puede estar vacio el vector paredes)
 * POST-CONDICIONES: Rellena el mapa con las posiciones de las paredes
 */
void cargar_paredes_juego(coordenada_t paredes[MAX_PAREDES], char mapa_juego[MAX_FIL_MAPA][MAX_COL_MAPA], int tope_pared)
{

    for (int i = 0; i < tope_pared; i++)
    {
        mapa_juego[paredes[i].fil][paredes[i].col] = PARED;
    }
}

/*
 * POST-CONDICIONES: Rellena el mapa con la posicion inicial del jugador
 */
void cargar_posicion_inicial_jugador_juego(coordenada_t pos_inicial_jugador, char mapa_juego[MAX_FIL_MAPA][MAX_COL_MAPA])
{
    mapa_juego[pos_inicial_jugador.fil][pos_inicial_jugador.col] = MIKE;
}

/*
 * POST-CONDICIONES: Actualiza la posicion del jugador en el mapa
 */
void cargar_posicion_jugador(coordenada_t posicion_jugador, char mapa_juego[MAX_FIL_MAPA][MAX_COL_MAPA])
{

    mapa_juego[posicion_jugador.fil][posicion_jugador.col] = MIKE;
}

/*
 * PRE-CONDICIONES: Los obstaculos deben estar inicializados (no puede estar vacio el vector obstaculos)
 * POST-CONDICIONES: Rellena el mapa con la posicion de los obstaculos
 */
void cargar_obstaculos(objeto_t obstaculos[MAX_OBSTACULOS], char mapa_juego[MAX_FIL_MAPA][MAX_COL_MAPA], int tope_obstaculos)
{
    for (int i = 0; i < tope_obstaculos; i++)
    {
        mapa_juego[obstaculos[i].posicion.fil][obstaculos[i].posicion.col] = obstaculos[i].tipo;
    }
}

/*
 * PRE-CONDICIONES: Las herramientas deben estar inicializadas (no puede estar vacio el vector herramientas)
 * POST-CONDICIONES: Rellena el mapa con la posicion de las herramientas
 */
void cargar_herramientas(objeto_t herramientas[MAX_HERRAMIENTAS], char mapa_juego[MAX_FIL_MAPA][MAX_COL_MAPA], int tope_pared)
{
    for (int i = 0; i < tope_pared; i++)
    {
        mapa_juego[herramientas[i].posicion.fil][herramientas[i].posicion.col] = herramientas[i].tipo;
    }
}

/*
 * PRE-CONDICIONES: Los papeleos deben estar inicializados (no puede estar vacio el vector papeleos)
 * POST-CONDICIONES: Rellena el mapa con la posicion de los papeleos
 */
void cargar_papeleos(papeleo_t papeleos[MAX_PAPELEOS], char mapa_juego[MAX_FIL_MAPA][MAX_COL_MAPA], int tope_papeleos)
{
    for (int i = 0; i < tope_papeleos; i++)
    {
        mapa_juego[papeleos[i].posicion.fil][papeleos[i].posicion.col] = (char)(papeleos[i].id_papeleo + ASCII_DEL_0);
    }
}

/*
 * PRE-CONDICIONES: El nivel_actual deberia estar entre los posibles (3 en este caso)
 * POST-CONDICIONES: Define una posicion inicial al jugador, junto con sus movimientos y herramientas. Tambien recibe su regalo dependiendo del personaje que obtuvo
 */
void inicializar_jugador(jugador_t *jugador, int nivel_actual, coordenada_t pos_inicial, char amigo)
{
    if (nivel_actual == 1)
    {
        jugador->extintores = EXTINTORES_NIVEL_1;
        jugador->movimientos = MOVIMIENTOS_INICIALES_NIVEL_1;
        jugador->martillos = MARTILLOS_NIVEL_1;
        jugador->ahuyenta_randall = false;
        jugador->posicion = pos_inicial;
        jugador->movimientos_realizados = 0;
    }
    else if (nivel_actual == 2)
    {
        jugador->extintores = EXTINTORES_NIVEL_2;
        jugador->movimientos = MOVIMIENTOS_INICIALES_NIVEL_2 + jugador->movimientos;
        jugador->martillos = MARTILLOS_NIVEL_2;
        jugador->ahuyenta_randall = false;
        jugador->posicion = pos_inicial;
        jugador->movimientos_realizados = 0;
    }
    else
    {
        jugador->extintores = EXTINTORES_NIVEL_3;
        jugador->movimientos = MOVIMIENTOS_INICIALES_NIVEL_3 + jugador->movimientos;
        jugador->martillos = MARTILLOS_NIVEL_3;
        jugador->ahuyenta_randall = false;
        jugador->posicion = pos_inicial;
        jugador->movimientos_realizados = 0;
    }

    if (amigo == JASMIN)
    {
        jugador->martillos = jugador->martillos + MARTILLOS_EXTRA_JASMIN;
    }

    if (amigo == RAYO_MCQUEEN && nivel_actual == 1)
    {
        jugador->movimientos = jugador->movimientos + MOVIMIENTOS_EXTRA_RAYO;
    }
}

/*
 * PRE-CONDICIONES: El nivel_actual deberia estar entre los posibles (3 en este caso)
 * POST-CONDICIONES: actualiza los valores del jugador al pasar de nivel
 */
void actualizar_jugador(jugador_t *jugador, int nivel_actual, char amigo)
{
    if (nivel_actual == 1)
    {
        jugador->extintores = EXTINTORES_NIVEL_1;
        jugador->movimientos = MOVIMIENTOS_INICIALES_NIVEL_1;
        jugador->martillos = MARTILLOS_NIVEL_1;
        jugador->ahuyenta_randall = false;
        jugador->movimientos_realizados = 0;
    }
    else if (nivel_actual == 2)
    {
        jugador->extintores = EXTINTORES_NIVEL_2;
        jugador->movimientos = MOVIMIENTOS_INICIALES_NIVEL_2 + jugador->movimientos;
        jugador->martillos = MARTILLOS_NIVEL_2;
        jugador->ahuyenta_randall = false;
        jugador->movimientos_realizados = 0;
    }
    else
    {
        jugador->extintores = EXTINTORES_NIVEL_3;
        jugador->movimientos = MOVIMIENTOS_INICIALES_NIVEL_3 + jugador->movimientos;
        jugador->martillos = MARTILLOS_NIVEL_3;
        jugador->ahuyenta_randall = false;
        jugador->movimientos_realizados = 0;
    }

    if (amigo == JASMIN)
    {
        jugador->martillos = jugador->martillos + MARTILLOS_EXTRA_JASMIN;
    }

    if (amigo == RAYO_MCQUEEN && nivel_actual == 1)
    {
        jugador->movimientos = jugador->movimientos + MOVIMIENTOS_EXTRA_RAYO;
    }
}

/*
 * PRE-CONDICIONES: El nivel_actual deberia estar entre los posibles (3 en este caso)
 * POST-CONDICIONES: Define una posicion aleatoria a una pared
 */
void crear_pared(coordenada_t *pared, int nivel_actual)
{
    (*pared) = coordenada_aleatoria(nivel_actual);
}

/*
 * PRE-CONDICIONES: El nivel_actual deberia estar entre los posibles (3 en este caso)
 * POST-CONDICIONES: Define una posicion aleatoria y el id a un papeleo, ademas de asignarle recolectado como falso
 */
void crear_papeleo(papeleo_t *papeleo, int papeleo_id, int nivel_actual)
{
    papeleo->id_papeleo = papeleo_id;

    papeleo->posicion = coordenada_aleatoria(nivel_actual);

    papeleo->recolectado = false;
}

/*
 * PRE-CONDICIONES: El nivel_actual deberia estar entre los posibles (3 en este caso)
 * POST-CONDICIONES: Crea una pared en una posicion aleatoria, verificando que esta este libre, y lo coloca en el mapa
 */
void generar_pared(char mapa_juego[MAX_FIL_MAPA][MAX_COL_MAPA], coordenada_t paredes[MAX_PAREDES], int *tope_paredes, int nivel_actual)
{
    do
    {
        crear_pared(&paredes[*tope_paredes], nivel_actual);
    } while (!hay_espacio_libre(mapa_juego, paredes[*tope_paredes]));

    mapa_juego[paredes[*tope_paredes].fil][paredes[*tope_paredes].col] = PARED;

    (*tope_paredes)++;
}

/*
 * POST-CONDICIONES: Cambia en la posicion indicada del mapa por otro elemento
 */
void cambiar_elemento_mapa(char mapa_juego[MAX_FIL_MAPA][MAX_COL_MAPA], int fil, int col, char elemento)
{
    mapa_juego[fil][col] = elemento;
}

/*
 * POST-CONDICIONES: Actualiza el mapa del juego con los nuevos datos
 */
void actualizar_mapa(nivel_t *nivel, char mapa_juego[MAX_FIL_MAPA][MAX_COL_MAPA], coordenada_t posicion_jugador)
{
    cargar_paredes_juego(nivel->paredes, mapa_juego, nivel->tope_paredes);

    cargar_posicion_jugador(posicion_jugador, mapa_juego);

    cargar_obstaculos(nivel->obstaculos, mapa_juego, nivel->tope_obstaculos);

    cargar_herramientas(nivel->herramientas, mapa_juego, nivel->tope_herramientas);

    cargar_papeleos(nivel->papeleos, mapa_juego, nivel->tope_papeleos);
}

/*
 * PRE-CONDICIONES: El nivel_actual deberia estar entre los posibles (3 en este caso), mapa_juego deberia estar ya relleno con valores
 * POST-CONDICIONES: Muestra el mapa verdadero del juego por pantalla,
 */
void mostrar_mapa(char mapa_juego[MAX_FIL_MAPA][MAX_COL_MAPA], int nivel_actual)
{
    int columnas_juego, filas_juego;

    if (nivel_actual == 1)
    {
        columnas_juego = COLUMNAS_NIVEL_1;
        filas_juego = FILAS_NIVEL_1;
    }
    else if (nivel_actual == 2)
    {
        columnas_juego = COLUMNAS_NIVEL_2;
        filas_juego = FILAS_NIVEL_2;
    }
    else
    {
        columnas_juego = COLUMNAS_NIVEL_3;
        filas_juego = FILAS_NIVEL_3;
    }

    for (int i = 0; i < filas_juego; i++)
    {
        for (int j = 0; j < columnas_juego; j++)
        {
            printf("%c", mapa_juego[i][j]);
        }
        printf("\n");
    }
}

/*
 * PRE-CONDICIONES: El nivel_actual deberia estar entre los posibles (3 en este caso), mapa_juego deberia estar ya relleno con valores
 * POST-CONDICIONES: carga el mapa con todos los valores iniciales del nivel
 */
void cargar_mapa(nivel_t *nivel, char mapa_juego[MAX_FIL_MAPA][MAX_COL_MAPA], int nivel_actual, jugador_t *jugador, char amigo)
{
    actualizar_jugador(jugador, nivel_actual, amigo);

    cargar_piso_juego(mapa_juego, nivel_actual);

    cargar_paredes_juego(nivel->paredes, mapa_juego, nivel->tope_paredes);

    cargar_posicion_inicial_jugador_juego(nivel->pos_inicial_jugador, mapa_juego);

    cargar_obstaculos(nivel->obstaculos, mapa_juego, nivel->tope_obstaculos);

    cargar_herramientas(nivel->herramientas, mapa_juego, nivel->tope_herramientas);

    cargar_papeleos(nivel->papeleos, mapa_juego, nivel->tope_papeleos);
}