#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define AFIRMATIVO "Sí"
#define AFIRMATIVONT "No"

typedef struct tesoro {
char metal; // Oro, Plata, Bronce
int gramos;
int precio_por_gramo;
bool tiene_piedras_preciosas;
} tesoro_t;

bool son_parecidos(tesoro_t tesoro_a, tesoro_t tesoro_b){
    int contador = 0;
    if(tesoro_a.metal == tesoro_b.metal){
        contador++;
    }
    if(tesoro_a.gramos == tesoro_b.gramos){
        contador++;
    }
    if(tesoro_a.precio_por_gramo == tesoro_b.precio_por_gramo){
        contador++;
    }
    if(tesoro_a.tiene_piedras_preciosas == tesoro_b.tiene_piedras_preciosas){
        contador++;
    }

    return (contador > 2); 
}

// MODULARIZAR!!!!
void elegir_tesoros(tesoro_t tesoros[],
                    int tope_tesoros,
                    char* path_conf) {
    FILE* caracteristicas = fopen(path_conf,"r");
    if( caracteristicas == NULL ) {
        perror("no se pudo abrir el archivo bro");
        return;
    }
    tesoro_t configuracion;
    fscanf(caracteristicas,"METAL=%c%*s\n", &(configuracion.metal));
    fscanf(caracteristicas,"GRAMOS=%i\n", &(configuracion.gramos));
    fscanf(caracteristicas,"PRECIO_POR_GRAMO=%i\n", &(configuracion.precio_por_gramo));
    char tiene_piedras [3];
    fscanf(caracteristicas,"TIENE_PIEDRAS_PRECIOSAS=%s\n", tiene_piedras);

    if( strcmp(tiene_piedras, AFIRMATIVO) == 0 ) {
        configuracion.tiene_piedras_preciosas = true;
    }else{
        configuracion.tiene_piedras_preciosas = false;
    }

    fclose(caracteristicas);

    for(int i=0; i<tope_tesoros; i++){
        if(son_parecidos(configuracion,tesoros[i])){
            printf("see el tesoro en la posicion %i es igual\n",i);
        }
    }

}


int main (int argc, char* argv []){
    if ( argc != 2 ) {
        perror("cant parametros invalida \n");
        return -1;
    }
    tesoro_t tesoros[3];
    tesoros[0].metal= 'O';
    tesoros[0].gramos = 515;
    tesoros[0].precio_por_gramo = 13;
    tesoros[0].tiene_piedras_preciosas = true;
    int tope = 1;
    //elegir_tesoros(tesoros, tope,argv[1]);
    


    return 0;
}