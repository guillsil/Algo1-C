#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define MAX_NOMBRE 50
#define MAX_COLOR 50
#define READ "r"
#define WRITE "w"
#define ARCHIVO_PRIMOS "primos.csv"
#define ARCHIVO_PRIMOS_AMIGOS "primos_amigos.csv"
#define ARCHIVO_PRIMOS_ENEMIGOS "primos_enemigos.csv"
#define LECTURA_PRIMO "%[^;]%[^;];%i;%c;%c\n"
#define ESCRITURA_PRIMOS "%s%s;%i;%c;%c\n"
#define CANT_LEIDOS 5
const char SI = 'S';
const char NO = 'N';
/*Ejercicio 1
Stitch, siendo el primo más fuerte de todos, tiene tanto enemigos como amigos, pero como son
muchos no se acuerda con quien está peleado y con quien no. Necesita de nuestra ayuda para
organizarse mejor y pelear con quien debe y no ganarse nuevos enemigos.
Teniendo un archivo csv que contiene a todos los primos de Stitch se pide generar dos nuevos
archivos csv, uno que contenga todos los primos que son amigos, y otro que contenga todos los
primos que son enemigos.Se considera a un primo amigo cuando hace sandwichs o es chevere y la fuerza no supera 1000.
*/

typedef struct primo {
char nombre[MAX_NOMBRE];
char color[MAX_COLOR];
int fuerza;
bool es_chevere;
bool hace_sandwichs;
} primo_t;

//pre:Se considera a un primo amigo cuando hace sandwichs o es chevere y la fuerza no supera 1000
bool es_primo_amigo(primo_t primo){
    return(primo.hace_sandwichs || (primo.es_chevere && primo.fuerza<=1000));
}

bool char_to_boolean(char caracter){
    return(caracter == SI);
}
/* 
pre:ARCHIVO_PRIMOS tiene que ser un archivo valido
post:toma el archivo ARCHIVO_PRIMO  y va a crear sps csv , uno con los enemigos y otro con los amigos , devuelve 0 en caso de exito o si no 1. 
*/
int leer_primos(FILE* f_primo, primo_t* primo){
    char es_chevere_char;
    char hace_sanguches;

    int leidos = fscanf(f_primo, LECTURA_PRIMO, primo->nombre, primo->color, primo->fuerza, &es_chevere_char, &hace_sanguches);

    primo->es_chevere = char_to_boolean(es_chevere_char);
    primo->hace_sandwichs = char_to_boolean(hace_sanguches);

    return leidos;
}
//post:si el valor es true devuelve SI en caso contrario devuelve No
char boolean_to_char(bool valor){
    if(valor){
        return SI;
    }else{
        return NO;
    }
}
//pre:eln primo tiene que tener campos inicializados y validos
//post:
int escribir_primo(FILE* f_primo, primo_t primo){
    char es_chevere_char = boolean_to_char(primo.es_chevere);
    char hace_sanguches = boolean_to_char(primo.hace_sandwichs);

    int escritos = fprintf(f_primo, ESCRITURA_PRIMOS, primo.nombre, primo.color, primo.fuerza, es_chevere_char, hace_sanguches);
    return escritos;
}

int separar_primos(){
    FILE* f_primo = fopen(ARCHIVO_PRIMOS, READ);
    if(!f_primo){
        perror("noce se puede abrir ");
        return 1;
    }
    
    FILE* f_primo_amigos = fopen(ARCHIVO_PRIMOS_AMIGOS, WRITE);
    if(!f_primo_amigos){
        perror("noce se puede abrir ");
        fclose(f_primo);
        return 1;
    }
    
    FILE* f_primo_enemigos = fopen(ARCHIVO_PRIMOS_ENEMIGOS, WRITE);
    if(!f_primo_enemigos){
        perror("noce se puede abrir ");
        fclose(f_primo);
        fclose(f_primo_amigos);
        return 1;
    }
    
    primo_t primo;

    int leidos = leer_primos(f_primo, &primo);
    
    while (leidos == CANT_LEIDOS){
        if(es_primo_amigo(primo)){
            escribir_primo(f_primo_amigos, primo);
        }else{
            escribir_primo(f_primo_enemigos, primo);
        }
        leidos = leer_primos(f_primo, &primo);

    }

    fclose(f_primo);
    fclose(f_primo_amigos);
    fclose(f_primo_enemigos);
    return 0;
}


int main(int argc, char const *argv[]){
    
    separar_primos();

    return 0;
}
