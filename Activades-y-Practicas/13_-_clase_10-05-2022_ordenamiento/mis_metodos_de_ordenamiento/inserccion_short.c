#include <stdio.h>
#include <stdbool.h>
#define MAX_ARRAY 10
/*

*/

/*
Para explicar este tipo de ordenamiento consideremos que tengo unas cartas en mi mano y las cartas están ordenadas.Si tomo una nueva carta del mazo. Y la coloco en el sitio correcto de manera que las cartas en mi mano sigan estando ordenadas. Pero en este ejemplo de las cartas, la nueva carta podría ser menor que algunas de las cartas que ya tengo en la mano, así que tengo que ir una por una, comparando la nueva carta con cada una de las que ya tengo en la mano, hasta encontrar el lugar donde debe ser colocada. Agrego la nueva carta en el sitio correcto y, una vez más, tengo en la mano cartas completamente ordenadas. Entonces tomo otra carta del mazo y repito el mismo procedimiento. Luego otra carta, y otra, y así repetidamente, hasta terminar con el mazo.
*/

void imprimir_array(int array[MAX_ARRAY],int tope_array){
    for (int i = 0; i < tope_array; i++){
        printf("%i, ", array[i]);
    }
}

void swap(int* a, int* b){
    int aux;
    aux = *a;
    *a= *b;
    *b = aux;
}

void insercion_sort_de_menor_a_mayor(int array[MAX_ARRAY], int tope){
    int j, aux;
    for (int i = 1; i < tope; i++){
        j = i;
        aux = array[i];
        while (j>0 && aux < array[j-1]){
            array[j]=array[j-1];
            j--;
        }
        array[j]=aux;
    }
}

void insercion_sort_de_mayor_a_menor(int array[MAX_ARRAY], int tope){
    int j, aux;
    for (int i = 1; i < tope; i++){
        j = i;
        aux = array[i];
        while (j>0 && aux > array[j-1]){
            array[j]=array[j-1];
            j--;
        }
        array[j]=aux;
    }
}








int main(){
    int array[MAX_ARRAY]={2,4,5,6,7,9,1,2,3,8};
    int tope_array = 10;
    printf("ARRAY RANDOM\n");
    imprimir_array(array, tope_array);

    insercion_sort_de_menor_a_mayor(array, tope_array);
    printf("\nARRAY ORDENADO DE MENOR A MAYOR\n");
    imprimir_array(array, tope_array);

    insercion_sort_de_mayor_a_menor(array, tope_array);
    printf("\nARRAY ORDENADO DE MAYOR A MENOR\n");
    imprimir_array(array, tope_array);

    
}