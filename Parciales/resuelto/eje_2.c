/*

Mojojojo estuvo reclutando monitos para su nuevo ejércíto y se dió cuenta que era una buena oportunidad para tener un
doble. Con el, podria enganar a las chicas superpoderosas y conquistar Saltadilla.
Cuenta con un vector de monito_t donde cada elemento es un soldado de su ejército.
Como todos los monitos que recluto tienen similares rasgos taciales, va a elegir al que tenga su misma altura y peso.
Para buscarlo, recorrerá el vector de una manera particular
Si el soldado actual es mas alto que él por más de 10 cm, avanzará 5 soldados.
Si el soldado actual pesa menos que él, retrocederá 3 soldados.
Si se dan ambas cosas, o ninguna, avanzará un solo soldado.
SE PIDE
1. Crear un procedimiento recursivo que recorra el vector de soldados buscando el que pese y mida lo
mismo que Mojojojo y muestre por pantalla su nombre, en caso de existir.
Aclaración: tener en cuenta los casos bordes y justificar cómo resuelve los mismos.

*/
#include<stdio.h>
#include<string.h>
#define MAX_NOMBRE
#define ERROR -1
#define SI_ES_MAS_ALTO 5
#define SI_PESA_MENOS 3
#define SI_SON_AMBOS 1

typedef struct monitos {
    char name[MAX_NOMBRE];
    int edad;
    int altura;
    int peso;
} monito_t;

char buscar_monito_parecito_a_mojojojo_rec(monito_t monitos,int tope_monitos,int altura_mojojojo, int peso_mojojojo, int posicion_actual,  int cantidad_recorrida){
    //caso base
    if(posicion_actual >= tope_monitos){
        return ERROR;
    }
    if(monitos.altura == altura_mojojojo && monitos.peso == peso_mojojojo){
        printf("el nombre del mono similar a mojojojo es: %c", monitos.name[posicion_actual]);
    }
    //llamado a la recursividad
    int desplazamiento = SI_SON_AMBOS;
    if(monitos.altura > altura_mojojojo){
        desplazamiento = SI_ES_MAS_ALTO;
    }else if(monitos.peso < peso_mojojojo){
        desplazamiento = SI_PESA_MENOS;
    }

    return buscar_monito_parecito_a_mojojojo_rec(monitos, tope_monitos, altura_mojojojo, peso_mojojojo, posicion_actual+desplazamiento, cantidad_recorrida+1);
}

char buscar_monito_parecito_a_mojojojo(monito_t monitos, int tope_monitos, int altura_mojojojo, int peso_mojojojo){
    return buscar_monito_parecito_a_mojojojo_rec(monitos, tope_monitos, altura_mojojojo, peso_mojojojo, 0, 0);
}

