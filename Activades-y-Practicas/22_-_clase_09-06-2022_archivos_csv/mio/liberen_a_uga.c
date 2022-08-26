#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define MAX_LETRAS 100
#define LECTURA_ANIMALITO "%[^;];%[^;];%[^;];%[^;];%i;%f\n" 
#define ESCRITURA_ANIMALITO "%s;%s;%s;%s;%i;%f\n"

typedef struct animalitos{
    char nombre[MAX_LETRAS];//o 8 bits = 1byte -> 100bytes
    char humano[MAX_LETRAS];//-> 100bytes
    char color[MAX_LETRAS];//-> 100bytes
    char especie[MAX_LETRAS];//-> 100bytes
    int edad;//4bytes
    float peso;//4bytes
}animalitos_t;
//-> total aprox 408 bytes



int main(int argc, char const *argv[]){
    
    FILE* f_animales = fopen(argv[1], "r");
    if(f_animales == NULL){
        perror("no se pudo abrir el archivo\n");
        return 1;
    }
    FILE* f_animales_aux = fopen("aux.csv", "w");
    if(f_animales == NULL){
        perror("no se pudo abrir el archivo\n");
        fclose(f_animales);
        return 1;
    }
    //nombre;humano;color;especies;edad;peso"
    animalitos_t animalito;
    //como hacer para buscar en un csv las lineas que estan mal
    int leidos = fscanf(f_animales, LECTURA_ANIMALITO, animalito.nombre, animalito.humano, animalito.color, animalito.especie, (&animalito.edad), &(animalito.peso));

    while (leidos == 6){
        if(strcmp(animalito.especie, argv[2]) != 0){
            fprintf(f_animales_aux, ESCRITURA_ANIMALITO, animalito.nombre, animalito.humano, animalito.color, animalito.especie, animalito.edad, animalito.peso );
        }

        leidos = fscanf(f_animales, LECTURA_ANIMALITO, animalito.nombre, animalito.humano, animalito.color, animalito.especie, &(animalito.edad), &(animalito.peso));
    }
    fclose(f_animales);
    fclose(f_animales_aux);

    //rename("aux.csv", argv[1]);

    return 0;
}

/* 
1)abro 
2)verifico
3)proceso 
4)verifico
 */
