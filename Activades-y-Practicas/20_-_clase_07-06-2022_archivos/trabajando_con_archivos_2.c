 #include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char* argv[]){

    FILE* archivo_config = fopen(argv[1], "r");
    if (archivo_config == NULL){
        perror("No se pudo abrir el archivo. COD: 001.");
        return -1;
    }

    int edad = 99;
    char color[50] = "azul";
    char gusto_empanada = 'C';
    /*
    fscanf(archivo_config, "EDAD=%i\n", &edad);
    fscanf(archivo_config, "COLOR=%s\n", color);
    fscanf(archivo_config, "GUSTOEMPANADA=%c\n", &gusto_empanada);

    printf("La edad leida es %i, el color leido es %s y el gusto de empanada es %c.\n", edad, color, gusto_empanada);
    */
    char comando[50];
    char valor[50];
    
    /* "%[^=]=%s\n"  */
    int leidos = fscanf(archivo_config, "%[^=]=%s\n", comando, valor);
    while (leidos == 2){
        if (strcmp(comando, "EDAD") == 0){
            edad = atoi(valor);
        } else if (strcmp(comando, "COLOR") == 0){
            strcpy(color, valor);
        } else if (strcmp(comando, "GUSTOEMPANADA") == 0){
            gusto_empanada = valor[0];
        }
        leidos = fscanf(archivo_config, "%[^=]=%s\n", comando, valor);
    }
    printf("La edad leida es %i, el color leido es %s y el gusto de empanada es %c.\n", edad, color, gusto_empanada);

    fclose(archivo_config);
    
    return 0;
}
