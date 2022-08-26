#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h> 
#include"la_sombra_de_mac.h"   
#include"utiles.h"                                                                    


int main(){

    
    srand((unsigned)time(NULL));
   
      
    juego_t juego;
    
    inicializar_juego(&juego);      
    imprimir_terreno(juego);
    while(estado_juego(juego) == 0){
        realizar_jugada(&juego);
    }
   


    
    return 0;
}