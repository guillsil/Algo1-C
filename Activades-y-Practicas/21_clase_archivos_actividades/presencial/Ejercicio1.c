#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/* Ejercicio 1-1
int main(int argc, char* argv[]) {

    
    if(argc != 2) {
        perror("Error");
        // constante!
        return -1;
    }

    // argv = ["ej1", "nombreArchivo"]
    // constante!
    char nombre[100];

    strcpy(nombre, argv[1]);
    printf("llego papi, %s\n", nombre);

    FILE* agenda_walle = fopen(nombre, "r");
    if(agenda_walle == NULL) {
        perror("No se pudo abrir el archivo");
        return -1; // constante!
    }

    int hora;
    char accion[500]; // constante!

    int items_leidos = fscanf(agenda_walle, "%i - %[^\n]\n", &hora, accion);

    // leer hasta el final del archivo
    while(items_leidos > 0) {
        printf("%i - %s\n", hora, accion);
        items_leidos = fscanf(agenda_walle, "%i - %[^\n]\n", &hora, accion);
    }

    fclose(agenda_walle);

    return 0;
}
*/

/* Ejercicio 2
int main(int argc, char* argv[]) {
    if(argc != 3) { // constante!
        perror("Error");
        // constante!
        return -1;
    }

    // argv = ["ej1", "nombreArchivo", "1300"]
    // constante!
    char nombre[100];
    int hora_ingresada;

    strcpy(nombre, argv[1]);
    hora_ingresada = atoi(argv[2]);
    printf("llego papi, %s\n", nombre);

    FILE* agenda_walle = fopen(nombre, "r");
    if(agenda_walle == NULL) {
        perror("No se pudo abrir el archivo");
        return -1; // constante!
    }

    int hora;
    char accion[500]; // constante!

    int items_leidos = fscanf(agenda_walle, "%i - %[^\n]\n", &hora, accion);

    // leer hasta el final del archivo
    while(items_leidos > 0) {
        if(hora == hora_ingresada) {
            printf("%i - %s\n", hora, accion);
        }
        items_leidos = fscanf(agenda_walle, "%i - %[^\n]\n", &hora, accion);
    }

    fclose(agenda_walle);

    return 0;
}
*/

/* Ejercicio 1.3
int main(int argc, char* argv[]) {
    if(argc != 4) { // constante!
        perror("Error");
        // constante!
        return -1;
    }

    // argv = ["ej1", "nombreArchivo", "1300", "1600"]
    // constante!
    char nombre[100];
    int hora_i;
    int hora_f;

    strcpy(nombre, argv[1]);
    hora_i = atoi(argv[2]);
    hora_f = atoi(argv[3]);

    printf("Hora inicial: %i. Hora final: %i\n", hora_i, hora_f);

    printf("llego papi, %s\n", nombre);

    FILE* agenda_walle = fopen(nombre, "r");
    if(agenda_walle == NULL) {
        perror("No se pudo abrir el archivo");
        return -1; // constante!
    }

    int hora;
    char accion[500]; // constante!

    int items_leidos = fscanf(agenda_walle, "%i - %[^\n]\n", &hora, accion);

    // leer hasta el final del archivo
    while(items_leidos > 0) {
        if(hora >= hora_i && hora <= hora_f) {
            printf("%i - %s\n", hora, accion);
        }
        items_leidos = fscanf(agenda_walle, "%i - %[^\n]\n", &hora, accion);
    }

    fclose(agenda_walle);

    return 0;
}
*/

/* Prueba
int main(int tope, char* trackel[]) {

    printf("Tope: %i. Primer posicion: %s\n", tope, trackel[0]);
    return 0;
}
*/