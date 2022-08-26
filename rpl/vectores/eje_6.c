/* 
Después de varios días de ahorros Alex, Justin y Max por fin pudieron comprar una nueva varita mágica con un diseño que a los tres les gusta mucho. El tema es que solo lograron comprar una y no se deciden en quien la usará primero. Por lo que llegaron a un acuerdo, el que haya ahorrado más plata en un día usará la varita primero.
Recordemos que tenían sus ahorros en un vector donde cada posición corresponde a un día diferente. Esto quiere decir que en la posición 0 (cero) del vector vamos a tener el día 1 (uno), luego la 2 (dos) y así.

    Implementar una función que dado el vector con los ahorros devuelva quién es el ganador.
    Se sabe que en los días pares ahorró solo Alex, en los impares múltiplos de 5 ahorró Justin y en el resto ahorró Max. Tene en cuenta que el ganador es el que más ahorró en un día, no en total y que cada uno se representa con un char:

    -Justin (J).
    -Alex (A).
    -Max (M).

En el caso de que no haya ahorros, es decir, que el vector de ahorros esté vacío, se debe devolver N de nadie.
*/

#include <stdio.h>
#define MAX_AHORROS 256
const char JUSTIN = 'J';
const char ALEX = 'A';
const char MAX = 'M';

void el_ganador(int j, int a, int m){
    if (j>a && j>m){
        printf("el ganador es %c\n", JUSTIN);
    }else if (m>j && m>a){
        printf("el ganador es %c\n", MAX);
    }else if(a >j && a > m){
        printf("el ganador es %c\n", ALEX);
    }else if(a == 0 && j == 0 && m == 0){
        printf("N");
    }
}

char ganador_ahorrista(int ahorros[MAX_AHORROS], int tope_ahorros) {
    int ahorros_j = 0, ahorros_a = 0, ahorros_m = 0;
    for(int i = 0; i < tope_ahorros; i++){
        if(ahorros[i] % 2 == 0){
            ahorros_a++;
        }else if(ahorros[i] % 5 == 0){
            ahorros_j++;

        }else{
            ahorros_m++;
        }
    }
    printf("Justin ahorro: %i\n", ahorros_j);
    printf("Max ahorro : %i\n", ahorros_m);
    printf("Alex ahorro :%i\n", ahorros_a);

    el_ganador(ahorros_j, ahorros_a, ahorros_m);
}

int main(){
    int array[MAX_AHORROS]= {2, 3,5, 6 ,8, 3 ,2 ,3, 10, 15};
    int tope = 9;
    ganador_ahorrista(array, tope);
    return 0;
}