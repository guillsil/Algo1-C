#include <stdio.h>
#include <stdbool.h>
#define MAX_ARRAY 10

/*
Consiste en encontrar el menor de todos los elementos del vector e intercambiarlo con el que está en la primera posición. Luego el segundo mas pequeño, y así sucesivamente hasta ordenarlo todo.
*/

/*
para explicar este metodo de ordenamiento , supongamos que tenemos una balanza de cruz y tenemos distintos manzanas de distintos tamaños y peso , pero a nosotros nos intereza ordenanarlas por su peso , para este ejemplo tenemos 4 manzanas que estan mezcladas y puesta sobre la mesa una al lado de la otra , si queremos ordenanrlas por el metodo de seleccion lo que haremos es empezar con la primera manzana que esta a la izquierda(Aclaracion vamos a ordenarlas de menor peso a mayor) agarramos esta manzana y la ponemos a la derecha de balanza cruz , y en la izquierda colocamos a la manzana que esta a la derecha de la primera manzana agarrada , como vemos que la balanza cruz me marca que la manzana que agarre para compararla con la primera es mas pesada que la primera , entonces la bajo y pruebo con la siguiente , realizo el mismo procedimiento con las otros dos manzanas restantes. Se da el caso que al compararla con la ultima manzana esta es de menor peso que la manzana agarrada al princio , como esto sucede entonces esta manza al ser de menor, peso la coloco en la posicion de la primera manzana que agarre , ahora esta manzana me quedo ordenada, lo que sigue es hacer el mismo mecanismo con las demas manzanas , sin tener en cuenta a la ya encontrada de menor peso, lo que hago es agarrar a la segunda manzana que esta a la derecha de la que encontre y la pongo a la derecha de a balanza cruz , y a la izquierda coloco a la otra manzana que esta esta a la derecha de la que agarre recien , sigo este mecanismo hasta que la manzana de la ultima posicion ya estee ordenada.
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

int posicion_maximo(int array[MAX_ARRAY], int tope, int inicio){
    int pos_max = inicio;
    for (int i = (inicio+1); i < tope; i++){
        if(array[i]>array[pos_max]){
            pos_max = i;
        }
    }
    return pos_max;
}


int posicion_minimo(int array[MAX_ARRAY], int tope, int inicio){
    int pos_minimo = inicio;
    for (int i = (inicio+1); i < tope; i++){
        if(array[i]<array[pos_minimo]){
            pos_minimo = i;
        }
    }
    return pos_minimo;
}

void selection_sort_de_menor_a_mayor(int array[MAX_ARRAY], int tope_array){
    for (int i = 0; i < tope_array; i++){
        int pos_minimo = posicion_minimo(array, tope_array, i);
        swap(&array[i], &array[pos_minimo]);
    }    
}


void selection_sort_de_mayor_a_menor(int array[MAX_ARRAY], int tope_array){
    for (int i = 0; i < tope_array; i++){
        int pos_max = posicion_maximo(array, tope_array, i);
        swap(&array[i], &array[pos_max]);
    }    
}

int main(){
    int array[MAX_ARRAY]={2,4,5,6,7,9,1,2,3,8};
    int tope_array = 10;
    printf("ARRAY RANDOM\n");
    imprimir_array(array, tope_array);

    selection_sort_de_menor_a_mayor(array, tope_array);
    printf("\nARRAY ORDENADO DE MENOR A MAYOR\n");
    imprimir_array(array, tope_array);

    selection_sort_de_mayor_a_menor(array, tope_array);
    printf("\nARRAY ORDENADO DE MAYOR A MENOR\n");
    imprimir_array(array, tope_array);
}