/*
Bolt se dió cuenta que Penny tiene anotado en un vector la cantidad de comida que le da por día en toda la semana, y quiere alterar un poco los números, ya que se dió cuenta que los días que más hambre tiene, son los días que menos recibe.

-Implementar un procedimiento que cree un nuevo vector para reemplazar el anterior, intercambiando la cantidad de comida que recibe los lunes, por los viernes, y la cantidad de comida que recibe los domingos, por los miércoles.
Las posiciones del vector representan los días de semana comenzando por el domingo en la posición 0.

Tener en cuenta:

    Las posiciones del vector representan los días de semana comenzando por el domingo en la posición 0.
    Ambos vectores tienen de tope el MAX_DIAS siempre. Es decir, siempre vienen con 7 elementos, ni más ni menos.

Ejemplo:

    Teniendo el vector de comidas originales [1, 4, 6, 2, 5, 1, 7] el vector de comidas intercambiadas debe quedar [2, 1, 6, 1, 5, 4, 7].

*/
#define MAX_DIAS  7
#include <stdio.h>

void intercambiar_comidas(int comidas_original[MAX_DIAS], int comidas_intercambiadas[MAX_DIAS]){
    /*0_D 1_L 2_M 3_M 4_J 5_V 6_S */

    int lunes_por_viernes;
    int domingos_por_miercoles;

    comidas_intercambiadas[1] = comidas_original[5];
    comidas_intercambiadas[0] = comidas_original[3];

    comidas_intercambiadas[3] = comidas_original[0];
    comidas_intercambiadas[5] = comidas_original[1];

    comidas_original[2] = comidas_intercambiadas[2];
    comidas_original[4] = comidas_intercambiadas[4];
    comidas_original[6] = comidas_intercambiadas[6];

    for (int  i = 0; i < MAX_DIAS; i++){
        printf("%i, ", comidas_original[i]);
    }
    printf("\n");
    for (int  i = 0; i < MAX_DIAS; i++){
        printf("%i, ", comidas_intercambiadas[i]);
    }       
}

int main(){
    int comidas_original[MAX_DIAS]= {2, 4, 5, 7, 1, 3, 5};
    int comidas_intercamnbiadas[MAX_DIAS] = {7, 6, 3, 2, 1, 8, 9};
    intercambiar_comidas(comidas_original, comidas_intercamnbiadas);
}