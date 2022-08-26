#include <stdio.h>
#include <string.h>
#include "operaciones.h"

#define MAX_NOMBRE 100
#define MAX_PAIS 100
#define MAX_PILON 5

typedef struct jugador{
    int id;
    char nombre[MAX_NOMBRE];
    int dorsal;
    char pais[MAX_PAIS];
}jugador_t;

void imprimir_jugador(jugador_t jugador) {
    printf("- ID: %i\n", jugador.id);
    printf("- Nombre: %s\n", jugador.nombre);
    printf("- Dorsal: %i\n", jugador.dorsal);
    printf("- Pais: %s\n\n", jugador.pais);
}

void imprimir_pilon(jugador_t pilon[MAX_PILON], int tope) {
    for (int i = 0; i < tope; i++) {
        imprimir_jugador(pilon[i]);
    }
}

void inicializar_pilon_pinocho(jugador_t pilon_pinocho[MAX_PILON], int* tope_pinocho){
    *tope_pinocho = 0;

    pilon_pinocho[*tope_pinocho].id = 1;
    strcpy(pilon_pinocho[*tope_pinocho].nombre, "Messi");
    pilon_pinocho[*tope_pinocho].dorsal = 10;
    strcpy(pilon_pinocho[*tope_pinocho].pais, "Argentina");
    (*tope_pinocho)++;

    pilon_pinocho[*tope_pinocho].id = 2;
    strcpy(pilon_pinocho[*tope_pinocho].nombre, "Aguero");
    pilon_pinocho[*tope_pinocho].dorsal = 16;
    strcpy(pilon_pinocho[*tope_pinocho].pais, "Argentina");
    (*tope_pinocho)++;

    pilon_pinocho[*tope_pinocho].id = 3;
    strcpy(pilon_pinocho[*tope_pinocho].nombre, "Di Maria");
    pilon_pinocho[*tope_pinocho].dorsal = 11;
    strcpy(pilon_pinocho[*tope_pinocho].pais, "Argentina");
    (*tope_pinocho)++;

    pilon_pinocho[*tope_pinocho].id = 4;
    strcpy(pilon_pinocho[*tope_pinocho].nombre, "De Paul");
    pilon_pinocho[*tope_pinocho].dorsal = 7;
    strcpy(pilon_pinocho[*tope_pinocho].pais, "Argentina");
    (*tope_pinocho)++;

    pilon_pinocho[*tope_pinocho].id = 8;
    strcpy(pilon_pinocho[*tope_pinocho].nombre, "Lewandoski");
    pilon_pinocho[*tope_pinocho].dorsal = 9;
    strcpy(pilon_pinocho[*tope_pinocho].pais, "Polonia");
    (*tope_pinocho)++;

    pilon_pinocho[*tope_pinocho].id = 9;
    strcpy(pilon_pinocho[*tope_pinocho].nombre, "Pique");
    pilon_pinocho[*tope_pinocho].dorsal = 3;
    strcpy(pilon_pinocho[*tope_pinocho].pais, "España");
    (*tope_pinocho)++;

    pilon_pinocho[*tope_pinocho].id = 10;
    strcpy(pilon_pinocho[*tope_pinocho].nombre, "Neymar");
    pilon_pinocho[*tope_pinocho].dorsal = 10;
    strcpy(pilon_pinocho[*tope_pinocho].pais, "Brasil");
    (*tope_pinocho)++;

    pilon_pinocho[*tope_pinocho].id = 11;
    strcpy(pilon_pinocho[*tope_pinocho].nombre, "Keylor Navas");
    pilon_pinocho[*tope_pinocho].dorsal = 1;
    strcpy(pilon_pinocho[*tope_pinocho].pais, "Costa Rica");
    (*tope_pinocho)++;

    pilon_pinocho[*tope_pinocho].id = 12;
    strcpy(pilon_pinocho[*tope_pinocho].nombre, "Gary Medel");
    pilon_pinocho[*tope_pinocho].dorsal = 17;
    strcpy(pilon_pinocho[*tope_pinocho].pais, "Chile");
    (*tope_pinocho)++;

    pilon_pinocho[*tope_pinocho].id = 13;
    strcpy(pilon_pinocho[*tope_pinocho].nombre, "Cuadrado");
    pilon_pinocho[*tope_pinocho].dorsal = 11;
    strcpy(pilon_pinocho[*tope_pinocho].pais, "Colombia");
    (*tope_pinocho)++;
}

void inicializar_pilon_grillo(jugador_t pilon_pp_grillo[MAX_PILON], int* tope_pp_grillo){
    *tope_pp_grillo = 0;

    pilon_pp_grillo[*tope_pp_grillo].id = 1;
    strcpy(pilon_pp_grillo[*tope_pp_grillo].nombre, "Messi");
    pilon_pp_grillo[*tope_pp_grillo].dorsal = 10;
    strcpy(pilon_pp_grillo[*tope_pp_grillo].pais, "Argentina");
    (*tope_pp_grillo)++;

    pilon_pp_grillo[*tope_pp_grillo].id = 4;
    strcpy(pilon_pp_grillo[*tope_pp_grillo].nombre, "De Paul");
    pilon_pp_grillo[*tope_pp_grillo].dorsal = 7;
    strcpy(pilon_pp_grillo[*tope_pp_grillo].pais, "Argentina");
    (*tope_pp_grillo)++;

    pilon_pp_grillo[*tope_pp_grillo].id = 5;
    strcpy(pilon_pp_grillo[*tope_pp_grillo].nombre, "Julian Alvarez");
    pilon_pp_grillo[*tope_pp_grillo].dorsal = 27;
    strcpy(pilon_pp_grillo[*tope_pp_grillo].pais, "Argentina");
    (*tope_pp_grillo)++;

    pilon_pp_grillo[*tope_pp_grillo].id = 6;
    strcpy(pilon_pp_grillo[*tope_pp_grillo].nombre, "Tagliafico");
    pilon_pp_grillo[*tope_pp_grillo].dorsal = 3;
    strcpy(pilon_pp_grillo[*tope_pp_grillo].pais, "Argentina");
    (*tope_pp_grillo)++;

    pilon_pp_grillo[*tope_pp_grillo].id = 7;
    strcpy(pilon_pp_grillo[*tope_pp_grillo].nombre, "Manuel Camejo");
    pilon_pp_grillo[*tope_pp_grillo].dorsal = 33;
    strcpy(pilon_pp_grillo[*tope_pp_grillo].pais, "Argentina");
    (*tope_pp_grillo)++;

    pilon_pp_grillo[*tope_pp_grillo].id = 8;
    strcpy(pilon_pp_grillo[*tope_pp_grillo].nombre, "Lewandoski");
    pilon_pp_grillo[*tope_pp_grillo].dorsal = 9;
    strcpy(pilon_pp_grillo[*tope_pp_grillo].pais, "Polonia");
    (*tope_pp_grillo)++;

    pilon_pp_grillo[*tope_pp_grillo].id = 9;
    strcpy(pilon_pp_grillo[*tope_pp_grillo].nombre, "Pique");
    pilon_pp_grillo[*tope_pp_grillo].dorsal = 3;
    strcpy(pilon_pp_grillo[*tope_pp_grillo].pais, "España");
    (*tope_pp_grillo)++;
}


int main(){

    jugador_t pilon_pinocho[MAX_PILON];
    int tope_pinocho;
    inicializar_pilon_pinocho(pilon_pinocho, &tope_pinocho);
    printf("VEctor de pinocho\n\n");
    imprimir_pilon(pilon_pinocho, tope_pinocho);

    jugador_t pilon_pp_grillo[MAX_PILON];
    int tope_pp_grillo;
    inicializar_pilon_grillo(pilon_pp_grillo, &tope_pp_grillo);
    printf("Vector de grillo\n\n");
    imprimir_pilon(pilon_pp_grillo, tope_pp_grillo);
    
    jugador_t resultado[MAX_PILON];
    int tope_resultado;
    obtener_mezcla(pilon_pinocho, tope_pinocho, pilon_pp_grillo, tope_pp_grillo, resultado, &tope_resultado);
    obtener_union(pilon_pinocho, tope_pinocho, pilon_pp_grillo, tope_pp_grillo, resultado, &tope_resultado);
    obtener_interseccion(pilon_pinocho, tope_pinocho, pilon_pp_grillo, tope_pp_grillo, resultado, &tope_resultado);
    obtener_diferencia(pilon_pp_grillo, tope_pp_grillo, pilon_pinocho, tope_pinocho, resultado, &tope_resultado);
    printf("RESULTADOOOO\n\n\n\n");
    imprimir_pilon(resultado, tope_resultado);

    return 0;
}