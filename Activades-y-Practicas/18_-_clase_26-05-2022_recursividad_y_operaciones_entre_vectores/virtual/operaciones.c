#include "operaciones.h"


void obtener_mezcla(jugador_t pilon_pinocho[MAX_PILON], int tope_pinocho,
    jugador_t pilon_pp_grillo[MAX_PILON], int tope_pp_grillo,
    jugador_t mezcla[2*MAX_PILON], int* tope_mezcla) {

    *tope_mezcla = 0;

    int pos_grillo = 0;
    int pos_pinocho = 0;

    while (pos_grillo < tope_pp_grillo && pos_pinocho < tope_pinocho) {

        jugador_t pinocho = pilon_pinocho[pos_pinocho];
        jugador_t grillo = pilon_pp_grillo[pos_grillo];

        if (pinocho.id == grillo.id) {
            mezcla[*tope_mezcla] = pinocho;
            (*tope_mezcla)++;

            mezcla[*tope_mezcla] = grillo;
            (*tope_mezcla)++;

            pos_grillo++;
            pos_pinocho++;
        } else if (pinocho.id > grillo.id) {
            mezcla[*tope_mezcla] = grillo;
            (*tope_mezcla)++;
            pos_grillo++;
        } else {
            mezcla[*tope_mezcla] = pinocho;
            (*tope_mezcla)++;
            pos_pinocho++;
        }
    }

    while (pos_grillo < tope_pp_grillo) {
        mezcla[*tope_mezcla] = pilon_pp_grillo[pos_grillo];
        (*tope_mezcla)++;
        pos_grillo++;
    }

    while (pos_pinocho < tope_pinocho) {
        mezcla[*tope_mezcla] = pilon_pinocho[pos_pinocho];
        (*tope_mezcla)++;
        pos_pinocho++;
    }
}

void obtener_union(jugador_t pilon_pinocho[MAX_PILON], int tope_pinocho,
    jugador_t pilon_pp_grillo[MAX_PILON], int tope_pp_grillo,
    jugador_t union_jugadores[2*MAX_PILON], int* tope_union) {

    *tope_union = 0;

    int pos_grillo = 0;
    int pos_pinocho = 0;

    while (pos_grillo < tope_pp_grillo && pos_pinocho < tope_pinocho) {

        jugador_t pinocho = pilon_pinocho[pos_pinocho];
        jugador_t grillo = pilon_pp_grillo[pos_grillo];

        if (pinocho.id == grillo.id) {
            union_jugadores[*tope_union] = pinocho;
            (*tope_union)++;

            pos_pinocho++;
            pos_grillo++;
        } else if (pinocho.id > grillo.id) {
            union_jugadores[*tope_union] = grillo;
            (*tope_union)++;
            pos_grillo++;
        } else {
            union_jugadores[*tope_union] = pinocho;
            (*tope_union)++;
            pos_pinocho++;
        }
    }

    while (pos_grillo < tope_pp_grillo) {
        union_jugadores[*tope_union] = pilon_pp_grillo[pos_grillo];
        (*tope_union)++;
        pos_grillo++;
    }

    while (pos_pinocho < tope_pinocho) {
        union_jugadores[*tope_union] = pilon_pinocho[pos_pinocho];
        (*tope_union)++;
        pos_pinocho++;
    }
}

void obtener_interseccion(jugador_t pilon_pinocho[MAX_PILON], int tope_pinocho,
    jugador_t pilon_pp_grillo[MAX_PILON], int tope_pp_grillo,
    jugador_t interseccion[2*MAX_PILON], int* tope_interseccion) {

    *tope_interseccion = 0;

    int pos_grillo = 0;
    int pos_pinocho = 0;

    while (pos_grillo < tope_pp_grillo && pos_pinocho < tope_pinocho) {

        jugador_t pinocho = pilon_pinocho[pos_pinocho];
        jugador_t grillo = pilon_pp_grillo[pos_grillo];

        if (pinocho.id == grillo.id) {
            interseccion[*tope_interseccion] = pinocho;
            (*tope_interseccion)++;

            pos_pinocho++;
            pos_grillo++;
        } else if (pinocho.id > grillo.id) {
            pos_grillo++;
        } else {
            pos_pinocho++;
        }
    }
}

void obtener_diferencia(jugador_t pilon_pinocho[MAX_PILON], int tope_pinocho,
    jugador_t pilon_pp_grillo[MAX_PILON], int tope_pp_grillo,
    jugador_t diferencia[2*MAX_PILON], int* tope_diferencia) {

    *tope_diferencia = 0;

    int pos_grillo = 0;
    int pos_pinocho = 0;

    while (pos_grillo < tope_pp_grillo && pos_pinocho < tope_pinocho) {
        jugador_t pinocho = pilon_pinocho[pos_pinocho];
        jugador_t grillo = pilon_pp_grillo[pos_grillo];

        if (pinocho.id == grillo.id) {
            pos_grillo++;
            pos_pinocho++;
        } else if (pinocho.id > grillo.id) {
            pos_grillo++;
        } else {
            diferencia[*tope_diferencia] = pinocho;
            (*tope_diferencia)++;
            pos_pinocho++;
        }
    }

    while (pos_pinocho < tope_pinocho) {
        diferencia[*tope_diferencia] = pilon_pinocho[pos_pinocho];
        (*tope_diferencia)++;
        pos_pinocho++;
    }
}