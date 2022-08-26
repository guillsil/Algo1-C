#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define MAX_LINEA 256
//1)
void mostrar_elementos(FILE* archivo_diario){
    char linea[MAX_LINEA];
    //feof cheakea si llego al final
    while (!feof(archivo_diario)){
    // es como el el i++ que se usa para recorrer un vector 
    //(%[^\n]\n) es ṕara que se muestre la linea completa
    /* fscanf(archivo_diario, "%[^\n]\n", linea);
    printf("%s\n", linea); */
       fscanf(archivo_diario, "%[^\n]\n", linea);
       printf("%s\n", linea);
    }
    printf("\n"); 
}
//2)
void mostrar_eventos_por_hora(FILE* archivo_diario, int hora){
    char linea[MAX_LINEA];
    int hora_evento;
    while (!feof(archivo_diario)){
       fscanf(archivo_diario, "%i -%[^\n]\n", &hora_evento, linea);
        if(hora == hora_evento){
            printf("%s\n", linea);
        }  
    }
}
//3)
void mostrar_eventos_entre_horas(FILE* archivo_diario, int desde, int hasta){
    char linea[MAX_LINEA];
    int hora_evento;
    while (!feof(archivo_diario)){
       fscanf(archivo_diario, "%i -%[^\n]\n", &hora_evento, linea);
        if(hora_evento <= hasta && hora_evento >= desde){
            printf("%s\n", linea);
        }  
    }
}

/* con el (*) luego del tipo de dato le indico que puedo cambiar el max , es decir el max fisico
void recorrer_vector(int* vector[MAX_VECTOR], int tope)
*/
//los argumentos los separo con espacios
//argv[0]: nombre del ejecutable
int main(int argc, char* argv[]){
    //buena practica chheckear la cantidad de argumentos que recibe el programa
 
    if(argc != 4){
        printf("La cantridad de argumentos no es correcta");
        return -1;
    }
    //fopen : nombre del archivo y si se escribe o write o read
    FILE* archivo_diario = fopen(argv[1], "r");
    // (!archivo_diario) == (archivo_diario == (NULL = 0))
    if(archivo_diario == NULL){
        printf("no se pudo abrir el archivo");
        return -1;
    }
    //mostrar_elementos(archivo_diario);

    int hora_desde = atoi(argv[2]);
    int hora_hasta = atoi(argv[3]);
    //mostrar_eventos_por_hora(archivo_diario, hora_desde);
    
    mostrar_eventos_entre_horas(archivo_diario,hora_desde, hora_hasta);
    //cerrar el archivo
    fclose(archivo_diario);
    return 0;
}