#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "utiles.h"
#include "papeleo.h"
#include "enums.h"
#include "cargar_mapa.h"

const int MOVIMIENTOS_PARA_RANDALL_1 = 7, MOVIMIENTOS_PARA_RANDALL_2 = 5, MOVIMIENTOS_PARA_RANDALL_3 = 3;
const int PAREDES_A_CREAR_1 = 40, PAREDES_A_CREAR_2 = 30, PAREDES_A_CREAR_3 = 20;
const int MOVIMIENTOS_ELIMINADOS_MEDIAS = 10, MOVIMIENTOS_OTORGA_GRITOS = 7, PISAR_FUEGO = -100;
const char UTILIZAR_MARTILLO = 'Z', UTILIZAR_EXTINTOR = 'C', ACCION_ABAJO = 'S', ACCION_ARRIBA = 'W', ACCION_DERECHA = 'D', ACCION_IZQUIERDA = 'A', ROTACION_HORARIA = 'E', ROTACION_ANTI_HORARIA = 'Q';
/*
 * PRE-CONDICIONES: Los valores de las coordenadas de la posicion deberian estar dentro de los bordes del mapa, contando a estos.
 * POST-CONDICIONES: devuelve el elemento que se encuentra en la posicion indicada
 */
char elemento_en_posicion(char mapa_juego[MAX_FIL_MAPA][MAX_COL_MAPA], int fil, int col)
{
    return mapa_juego[fil][col];
}

/*
 * POST-CONDICIONES: Verifica que la posicion de una pared recibida este en uno de los bordes del mapa, si lo esta, devuelve verdadero, si no, falso
 */
bool pared_esta_en_borde(coordenada_t pared, int nivel_actual)
{
    if (nivel_actual == 1)
    {
        return (pared.col == 0 || pared.fil == 0 || pared.col == COLUMNAS_NIVEL_1 - 1 || pared.fil == FILAS_NIVEL_1 - 1);
    }
    else if (nivel_actual == 2)
    {
        return (pared.col == 0 || pared.fil == 0 || pared.col == COLUMNAS_NIVEL_2 - 1 || pared.fil == FILAS_NIVEL_2 - 1);
    }
    else
    {
        return (pared.col == 0 || pared.fil == 0 || pared.col == COLUMNAS_NIVEL_3 - 1 || pared.fil == FILAS_NIVEL_3 - 1);
    }
}

/*
 * PRE-CONDICIONES: Los valores de las coordenadas de la posicion deberian estar dentro de los bordes del mapa, contando a estos.
 * POST-CONDICIONES: Si el elemento en la posicion indicada es una pared, devuelve falso, cualquier otro elemento, verdadero
 */
bool movimiento_permitido(char mapa_juego[MAX_FIL_MAPA][MAX_COL_MAPA], int fil, int col)
{
    return elemento_en_posicion(mapa_juego, fil, col) != PARED;
}

/*
 * POST-CONDICIONES: Verifica los papeleos, si todos los elementos del vector tienen el campo recolectado como verdadero, devuelve ganado, si no, jugando
 */
int estado_nivel(papeleo_t papeleos[MAX_PAPELEOS], int tope_papeleos)
{
    int i = 0;

    int papeleos_necesarios = tope_papeleos;

    int papeleos_obtenidos = 0;

    bool tiene_todos_papeleos = false;

    int estado_actual = JUGANDO;

    while (i < tope_papeleos && !tiene_todos_papeleos)
    {

        if (papeleos[i].recolectado)
        {
            papeleos_obtenidos++;
        }
        if (papeleos_obtenidos == papeleos_necesarios)
        {
            tiene_todos_papeleos = true;

            estado_actual = GANADO;
        }

        i++;
    }

    return estado_actual;
}

/*
 * POST-CONDICIONES: Si los movimientos del jugador son menores que 0, se pierde el juego, si no, devuelve jugando
 * verifica si el ultimo nivel tiene recolectado todos los papeleos, si es asi, se gana el juego.
 */
int estado_juego(juego_t juego)
{
    int estado_actual = JUGANDO;

    if (juego.jugador.movimientos <= 0)
    {
        estado_actual = PERDIDO;

        return estado_actual;
    }

    if (estado_nivel(juego.niveles[NIVELES_TOTALES - 1].papeleos, juego.niveles[NIVELES_TOTALES - 1].tope_papeleos) == GANADO)
    {
        estado_actual = GANADO;

        return estado_actual;
    }
    else
    {
        estado_actual = JUGANDO;

        return estado_actual;
    }
}

/*
 * PRE-CONDICIONES: debe haber almenos un papeleo, asi que el tope debe ser mayor o igual que 1
 * POST-CONDICIONES: sobreescribe un papeleo existente que no fue recolectado por otro en una posicion aleatoria
 */
void cambiar_posicion_papeleos(char mapa_juego[MAX_FIL_MAPA][MAX_COL_MAPA], papeleo_t papeleos[MAX_PAPELEOS], int tope_papeleos, int nivel_actual)
{
    int papeleo_aleatorio = rand() % (tope_papeleos);

    do
    {
        if (!papeleos[papeleo_aleatorio].recolectado)
        {
            cambiar_elemento_mapa(mapa_juego, papeleos[papeleo_aleatorio].posicion.fil, papeleos[papeleo_aleatorio].posicion.col, VACIO);

            crear_papeleo(&papeleos[papeleo_aleatorio], papeleo_aleatorio, nivel_actual);
        }
        else
        {
            papeleo_aleatorio = rand() % (tope_papeleos);
        }

    } while (!hay_espacio_libre(mapa_juego, papeleos[papeleo_aleatorio].posicion));
}

/*
 * POST-CONDICIONES: devuelve el indice del vector recibido en el cual se encuentra la pared con la fila y columna especificada
 */
int indice_pared_posicion_indicada(coordenada_t paredes[MAX_PAREDES], int tope_paredes, int fil, int col)
{
    int i = 0;

    bool encontrado = false;

    while (i < tope_paredes && !encontrado)
    {
        if ((paredes[i].fil == fil) && (paredes[i].col == col))
        {
            encontrado = true;
        }

        i++;
    }

    return i - 1;
}

/*
 * POST-CONDICIONES: devuelve el indice del vector recibido en el cual se encuentra el fuego con la fila y columna especificada
 */
int indice_fuego_posicion_indicada(objeto_t obstaculos[MAX_OBSTACULOS], int tope_obstaculos, int fil, int col)
{
    int i = 0;

    bool encontrado = false;

    while (i < tope_obstaculos && !encontrado)
    {
        if ((obstaculos[i].posicion.fil == fil) && (obstaculos[i].posicion.col == col))
        {
            encontrado = true;
        }

        i++;
    }

    return i - 1;
}

/*
 * PRE-CONDICIONES: debe haber almenos un papeleo, asi que el tope debe ser mayor o igual que 1
 * POST-CONDICIONES: cuando los movimientos realizados por el jugador son divisibles por alguno de los 3 valores posibles y esta desactivado el
 * ahuyenta randall, se llama a la funcion cambiar_posicion_papeleos
 */
void ataque_de_randall(char mapa_juego[MAX_FIL_MAPA][MAX_COL_MAPA], jugador_t jugador, papeleo_t papeleos[MAX_PAPELEOS], int tope_papeleos, int nivel_actual)
{
    if ((jugador.movimientos_realizados != 0) && (nivel_actual == 1) && !(jugador.ahuyenta_randall) && (jugador.movimientos_realizados % MOVIMIENTOS_PARA_RANDALL_1 == 0))
    {
        cambiar_posicion_papeleos(mapa_juego, papeleos, tope_papeleos, nivel_actual);
    }
    else if ((jugador.movimientos_realizados != 0) && (nivel_actual == 2) && !(jugador.ahuyenta_randall) && (jugador.movimientos_realizados % MOVIMIENTOS_PARA_RANDALL_2 == 0))
    {
        cambiar_posicion_papeleos(mapa_juego, papeleos, tope_papeleos, nivel_actual);
    }
    else if ((jugador.movimientos_realizados != 0) && (nivel_actual == 3) && !(jugador.ahuyenta_randall) && (jugador.movimientos_realizados % MOVIMIENTOS_PARA_RANDALL_3 == 0))
    {
        cambiar_posicion_papeleos(mapa_juego, papeleos, tope_papeleos, nivel_actual);
    }
}

/*
 * PRE-CONDICIONES: El nivel_actual deberia estar entre los posibles (3 en este caso)
 * POST-CONDICIONES: verifica que exista una pared en la posicion donde el jugador intenta utilizar un martillo, si existe, devuelve su indice del vector, caso contrario, un error
 */
int posicion_pared_al_lado_jugador(char mapa_juego[MAX_FIL_MAPA][MAX_COL_MAPA], coordenada_t paredes[MAX_PAREDES], int tope_paredes, coordenada_t posicion_jugador, char posicion, int nivel_actual)
{
    int indice = ERROR;

    if ((posicion == ACCION_ABAJO) || (posicion == ACCION_ARRIBA) || (posicion == ACCION_DERECHA) || (posicion == ACCION_IZQUIERDA))
    {
        if ((posicion == ACCION_ABAJO) && (elemento_en_posicion(mapa_juego, posicion_jugador.fil + 1, posicion_jugador.col) == PARED))
        {
            indice = indice_pared_posicion_indicada(paredes, tope_paredes, posicion_jugador.fil + 1, posicion_jugador.col);
        }
        else if ((posicion == ACCION_ARRIBA) && (elemento_en_posicion(mapa_juego, posicion_jugador.fil - 1, posicion_jugador.col) == PARED))
        {
            indice = indice_pared_posicion_indicada(paredes, tope_paredes, posicion_jugador.fil - 1, posicion_jugador.col);
        }
        else if ((posicion == ACCION_DERECHA) && (elemento_en_posicion(mapa_juego, posicion_jugador.fil, posicion_jugador.col + 1) == PARED))
        {
            indice = indice_pared_posicion_indicada(paredes, tope_paredes, posicion_jugador.fil, posicion_jugador.col + 1);
        }
        else if ((posicion == ACCION_IZQUIERDA) && (elemento_en_posicion(mapa_juego, posicion_jugador.fil, posicion_jugador.col - 1) == PARED))
        {
            indice = indice_pared_posicion_indicada(paredes, tope_paredes, posicion_jugador.fil, posicion_jugador.col - 1);
        }
    }

    if (!pared_esta_en_borde(paredes[indice], nivel_actual))
    {
        return indice;
    }

    return ERROR;
}

/*
 * PRE-CONDICIONES: El nivel_actual deberia estar entre los posibles (3 en este caso)
 * POST-CONDICIONES: verifica que exista un fuego en la posicion donde el jugador intenta utilizar un extintor, si existe, devuelve su indice del vector, caso contrario, un error
 */
int posicion_fuego_al_lado_jugador(char mapa_juego[MAX_FIL_MAPA][MAX_COL_MAPA], objeto_t obstaculos[MAX_OBSTACULOS], int tope_obstaculos, coordenada_t posicion_jugador, char posicion)
{
    int indice = ERROR;

    if ((posicion == ACCION_ARRIBA) || (posicion == ACCION_DERECHA) || (posicion == ACCION_IZQUIERDA))
    {

        if ((posicion == ACCION_ARRIBA) && (elemento_en_posicion(mapa_juego, posicion_jugador.fil - 1, posicion_jugador.col) == FUEGOS))
        {
            indice = indice_fuego_posicion_indicada(obstaculos, tope_obstaculos, posicion_jugador.fil - 1, posicion_jugador.col);
        }
        else if ((posicion == ACCION_DERECHA) && (elemento_en_posicion(mapa_juego, posicion_jugador.fil, posicion_jugador.col + 1) == FUEGOS))
        {
            indice = indice_fuego_posicion_indicada(obstaculos, tope_obstaculos, posicion_jugador.fil, posicion_jugador.col + 1);
        }
        else if ((posicion == ACCION_IZQUIERDA) && (elemento_en_posicion(mapa_juego, posicion_jugador.fil, posicion_jugador.col - 1) == FUEGOS))
        {
            indice = indice_fuego_posicion_indicada(obstaculos, tope_obstaculos, posicion_jugador.fil, posicion_jugador.col - 1);
        }
    }
    return indice;
}

/*
 * PRE-CONDICIONES: El nivel_actual deberia estar entre los posibles (3 en este caso)
 * POST-CONDICIONES: elimina de forma fisica una pared del vector si existe en la posicion indicada y es valida
 */
void destruir_pared(char mapa_juego[MAX_FIL_MAPA][MAX_COL_MAPA], nivel_t *nivel, jugador_t *jugador, char posicion_martilleo, int nivel_actual)
{
    int indice_pared = posicion_pared_al_lado_jugador(mapa_juego, nivel->paredes, nivel->tope_paredes, jugador->posicion, posicion_martilleo, nivel_actual);

    if (indice_pared != ERROR)
    {
        cambiar_elemento_mapa(mapa_juego, nivel->paredes[indice_pared].fil, nivel->paredes[indice_pared].col, VACIO);

        nivel->paredes[indice_pared] = nivel->paredes[nivel->tope_paredes - 1];

        (jugador->martillos) = (jugador->martillos - 1);

        (nivel->tope_paredes--);
    }
    else
    {
        printf("Accion cancelada, recorda que no podes martillar al aire o una pared del borde.");
    }
}

/*
 * PRE-CONDICIONES: El nivel_actual deberia estar entre los posibles (3 en este caso)
 * POST-CONDICIONES: elimina de forma fisica un fuego del vector si existe en la posicion indicada
 */
void apagar_fuego(nivel_t *nivel, jugador_t *jugador, char posicion_extintor, char mapa_juego[MAX_FIL_MAPA][MAX_COL_MAPA])
{
    int indice_fuego = posicion_fuego_al_lado_jugador(mapa_juego, nivel->obstaculos, nivel->tope_obstaculos, jugador->posicion, posicion_extintor);

    if (indice_fuego != ERROR)
    {
        cambiar_elemento_mapa(mapa_juego, nivel->obstaculos[indice_fuego].posicion.fil, nivel->obstaculos[indice_fuego].posicion.col, VACIO);

        nivel->obstaculos[indice_fuego] = nivel->obstaculos[nivel->tope_obstaculos - 1];

        (jugador->extintores) = (jugador->extintores - 1);

        nivel->tope_obstaculos--;
    }
    else
    {
        printf("Accion cancelada, recorda que no podes usar un extintor a la nada.");
    }
}

/*
 * PRE-CONDICIONES: El nivel_actual deberia estar entre los posibles (3 en este caso)
 * POST-CONDICIONES: Rota todos los elementos del mapa menos al jugador de manera horario o anti-horaria
 */
void controlador_rotacion(char mapa_juego[MAX_FIL_MAPA][MAX_COL_MAPA], nivel_t *nivel, coordenada_t *posicion_jugador, char tipo_rotacion, int nivel_actual)
{
    int filas_totales;

    int columnas_totales;

    int auxiliar;

    cargar_piso_juego(mapa_juego, nivel_actual);

    if (nivel_actual == 1)
    {
        filas_totales = FILAS_NIVEL_1 - 1;
        columnas_totales = COLUMNAS_NIVEL_1 - 1;
    }
    else if (nivel_actual == 2)
    {
        filas_totales = FILAS_NIVEL_2 - 1;
        columnas_totales = COLUMNAS_NIVEL_2 - 1;
    }
    else if (nivel_actual == 3)
    {
        filas_totales = FILAS_NIVEL_3 - 1;
        columnas_totales = COLUMNAS_NIVEL_3 - 1;
    }

    if (tipo_rotacion == ROTACION_HORARIA)
    {
        auxiliar = (posicion_jugador->col);

        posicion_jugador->col = abs((posicion_jugador->fil - filas_totales));

        posicion_jugador->fil = auxiliar;

        for (int i = 0; i < nivel->tope_paredes; i++)
        {
            auxiliar = nivel->paredes[i].col;

            nivel->paredes[i].col = abs((nivel->paredes[i].fil - filas_totales));

            nivel->paredes[i].fil = auxiliar;
        }
        for (int i = 0; i < nivel->tope_obstaculos; i++)
        {
            auxiliar = nivel->obstaculos[i].posicion.col;

            nivel->obstaculos[i].posicion.col = abs(nivel->obstaculos[i].posicion.fil - filas_totales);

            nivel->obstaculos[i].posicion.fil = auxiliar;
        }
        for (int i = 0; i < nivel->tope_herramientas; i++)
        {
            auxiliar = nivel->herramientas[i].posicion.col;

            nivel->herramientas[i].posicion.col = abs(nivel->herramientas[i].posicion.fil - filas_totales);

            nivel->herramientas[i].posicion.fil = auxiliar;
        }
        for (int i = 0; i < nivel->tope_papeleos; i++)
        {
            auxiliar = nivel->papeleos[i].posicion.col;

            nivel->papeleos[i].posicion.col = abs(nivel->papeleos[i].posicion.fil - filas_totales);

            nivel->papeleos[i].posicion.fil = auxiliar;
        }
    }
    else if (tipo_rotacion == ROTACION_ANTI_HORARIA)
    {
        auxiliar = (posicion_jugador->fil);

        posicion_jugador->fil = abs((posicion_jugador->col - columnas_totales));

        posicion_jugador->col = auxiliar;

        for (int i = 0; i < nivel->tope_paredes; i++)
        {
            auxiliar = nivel->paredes[i].fil;

            nivel->paredes[i].fil = abs(nivel->paredes[i].col - columnas_totales);

            nivel->paredes[i].col = auxiliar;
        }
        for (int i = 0; i < nivel->tope_obstaculos; i++)
        {
            auxiliar = nivel->obstaculos[i].posicion.fil;

            nivel->obstaculos[i].posicion.fil = abs(nivel->obstaculos[i].posicion.col - columnas_totales);

            nivel->obstaculos[i].posicion.col = auxiliar;
        }
        for (int i = 0; i < nivel->tope_herramientas; i++)
        {
            auxiliar = nivel->herramientas[i].posicion.fil;

            nivel->herramientas[i].posicion.fil = abs(nivel->herramientas[i].posicion.col - columnas_totales);

            nivel->herramientas[i].posicion.col = auxiliar;
        }
        for (int i = 0; i < nivel->tope_papeleos; i++)
        {
            auxiliar = nivel->papeleos[i].posicion.fil;

            nivel->papeleos[i].posicion.fil = abs(nivel->papeleos[i].posicion.col - columnas_totales);

            nivel->papeleos[i].posicion.col = auxiliar;
        }
    }

    actualizar_mapa(nivel, mapa_juego, *posicion_jugador);
}

/*
 * PRE-CONDICIONES: papeleos obtenidos deberia empezar en 0
 * POST-CONDICIONES: elimina de forma logica un papeleo del vector, cambiando su estado de recolectado a verdadero.
 */
void controlador_papeleos(char mapa_juego[MAX_FIL_MAPA][MAX_COL_MAPA], coordenada_t posicion_jugador, papeleo_t papeleos[MAX_PAPELEOS], int *papeleos_obtenidos)
{
    if (elemento_en_posicion(mapa_juego, posicion_jugador.fil, posicion_jugador.col) == (char)(*papeleos_obtenidos + ASCII_DEL_0))
    {
        papeleos[*papeleos_obtenidos].recolectado = true;

        (*papeleos_obtenidos) = (*papeleos_obtenidos) + 1;
    }
}

/*
 * POST-CONDICIONES: verifica la cantidad de martillos que tenga el jugador sea mayor que 0, si lo es, pregunta
 * pregunta al jugador hacia donde quiere martillar, para luego llamar a destruir_pared
 */
void controlador_martillo(char mapa_juego[MAX_FIL_MAPA][MAX_COL_MAPA], juego_t *juego)
{
    char posicion_martilleo;

    if (juego->jugador.martillos <= 0)
    {
        printf("No cuentas con ningun martillo \n");
    }
    else
    {
        printf("Hacia donde quieres martillar? W arriba, S abajo, D derecha, A izquierda \n");

        scanf(" %c", &posicion_martilleo);

        destruir_pared(mapa_juego, &juego->niveles[juego->nivel_actual - 1], &juego->jugador, posicion_martilleo, juego->nivel_actual);
    }
}

/*
 * PRE-CONDICIONES: El nivel_actual deberia estar entre los posibles (3 en este caso)
 * POST-CONDICIONES: controla cuando es posible llamar a generar_pared verificando el nivel actual y los movimientos realizados del jugador
 */
void controlador_paredes(char mapa_juego[MAX_FIL_MAPA][MAX_COL_MAPA], nivel_t *nivel, int nivel_actual, int movimientos_realizados)
{
    if (nivel_actual == 1 && movimientos_realizados <= PAREDES_A_CREAR_1)
    {
        generar_pared(mapa_juego, nivel->paredes, &nivel->tope_paredes, nivel_actual);
    }
    else if (nivel_actual == 2 && movimientos_realizados <= PAREDES_A_CREAR_2)
    {
        generar_pared(mapa_juego, nivel->paredes, &nivel->tope_paredes, nivel_actual);
    }
    else if (nivel_actual == 3 && movimientos_realizados <= PAREDES_A_CREAR_3)
    {
        generar_pared(mapa_juego, nivel->paredes, &nivel->tope_paredes, nivel_actual);
    }
}

/*
 * POST-CONDICIONES: verifica la cantidad de extintores que tenga el jugador sea mayor que 0, si lo es, pregunta
 * pregunta al jugador hacia donde quiere extinguir fuego, para luego llamar a apagar_fuego
 */
void controlador_extintor(char mapa_juego[MAX_FIL_MAPA][MAX_COL_MAPA], juego_t *juego)
{
    char posicion_extintor;

    if (juego->jugador.extintores <= 0)
    {
        printf("No cuentas con ningun extintor");
    }
    else
    {
        printf("Hacia donde quieres apagar el fuego? W arriba, D derecha, A izquierda");

        scanf(" %c", &posicion_extintor);

        apagar_fuego(&juego->niveles[juego->nivel_actual - 1], &juego->jugador, posicion_extintor, mapa_juego);
    }
}

/*
 * POST-CONDICIONES: dependiendo del caracter que se le envia, realizara una accion relacionada con el movimiento,
 * ya sea moverse a la derecha, izquierda o rotar el mapa de forma horaria o anti-horaria
 */
void controlador_movimiento(char mapa_juego[MAX_FIL_MAPA][MAX_COL_MAPA], juego_t *juego, char accion)
{
    bool logro_movimiento = false;

    if ((accion == ACCION_DERECHA) && (movimiento_permitido(mapa_juego, juego->jugador.posicion.fil, juego->jugador.posicion.col + 1)))
    {
        logro_movimiento = true;

        cambiar_elemento_mapa(mapa_juego, juego->jugador.posicion.fil, juego->jugador.posicion.col, VACIO);

        juego->jugador.posicion.col++;

        juego->jugador.movimientos_realizados++;

        juego->jugador.movimientos--;
    }
    else if (accion == ACCION_IZQUIERDA && movimiento_permitido(mapa_juego, juego->jugador.posicion.fil, juego->jugador.posicion.col - 1))
    {
        logro_movimiento = true;

        cambiar_elemento_mapa(mapa_juego, juego->jugador.posicion.fil, juego->jugador.posicion.col, VACIO);

        juego->jugador.posicion.col--;

        juego->jugador.movimientos_realizados++;

        juego->jugador.movimientos--;
    }
    else if (accion == ROTACION_HORARIA)
    {
        logro_movimiento = true;

        controlador_rotacion(mapa_juego, &juego->niveles[juego->nivel_actual - 1], &juego->jugador.posicion, accion, juego->nivel_actual);

        juego->jugador.movimientos_realizados++;

        juego->jugador.movimientos--;
    }
    else if (accion == ROTACION_ANTI_HORARIA)
    {
        logro_movimiento = true;

        controlador_rotacion(mapa_juego, &juego->niveles[juego->nivel_actual - 1], &juego->jugador.posicion, accion, juego->nivel_actual);

        cambiar_elemento_mapa(mapa_juego, juego->jugador.posicion.fil, juego->jugador.posicion.col, VACIO);

        juego->jugador.movimientos_realizados++;

        juego->jugador.movimientos--;
    }
    else
    {
        printf("Accion cancelada");
    }

    if (logro_movimiento)
    {
        controlador_paredes(mapa_juego, &juego->niveles[juego->nivel_actual], juego->nivel_actual, juego->jugador.movimientos_realizados);
    }
}

/*
 * PRE-CONDICIONES: papeleos obtenidos deberia empezar en 0
 * POST-CONDICIONES: Verifica la posicion del jugador, dependiendo del elemento con el que haya interactuado ocurren distintos sucesos
 */
void verificar_posicion(char mapa_juego[MAX_FIL_MAPA][MAX_COL_MAPA], juego_t *juego, int *papeleos_obtenidos)
{
    int fila_jugador = juego->jugador.posicion.fil;

    int columna_jugador = juego->jugador.posicion.col;

    if (elemento_en_posicion(mapa_juego, fila_jugador, columna_jugador) == FUEGOS)
    {
        juego->jugador.movimientos = PISAR_FUEGO;
    }
    else if (elemento_en_posicion(mapa_juego, fila_jugador, columna_jugador) == MEDIAS)
    {
        juego->jugador.movimientos -= MOVIMIENTOS_ELIMINADOS_MEDIAS;
    }
    else if (elemento_en_posicion(mapa_juego, fila_jugador, columna_jugador) == INTERRUPTORES_AHUYENTA_RANDALL)
    {
        (juego->jugador.ahuyenta_randall) = !(juego->jugador.ahuyenta_randall);
    }
    else if (elemento_en_posicion(mapa_juego, fila_jugador, columna_jugador) == (char)(*papeleos_obtenidos + ASCII_DEL_0))
    {
        controlador_papeleos(mapa_juego, juego->jugador.posicion, juego->niveles[juego->nivel_actual - 1].papeleos, papeleos_obtenidos);
    }
    else if (elemento_en_posicion(mapa_juego, fila_jugador, columna_jugador) == BOTELLAS_DE_GRITOS)
    {
        juego->jugador.movimientos += MOVIMIENTOS_OTORGA_GRITOS;
    }
}

/*
 * PRE-CONDICIONES: papeleos obtenidos deberia empezar en 0
 * POST-CONDICIONES: si el jugador no se encuentra sobre una pared, cae hasta estar sobre una, detecta los elementos que interactuo al caer
 */
void aplicar_gravedad(char mapa_juego[MAX_FIL_MAPA][MAX_COL_MAPA], juego_t *juego, int *papeleos_obtenidos)
{
    verificar_posicion(mapa_juego, juego, papeleos_obtenidos);

    int i = juego->jugador.posicion.fil;

    int altura_original_jugador = juego->jugador.posicion.fil;

    bool tocando_piso = false;

    int altura_nivel;

    if (juego->nivel_actual == 1)
    {
        altura_nivel = FILAS_NIVEL_1;
    }
    else if (juego->nivel_actual == 2)
    {
        altura_nivel = FILAS_NIVEL_2;
    }
    else if (juego->nivel_actual == 3)
    {
        altura_nivel = FILAS_NIVEL_3;
    }

    while (i < altura_nivel && !tocando_piso)
    {
        if (elemento_en_posicion(mapa_juego, juego->jugador.posicion.fil + 1, juego->jugador.posicion.col) == PARED)
        {
            cambiar_elemento_mapa(mapa_juego, altura_original_jugador, juego->jugador.posicion.col, VACIO);

            tocando_piso = true;
        }
        else
        {
            juego->jugador.posicion.fil++;
        }

        verificar_posicion(mapa_juego, juego, papeleos_obtenidos);

        i++;
    }
}

/*
 * PRE-CONDICIONES: el juego deberia tener los valores iniciales cargados
 * POST-CONDICIONES: procedimiento principal que maneja el flujo del juego, preguntando al jugador que jugadas va a realizar
 * pasando niveles cuando sea correcto y terminando el programa cuando se pierde el juego.
 */
void realizar_jugada(juego_t *juego)
{
    char tecla;

    char mapa_juego[MAX_FIL_MAPA][MAX_COL_MAPA];

    int papeleos_obtenidos;

    int i = 1;

    int estado_juego_actual = JUGANDO;

    while ((i <= NIVELES_TOTALES) && !(estado_juego_actual == PERDIDO))
    {
        papeleos_obtenidos = 0;

        juego->nivel_actual = i;

        int estado_nivel_actual = JUGANDO;

        cargar_mapa(&juego->niveles[juego->nivel_actual - 1], mapa_juego, juego->nivel_actual, &juego->jugador, juego->personaje_tp1);

        while ((estado_nivel_actual == JUGANDO) && !(estado_juego_actual == PERDIDO))
        {
            aplicar_gravedad(mapa_juego, juego, &papeleos_obtenidos);

            ataque_de_randall(mapa_juego, juego->jugador, juego->niveles[juego->nivel_actual - 1].papeleos, juego->niveles[juego->nivel_actual - 1].tope_papeleos, juego->nivel_actual);

            actualizar_mapa(&juego->niveles[juego->nivel_actual - 1], mapa_juego, juego->jugador.posicion);

            estado_nivel_actual = estado_nivel(juego->niveles[juego->nivel_actual - 1].papeleos, juego->niveles[juego->nivel_actual - 1].tope_papeleos);

            estado_juego_actual = estado_juego(*juego);

            mostrar_mapa(mapa_juego, juego->nivel_actual);

            printf("Que jugada vas a realizar? \n");

            printf("Movimientos restantes: %i \n", juego->jugador.movimientos);

            printf("Movimientos realizados: %i \n", juego->jugador.movimientos_realizados);

            printf("Cantidad de martillos disponsibles: %i \n", juego->jugador.martillos);

            printf("Cantidad de extintores disponsibles: %i \n", juego->jugador.extintores);

            if (estado_juego_actual != PERDIDO)
            {
                scanf(" %c", &tecla);
            }

            if (tecla == UTILIZAR_MARTILLO)
            {
                controlador_martillo(mapa_juego, juego);
            }
            else if (tecla == ACCION_DERECHA)
            {
                controlador_movimiento(mapa_juego, juego, tecla);
            }
            else if (tecla == ACCION_IZQUIERDA)
            {
                controlador_movimiento(mapa_juego, juego, tecla);
            }
            else if (tecla == ROTACION_HORARIA)
            {
                controlador_movimiento(mapa_juego, juego, tecla);
            }
            else if (tecla == ROTACION_ANTI_HORARIA)
            {
                controlador_movimiento(mapa_juego, juego, tecla);
            }
            else if (tecla == UTILIZAR_EXTINTOR)
            {
                controlador_extintor(mapa_juego, juego);
            }
            else
            {
                printf("Esa tecla no realiza ninguna accion \n");
            }

            system("clear");
        }

        i++;
    }
}
