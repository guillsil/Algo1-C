/* 
Lilo y Stitch llevan registro de todos los experimentos extraviados del Dr. Jumba que encuentran, y para hacerlo los tienen en un vector donde a cada experimento lo representan con un id que es un entero.
Últimamente están encontrando muchos experimentos nuevos y se les complica un poco estar agregándolos a mano a este vector, por lo que nos pidieron ayuda para que creemos un algoritmo que lo haga por ellos. Pero como nosotros nos dormimos en esas clases te lo pedimos a vos.

    Implementar una función que dado un vector, su tope y un id agregue al nuevo experimento al vector.
    Además si no es posible agregarlo porque el vector ya está al máximo de su capacidad se pide que devuelva false y en caso contrario que devuelva true.

*/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX_EXPERIMENTOS 10

/*  
Si sizeof devuelve el tamaño en bytes de un arreglo
*/
int main(){
    int experimentos[MAX_EXPERIMENTOS]= {3,4,5,5,6,7,9};
    int tope= 7;
    int id = 8; 
    /*//memoria que ocupa todo el arreglo
    int tamnio_del_array = sizeof(experimentos);
    //memoria que ocupa la primer componente del vector
    int tamnio_del_primer_componentente_del_array = sizeof(experimentos[0]);
    //divicion para obtener el tamnio del arrglo 
    int longitud = tamnio_del_array / tamnio_del_primer_componentente_del_array;
    printf("%i:\n", longitud); */
    int total = tope+1;
    experimentos[total]= id;

    printf("%i", total);
    for (int i = 0; i < total; i++){
        printf("%i, ", experimentos[i]);
    }

}