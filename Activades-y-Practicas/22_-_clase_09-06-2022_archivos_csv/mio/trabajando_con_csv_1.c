#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define MAX_LETRAS 100
#define LECTURA_ANIMALITO "%[^;];%[^;];%[^;];%[^;];%i;%f\n" 

typedef struct animalitos{
    char nombre[MAX_LETRAS];
    char humano[MAX_LETRAS];
    char color[MAX_LETRAS];
    char especie[MAX_LETRAS];
    int edad;
    float peso;

}animalitos_t;

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

    while (leidos == 6){
        //imprime a todos los gatos que tengan mas de edad que le ingrese en el segundo argumento
        if (animalito.edad >= atoi(argv[2])){
            imprimir_animalito(animalito);    
        }
        leidos = fscanf(f_animales, LECTURA_ANIMALITO, animalito.nombre, animalito.humano, animalito.color, animalito.especie, &(animalito.edad), &(animalito.peso));

    }
    


    fclose(f_animales); 

    return 0;
}

/* 
1)abro 
2)verifico
3)proceso 
4)verifico
 */
