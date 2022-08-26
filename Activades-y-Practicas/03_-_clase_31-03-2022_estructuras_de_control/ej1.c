#include <stdio.h>

#define PRIMERA_MAYUSCULA 'A'
const char ULTIMA_MAYUSCULA = 'Z';
const char PRIMERA_MINUSCULA = 'a';
const char ULTIMA_MINUSCULA = 'z';

int main(){
    char letra = '5';

    if(letra >= PRIMERA_MAYUSCULA && letra <= ULTIMA_MAYUSCULA){
        printf("Las mayusculas son grandes como bokitaa\n");
    } else if(letra >= PRIMERA_MINUSCULA && letra <= ULTIMA_MINUSCULA){
        printf("Las minusculas son chikis como river\n");
    } else{
        printf("para para que me estas mandando?\n");
    }
    return 0;
}

