#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    // abrir archivo (fopen("nbombre del archivo", "como lo quiero abrir, escritura o lectura"))
    FILE* archivo_saludo = fopen("saludo.txt", "r");
    /* fprintf(archivo, "escribir" ); escribe en el archivo */ 
    /* cat, te muestra el contenido de un archivo en la terminal */
    /* verificar si se abrio el archivo */
    if (archivo_saludo == NULL){
        perror("No se pudo abrir el archivo. COD: 001.");
        return -1;
    }

    char letra;
    /* fsacnf lee archivo , y devuelve la cantidad de variables que puedo llenar */
    fscanf(archivo_saludo, "%c", &letra);
    printf("%c", letra);
    /* feof me dice si termin el archivo */
    while (!feof(archivo_saludo)){
        fscanf(archivo_saludo, "%c", &letra);
        printf("%c", letra);
    }
    //cierra el archivo 
    fclose(archivo_saludo);
    
    return 0;
}
