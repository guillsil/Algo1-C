#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINEA 256

void mostrar_eventos(FILE* archivo_diario) {

    // while (i < tope) {
    //     // hacen algo
    //     i++;
    // }
 
    char linea[MAX_LINEA];
    // char letra;
    while (!feof(archivo_diario)) {
                                
        fscanf(archivo_diario, "%[^\n]\n", linea);
        printf("%s\n", linea);

        // fscanf(archivo_diario, "%c", &letra);
        // printf("%c", letra);
    }
}


void mostrar_eventos_por_hora(FILE* archivo_diario, int hora) {
    
    int hora_evento;
    char linea[MAX_LINEA];
    while (!feof(archivo_diario)) {
                                
        fscanf(archivo_diario, "%i - %[^\n]\n", &hora_evento, linea);
        if (hora == hora_evento) {
            printf("%s\n", linea);
        }
    }
}

void mostrar_eventos_entre_horas(FILE* archivo_diario, int desde, int hasta) {
    int hora_evento;
    char linea[MAX_LINEA];
    while (!feof(archivo_diario)) {
                                
        fscanf(archivo_diario, "%i - %[^\n]\n", &hora_evento, linea);
        if (hora_evento <= hasta && hora_evento >= desde) {
            printf("%s\n", linea);
        }
    }
}

// argv[0] : nombre ejecutable
// argv[1] : nombre archivo a leer
// argv[2] : hora_desde
// argv[3] : hora_hasta
int main (int argc, char* argv[]) {

    // for (int i = 0; i < argc; i++) {
    //     printf("el argumento %i es: %s\n", i, argv[i]);
    // }

    if (argc != 4) {
        printf("cantidad de arguemntos incorrecta\n");
        return -1;
    }

    FILE* archivo_diario = fopen(argv[1], "r");
    if (archivo_diario ==  NULL) {
        printf("no se pudo abrir el archivo.\n");
        return -1;
    }

    int hora_desde = atoi(argv[2]);
    int hora_hasta = atoi(argv[3]);
    // mostrar_eventos(archivo_diario);
    // mostrar_eventos_por_hora(archivo_diario, hora);
    mostrar_eventos_entre_horas(archivo_diario, hora_desde, hora_hasta);

    fclose(archivo_diario);

    return 0;
}