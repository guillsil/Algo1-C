/*
Enunciado

Ed, Edd y Eddy tienen un vector compuesto por elementos del siguiente registro :
Se pide

    Ayúdalos a encontrar cuántos caramelos insalubres tienen. Un caramelo insalubre se clasifica cuando:

    Su sabor es ananá (A).
    Sus calorías son mayores a 400.

Implementa una función que reciba un vector de caramelos con su respectivo tope y devuelva la cantidad que son insalubres.

    Ayúdalos a ordenar dicho vector de la siguiente forma:

    Descendente por color.
    Ascendiente por calorías.

Es decir que si hay caramelos del mismo color se desempatada por la cantidad de calorías.

Para esto implementa un procedimiento que reciba un vector de caramelos con su respectivo tope y ordene el mismo. Podes usar cualquier método de ordenamiento.
*/
#include<stdio.h>

#define MAX_NOMBRE_COLOR 100
typedef struct caramelo{
   char color[MAX_NOMBRE_COLOR];
   unsigned int radio; //en milímetros
   char sabor;
   unsigned int calorias;
}caramelo_t;

bool hay_que_intercambiar(caramelo_t caramelo_a, caramelo_t caramelo_b){
	if(strcmp(caramelo_a.color, caramelo_b.color)<0){
		return true;
	} else if(strcmp(caramelo_a.color, caramelo_b.color)>0){
		return false;
	} else{

		return caramelo_a.calorias > caramelo_b.calorias;

		/*if(caramelo_a.calorias > caramelo_b.calorias){
			return true;
		} else{
			return false;
		}*/
	}

}

void ordenar_caramelos(caramelo_t caramelos[MAX],int tope){

	for(int i=0;i<tope;i++){
		for(int j=0;j<tope-i-1;j++){
			bool intercambiamos = hay_que_intercambiar(caramelos[j],caramelos[j+1]);
			if(intercambiamos){
				caramelo_t aux;
				aux = caramelos[j];
				caramelos[j] = caramelos[j+1];
				caramelos[j+1] = aux;
			}
		}
	}
}