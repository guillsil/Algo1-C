#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_FRUTAS 10
#define MAX_NOMBRE 100
#define MAX_COLOR 50

const int NO_ENCONTRADO = -1;

typedef struct fruta {
    char nombre[MAX_NOMBRE];
    char color[MAX_COLOR];
    int peso; // en gramos
    bool se_come_cascara;
    bool pinchudo;
} fruta_t;


void inicializar_frutas(fruta_t frutas[MAX_FRUTAS], int *tope_frutas);

void imprimir_fruta(fruta_t fruta);

void imprimir_frutas(fruta_t frutas[MAX_FRUTAS], int tope_frutas, bool solo_no_pinchudos);

void inicializar_fruta(fruta_t *fruta, char *nombre, char *color, int peso, bool se_come_cascara, bool es_pinchudo);

void eliminar_fruta(char nombre[MAX_NOMBRE], fruta_t frutas[MAX_FRUTAS], int *tope);

void set_pinchudo(char nombre[MAX_NOMBRE], fruta_t frutas[MAX_FRUTAS], int tope);

void agregar_fruta(fruta_t fruta, fruta_t frutas[MAX_FRUTAS], int *tope);

int main() {
    fruta_t frutas[MAX_FRUTAS];
    int tope_frutas;

    inicializar_frutas(frutas, &tope_frutas);
    imprimir_frutas(frutas, tope_frutas, false);

    //eliminar_fruta("Pitaya", frutas, &tope_frutas);

    //set_pinchudo("Pitaya", frutas, tope_frutas);

    //imprimir_frutas(frutas, tope_frutas, false);

    fruta_t pitaya;
    inicializar_fruta(&pitaya, "Pitaya", "Bermellon", 1, false, true);

    agregar_fruta(pitaya, frutas, &tope_frutas);

    imprimir_frutas(frutas, tope_frutas, false);

    return 0;
}

void agregar_fruta(fruta_t fruta, fruta_t frutas[MAX_FRUTAS], int *tope) {

    int i = (*tope);
    bool inserte = false;

    while(i > 0 && !inserte){
        inserte = fruta.peso > frutas[i-1].peso;
        if(!inserte){
            frutas[i] = frutas[i-1];
            i--;
        }
    }
    frutas[i] = fruta;
    (*tope)++;
}

int posicion_fruta(char nombre[MAX_NOMBRE], fruta_t frutas[MAX_FRUTAS], int tope){
    int indice = 0;
    bool encontre = false;
    while (indice < tope && !encontre) {
        encontre = strcmp(frutas[indice].nombre, nombre) == 0;
        if(!encontre){
            indice++;
        }
    }

    if(!encontre){
        return NO_ENCONTRADO;
    }

    return indice;
}


void set_pinchudo(char nombre[MAX_NOMBRE], fruta_t frutas[MAX_FRUTAS], int tope) {
    int indice = posicion_fruta(nombre, frutas, tope);
    if(indice == NO_ENCONTRADO){
        printf("No se puede eliminar %s porque no esta en el vector\n", nombre);
        return;
    }

    frutas[indice].pinchudo = true;

}

void eliminar_fruta(char nombre[MAX_NOMBRE], fruta_t frutas[MAX_FRUTAS], int *tope) {

    int indice = posicion_fruta(nombre, frutas, *tope);
    if(indice == NO_ENCONTRADO){
        printf("No se puede eliminar %s porque no esta en el vector\n", nombre);
        return;
    }

    for(int i = indice; i < (*tope)-1; i++){
        frutas[i] = frutas[i+1];
    }
    (*tope)--;
}


void inicializar_fruta(fruta_t *fruta, char *nombre, char *color, int peso, bool se_come_cascara, bool es_pinchudo) {
    strcpy(fruta->nombre, nombre);
    strcpy(fruta->color, color);
    fruta->peso = peso;
    fruta->se_come_cascara = se_come_cascara;
    fruta->pinchudo = es_pinchudo;
}


void inicializar_frutas(fruta_t frutas[MAX_FRUTAS], int *tope_frutas) {
    (*tope_frutas) = 0;

    strcpy(frutas[(*tope_frutas)].nombre, "Cereza");
    strcpy(frutas[(*tope_frutas)].color, "Rojo");
    frutas[(*tope_frutas)].peso = 9;
    frutas[(*tope_frutas)].se_come_cascara = true;
    frutas[(*tope_frutas)].pinchudo = false;
    (*tope_frutas)++;

    strcpy(frutas[(*tope_frutas)].nombre, "Cereza");
    strcpy(frutas[(*tope_frutas)].color, "Rojo");
    frutas[(*tope_frutas)].peso = 9;
    frutas[(*tope_frutas)].se_come_cascara = true;
    frutas[(*tope_frutas)].pinchudo = false;
    (*tope_frutas)++;

    strcpy(frutas[(*tope_frutas)].nombre, "Banana");
    strcpy(frutas[(*tope_frutas)].color, "Amarillo");
    frutas[(*tope_frutas)].peso = 150;
    frutas[(*tope_frutas)].se_come_cascara = false;
    frutas[(*tope_frutas)].pinchudo = false;
    (*tope_frutas)++;

    strcpy(frutas[(*tope_frutas)].nombre, "Manzana");
    strcpy(frutas[(*tope_frutas)].color, "Rojo");
    frutas[(*tope_frutas)].peso = 200;
    frutas[(*tope_frutas)].se_come_cascara = true;
    frutas[(*tope_frutas)].pinchudo = false;
    (*tope_frutas)++;

    strcpy(frutas[(*tope_frutas)].nombre, "Pitaya");
    strcpy(frutas[(*tope_frutas)].color, "Bermellon");
    frutas[(*tope_frutas)].peso = 275;
    frutas[(*tope_frutas)].se_come_cascara = false;
    frutas[(*tope_frutas)].pinchudo = false;
    (*tope_frutas)++;

    strcpy(frutas[(*tope_frutas)].nombre, "Palta");
    strcpy(frutas[(*tope_frutas)].color, "Verde");
    frutas[(*tope_frutas)].peso = 300;
    frutas[(*tope_frutas)].se_come_cascara = false;
    frutas[(*tope_frutas)].pinchudo = false;
    (*tope_frutas)++;

    strcpy(frutas[(*tope_frutas)].nombre, "Melon");
    strcpy(frutas[(*tope_frutas)].color, "Verde");
    frutas[(*tope_frutas)].peso = 380;
    frutas[(*tope_frutas)].se_come_cascara = false;
    frutas[(*tope_frutas)].pinchudo = false;
    (*tope_frutas)++;
}

void imprimir_fruta(fruta_t fruta) {
    printf("Nombre: %s\n", fruta.nombre);
    printf("Color: %s\n", fruta.color);
    printf("Peso: %i\n", fruta.peso);

    if (fruta.se_come_cascara) {
        printf("Se come la cascara\n");
    } else {
        printf("No se come la cascara\n");
    }

    if (fruta.pinchudo) {
        printf("Es pinchudo\n");
    } else {
        printf("No es pinchudo\n");
    }
}

void imprimir_frutas(fruta_t frutas[MAX_FRUTAS], int tope_frutas, bool solo_no_pinchudos) {
    printf("--- FRUTAS ---\n");

    for (int i = 0; i < tope_frutas; i++) {
        if (frutas[i].pinchudo && solo_no_pinchudos) continue;
        printf("\n");
        imprimir_fruta(frutas[i]);
    }
}