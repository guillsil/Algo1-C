#include <stdio.h>
#define ERROR -1

int factorial(int fact){
    //caso base 
    if(fact == 0){
        return ERROR;
    }
    //llamado a la recursividad y proceso
    return ((fact * factorial(fact-1))) * (-1);
}

int main(){
    int fact = factorial(7);
    printf("%i", fact);
}