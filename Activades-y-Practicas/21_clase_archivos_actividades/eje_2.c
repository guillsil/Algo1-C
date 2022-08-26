#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>
#define MAX_TESORO 100
#define COINCIDENCIAS_NECESARIAS 2
#define ERROR -1

typedef struct tesoro {
char metal; // oro, Plata, Bronce
int gramos;
int precio_por_gramo;
bool tiene_piedras_preciosas;
} tesoro_t;

void cargar_tesoro(tesoro_t tesoros[MAX_TESORO], int* tope_tesoro){
    tesoros[0].metal = 'P';
    tesoros[0].gramos = 200;
    tesoros[0].precio_por_gramo = 15;
    tesoros[0].tiene_piedras_preciosas = false;

    tesoros[1].metal = 'O';
    tesoros[1].gramos = 200;
    tesoros[1].precio_por_gramo = 15;
    tesoros[1].tiene_piedras_preciosas = false;
    tesoros[2].metal = 'O';
    tesoros[2].gramos = 50;
    tesoros[2].precio_por_gramo = 4;
    tesoros[2].tiene_piedras_preciosas = false;
    *tope_tesoro = 3;
}

void imprimir_tesoros(tesoro_t tesoros[MAX_TESORO], int tope_tesoros, tesoro_t tesoro_ideal){
    printf("tesoros importantes:\n");
    for (int i = 0; i < tope_tesoros; i++){
        int coincideancias = 0;
        if(tesoros[i].metal == tesoro_ideal.metal){
            coincideancias++;
        }
        if(tesoros[i].gramos == tesoro_ideal.gramos){
            coincideancias++;
        }
        if(tesoros[i].precio_por_gramo == tesoro_ideal.precio_por_gramo){
            coincideancias++;
        }
        if(tesoros[i].tiene_piedras_preciosas == tesoro_ideal.tiene_piedras_preciosas){
            coincideancias++;
        }
        if(coincideancias >= COINCIDENCIAS_NECESARIAS){
            printf("Tesoro: # %i\n", i);
        }
    } 
}



int main(int argc, char const *argv[]){
    if(argc !=2){
        printf("Cantidad de argumentos inesperadas");
        return -1;
    }
    tesoro_t tesoro[MAX_TESORO];
    int tope_tesoro = 0;
    cargar_tesoro(tesoro, &tope_tesoro);
    tesoro_t tesoro_ideal;
    char lectura_piedra[4];
    
    FILE* archivo_config = fopen(argv[1], "r");
    if (!archivo_config) {
		printf("Error al abrir el archivo\n");
		return ERROR;
	}

    //"%*[^=]=%c ,lo que hace el aterisco es leer hasta el = y no lo guarda 
    fscanf(archivo_config, "%*[^=]=%c", &tesoro_ideal.metal);
    fscanf(archivo_config, "%*[^=]=%i", &tesoro_ideal.gramos);
    fscanf(archivo_config, "%*[^=]=%i", &tesoro_ideal.precio_por_gramo);
    fscanf(archivo_config, "%*[^=]=%s", lectura_piedra);

    tesoro_ideal.tiene_piedras_preciosas = (strcmp(lectura_piedra, "Sí") == 0);
    /* if(strcmp(lectura_piedra, "Sí")  == 0){
        tesoro_ideal.tiene_piedras_preciosas = true;
    }else{
        tesoro_ideal.tiene_piedras_preciosas = false;
    } */
    printf("TESORO IDEAL\n");

    printf("METAL: %c\n", tesoro_ideal.metal);
    printf("GRAMOS: %i\n", tesoro_ideal.gramos);
    printf("PRECIO POR GRAMO: %i\n", tesoro_ideal.precio_por_gramo);
    printf("TIENE PIEDRA: %i\n", tesoro_ideal.tiene_piedras_preciosas);

    imprimir_tesoros(tesoro, tope_tesoro, tesoro_ideal);

    fclose(archivo_config);
    return 0;
}
