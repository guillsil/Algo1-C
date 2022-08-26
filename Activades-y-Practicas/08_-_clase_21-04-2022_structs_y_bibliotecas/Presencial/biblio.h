#ifndef _biblio_h_
#define _biblio_h_

#include <stdbool.h>

//static const int STITCH = 720;
// #define STITCH 720

//pre: numero_lilo tiene que ser positivo
//post: imprime los divisores de STITCH desde 1 hasta numero_lilo
void imprimir_divisores(int numero_lilo);

/*
 * pre: 
 * post:pide un numero al usuario hasta que sea valido definido por es_numero_valido()
 * y carga el numero en numero_lilo.
 */
void pedir_numerito(int* numero_lilo);

#endif //_biblio_h_