#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    
    int dia, mes, anio;
    printf(" Ingrese fecha: ");
    int leidos = scanf("%i/%i/%i", &dia, &mes, &anio);

    printf("dia: %i, mes: %i, anio: %i\n", dia, mes, anio);
    printf("leidos: %i", leidos);

    return 0;
}
