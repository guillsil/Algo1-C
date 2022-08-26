#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define MAX_LETRAS 100
#define LECTURA_ANIMALITO "%[^;];%[^;];%[^;];%[^;];%i;%f\n" 
#define ESCRITURA_ANIMALITO "%s;%s;%s;%s;%i;%f\n"
#define MAX_ANIMALITOS 200

typedef struct animalitos{
    char nombre[MAX_LETRAS];//o 8 bits = 1byte -> 100bytes
    char humano[MAX_LETRAS];//-> 100bytes
    char color[MAX_LETRAS];//-> 100bytes
    char especie[MAX_LETRAS];//-> 100bytes
    int edad;//4bytes
    float peso;//4bytes
}animalitos_t;
//-> total aprox 408 bytes

void ordenar_animalito(animalitos_t animalito,int tope){

}

void imprimir_animalito(animalitos_t animalitos){
    printf("=========ANIMALITOS=======\n");
    printf("====Nombre: %s\n", animalitos.nombre);
    printf("====Humano: %s\n", animalitos.humano);
    printf("====Color: %s\n", animalitos.color);
    printf("====Especie: %s\n", animalitos.especie);
    printf("====Edad: %i\n", animalitos.edad);
    printf("====Peso: %.2f\n", animalitos.peso);
    printf("===================");

}


int main(int argc, char const *argv[]){
    
    FILE* f_animales = fopen(argv[1], "r");
    if(f_animales == NULL){
        perror("no se pudo abrir el archivo\n");
        return 1;
    }
    //nombre;humano;color;especies;edad;peso"
    animalitos_t animalito;
    //como hacer para buscar en un csv las lineas que estan mal
    int leidos = fscanf(f_animales, LECTURA_ANIMALITO, animalito.nombre, animalito.humano, animalito.color, animalito.especie, (&animalito.edad), &(animalito.peso));
    int tope;
    animalitos_t animal[MAX_ANIMALITOS];

    while (leidos == 6){
        animal[tope++] = animalito;
    
        leidos = fscanf(f_animales, LECTURA_ANIMALITO, animalito.nombre, animalito.humano, animalito.color, animalito.especie, &(animalito.edad), &(animalito.peso));
    }
    fclose(f_animales);

    ordenar_animalito(animalito, tope);

    FILE* f_animales_ordenados = fopen("animalitos_ordenados.csv", "w");
    if(f_animales_ordenados == NULL){
        perror("no se pudo abrir el archivo\n");
        return 1;
    }

    for (int i = 0; i < tope; i++){
        fprintf(f_animales_ordenados, ESCRITURA_ANIMALITO, animal[i].nombre, animal[i].humano, animal[i].color, animal[i].especie, animal[i].edad, animal[i].peso );
    }
    
    fclose(f_animales_ordenados);

    return 0;
}

/* 
1)abro 
2)verifico
3)proceso 
4)verifico
 */
