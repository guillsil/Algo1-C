/*
Después de haber elegido el lugar y la fecha donde vacacionar, Simba, Timón y Pumba están haciendo las últimas compras necesarias para viajar. Su idea es gastar lo menos posible, para que les quede mucha plata para llevar y gastarla en el lugar.

    Implementar un procedimiento que calcule el precio total que tienen que gastar, y lo escriba en el campo precio_total del registro de lista de compras.

    Lista de precios disponibles:
        Chocolate: 50.
        Caramelos: 10.
        Gaseosa: 70.
        Pelota de playa: 120.

Ejemplo:

Si nos vienen las siguientes cantidades en nuestra lista:

    Chocolates: 5.
    Caramelos: 0.
*/
#include <stdio.h>
#include "solucion.h"
// Acá deberian ir las constantes.

typedef struct lista_compras {
	int cantidad_chocolates;
	int cantidad_caramelos;
	int cantidad_gaseosas;
	int cantidad_pelotas_playa;
	int precio_total;
} lista_compras_t;

void calcular_precio_total(lista_compras_t* lista_compras){
	int cant_choc;
	int cant_caram;
	int cant_gase;
	int cant_pel;
	cant_choc = lista_compras->cantidad_chocolates*50;
	cant_caram = lista_compras->cantidad_caramelos*10;
	cant_gase = lista_compras->cantidad_gaseosas*70;
	cant_pel = lista_compras->cantidad_pelotas_playa*120;
	lista_compras->precio_total = cant_choc + cant_caram +cant_gase +cant_pel;

}