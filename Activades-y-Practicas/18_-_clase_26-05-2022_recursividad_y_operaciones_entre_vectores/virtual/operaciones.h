#ifndef __OPERACIONES__
#define __OPERACIONES__

#define MAX_NOMBRE 100
#define MAX_PAIS 100
#define MAX_PILON 500

typedef struct jugador{
    int id;
    char nombre[MAX_NOMBRE];
    int dorsal;
    char pais[MAX_PAIS];
}jugador_t;


void obtener_mezcla(jugador_t pilon_pinocho[MAX_PILON], int tope_pinocho,
    jugador_t pilon_pp_grillo[MAX_PILON], int tope_pp_grillo, jugador_t mezcla[2*MAX_PILON], int* tope_mezcla);

void obtener_union(jugador_t pilon_pinocho[MAX_PILON], int tope_pinocho,
    jugador_t pilon_pp_grillo[MAX_PILON], int tope_pp_grillo,
    jugador_t union_jugadores[2*MAX_PILON], int* tope_union);

void obtener_interseccion(jugador_t pilon_pinocho[MAX_PILON], int tope_pinocho,
    jugador_t pilon_pp_grillo[MAX_PILON], int tope_pp_grillo,
    jugador_t interseccion[2*MAX_PILON], int* tope_interseccion);

void obtener_diferencia(jugador_t pilon_pinocho[MAX_PILON], int tope_pinocho,
    jugador_t pilon_pp_grillo[MAX_PILON], int tope_pp_grillo,
    jugador_t diferencia[2*MAX_PILON], int* tope_diferencia);

#endif