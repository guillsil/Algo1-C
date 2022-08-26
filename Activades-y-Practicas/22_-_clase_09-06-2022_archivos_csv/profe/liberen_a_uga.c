#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOMBRE 50
#define MAX_COLOR 50
#define MAX_ESPECIE 50

#define LECTURA_ANIMALITO "%[^;];%[^;];%[^;];%[^;];%i;%f\n"
#define ESCRITURA_ANIMALITO "%s;%s;%s;%s;%i;%f\n"

typedef struct anmilalito {
    char nombre[MAX_NOMBRE];
    char humano[MAX_NOMBRE];
    char color[MAX_COLOR];
    char especie[MAX_ESPECIE];
    int edad;
    float peso;
} anmilalito_t;


int main(int argc, char* argv[]){

    FILE* f_animales = fopen(argv[1], "r");
    if (f_animales == NULL) {
        perror("No pudo ser abierto el archivo.");
        return 1;
    }

    FILE* f_animales_aux = fopen("aux.csv", "w");
    if (f_animales_aux == NULL) {
        perror("No pudo ser abierto el archivo.");
        fclose(f_animales);
        return 1;
    }

    anmilalito_t animalito;
    int leidos = fscanf(f_animales, LECTURA_ANIMALITO, animalito.nombre, animalito.humano, animalito.color, animalito.especie, &(animalito.edad), &(animalito.peso));
    while(leidos == 6){

        if (strcmp(animalito.especie, argv[2]) != 0){
            fprintf(f_animales_aux, ESCRITURA_ANIMALITO, animalito.nombre, animalito.humano, animalito.color, animalito.especie, animalito.edad, animalito.peso);
        }

        leidos = fscanf(f_animales, LECTURA_ANIMALITO, animalito.nombre, animalito.humano, animalito.color, animalito.especie, &(animalito.edad), &(animalito.peso));
    }

    fclose(f_animales);
    fclose(f_animales_aux);

    rename("aux.csv", argv[1]);

    return 0;
}
