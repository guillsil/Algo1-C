#include<stdio.h>
#include"tp1.h"

#define EXAMEN 15.3f
static const char OLAF = 'O', STITCH = 'S', JASMIN = 'J', RAYO = 'R';
static const char  TRINEO = 'T', NAVE = 'N', CAMION = 'C',ALFOMBRA = 'A';
static const char BOLAS ='B', PIUM = 'P', KUCHAU = 'K', GENIO = 'G';

static const int PUNTOS1_PREG1 = 10, PUNTOS2_PREG1 = 20;

static const int PUNTOS1_PREG2 = 3, PUNTOS2_PREG2 = 6;
static const int PUNTOS3_PREG2 = 9, PUNTOS4_PREG2 = 12;

static const int MULTI_VALOR1 = 1, MULTI_VALOR2 = 2;
static const int MULTI_VALOR3 = 3, MULTI_VALOR4 = 4;

static const int HORA_MIN = 1, HORA_MAX = 23;
static const float MINUTO_MAX = 0.60f;

static const int NOTA_MIN = 1, NOTA_MAX = 10;

static const int PUNTOS_MIN = 13, PUNTOS_MED = 42, PUNTOS_MAX = 68;


//Pre:-
//Post:modifico la variable que almacena esa respuesta.
void preguntar_transporte(char* opc){
    printf("\nEstás saliendo de tu casa, y te enteras que hay paro de trenes, ¿Qué otro transporte elegís\n");
    printf("Las respuestas pueden ser: Trineo (T), Nave Espacial (N), Camión (C) o Alfombra (A): ");
    scanf(" %c", opc);
}
//Pre:los puntos asignar tienen que ser menor a 20-
//Post:Asigno puntos al contador.
void asignacion_puntos1(char* opcion, int* contador){
    if (*opcion == TRINEO || *opcion == NAVE)*contador = PUNTOS1_PREG1;
    else {
        *contador = PUNTOS2_PREG1;
    }
}
//Pre: La respuetas tienen que ser en mayuscula.
//Post: Sumo los puntos a contador y comprueba si es correcta la respuesta del usuario
int pregunta_transporte(){
    char opcion ;
    int contador = 0;
    preguntar_transporte(&opcion);
    while ((opcion != TRINEO) && (opcion != NAVE) && (opcion != CAMION) && (opcion != ALFOMBRA)){
        printf("\nRESPUESTA INCORRECTA, Vuelva a Ingreasar una Opcion Válida entre las opciones disponibles.\n");
        preguntar_transporte(&opcion);
    }
    asignacion_puntos1(&opcion, &contador);
    return contador;
}
//Pre:Poder tiene que estar entre las constantes validas PIUM, KUCHAU, GENIO, BOLAS.
//POst:-
void preguntar_poder(char* opc){
    printf("\nEn medio del camino te encontras con una manifestación, ¿Que medio utilizas para deshacerte de la manifestación?\n");
    printf("Las respuestas pueden ser: Bolas de nieve (B), Pium pium (P), Kuchau (K) o Genio (G): ");
    scanf(" %c", opc);
}
//Pre:-
//Post: Dependiendo la opcion escogida te asigno los puntos a contador.
void asignacion_puntos2(char* opc, int* contad){
    if (*opc == BOLAS){
        *contad = PUNTOS1_PREG2;
        }
    else if (*opc == PIUM){
        *contad = PUNTOS2_PREG2;
    }
    else if (*opc == KUCHAU){
        *contad = PUNTOS3_PREG2;
    }
    else{
        *contad = PUNTOS4_PREG2;
    }
}
//Pre:La opciones ingresada por el user deben ser BOLAS, PIUM, KUCHAU, GENIO 
//Post:Te sumo los puntos correspondiente al contador
int pregunta_poder(){
    char opcion;
    int contador;
    preguntar_poder(&opcion);
    while ((opcion != BOLAS) && (opcion != PIUM) && (opcion != KUCHAU) && (opcion !=GENIO)){
        printf("\nRESPUESTA INCORRECTA, Vuelva a Ingreasar una Opcion Válida entre las opciones disponibles\n");
        preguntar_poder(&opcion);
    }
    asignacion_puntos2(&opcion, &contador);
    return contador;
}

//Pre:la hora tine que ser mayor a 1 y menor a 23 y los minutos mayor a 1 y menor a 60
//Post:-
void preguntar_hora(float* hora_usuario, int* hora, float* minuto){
    printf("\nLograste superar la manifestación, ¿A qué hora conseguiste llegar a la universidad?\n");
    printf("Indica la hora seguida de los minutos: ");
    scanf("%f", hora_usuario);
    *hora = (int)*hora_usuario;
    *minuto = *hora_usuario - (float)*hora;
}
//Pre:Los minutos tiene que ser mayor a 1 y menor a 60 y la hora tine que ser mayor a 1 y menor a 23. 
//POst:Asigna los puntos correspondientes a la variable contador
float pregunta_hora_llegada(){
    float tiempo_user= 0,minuto = 0;
    int hora = 0;
    preguntar_hora(&tiempo_user, &hora, &minuto);
    while (hora < HORA_MIN || hora > HORA_MAX || minuto > MINUTO_MAX){
        printf("\nHORA INVALIDA.INGRESA UNA HORA CORRECTAMENTE.\n ");
        preguntar_hora(&tiempo_user, &hora, &minuto);
    }
    return tiempo_user;
}
//Pre:La nota debe ser mayor o igual a 1 y menor o igual a 10.
//Post:-
void preguntar_nota(int* opcion){
    printf("\nPor fin llegó la nota del parcial! ¿Qué nota lograste sacarte?\n");
    scanf("%i", opcion);
}
//Pre:la nota debe ser mayor o igual a 1 y menor o igual a 10.
//Post:multiplicador recibe los valores que le corresponde segun la nota.
void asignacion_puntos4(int* opcion, int* multiplicador){
    if (*opcion >= 1 && *opcion <= 3){
        *multiplicador = MULTI_VALOR1;
    }
    else if (*opcion >= 4 && *opcion <= 6){
        *multiplicador = MULTI_VALOR2;
    }
    else if (*opcion >= 7 && *opcion <= 8){
        *multiplicador = MULTI_VALOR3;
    }
    else{
        *multiplicador = MULTI_VALOR4;
    }
}
//Pre:La nota debe ser mayor o igual a 1 y menor o igual a 10
//Post: te sumo los puntos correspondiente al contador.
int pregunta_nota_examen(){
    int opcion = 0 ,multiplicador = 0;
    preguntar_nota(&opcion);
    while (opcion  < NOTA_MIN|| opcion >NOTA_MAX){
        printf("Respuesta Incorrecta, Vuelva a Ingrsar el valor correctamente.\n");
        preguntar_nota(&opcion);
    }
    asignacion_puntos4(&opcion, &multiplicador);
    return multiplicador;
}
//Pre: 'contador3' tiene que ser  menor o igual a 23.
//Post:Te devuelvo el resultado de la operacion en la variable puntaje.
int calculo_puntaje(int contador1, int contador2, int contador4){
    int puntaje = 0;
    puntaje = contador1 + ((contador2) * (contador4));
    return puntaje;
}
//Pre:Puntaje tiene que ser <= a 41 y la hora <= a 23
//Post:En base a la hora que llego el personaje,te digo tu personaje.
void determinacion_team1(int puntaje, float contador3, char* personaje_obtenido){
    if (puntaje >= PUNTOS_MIN && puntaje < PUNTOS_MED){
        if (contador3 <= EXAMEN){
           printf("Felicidades,Con un puntaje de %i puntos se definió el personaje de  -"RESPUESTA_STITCH"-\n", puntaje);
            *personaje_obtenido = STITCH;
        } else if (contador3 > EXAMEN){
             printf("Felicidades, Con un puntaje de %i puntos se definió el personaje de -"RESPUESTA_OLAF"-\n", puntaje);
            *personaje_obtenido = OLAF;
        }
    }
}
//Pre:Puntaje tiene que ser > igual a 41 y la hora <= a 23
//Post:En base a la hora que llego el personaje,te digo tu personaje.
void determinacion_team2(int puntaje, float contador3, char* personaje_obtenido){
    if (puntaje > PUNTOS_MED && puntaje <= PUNTOS_MAX){
        if (contador3 <= EXAMEN){
            printf("Felicidades, Con un puntaje de %i puntos se definió el personaje de -"RESPUESTA_JASMIN"-\n", puntaje);
            *personaje_obtenido = JASMIN;
        }
        else if(contador3 > EXAMEN){
            printf("Felicidades, Con un puntaje de %i puntos se definió el personaje de -"RESPUESTA_RAYO"-\n", puntaje);
            *personaje_obtenido = RAYO;
        }   
    }   
}

void programa_tp1(char *personaje_obtenido){
    int contador1= 0, contador2 = 0, contador4 = 0, puntaje = 0;
    float contador3 = 0.0f;
    contador1 = pregunta_transporte();
    contador2 = pregunta_poder();
    contador3 = pregunta_hora_llegada();
    contador4 = pregunta_nota_examen();
    puntaje = calculo_puntaje(contador1, contador2, contador4);
    determinacion_team1(puntaje, contador3, personaje_obtenido);
    determinacion_team2(puntaje, contador3, personaje_obtenido);
}