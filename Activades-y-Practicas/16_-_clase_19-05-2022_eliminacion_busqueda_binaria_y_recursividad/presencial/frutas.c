#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_FRUTAS 10
#define MAX_NOMBRE 100
#define MAX_COLOR 50

typedef struct fruta {
  char nombre[MAX_NOMBRE];
  char color[MAX_COLOR];
  int peso; // en gramos
  bool se_come_cascara;
  bool es_pinchudo;
} fruta_t;

void inicializar_frutas(fruta_t frutas[MAX_FRUTAS], int* tope_frutas) {
  (*tope_frutas) = 0;

  strcpy(frutas[(*tope_frutas)].nombre, "Cereza");
  strcpy(frutas[(*tope_frutas)].color, "Rojo");
  frutas[(*tope_frutas)].es_pinchudo = false;
  frutas[(*tope_frutas)].peso = 9;
  frutas[(*tope_frutas)].se_come_cascara = true;
  (*tope_frutas)++;

  strcpy(frutas[(*tope_frutas)].nombre, "Cereza");
  strcpy(frutas[(*tope_frutas)].color, "Rojo");
  frutas[(*tope_frutas)].es_pinchudo = false;
  frutas[(*tope_frutas)].peso = 9;
  frutas[(*tope_frutas)].se_come_cascara = true;
  (*tope_frutas)++;

  strcpy(frutas[(*tope_frutas)].nombre, "Banana");
  strcpy(frutas[(*tope_frutas)].color, "Amarillo");
  frutas[(*tope_frutas)].es_pinchudo = false;
  frutas[(*tope_frutas)].peso = 150;
  frutas[(*tope_frutas)].se_come_cascara = false;
  (*tope_frutas)++;

  strcpy(frutas[(*tope_frutas)].nombre, "Manzana");
  strcpy(frutas[(*tope_frutas)].color, "Rojo");
  frutas[(*tope_frutas)].es_pinchudo = false;
  frutas[(*tope_frutas)].peso = 200;
  frutas[(*tope_frutas)].se_come_cascara = true;
  (*tope_frutas)++;

  strcpy(frutas[(*tope_frutas)].nombre, "Pitaya");
  strcpy(frutas[(*tope_frutas)].color, "Bermellón");
  frutas[(*tope_frutas)].es_pinchudo = false;
  frutas[(*tope_frutas)].peso = 275;
  frutas[(*tope_frutas)].se_come_cascara = false;
  (*tope_frutas)++;

  strcpy(frutas[(*tope_frutas)].nombre, "Palta");
  strcpy(frutas[(*tope_frutas)].color, "Verde");
  frutas[(*tope_frutas)].es_pinchudo = false;
  frutas[(*tope_frutas)].peso = 300;
  frutas[(*tope_frutas)].se_come_cascara = false;
  (*tope_frutas)++;

  strcpy(frutas[(*tope_frutas)].nombre, "Melón");
  strcpy(frutas[(*tope_frutas)].color, "Verde");
  frutas[(*tope_frutas)].es_pinchudo = false;
  frutas[(*tope_frutas)].peso = 380;
  frutas[(*tope_frutas)].se_come_cascara = false;
  (*tope_frutas)++;
}

void imprimir_fruta(fruta_t fruta) {
  printf("Nombre: %s\n", fruta.nombre);
  printf("Color: %s\n", fruta.color);
  printf("Peso: %i\n", fruta.peso);
  if(fruta.es_pinchudo == true){
    printf("Es pinchudo\n");
  }else{
    printf("No es pinchudo\n");
  }

  if(fruta.se_come_cascara) {
    printf("Se come la cascara\n");
  } else {
    printf("No se come la cascara\n");
  }
}

void imprimir_frutas(fruta_t frutas[MAX_FRUTAS], int tope_frutas) {
  printf("--- FRUTAS ---\n");

  for(int i = 0; i < tope_frutas; i++) {
    printf("\n");
    imprimir_fruta(frutas[i]);
  }
}


void buscar_fruta(fruta_t frutas[MAX_FRUTAS],int tope, char color_buscado[MAX_COLOR], int* posicion){
  int i=0;
  bool se_encontro = false;
  while(!se_encontro && i<tope){
    if(strcmp(frutas[i].color,color_buscado)==0){
      se_encontro = true;
      *posicion = i;
    }
    i++;
  }
}

void eliminar_logico(fruta_t frutas[MAX_FRUTAS], int tope,char color[MAX_COLOR]){
  int posicion_buscado = -1;
  buscar_fruta(frutas,tope,color,&posicion_buscado);
  if(posicion_buscado != -1){
    frutas[posicion_buscado].es_pinchudo = true;
  }
}


void eliminar_fruta(fruta_t frutas[MAX_FRUTAS], int* tope, char color[MAX_COLOR]){
  int posicion_buscado = -1;
  buscar_fruta(frutas,*tope,color,&posicion_buscado);
  if(posicion_buscado == -1){
    return;
  }
  for(int i=posicion_buscado;i<(*tope-1);i++){
    frutas[i] = frutas[i+1];
  }
  (*tope)--;
}

void insertar_fruta(fruta_t frutas[MAX_FRUTAS],int* tope,fruta_t fruta_a_insertar){
  if(*tope >= MAX_FRUTAS){
    printf("lolaaaaa, no hay lugar\n");
    return;
  }
  fruta_t fruta_aux;
  for(int i=0;i<(*tope);i++){
    if(frutas[i].peso > fruta_a_insertar.peso){
      fruta_aux = frutas[i];
      frutas[i] = fruta_a_insertar;
      fruta_a_insertar = fruta_aux;
    }
  }
  frutas[*tope] = fruta_a_insertar;
  (*tope)++;
}


int main() {
  fruta_t frutas[MAX_FRUTAS];
  int tope_frutas;
  fruta_t fruta;
  inicializar_frutas(frutas, &tope_frutas);
  imprimir_frutas(frutas, tope_frutas);
  //eliminar_logico(frutas,tope_frutas,"Bermellón");
  eliminar_fruta(frutas,&tope_frutas,"Bermellón");
  printf("BERMELLON ELIMINADOOOO\n");
  imprimir_frutas(frutas, tope_frutas);

  strcpy(fruta.nombre, "Pitaya");
  strcpy(fruta.color, "Bermellón");
  fruta.es_pinchudo = false;
  fruta.peso = 275;
  fruta.se_come_cascara = false;

  insertar_fruta(frutas,&tope_frutas,fruta);
  printf("BERMELLON AGREGADOOOOO\n");
  imprimir_frutas(frutas, tope_frutas);

  return 0;
}
