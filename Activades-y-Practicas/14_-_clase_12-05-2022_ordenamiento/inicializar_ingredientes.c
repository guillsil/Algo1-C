/*
VAMOS A CREAR UN LINDO STRUCT
Nombre -> string
Cantidad necesaria -> entero
Precio por unidad -> float (si pero no)
Si es usada para recetas -> char
  dulces (D), 
  saladas (S) o 
  en ambas (A).
Lugares en los que se puede conseguir -> vector 
                                        de strings
                                    (vector de vectores
                                          #miedo)
                                    (aaaahh matriz)
1. Crear un programa que dado una receta, 
representada como un vector de structs de tipo
ingrediente_t, lo ordene alfabéticamente por nombre.
*/




#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_INGREDIENTES 10
#define MAX_NOMBRE_INGREDIENTE 125
#define MAX_NOMBRE_LUGAR 125
#define MAX_LUGARES 25

#define TIPO_RECETA_DULCE 'D'
#define TIPO_RECETA_SALADA 'S'
#define TIPO_RECETA_AMBAS 'A'


typedef struct ingrediente {
  char nombre[MAX_NOMBRE_INGREDIENTE];
  int cantidad_necesaria;
  int precio_por_unidad;
  char tipo_de_recetas;
  char lugares_donde_conseguir[MAX_LUGARES][MAX_NOMBRE_LUGAR];
  int tope_lugares_donde_conseguir;
} ingrediente_t;

void inicializar_ingredientes(ingrediente_t ingredientes[MAX_INGREDIENTES], int* tope_ingredientes) {
  (*tope_ingredientes) = 0;

  strcpy(ingredientes[(*tope_ingredientes)].nombre, "Azúcar");
  ingredientes[(*tope_ingredientes)].cantidad_necesaria = 2;
  ingredientes[(*tope_ingredientes)].precio_por_unidad = 100;
  ingredientes[(*tope_ingredientes)].tipo_de_recetas = TIPO_RECETA_DULCE;
  strcpy(ingredientes[(*tope_ingredientes)].lugares_donde_conseguir[0], "Carrefour");
  strcpy(ingredientes[(*tope_ingredientes)].lugares_donde_conseguir[1], "Día");
  strcpy(ingredientes[(*tope_ingredientes)].lugares_donde_conseguir[2], "Coto");
  ingredientes[(*tope_ingredientes)].tope_lugares_donde_conseguir = 3;
  (*tope_ingredientes)++;

  strcpy(ingredientes[(*tope_ingredientes)].nombre, "Tomate");
  ingredientes[(*tope_ingredientes)].cantidad_necesaria = 5;
  ingredientes[(*tope_ingredientes)].precio_por_unidad = 5;
  ingredientes[(*tope_ingredientes)].tipo_de_recetas = TIPO_RECETA_SALADA;
  strcpy(ingredientes[(*tope_ingredientes)].lugares_donde_conseguir[0], "La verdulería de acá a la vuelta");
  strcpy(ingredientes[(*tope_ingredientes)].lugares_donde_conseguir[1], "Día");
  ingredientes[(*tope_ingredientes)].tope_lugares_donde_conseguir = 2;
  (*tope_ingredientes)++;

  strcpy(ingredientes[(*tope_ingredientes)].nombre, "Papa");
  ingredientes[(*tope_ingredientes)].cantidad_necesaria = 5;
  ingredientes[(*tope_ingredientes)].precio_por_unidad = 10;
  ingredientes[(*tope_ingredientes)].tipo_de_recetas = TIPO_RECETA_SALADA;
  strcpy(ingredientes[(*tope_ingredientes)].lugares_donde_conseguir[0], "La verdulería de acá a la vuelta");
  strcpy(ingredientes[(*tope_ingredientes)].lugares_donde_conseguir[1], "Día");
  ingredientes[(*tope_ingredientes)].tope_lugares_donde_conseguir = 2;
  (*tope_ingredientes)++;

  strcpy(ingredientes[(*tope_ingredientes)].nombre, "Aceite");
  ingredientes[(*tope_ingredientes)].cantidad_necesaria = 1;
  ingredientes[(*tope_ingredientes)].precio_por_unidad = 50;
  ingredientes[(*tope_ingredientes)].tipo_de_recetas = TIPO_RECETA_AMBAS;
  strcpy(ingredientes[(*tope_ingredientes)].lugares_donde_conseguir[0], "Carrefour");
  strcpy(ingredientes[(*tope_ingredientes)].lugares_donde_conseguir[1], "Día");
  strcpy(ingredientes[(*tope_ingredientes)].lugares_donde_conseguir[2], "Coto");
  strcpy(ingredientes[(*tope_ingredientes)].lugares_donde_conseguir[3], "El mercado del barrio");
  strcpy(ingredientes[(*tope_ingredientes)].lugares_donde_conseguir[4], "Alguna tienda online");
  ingredientes[(*tope_ingredientes)].tope_lugares_donde_conseguir = 5;
  (*tope_ingredientes)++;

  strcpy(ingredientes[(*tope_ingredientes)].nombre, "Harina");
  ingredientes[(*tope_ingredientes)].cantidad_necesaria = 1;
  ingredientes[(*tope_ingredientes)].precio_por_unidad = 120;
  ingredientes[(*tope_ingredientes)].tipo_de_recetas = TIPO_RECETA_AMBAS;
  strcpy(ingredientes[(*tope_ingredientes)].lugares_donde_conseguir[0], "Carrefour");
  strcpy(ingredientes[(*tope_ingredientes)].lugares_donde_conseguir[1], "Día");
  strcpy(ingredientes[(*tope_ingredientes)].lugares_donde_conseguir[2], "Coto");
  strcpy(ingredientes[(*tope_ingredientes)].lugares_donde_conseguir[3], "El mercado del barrio");
  ingredientes[(*tope_ingredientes)].tope_lugares_donde_conseguir = 4;
  (*tope_ingredientes)++;

  strcpy(ingredientes[(*tope_ingredientes)].nombre, "Frutillas");
  ingredientes[(*tope_ingredientes)].cantidad_necesaria = 25;
  ingredientes[(*tope_ingredientes)].precio_por_unidad = 20;
  ingredientes[(*tope_ingredientes)].tipo_de_recetas = TIPO_RECETA_DULCE;
  strcpy(ingredientes[(*tope_ingredientes)].lugares_donde_conseguir[0], "Carrefour");
  strcpy(ingredientes[(*tope_ingredientes)].lugares_donde_conseguir[1], "Día");
  strcpy(ingredientes[(*tope_ingredientes)].lugares_donde_conseguir[2], "La verdulería de acá a la vuelta");
  ingredientes[(*tope_ingredientes)].tope_lugares_donde_conseguir = 3;
  (*tope_ingredientes)++;
}

void imprimir_ingrediente(ingrediente_t ingrediente) {
  printf("Nombre: %s\n", ingrediente.nombre);
  printf("Cantidad necesaria: %i\n", ingrediente.cantidad_necesaria);
  printf("Precio por unidad: %i\n", ingrediente.precio_por_unidad);
  printf("Tipo de recetas: %c\n", ingrediente.tipo_de_recetas);
  printf("Lugares donde conseguir: ");

  for(int i = 0; i < ingrediente.tope_lugares_donde_conseguir; i++) {
    printf("%s, ", ingrediente.lugares_donde_conseguir[i]);
  }

  printf("\n");
}

void imprimir_ingredientes(ingrediente_t ingredientes[MAX_INGREDIENTES], int tope_ingredientes) {
  printf("--- INGREDIENTES ---\n");

  for(int i = 0; i < tope_ingredientes; i++) {
    printf("\n");
    imprimir_ingrediente(ingredientes[i]);
  }
}





















void intercambiar(ingrediente_t* ingrediente_a, ingrediente_t* ingrediente_b){
  ingrediente_t aux = *ingrediente_a;
  *ingrediente_a = *ingrediente_b;
  *ingrediente_b = aux;
}

//Punto 1
/*void ordenar_ingredientes(ingrediente_t receta[MAX_INGREDIENTES], int tope_receta){
  //burbujeo
  //ordenamos por nombre de ingrediente

  for(int i = 1; i < tope_receta; i++){ //con este todo elvector
    for(int j = 0; j < tope_receta-i; j++){
      if(strcmp(receta[j].nombre, receta[j+1].nombre) > 0){
        intercambiar(&(receta[j]), &(receta[j+1]));
      }
    }
  }
}*/

bool hay_que_intercambiar(ingrediente_t ingrediente_a, ingrediente_t ingrediente_b){
  return (ingrediente_a.cantidad_necesaria
                  < ingrediente_b.cantidad_necesaria) ||
          ( (ingrediente_a.cantidad_necesaria 
            == ingrediente_b.cantidad_necesaria) ) &&
            (strcmp(ingrediente_a.nombre, ingrediente_b.nombre) > 0);
}

//Punto 2
void ordenar_ingredientes(ingrediente_t receta[MAX_INGREDIENTES], int tope_receta){
  //burbujeo
  //ordenamos por cantidad de ingrediente DESC

  for(int i = 1; i < tope_receta; i++){ //con este todo elvector
    for(int j = 0; j < tope_receta-i; j++){
      if(hay_que_intercambiar(receta[j], receta[j+1])){
        intercambiar(&(receta[j]), &(receta[j+1]) );
      }
    }
  }
}


void ordenar_lugares(char lugares[MAX_LUGARES][MAX_NOMBRE_LUGAR], int tope_lugares){
  char aux[MAX_NOMBRE_LUGAR]; 
  for(int i=0; i<tope_lugares-1; i++){
    int posicion_minimo = i;
    for(int j=i+1;j<tope_lugares; j++){
      if(strcmp(lugares[j],lugares[posicion_minimo])< 0){
        posicion_minimo = j;
      }
    }
    strcpy(aux,lugares[i]);
    strcpy(lugares[i],lugares[posicion_minimo]);
    strcpy(lugares[posicion_minimo], aux);
  }
}

void ordenar_todos_los_lugares(ingrediente_t receta[MAX_INGREDIENTES], int tope_receta){
  for(int i =0; i<tope_receta;i++){
    ordenar_lugares(receta[i].lugares_donde_conseguir,receta[i].tope_lugares_donde_conseguir);
  }
}










int main() {
  ingrediente_t receta[MAX_INGREDIENTES];
  int tope_receta;

  inicializar_ingredientes(receta, &tope_receta);
  //IMPRESIÓN DESORDENDA
  //imprimir_ingredientes(receta, tope_receta);

  //ordenar_ingredientes(receta, tope_receta);
  ordenar_todos_los_lugares(receta, tope_receta);
  //IMPRESIÓN ORDENDA
  imprimir_ingredientes(receta, tope_receta);
  return 0;
}
