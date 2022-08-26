#include <stdio.h>
#define MAX_ARRAY 20
#define NO_EXISTE -1


int busquea_binaria_rec(int array[MAX_ARRAY],int inicio, int fin, int buscado){
    //CASO BASE 1
    if (inicio > fin){
        return NO_EXISTE;
    }
    int centro = (inicio + fin)/2;
    //CASO BASE 2
    if(array[centro] == buscado){
        return centro;
    }
    //llamada a funcion recursiva
    if(array[centro] > buscado){
        return busquea_binaria_rec(array, inicio, (centro-1), buscado);
    }else if(array [centro] < buscado) {
        return busquea_binaria_rec(array, (centro+1), fin, buscado);
    }
}

int busquea_binaria(int array[MAX_ARRAY], int tope, int buscado){
    //inicio= 0; fin= tope-1
    return busquea_binaria_rec(array, 0, (tope-1), buscado);
}

int main(){
    int array[MAX_ARRAY]= {5, 6, 7, 8, 9, 2, 1, 3};
    int tope = 8;
    int buscado = 2;
    int se_econtro = 0;
    se_econtro = busquea_binaria(array, tope, buscado);
    printf("%i", se_econtro);
}