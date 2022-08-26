#ifndef _BIBLIOTECA_TP_2_C
#define _BIBLIOTECA_TP_2_C
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include"utiles.h"
#include"papeleo.h"

#define MAX_OBJETOS  100
#define MAX_FIL 22
#define MAX_COL 22
#define MAX_LETRAS 500

static const char PERSONAJE_JASMIN = 'J', PERSONAJE_OLAF = 'O', PERSONAJE_RAYO = 'R', PERSONAJE_STITCH = 'S', PERSONAJE_JUEGO = 'W';
static const char PARED = '+', ESPACIO = ' ';
static const char FUEGO = 'F', MEDIAS = 'M', INTERRUPTORES = 'I', PAPELEO = 'P', BOTELLAS = 'G';

static const int CANTIDAD_MOVIMIENTO_NIVEL_1 = 40, CANTIDAD_MOVIMIENTO_NIVEL_2 = 30, CANTIDAD_MOVIMIENTO_NIVEL_3 = 20;
static const int CANTIDAD_FUEGOS_1 = 10, CANTIDAD_FUEGOS_2 = 5, CANTIDAD_FUEGOS_3 = 3;
static const int CANTIDAD_MEDIAS_1 = 5, CANTIDAD_MEDIAS_2 = 4, CANTIDAD_MEDIAS_3 = 3;
static const int CANTIDAD_EXTINTORES_1 = 4, CANTIDAD_EXTINTORES_2 = 2, CANTIDAD_EXTINTORES_3 = 2;
static const int CANTIDAD_MARTILLOS_1 = 4, CANTIDAD_MARTILLOS_2 = 5, CANTIDAD_MARTILLOS_3 = 6;
static const int CANTIDAD_BOTELLAS_1 = 4, CANTIDAD_BOTELLAS_2 = 3, CANTIDAD_BOTELLAS_3 = 2;
static const int CANTIDAD_INTERRUPTORES_1 = 1, CANTIDAD_INTERRUPTORES_3 = 0, CANTIDAD_INTERRUPTORES_2 = 1;
static const int CANTIDAD_PAPELEO_1 = 2, CANTIDAD_PAPELEO_2 = 3, CANTIDAD_PAPELEO_3 = 4;

static const int  NIVEL_1 = 1,  NIVEL_2 = 2,  NIVEL_3 = 3;
static const int SIZE_NIVEL_1 = 22, SIZE_NIVEL_2 = 17, SIZE_NIVEL_3 = 12;

static const int MARTILLO_EXTRA = 1, FUEGO_BORRAR_PRIMER_N = 2, FUEGO_BORRAR_SEGUNDO_N = 1, MOVIMIENTO_EXTRA_PRIMER_N = 10, PAPELEO_RESTAR_TERCER_N = 1;

static const int NO_ENCONTRADO = -1, MAX_MOVIMIENTOS = 100, MOVIMIENTO_CHOCAR_CON_MEDIA = 10, MOVIMIENTO_CHOCAR_BOTELLAS = 7;

static const int MAX_PAREDES_1 = 40, MAX_PAREDES_2  = 30, MAX_PAREDES_3 = 20;
/* 
//Pre:
 * Inicializará un nivel, cargando toda la información inicial, las paredes,
 * los objetos, los papeleos y la posición inicial del jugador en dicho nivel.
//Post:
*/
void inicializar_nivel(nivel_t* nivel, int numero_nivel, char personaje_tp1);
/* 
//Pre:recibe el nivel(el nivel tiene que estar entre 0 y 2) en el cual se encuentra el juego 
//Post: y muestra la dimension del mismo la cual debe estar entre 22, 17, 12
*/
void dimension_matriz(int* dimension, int nivel);
/*
Pre:Le ingresa el personaje obtenido , las cantidades de fuegos y papeleos que fueron creados anteriormente segun el nivel , tambien recibe el nivel.
Post:Si el personaje es Olaf o Sitch, entonce s se aplica lo siguiente:
Olaf:extingue dos fuegos del primer nivel y uno del segundo.
Stitch:con su pistolita elimina un papeleo del ultimo nivel. 
*/
void comprobar_obsequio_objetos(char personaje_tp1, int* cant_fuego, int* cant_papeleo, int numero_nivel);
/*
Pre:Le ingresa el struct juego_t , el personaje_tp1 y las cantidades de los martillos y movimientos
Post:Segun el personaje del tp anterior le asigna el valor a la cantidad de martillos y movimiento, en el caso que el personaje sea Jasmin agregara un martillo extra en cada nivel , si es el Rayo 10 movimientos extras para el primer nivel, cualquier otro distinto a estos se le aplicara las cantidades prederteminadas
*/
void comprobar_obsequio_al_personaje(juego_t juego, char personaje_tp1, int* cant_martillo, int* cant_movimiento);
/*
Pre:Recibe la matriz terreno el nivel el struct de niveles y las cantidades de fuego y papeleo .
Post:Se encargara de mostrar(pone los objetos, paredes y al jugador en la matriz) e inicializar las funciones que se inician en inicializar_nivel.
*/
void mostrar_elementos_e_inicializar(char terreno[MAX_FIL][MAX_COL], int numero_nivel, nivel_t* nivel, char personaje_tp1);
/*
Pre:Le ingresa el struct juego_t , el nivel puede ser hasta 3
Post:Inicializa el nivel, con todas sus elmentos a definir.
*/
void inicializar_cada_nivel(juego_t* juego);
/* 
Pre:recive el struct de juego, el nivel, la pos_jugador y las cantidades de martillos y movimientos
Post:aplicara los obsequios en caso que el personaje sea Jasmin o Rayo, tambien carga los demas elementos de la mochila 
 */
void inicialilizar_personaje(jugador_t* jugador, int nivel_actual,coordenada_t pos_jugador,  int  cant_martillo, int cant_movimiento);
/*
Pre:Recibe el struct juego_t
Post:Se encargara de imprimir en la consola el obsequio obtenido, las cantidades de herramientas en la mochila y el personaje que se le asigno al principio.
*/
void mostrar_datos_a_jugador(juego_t juego);
/*
Pre:Recibela matriz terreno, el struct nivel_t con el numero de nivel
Post:Se encarga de llamar a todas las funciones siguientes (mostrar_terreno, mostrar_paredes, mostrar_jugador, mostrar_objeto, mostrar_papeleos), los cuales rellenan la matriz terreno[MAX_FIL][MAX_COL].
*/
void inicializar_todo(char terreno[MAX_FIL][MAX_COL], nivel_t *nivel , int numero_nivel);
/*
Pre:Recibe la matriz terreno y el numero del nivel
Post:Inprimira todo los puesto en la matriz en el terreno de juego.
*/
void mostrar_todo(char terreno[MAX_FIL][MAX_COL], int numero_nivel);
/* 
//Pre:Recibe la matriz con la dimension de del nivel a mostrar (la dimension debe ser 22, 17, 12)
//Post:Mostrara en la pantalla un espacio , para que que la matriz noce inicie con basura
*/
void mostrar_terreno(char terreno[MAX_FIL][MAX_COL], int dimension);
/* 
Pre:Le ingresa la matriz terreno , las coordenadas de las paredes junto a su tope.
Post:Mostrara las paredes en la matriz.
*/
void mostrar_paredes(char terreno[MAX_FIL][MAX_COL], coordenada_t paredes[MAX_PAREDES],int tope_pared);
/* 
Pre:Recibe la matriz terreno y la pos_jugador
Post:Muestra al perosnaje en la matriz
*/
void mostrar_jugador(char terreno[MAX_FIL][MAX_COL], coordenada_t pos_jugador);
/*
Pre:Recibe la matriz terreno , el struct del objeto junto a su tope
Post:Se encarga de rellenar la matriz con el objeto recibido.
*/
void mostrar_objeto(char terreno[MAX_FIL][MAX_COL], objeto_t objeto[MAX_OBSTACULOS], int tope_objeto);
/* 
Pre:Recibe la matriz terreno , el struct de papeleo_t junto a su tope
Post: Muestra los papeleos en la matriz.
*/
void mostrar_papeleos(char terreno[MAX_FIL][MAX_COL], papeleo_t papeleos[MAX_PAPELEOS], int tope_papeleos);
/* 
//Pre:recibe un vector objeto con el tope y la coordenada a comparar 
//Post:si en el caso de que se encuentre una coordenada del vector objeto similar al de la posicion pasada entonces 
    devolvera la posicion del objeto que coincidieron y en caso contrario devolvera un -1.
*/
int buscar_objeto(objeto_t objeto[MAX_OBJETOS], int tope, coordenada_t posicion);
/* 
Pre: pide las coordenadas del vector paredes junto a su tope y la coordenada del objeto a comparar;
Post:busca en el vector paredes si coincide con alguna posicion del objeto, devuelve true si coincide con una las paredes.
*/
bool es_pared(nivel_t* nivel, coordenada_t objeto);
/* 
//Pre:recibe dos coordenadas y si las mismas son iguales
//Post:devuelve  true si las mismas son iguales en caso contrario un false
*/
bool es_coordenada_igual(coordenada_t l, coordenada_t g);
/* 
Pre: pide las coordenadas del vector paredes junto a su tope y la coordenada del objeto a comparar;
Post:busca en el vector paredes si coincide con alguna posicion del objeto, devuelve true si coincide con una las paredes.
*/
bool es_pared(nivel_t* nivel, coordenada_t objeto);
/*

*/
void intercambiar_objeto(char terreno[MAX_FIL][MAX_COL], char objeto, int fil_objeto, int col_objeto);
/* 
//Pre:recibe el vector del objeto a comparar , los vectores herramientas, obstaculos  con sus respectivos topes
//Post:si no encuentra ningun elemento devolvera un true.
*/
bool es_coordenada_libre(coordenada_t objeto, nivel_t nivel);
/* 
//Pre:Dados dos numeros, un max y un min, que representa el rango a crear de una coordenada,  
//Post:vevolvera una coordenada aleatoria entre ambos extremos , los cuales no pueden ser mayores ni menores a sus extremos 
*/
coordenada_t coordenada_aleatoria(int max_fil, int max_col);
/*

*/
char posicionar_objeto(char terreno[MAX_FIL][MAX_COL], int fil_objeto, int col_objeto);
/* 
Pre:Recibe el struct de papaleo_t , el id del papeleo y la dimension del nivel a crear
Post:Asiganara un valor al id , una coordenada aleatoria al papeleo y lo pondra en recolectado = false.
*/
void generar_papeleos(papeleo_t* papeleo, int id_papeleo, int dimension);
void refrescar_terreno(char terreno[MAX_FIL][MAX_COL], coordenada_t pos_jugador, int numero_nivel, nivel_t* nivel, char personaje_tp1);
#endif //_BIBLIOTECA_TP_2_C
