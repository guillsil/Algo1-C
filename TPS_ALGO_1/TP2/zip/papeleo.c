#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include"utiles.h"
#include"papeleo.h"
#include"tp1.h"

#define MAX_PERSONAJE_TP1 4
#define MAX_OBJETOS  100
#define MAX_FIL 22
#define MAX_COL 22

const char PERSONAJE_JASMIN = 'J';
const char PERSONAJE_OLAF = 'O';
const char PERSONAJE_RAYO = 'R';
const char PERSONAJE_STITCH = 'S';

const char PERSONAJE_JUEGO = 'W';

const char GUION = '-';
const char PARED = '#';
const char ESPACIO = ' ';

const int CANTIDAD_MOVIMIENTO_NIVEL_1 = 40;
const int CANTIDAD_MOVIMIENTO_NIVEL_2 = 30;
const int CANTIDAD_MOVIMIENTO_NIVEL_3 = 20;

const char FUEGO = 'F';
const int CANTIDAD_FUEGOS_1 = 10;
const int CANTIDAD_FUEGOS_2 = 5;
const int CANTIDAD_FUEGOS_3 = 3;

const char MEDIAS = 'M';
const int CANTIDAD_MEDIAS_1 = 5;
const int CANTIDAD_MEDIAS_2 = 4;
const int CANTIDAD_MEDIAS_3 = 3;

const char EXTINTORES = 'E';
const int CANTIDAD_EXTINTORES_1 = 4;
const int CANTIDAD_EXTINTORES_2 = 2;
const int CANTIDAD_EXTINTORES_3 = 2;

const char MARTILLOS = 'N';
const int CANTIDAD_MARTILLOS_1 = 4;
const int CANTIDAD_MARTILLOS_2 = 5;
const int CANTIDAD_MARTILLOS_3 = 6;

const char BOTELLAS = 'G';
const int CANTIDAD_BOTELLAS_1 = 4;
const int CANTIDAD_BOTELLAS_2 = 3;
const int CANTIDAD_BOTELLAS_3 = 2;

const char INTERRUPTORES = 'I';
const int CANTIDAD_INTERRUPTORES_1 = 1;
const int CANTIDAD_INTERRUPTORES_2 = 1;
const int CANTIDAD_INTERRUPTORES_3 = 0;

const char PAPELEO = 'P';
const int CANTIDAD_PAPELEO_1 = 2;
const int CANTIDAD_PAPELEO_2 = 3; 
const int CANTIDAD_PAPELEO_3 = 4;
const int RESTAR_PAPELEO = 3;

const int PAPERS_ID1 = 0;
const int PAPERS_ID2 = 1;
const int PAPERS_ID3 = 2;
const int PAPERS_ID4 = 3;
const int PAPERS_ID5 = 4;
const int PAPERS_ID6 = 5;
const int PAPERS_ID7 = 6;
const int PAPERS_ID8 = 7;
const int PAPERS_ID9 = 8;
const int PAPERS_ID10 = 9;

#define NIVEL_1 1
#define NIVEL_2 2
#define NIVEL_3 3

#define MAX_LETRAS 100

const int SIZE_NIVEL_1 = 22;
const int SIZE_NIVEL_2 = 17;
const int SIZE_NIVEL_3 = 12;

const int OBSEQUIO_MOVIMIENTOS = 10;

const int FUEGO_BORRAR_1 = 1;
const int FUEGO_BORRAR_2 = 2;

const int PERSONAJE_TP1_1 = 1;
const int PERSONAJE_TP1_2 = 2;
const int PERSONAJE_TP1_3 = 3;
const int PERSONAJE_TP1_4 = 4;

typedef struct obsequio{
    bool martillo;
    bool movimiento;
    bool pistolita;
    bool apagar_fuego;
}obsequio_t;



int buscar_objeto(objeto_t objeto[MAX_OBJETOS], int tope, coordenada_t posicion);
/* 
//Pre:recibe la letra de la inicial de peronaje del tp anterior, estas letras deben ser J,R,O,S
//Post:devuelve un numero entre el 1 y el 4
*/
void pasar_letra_a_number(char personaje_tp1, int* number_personaje){
    if (personaje_tp1 == PERSONAJE_JASMIN){
        *number_personaje = PERSONAJE_TP1_1;
    } else if(personaje_tp1 == PERSONAJE_OLAF){
        *number_personaje = PERSONAJE_TP1_2;
    } else if(personaje_tp1 == PERSONAJE_RAYO){
        *number_personaje = PERSONAJE_TP1_3;
    } else if(personaje_tp1 == PERSONAJE_STITCH){
        *number_personaje = PERSONAJE_STITCH;
    }
}
/* 
//Pre:Pide el  personaje obtenido del tp anterior ,al responder las preguntas del inicio  y el struct de obsequio el cual consta de 4 bool de los distintos obsequios que puede conseguir y una para almacenar la letra del inicial del personaje.
//Post: dependiendo  que personaje le toco al persona delvuelve el struc de obsequio completo con lo los obsequuios que se deben aplicar 
si el obsequio se debe apliar entonces ese obsequio devuele el valor de true en caso contarario devuelve un false 
*/
void asignar_obsequio(char amigo_pide_favor, obsequio_t* obsequio){
    if (amigo_pide_favor == PERSONAJE_JASMIN){
        obsequio->martillo = true;
        obsequio->movimiento = false;
        obsequio->pistolita = false;
        obsequio->apagar_fuego = false; 
    } else if (amigo_pide_favor == PERSONAJE_OLAF){
        obsequio->apagar_fuego = true;
        obsequio->martillo = false;
        obsequio->movimiento = false;
        obsequio->pistolita = false;
    } else if (amigo_pide_favor == PERSONAJE_RAYO) {
        obsequio->movimiento = true;
        obsequio->pistolita = false;
        obsequio->apagar_fuego = false;
        obsequio->martillo = false;
    } else if (amigo_pide_favor == PERSONAJE_STITCH) {
        obsequio->pistolita = true;
        obsequio->apagar_fuego = false;
        obsequio->martillo = false;
        obsequio->movimiento = false;
    }
}

/* 
//Pre:recibe el vector del objeto a comparar , los vectores herramientas, obstaculos  con sus respectivos topes
//Post:si no encuentra ningun elemento devolvera un true.
*/
bool es_coordenada_disponible(coordenada_t objeto, nivel_t* nivel){
    bool disponible= true;
    if ((buscar_objeto(nivel->herramientas, nivel->tope_herramientas, objeto) != -1 || buscar_objeto(nivel->obstaculos, nivel->tope_obstaculos, objeto)!= -1)){
        disponible = false;
    }
    return disponible;
}

/* 
//Pre:recibe dos coordenadas y si las mismas son iguales
//Post:devuelve  true si las mismas son iguales en caso contrario un false
*/
bool es_coordenadas_igual(coordenada_t l, coordenada_t g){
    return (l.fil == g.fil && l.col == g.col);
}

/* 
//Pre:recive un vector objeto con el tope y la coordenada a comparar 
//Post:si en el caso de que se encuentre una coordenada del vector objeto similar al de la posicion pasada entonces 
    devolvera la posicion del objeto que coincidieron y en caso contrario devolvera un -1.
*/
int buscar_objeto(objeto_t objeto[MAX_OBJETOS], int tope, coordenada_t posicion){
    int posicion_v = -1;
    for (int j = 0; j < tope; j++){
        if (es_coordenadas_igual(posicion, objeto[j].posicion)== true){
            posicion_v =j;
        }
    }
    return posicion_v;
}
/* 
//Pre:Dados dos numeros, un max y un min, que representa el rango a crear de una coordenada,  
//Post:vevolvera una coordenada aleatoria entre ambos extremos , los cuales no pueden ser mayores ni menores a sus extremos 
*/
coordenada_t coordenada_aleatoria(int max_fil, int max_col){
    coordenada_t pocision_aleatoria;
    pocision_aleatoria.fil = rand() % max_fil;
    pocision_aleatoria.col = rand() % max_col;
    return pocision_aleatoria;
}
/* 
Pre: pide las coordenadas del vector paredes junto a su tope y la coordenada del objeto a comparar;
Post:busca en el vector paredes si coincide con alguna posicion del objeto, devuelve true si coincide con una las paredes.
*/
bool es_pared(nivel_t* nivel, coordenada_t objeto){
    bool existe = false;
    for (int j = 0; j < nivel->tope_paredes; j++){
        if (es_coordenadas_igual(nivel->paredes[j], objeto)){
            existe = true;
        }   
    }
    return existe;
}
/* 
//Pre:recibe el nivel(el nivel tiene que estar entre 0 y 2) en el cual se encuentra el juego 
//Post: y muestra la dimencion del mismo la cual debe estar entre 22, 17, 12
*/
void dimencion_matriz(int* dimencion, int nivel){

    if (nivel == NIVEL_1){
        *dimencion = SIZE_NIVEL_1;
    } else if (nivel == NIVEL_2){
        *dimencion = SIZE_NIVEL_2;
    } else if (nivel == NIVEL_3){
        *dimencion = SIZE_NIVEL_3;
    }
}
/* 
//Pre:recive la matriz con la dimencion de del nivel a limpiar (la dimencion debe ser 22, 17, 12)
//Post:mostrara en la pantalla un espacio , para que que la matriz noce inicie con basura
*/
void limpiar_matriz(char game_terreno[MAX_PAREDES][MAX_PAREDES], int dimencion){
    for (int i = 0; i < dimencion; i++){
        for (int j = 0; j < dimencion; j++){
            game_terreno[i][j] = ESPACIO;
        } 
    }   
}
/* 
//Pre:recive la matriz con la dimencion (la dimencion debe ser 22, 17, 12), el tope de la pared con su vector 
//Post:imprimira las paredes por pantalla
*/
void armar_matriz(coordenada_t paredes[MAX_PAREDES], int dimencion, int tope_paredes, char game_terreno[MAX_PAREDES][MAX_PAREDES]){
    for (int i = 0; i < tope_paredes; i++){
            game_terreno[paredes[i].fil][paredes[i].col] = PARED; 
    }
}

/* 
Pre:Recibe el vector de  obstaculos y herramientas junto a sus topes, tambien los vectores  paredes junto a su tope y la posicion del jugador, el numero y tipo de obstaculo a crear
Post:EN CASO QUE NO SEA FUEGO: Se le asigna una coordenada aleatoria al vector herramienta que no coincida con el personaje, pared, obstaculo o herramienta
EN CASO QUE SEA FUEGO:Se le asigna una coordenada  al vector obstaculo  de tipo  fuegos próximos a una pared
(adyacentes no diagonales) que coincida con el de una  pared y se aumenta su tope
*/
void generar_obstaculo(nivel_t* nivel, int cantidad, char tipo, int dimencion){
    for (int i = 0; i < cantidad; i++){
        nivel->obstaculos[nivel->tope_obstaculos].tipo = tipo;

        if (tipo != FUEGO){
            do{
                nivel->obstaculos[nivel->tope_obstaculos].posicion = coordenada_aleatoria(dimencion, dimencion);  
            } while (es_pared(nivel, nivel->obstaculos[nivel->tope_obstaculos].posicion) == true || es_coordenada_disponible(nivel->obstaculos[nivel->tope_obstaculos].posicion, nivel) == false);
        }
        if (tipo == FUEGO){
            do{
                nivel->obstaculos[nivel->tope_obstaculos].posicion = coordenada_aleatoria(dimencion, dimencion);  
            } while (es_pared(nivel, nivel->obstaculos[nivel->tope_obstaculos].posicion) == false && es_coordenada_disponible(nivel->obstaculos[nivel->tope_obstaculos].posicion, nivel) == false);
        }
        nivel->tope_obstaculos +=1;
    }
}
/* 
Pre:Recibe el vector de herramientas y obstaculo junto a sus tope, tambien los vectores  paredes junto a su tope y la posicion del jugador, el numero y tipo de herramientas a crear
Post:Se le asigna una coordenada aleatoria al vector herramienta que no coincida con el personaje, pared, obstaculo o herramienta
*/
void generar_herramientas(nivel_t* nivel, int cantidad, char tipo, int dimencion){
    for (int i = 0; i < cantidad; i++){
        do{
            nivel->herramientas[nivel->tope_herramientas].posicion = coordenada_aleatoria(dimencion, dimencion); 
        } while (es_pared(nivel, nivel->herramientas[nivel->tope_herramientas].posicion) == true || es_coordenada_disponible(nivel->pos_inicial_jugador,nivel) == false);
    nivel->tope_herramientas +=1;
    }
}
/*
Pre:
Recibe el vector de papeleos y su tope , asi tambien el vector  obstaculos junto a su tope por referencia, el vector de herramientas junto a su tope, el vector de paredes junto a su tope, la cantidad de papeleos.
Se le asigna una coordenada aleatoria que no coincida con una pared, obstaculo o herramienta
Una vez generado, aumenta el tope de los papeleos
//Post:
*/
void generar_papeleos(nivel_t* nivel, int cantidad, int dimencion){
    for (int i = 0; i < cantidad; i++){
        do{

            nivel->papeleos[nivel->tope_papeleos].posicion = coordenada_aleatoria(dimencion, dimencion); 
        
        } while (es_coordenada_disponible(nivel->papeleos[nivel->tope_papeleos].posicion, nivel) == false || es_coordenadas_igual(nivel->papeleos[nivel->tope_papeleos].posicion, nivel->pos_inicial_jugador) == false || es_pared(nivel, nivel->papeleos[nivel->tope_papeleos].posicion) == true );
    nivel->tope_papeleos +=1;
    }
}
/* 
//Pre:En el caso que el personaje obtenido sea Jasmin se agregara un partillo extra por cada nivel , es decir
//Post:sumara a los martillos que se obtienen al inicializar el nivel uno extra.
*/
void martillo_extra(obsequio_t obsequio, jugador_t* jugador, int cantidad_martillo){
    if (obsequio.martillo == true){
        jugador->martillos = (cantidad_martillo + 1);
    } else if(obsequio.martillo == false){
        jugador->martillos = cantidad_martillo;
    }
}
/* 
//Pre:En el caso que el personaje obtenido sea El Rayo se agregara 10  movimientos extras al comenzar el primer nivel, es decir que se lo
//Post:sumara a los movientos que se obtienen al inicializar (10 movimientos extras).
*/
void movimiento_extra(obsequio_t obsequio, jugador_t* jugador, int cantidad_movimiento){
    if (obsequio.movimiento == true){
    jugador->movimientos = cantidad_movimiento + 10;
    } else if (obsequio.movimiento == false){
    jugador->movimientos = cantidad_movimiento;
    }

}
/*
//Pre:En el caso que el personaje obtenido sea OLAF 
//Post:extingue dos fuegos del primer nivel, y uno del segundo nivel.
 es decir le restara dos fuegos del primer nivel y uno del segundo.
*/
void fuego_extra(obsequio_t obsequio, nivel_t* nivel , int fuego_borrar, int cantidad_del_nivel, int nivel_actual, int dimencion){
    int total_borrar = cantidad_del_nivel - fuego_borrar; 
    if(obsequio.apagar_fuego == true){
    generar_obstaculo(nivel, total_borrar, FUEGO, dimencion);
    } else if (obsequio.apagar_fuego == false){
    generar_obstaculo(nivel, cantidad_del_nivel, FUEGO, dimencion);
    }
}
/*
//Pre:En el caso que el personaje obtenido sea STITCH  una de sus pistolitas con una única munición, quemara un papeleo del último nivel
//Post: es decir le restara un papeleo .
*/
void pistolita_stitch(obsequio_t obsequio, nivel_t* nivel){
    int total_papeleo_nivel3 = 3;
    if (obsequio.pistolita == true){
    generar_papeleos(nivel, total_papeleo_nivel3, SIZE_NIVEL_3);
    } else if (obsequio.pistolita == false){
    generar_papeleos(nivel, CANTIDAD_PAPELEO_3, SIZE_NIVEL_3);
    }
}
/* 
//Pre:recibe el struct de juego por referencia para ser cambiado por sus valores correspondientes segun el nivel
//Post:pone a los topes de las herramientas de cada nivel en cero y genera las herramientas de acuerdo al nivel, cantidad y tipo. 
*/
void inicializar_herramientas(nivel_t* nivel, int numero_nivel){
    if (numero_nivel == NIVEL_1){
        nivel->tope_obstaculos = 0;
        generar_herramientas(nivel, CANTIDAD_INTERRUPTORES_1, INTERRUPTORES, SIZE_NIVEL_1);
        generar_herramientas(nivel, CANTIDAD_BOTELLAS_1, BOTELLAS, SIZE_NIVEL_1);
    } else if(numero_nivel == NIVEL_2){
        nivel->tope_obstaculos = 0;
        generar_herramientas(nivel, CANTIDAD_INTERRUPTORES_2, INTERRUPTORES, SIZE_NIVEL_2);
        generar_herramientas(nivel, CANTIDAD_BOTELLAS_2, BOTELLAS, SIZE_NIVEL_2);
    } else if(numero_nivel == NIVEL_3){
        nivel->tope_obstaculos = 0;
        generar_herramientas(nivel, CANTIDAD_INTERRUPTORES_2, INTERRUPTORES, SIZE_NIVEL_2);
        generar_herramientas(nivel, CANTIDAD_BOTELLAS_2, BOTELLAS, SIZE_NIVEL_2);
    }    
}
/* 
//Pre:recibe el struct de juego por referencia para ser cambiado por sus valores correspondientes segun el nivel que corresponda
//Post:asigana  los topes de  obstaculos de cada nivel en cero y genera los obstaculos de acuerdo al nivel, cantidad y tipo.
*/
void inicializar_obstaculos(nivel_t* nivel, int numero_nivel){
    if (numero_nivel == NIVEL_1){
        nivel->tope_obstaculos = 0;
        generar_obstaculo(nivel, CANTIDAD_MEDIAS_1, MEDIAS, SIZE_NIVEL_1);
    } else if(numero_nivel == NIVEL_2){
        nivel->tope_obstaculos = 0;
        generar_obstaculo(nivel ,CANTIDAD_MEDIAS_2, MEDIAS, SIZE_NIVEL_2);
    } else if(numero_nivel == NIVEL_3){
        nivel->tope_obstaculos = 0;
        generar_obstaculo(nivel , CANTIDAD_FUEGOS_3, FUEGO, SIZE_NIVEL_3);    
        generar_obstaculo(nivel, CANTIDAD_MEDIAS_3, MEDIAS, SIZE_NIVEL_3);
    }
}
/* 

*/
void aplicar_obsequio_olaf_stitch(nivel_t* nivel, obsequio_t obsequio, int nivel_actual){
    if (nivel_actual == NIVEL_1){
        nivel->tope_obstaculos = 0;
        generar_obstaculo(nivel, CANTIDAD_MEDIAS_1, MEDIAS, SIZE_NIVEL_1);
        fuego_extra(obsequio, nivel, FUEGO_BORRAR_2, CANTIDAD_FUEGOS_1, NIVEL_1 ,  SIZE_NIVEL_1);
    } else if(nivel_actual == NIVEL_2){
        nivel->tope_obstaculos = 0;
        generar_obstaculo(nivel, CANTIDAD_MEDIAS_1, MEDIAS, SIZE_NIVEL_2);
        fuego_extra(obsequio, nivel, FUEGO_BORRAR_1, CANTIDAD_FUEGOS_2, NIVEL_2 ,  SIZE_NIVEL_2);
    } else if(nivel_actual == NIVEL_3){
        nivel->tope_obstaculos = 0;
        generar_obstaculo(nivel, CANTIDAD_MEDIAS_1, MEDIAS, SIZE_NIVEL_1);
    }  
}
/* 
//Pre:recibe el struct de juego por referencia para ser cambiado por sus valores correspondientes segun el nivel que corresponda y al struct de obsequio el cual trae almacenado el obsequio si se debe o no ,aplicar segun el personaje obtenido obtenido al inicio
//Post:asigana los topes de papeleo en 0 para cada nivel  y genera los papeleos de acuerdo al nivel, cantidad.
*/
void inicializar_papeleos(nivel_t* nivel, obsequio_t obsequio, int nivel_actual){    
    if (nivel_actual == NIVEL_1){
        nivel->tope_papeleos= 0;
        generar_papeleos(nivel, CANTIDAD_PAPELEO_1, SIZE_NIVEL_1);
    } else if(nivel_actual == NIVEL_1){
        nivel->tope_papeleos= 0;
        generar_papeleos(nivel, CANTIDAD_PAPELEO_2, SIZE_NIVEL_2);
    } else if(nivel_actual == NIVEL_1){
        pistolita_stitch(obsequio, nivel);        
    }
}

/* 
Pre:recive el struct de juego juanto al struct de obsequio el cual trae almacenado el obsequio si se debe o no ,aplicar segun el personaje obtenido en las preguntas del inicio
Post:asigana las herramientas con la que empieza el usuario y y los movimientos  cada nivel .
 */
void inicialilizar_personaje(jugador_t* jugador, obsequio_t obsequio, int nivel_actual){    
    if (nivel_actual == NIVEL_1){
        jugador->movimientos = CANTIDAD_MOVIMIENTO_NIVEL_1;
        jugador->martillos = CANTIDAD_MARTILLOS_1;
        jugador->extintores = CANTIDAD_EXTINTORES_1;
        jugador->ahuyenta_randall = false;
    } else if(nivel_actual == NIVEL_2){
        jugador->movimientos = CANTIDAD_MOVIMIENTO_NIVEL_2;
        jugador->martillos = CANTIDAD_MARTILLOS_2;
        jugador->extintores = CANTIDAD_EXTINTORES_2;
        jugador->ahuyenta_randall = false;
    } else if (nivel_actual == NIVEL_3){
        jugador->movimientos = CANTIDAD_MOVIMIENTO_NIVEL_3;
        jugador->martillos = CANTIDAD_MARTILLOS_3;
        jugador->extintores = CANTIDAD_EXTINTORES_3;
        jugador->ahuyenta_randall = false;
    }
}
/* 
 
*/
void aplicar_obsequios_rayo_jasmin(jugador_t* jugador, obsequio_t obsequio, int nivel_actual){
    if(nivel_actual == NIVEL_1){
        movimiento_extra(obsequio, jugador, CANTIDAD_MOVIMIENTO_NIVEL_1);
        martillo_extra(obsequio, jugador, CANTIDAD_MARTILLOS_1);
    } else if(nivel_actual == NIVEL_2){
        martillo_extra(obsequio, jugador, CANTIDAD_MARTILLOS_2);
    } else if(nivel_actual == NIVEL_3){
        martillo_extra(obsequio, jugador, CANTIDAD_MARTILLOS_3);
    }
}
/* 
//Pre:
//Post: 
*/
void obsequio_del_jugador(char personaje_tp1, char nombre[MAX_LETRAS], char obsequio[MAX_LETRAS]){
    if (personaje_tp1 == PERSONAJE_JASMIN){
        strcpy(obsequio, "Tenes un martillo extra por cada nivel");
        strcpy(nombre, "JASMIN");       
    } else if(personaje_tp1 == PERSONAJE_OLAF ){
        strcpy(obsequio, "Se te extinguen dos fuegos fuego del primer nivel y uno del segundo");
        strcpy(nombre, "OLAF");
    } else if(personaje_tp1 == PERSONAJE_RAYO){
        strcpy(obsequio, "Tenes 10 movimientos al iniciar el nivel");
        strcpy(nombre, "RAYO");
    } else if(personaje_tp1 == PERSONAJE_STITCH){
        strcpy(obsequio, "Tenes una pistolita , la cual quema un papeleo del último nivel");
        strcpy(nombre,"STITCH");
    }
}

void mostrar_datos_a_jugador(juego_t juego){
    char nombre[MAX_LETRAS];
    char obsequio[MAX_LETRAS];
    obsequio_del_jugador(juego.personaje_tp1, nombre, obsequio);
    printf("-----------------------------------------------------------------\n");
    printf("-------------   Tu PERSONAJE ES : %s  -----------------------\n", nombre);
    printf("-----------------------------------------------------------------\n");
    printf("-----------------------------------------------------------------\n");
    printf("----TU OBSEQUIO ES: %s-------\n", obsequio);
    printf("-----------------------------------------------------------------\n");
    printf("-----------------------------------------------------------------\n");
    printf("--------------   CANTIDAD DE MARTILLOS: %i -----------------------\n", juego.jugador.martillos);
    printf("-----------------------------------------------------------------\n");  
    printf("-----------------------------------------------------------------\n");
    printf("--------------  CANTIDAD DE EXTINTORES: %i -----------------------\n", juego.jugador.extintores);
    printf("-----------------------------------------------------------------\n");  


}
/* 
//Pre:
 * Inicializará un nivel, cargando toda la información inicial, las paredes,
 * los objetos, los papeleos y la posición inicial del jugador en dicho nivel.
//Post:
*/
void inicializar_nivel(nivel_t* nivel, int numero_nivel, char personaje_tp1){
    obtener_paredes(numero_nivel, nivel->paredes, &nivel->tope_paredes, &nivel->pos_inicial_jugador);
    obsequio_t obsequio;
    asignar_obsequio(personaje_tp1, &obsequio);

    inicializar_herramientas(nivel, numero_nivel);

    inicializar_obstaculos(nivel, numero_nivel);

    inicializar_papeleos(nivel, obsequio, numero_nivel);

    aplicar_obsequio_olaf_stitch(nivel, obsequio, numero_nivel);

}
/*
Inicializará el juego, cargando toda la información inicial, los datos del jugador, 
el personaje resultado del tp anterior, y los 3 niveles. El campo "nivel_actual"
comienza en 1.
*/
void inicializar_juego(juego_t* juego, char personaje_tp1){
    juego->nivel_actual = NIVEL_1;
    int dimencion = 0;
    dimencion_matriz(&dimencion, juego->nivel_actual);
    juego->personaje_tp1 = personaje_tp1;
    obsequio_t obsequio;
    asignar_obsequio(personaje_tp1, &obsequio);

    inicializar_nivel(juego->niveles ,NIVEL_1, personaje_tp1);
/*     inicializar_nivel(&juego->niveles[1] ,NIVEL_2, personaje_tp1);
    inicializar_nivel(&juego->niveles[2] ,NIVEL_3, personaje_tp1); */

    inicialilizar_personaje(&juego->jugador, obsequio, juego->nivel_actual);
    aplicar_obsequios_rayo_jasmin(&juego->jugador, obsequio, juego->nivel_actual);
    
}
/*
Pre:recibe el struct de juego_t junto a una coordenada de la posicion en la que recorre el for en inicializar_juego
Post:se encarga de rellenar la coordenada terreno evaluandola si las pocisiones de los objetos, personajes y paredes , que previamente ya se hicieron, si los objetos ,paredes, o el jugador (el personaje del juego), coincide con la posicion de la coordenada , entonces se almacena en esa posicion su valor (su simbolo ) y se lo guarda para luego imprimirlo
*/
char letra_de_la_matriz(juego_t juego, coordenada_t terreno_matriz){

    char letra = ' ';

    for (int k = 0; k < juego.niveles[juego.nivel_actual -1].tope_paredes; k++){
        if(es_coordenadas_igual(juego.niveles[juego.nivel_actual -1].paredes[k], terreno_matriz)){
            letra = PARED;
        }
    } 
    for (int  l = 0; l < juego.niveles[juego.nivel_actual -1].tope_herramientas; l++){
        if (es_coordenadas_igual(juego.niveles[juego.nivel_actual -1].herramientas[l].posicion, terreno_matriz)){
            if (juego.niveles[juego.nivel_actual -1].herramientas[l].tipo == BOTELLAS){
                 letra = BOTELLAS;
            } else if(juego.niveles[juego.nivel_actual -1].herramientas[l].tipo == INTERRUPTORES){
                letra = INTERRUPTORES;  
            }
        }        
    }
    for (int m = 0; m < juego.niveles[juego.nivel_actual -1].tope_obstaculos; m++){
        if (es_coordenadas_igual(juego.niveles[juego.nivel_actual -1].obstaculos[m].posicion, terreno_matriz)){
            if(juego.niveles[juego.nivel_actual -1].obstaculos[m].tipo == FUEGO){
                letra = FUEGO;
            } else if(juego.niveles[juego.nivel_actual -1].obstaculos[m].tipo == MEDIAS){
                letra = MEDIAS;
            }   
        }
    }
    for (int n = 0; n < juego.niveles[juego.nivel_actual -1].tope_papeleos; n++){
        if(es_coordenadas_igual(juego.niveles[juego.nivel_actual -1].papeleos[n].posicion, terreno_matriz)){
            letra = PAPELEO;
        }
    }
    if(es_coordenadas_igual(juego.jugador.posicion, terreno_matriz)){
        letra = PERSONAJE_JUEGO;
    }
    return letra;
}
/*
Pre:los niveles entre (1, 2, 3)
Procedimiento que recibe el juego e imprime toda su información por pantalla.
Post:muestra en la terminar todo lo correspondiente al juego
*/
void imprimir_terreno(juego_t juego){
    int dimencion = 0;
    dimencion_matriz(&dimencion, juego.nivel_actual);

    system("clear");
    //mostrar_datos_a_jugador(juego);

    coordenada_t terreno;

    for (int i = 0; i < dimencion; i++){
        for (int j = 0; j < dimencion; j++){
            terreno.fil = i;
            terreno.col = j;
            char letra = letra_de_la_matriz(juego, terreno);
            printf("%c", letra);
        }
        printf(" \n");
    }
}