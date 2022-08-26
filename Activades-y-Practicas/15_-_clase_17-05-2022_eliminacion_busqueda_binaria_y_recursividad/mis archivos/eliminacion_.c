#include<stdio.h>
#include<stdbool.h>
#define MAX_COLOR 10
#define MAX_COLORES 10
#define MAX_ARRAY 20
#define MAX_NOMBRE 100
#define NO_EXISTE -1


typedef struct perritos {
	int edad;
	char colores[MAX_COLORES][MAX_COLOR];
	char nombre[MAX_NOMBRE];
	bool esta;
} perritos_t;

void elliminar(int array[MAX_ARRAY], int tope){
    perritos_t dog[];
    int posicion = 8;
    //eliminacion logica 
    if(posicion > NO_EXISTE){
        dog.esta == false;
    }
    //eliminacion fisica no ordenada
    if(posicion > NO_EXISTE){
        for (int i = posicion; i < tope-1; i++){
			dog[i] = dog[i+1];
		}
		tope--
    }
    //eliminacion fisica ordenada 
    if(posicion > NO_EXISTE){

    }
}


int main{
    int array[MAX_ARRAY]= {1, 2, 3, 4, 5, 6 ,7 ,8};
    int tope = 8;
    int buscado = 4;
    elliminar(buscado);


}

