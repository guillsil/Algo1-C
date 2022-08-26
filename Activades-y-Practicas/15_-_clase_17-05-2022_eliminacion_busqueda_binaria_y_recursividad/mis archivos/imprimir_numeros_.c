#include <stdio.h>
#define ERROR -1

void imprimir_numero(int n){
    //caso base
    if (n == 0){
        return ERROR;
    }
    //llamado a la funcion recursiva
    imprimir_numero(n-1);
    //proceso 
    printf("%i\n", n);
}

void imprimir_array(){

    
}


int main(){
    imprimir_numero(100);
}