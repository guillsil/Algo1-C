#include <stdio.h>
#include <stdbool.h>
#define MAX_ARRAY 10

/*
Funciona revisando cada elemento de la lista que va a ser ordenada con el siguiente, intercambiándolos de posición si están en el orden equivocado. Es necesario revisar varias veces toda la lista hasta que no se necesiten más intercambios, lo cual significa que la lista está ordenada. Este algoritmo obtiene su nombre de la forma con la que suben por la lista los elementos durante los intercambios, como si fueran pequeñas "burbujas". También es conocido como el método del intercambio directo. Dado que solo usa comparaciones para operar elementos, se lo considera un algoritmo de comparación, siendo el más sencillo de implementar
*/

/*
explicacion con mis palabras:
el metodo de ordenamiento bubble sort funciona de una forma muy simple , supongamos que tenemos cajas de lapices los cuales vinen ordenados por el color , cada color representa un numero , ahora como nosotros somos demaciados ordenados y nos justa la proligidad queremos tener esa caja de lapices ordenadas segun el numero de colores , como tenemos todos los colores mezclados , lo que vamos hacer es ponerlo en la meza y arrancar con el primer par de lapices , y vemos los colores son 4(rojo) y 3(azul) al rojo lo tengo en la primera posicion a la izquierda y al azul a su derecha , como yo quiero ordenar en el orden que vinieron es decir de menor a mayor , entonces procedo a intercambiarlos ya que el azul esta antes que el rojo , por la razon que ya mencione anteriormente el (4(rojo) y 3(azul)), esta idea que plantee la seguiria haciendo para lo demas lapices siempre tomandolos de a pares y comparandolos , lo que va sucedes si hago esto sucesiamente es que los colores con numero de indentificacion mas grandes van a quedar al fondo, esto lo voy a repetir hasta que me asegure que todo queden ordenados.
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

void bubble_sort_de_menor_a_mayor(int array[MAX_ARRAY],int tope_array){
    for (int i = 0; i <(tope_array-1); i++){
        for (int j = 0; j < (tope_array-1-i); j++){
            if (array[j] > array[j+1]){
                swap(&array[j], &array[j+1]);
            }
        }   
    }
}

void bubble_sort_de_mayor_a_menor(int array[MAX_ARRAY],int tope_array){
    for (int i = 0; i <(tope_array-1); i++){
        for (int j = 0; j < (tope_array-1-i); j++){
            if (array[j] < array[j+1]){
                swap(&array[j], &array[j+1]);
            }
        }   
    }
}
//se corta antes en el caso que ya estan ordenados y no hace el ultimo recorrido
void bubble_sort_metodo_optizado(int array[MAX_ARRAY],int tope_array){
    bool encontrado = false;
    int i = 0;
    while(encontrado == false, i <(tope_array-1)){
        encontrado = true;
        for (int j = 0; j < (tope_array-1-i); j++){
            if (array[j] < array[j+1]){
                swap(&array[j], &array[j+1]);
                encontrado = false;
            }
        }  
        i++; 
    }
}

int main(){
    int array[MAX_ARRAY]={2,4,5,6,7,9,1,2,3,8};
    int tope_array = 10;
    printf("ARRAY RANDOM\n");
    imprimir_array(array, tope_array);

    bubble_sort_de_menor_a_mayor(array, tope_array);
    printf("\nARRAY ORDENADO DE MENOR A MAYOR\n");
    imprimir_array(array, tope_array);

    bubble_sort_de_mayor_a_menor(array, tope_array);
    printf("\nARRAY ORDENADO DE MAYOR A MENOR\n");
    imprimir_array(array, tope_array);

    bubble_sort_metodo_optizado(array, tope_array);
    printf("\nARRAY ORDENADO METODO OPTIMIZADO\n");
    imprimir_array(array, tope_array);
}