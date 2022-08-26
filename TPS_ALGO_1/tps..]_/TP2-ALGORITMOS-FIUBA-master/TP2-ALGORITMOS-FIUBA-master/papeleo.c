#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "utiles.h"
#include "papeleo.h"

#define MAX_COL_MAPA 100
#define MAX_FIL_MAPA 100
#define JASMIN 'J'
#define RAYO_MCQUEEN 'R'
#define STITCH 'S'
#define OLAF 'O'

const char FUEGOS = 'F', MEDIAS = 'M', BOTELLAS_DE_GRITOS = 'G', INTERRUPTORES_AHUYENTA_RANDALL = 'I', MIKE = 'W', VACIO = ' ', PARED = '+', PAPELEO = 'P';
const int COLUMNAS_NIVEL_1 = 22, COLUMNAS_NIVEL_2 = 17, COLUMNAS_NIVEL_3 = 12;
const int FILAS_NIVEL_1 = 22, FILAS_NIVEL_2 = 17, FILAS_NIVEL_3 = 12;
const int PAPELEOS_NIVEL_1 = 2, PAPELEOS_NIVEL_2 = 3, PAPELEOS_NIVEL_3 = 4;
const int FUEGOS_NIVEL_1 = 10, FUEGOS_NIVEL_2 = 5, FUEGOS_NIVEL_3 = 3;
const int MEDIAS_NIVEL_1 = 5, MEDIAS_NIVEL_2 = 4, MEDIAS_NIVEL_3 = 3;
const int MARTILLOS_NIVEL_1 = 4, MARTILLOS_NIVEL_2 = 5, MARTILLOS_NIVEL_3 = 6;
const int EXTINTORES_NIVEL_1 = 4, EXTINTORES_NIVEL_2 = 2, EXTINTORES_NIVEL_3 = 2;
const int BOTELLAS_GRITOS_NIVEL_1 = 4, BOTELLAS_GRITOS_NIVEL_2 = 3, BOTELLAS_GRITOS_NIVEL_3 = 2;
const int INTERRUPTORES_AHUYENTA_RANDALL_NIVEL_1 = 1, INTERRUPTORES_AHUYENTA_RANDALL_NIVEL_2 = 1, INTERRUPTORES_AHUYENTA_RANDALL_NIVEL_3 = 0;
const int MOVIMIENTOS_INICIALES_NIVEL_1 = 40, MOVIMIENTOS_INICIALES_NIVEL_2 = 30, MOVIMIENTOS_INICIALES_NIVEL_3 = 20;
const int NIVELES_TOTALES = 3;
const int ELIMINA_FUEGOS_OLAF_1 = 2, ELIMINA_FUEGOS_OLAF_2 = 1, MOVIMIENTOS_EXTRA_RAYO = 10, MARTILLOS_EXTRA_JASMIN = 1, PAPELEO_ELIMINADO_STITCH = 1;

/*
 * PRE-CONDICIONES: Los valores de las coordenadas de la posicion no deben ser numeros negativos
 * POST-CONDICIONES: Verifica que la posicion recibida se encuentre en un lugar vacio, si es asi devuelve verdadero, cualquier otro caso falso
 */
bool hay_espacio_libre(char mapa_juego[MAX_FIL_MAPA][MAX_COL_MAPA], coordenada_t posicion)
{
    return mapa_juego[posicion.fil][posicion.col] == VACIO;
}

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
 * POST-CONDICIONES: Define una posicion aleatoria y el tipo a un objeto
 */
void crear_objeto(objeto_t *objeto, char tipo, int nivel_actual)
{
    objeto->posicion = coordenada_aleatoria(nivel_actual);

    objeto->tipo = tipo;
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
        mapa_juego[papeleos[i].posicion.fil][papeleos[i].posicion.col] = PAPELEO;
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
    }
    else if (nivel_actual == 2)
    {
        jugador->extintores = EXTINTORES_NIVEL_2;
        jugador->movimientos = MOVIMIENTOS_INICIALES_NIVEL_2 + jugador->movimientos;
        jugador->martillos = MARTILLOS_NIVEL_2;
        jugador->ahuyenta_randall = false;
        jugador->posicion = pos_inicial;
    }
    else
    {
        jugador->extintores = EXTINTORES_NIVEL_3;
        jugador->movimientos = MOVIMIENTOS_INICIALES_NIVEL_3 + jugador->movimientos;
        jugador->martillos = MARTILLOS_NIVEL_3;
        jugador->ahuyenta_randall = false;
        jugador->posicion = pos_inicial;
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
        mapa_juego[papeleos[i].posicion.fil][papeleos[i].posicion.col] = PAPELEO;
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

    imprimir_terreno((*juego));
}
