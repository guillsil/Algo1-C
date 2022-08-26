 #include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(int argc, char* argv[]){

    for(int i = 0; i < argc; i++){
        printf("El argumento %i es: %s.\n", i+1, argv[i]);
    } 
    //atoi pasa char a entero
    int numero = atoi(argv[3]);
    printf("El 4to argumento es: %i\n", numero);
	
    return 0;
}
