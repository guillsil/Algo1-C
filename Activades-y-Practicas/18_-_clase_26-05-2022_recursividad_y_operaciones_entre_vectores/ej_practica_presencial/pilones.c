#include <stdio.h>
#include <string.h>

#define MAX_NOMBRE 100
#define MAX_PAIS 100
#define MAX_PILON 500

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


void diferenciar_figuritas(jugador_t pilon_j1[MAX_PILON], int tope_j1,
                            jugador_t pilon_j2[MAX_PILON], int tope_j2,
                            jugador_t diferencia[MAX_PILON], int* tope_diferencia){

    int i = 0;
    int j = 0;
    *tope_diferencia = 0;

    while(i < tope_j1 && j < tope_j2){
        if(pilon_j1[i].id < pilon_j2[j].id){
            diferencia[*tope_diferencia] = pilon_j1[i];
            (*tope_diferencia)++;
            i++;
        }

        if(pilon_j1[i].id == pilon_j2[j].id){
            i++;
            j++;
        }

        else{
            j++;
        }
    }

    while(i < tope_j1){
        diferencia[*tope_diferencia] = pilon_j1[i];
        (*tope_diferencia)++;
        i++;
    }
}


void intersecar_figuritas(jugador_t pilon_j1[MAX_PILON], int tope_j1,
                            jugador_t pilon_j2[MAX_PILON], int tope_j2,
                            jugador_t interseccion[MAX_PILON], int* tope_interseccion){

    int i = 0;
    int j = 0;
    *tope_interseccion = 0;

    while(i < tope_j1 && j < tope_j2){
        if(pilon_j1[i].id < pilon_j2[j].id){
            i++;
        }

        else if(pilon_j1[i].id == pilon_j2[j].id){
            interseccion[*tope_interseccion] = pilon_j1[i];
            (*tope_interseccion)++;
            i++;
            j++;
        }

        else{
            j++;
        }
    }
}


void unir_figuritas(jugador_t pilon_j1[MAX_PILON], int tope_j1,
                            jugador_t pilon_j2[MAX_PILON], int tope_j2,
                            jugador_t unionn[MAX_PILON], int* tope_union){

    int i = 0;
    int j = 0;
    *tope_union = 0;

    while(i < tope_j1 && j < tope_j2){
        if(pilon_j1[i].id < pilon_j2[j].id){
            unionn[*tope_union] = pilon_j1[i];
            i++;
        }

        else if(pilon_j1[i].id == pilon_j2[j].id){
            unionn[*tope_union] = pilon_j1[i];
            i++;
            j++;
        }

        else{
            unionn[*tope_union] = pilon_j2[j];
            j++;
        }

        (*tope_union)++;
    }

    while(i < tope_j1){
        unionn[*tope_union] = pilon_j1[i];
        (*tope_union)++;
        i++;
    }

    while(j < tope_j2){
        unionn[*tope_union] = pilon_j2[j];
        (*tope_union)++;
        j++;
    }
}

//VERSION LARGA INNECESARIA
/*void mezclar_figuritas(jugador_t pilon_j1[MAX_PILON], int tope_j1,
                            jugador_t pilon_j2[MAX_PILON], int tope_j2,
                            jugador_t mezcla[MAX_PILON], int* tope_mezcla){

    int i = 0;
    int j = 0;
    *tope_mezcla = 0;

    while(i < tope_j1 && j < tope_j2){
        if(pilon_j1[i].id < pilon_j2[j].id){
            mezcla[*tope_mezcla] = pilon_j1[i];
            (*tope_mezcla)++;
            i++;
        }

        else if(pilon_j1[i].id == pilon_j2[j].id){
            mezcla[*tope_mezcla] = pilon_j1[i];
            (*tope_mezcla)++;
            mezcla[*tope_mezcla] = pilon_j2[j];
            (*tope_mezcla)++;
            i++;
            j++;
        }

        else{
            mezcla[*tope_mezcla] = pilon_j2[j];
            (*tope_mezcla)++;
            j++;
        }
    }

    while(i < tope_j1){
        mezcla[*tope_mezcla] = pilon_j1[i];
        (*tope_mezcla)++;
        i++;
    }

    while(j < tope_j2){
        mezcla[*tope_mezcla] = pilon_j2[j];
        (*tope_mezcla)++;
        j++;
    }
}*/

//VERSION CORTA
void mezclar_figuritas(jugador_t pilon_j1[MAX_PILON], int tope_j1,
                            jugador_t pilon_j2[MAX_PILON], int tope_j2,
                            jugador_t mezcla[MAX_PILON], int* tope_mezcla){

    int i = 0;
    int j = 0;
    *tope_mezcla = 0;

    while(i < tope_j1 && j < tope_j2){
        if(pilon_j1[i].id < pilon_j2[j].id){
            mezcla[*tope_mezcla] = pilon_j1[i];
            (*tope_mezcla)++;
            i++;
        }
        else{
            mezcla[*tope_mezcla] = pilon_j2[j];
            (*tope_mezcla)++;
            j++;
        }
    }

    while(i < tope_j1){
        mezcla[*tope_mezcla] = pilon_j1[i];
        (*tope_mezcla)++;
        i++;
    }

    while(j < tope_j2){
        mezcla[*tope_mezcla] = pilon_j2[j];
        (*tope_mezcla)++;
        j++;
    }
}


int main(){

    jugador_t pilon_pinocho[MAX_PILON];
    int tope_pinocho;
    printf("pinocho\n");
    inicializar_pilon_pinocho(pilon_pinocho, &tope_pinocho);
    imprimir_pilon(pilon_pinocho, tope_pinocho);

    jugador_t pilon_pp_grillo[MAX_PILON];
    int tope_pp_grillo;
    printf("\npp grillo\n");
    inicializar_pilon_grillo(pilon_pp_grillo, &tope_pp_grillo);
    imprimir_pilon(pilon_pp_grillo, tope_pp_grillo);
    
    jugador_t diferencia[MAX_PILON];
    int tope_diferencia;
    diferenciar_figuritas(pilon_pinocho, tope_pinocho,
                            pilon_pp_grillo, tope_pp_grillo,
                            diferencia, &tope_diferencia);
    printf("\ndiferencia pinocho con pp grillo\n");
    imprimir_pilon(diferencia, tope_diferencia);

    diferenciar_figuritas(pilon_pp_grillo, tope_pp_grillo,
                            pilon_pinocho, tope_pp_grillo,
                            diferencia, &tope_diferencia);
    printf("\ndiferencia grillo con pinocho\n");
    imprimir_pilon(diferencia, tope_diferencia);

    jugador_t interseccion[MAX_PILON];
    int tope_interseccion;
    intersecar_figuritas(pilon_pinocho, tope_pinocho,
                            pilon_pp_grillo, tope_pp_grillo,
                            interseccion, &tope_interseccion);
    printf("\ninterseccion grillo con pinocho\n");
    imprimir_pilon(interseccion, tope_interseccion);

    jugador_t unionn[MAX_PILON];
    int tope_union;
    unir_figuritas(pilon_pinocho, tope_pinocho,
                            pilon_pp_grillo, tope_pp_grillo,
                            unionn, &tope_union);
    printf("\nunion grillo con pinocho\n");
    imprimir_pilon(unionn, tope_union);

    jugador_t mezcla[MAX_PILON];
    int tope_mezcla;
    mezclar_figuritas(pilon_pinocho, tope_pinocho,
                            pilon_pp_grillo, tope_pp_grillo,
                            mezcla, &tope_mezcla);
    printf("\nmezcla grillo con pinocho\n");
    imprimir_pilon(mezcla, tope_mezcla);

    return 0;
}