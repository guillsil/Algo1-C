#ifndef __CARGAR_MAPA_H__
#define __CARGAR_MAPA_H__

#define MAX_FIL_MAPA 100
#define MAX_COL_MAPA 100
#include "papeleo.h"

/*
 * PRE-CONDICIONES: El nivel_actual deberia estar entre los posibles (3 en este caso)
 * POST-CONDICIONES: Devuelve una coordenada aleatoria sin verificar que exista algo ya en esa posicion
 */
coordenada_t coordenada_aleatoria(int nivel_actual);

/*
 * PRE-CONDICIONES: El nivel_actual deberia estar entre los posibles (3 en este caso)
 * POST-CONDICIONES: Rellena el mapa con el piso vacio
 */
void cargar_piso_juego(char mapa_juego[MAX_FIL_MAPA][MAX_COL_MAPA], int nivel_actual);

/*
 * PRE-CONDICIONES: Los valores de las coordenadas de la posicion no deben ser numeros negativos
 * POST-CONDICIONES: Verifica que la posicion recibida se encuentre en un lugar vacio, si es asi devuelve verdadero, cualquier otro caso falso
 */
bool hay_espacio_libre(char mapa_juego[MAX_FIL_MAPA][MAX_COL_MAPA], coordenada_t posicion);

/*
 * PRE-CONDICIONES: El nivel_actual deberia estar entre los posibles (3 en este caso)
 * POST-CONDICIONES: Rellena el mapa con el piso vacio
 */
void cargar_piso_juego(char mapa_juego[MAX_FIL_MAPA][MAX_COL_MAPA], int nivel_actual);

/*
 * PRE-CONDICIONES: Las paredes deben estar inicializadas (no puede estar vacio el vector paredes)
 * POST-CONDICIONES: Rellena el mapa con las posiciones de las paredes
 */
void cargar_paredes_juego(coordenada_t paredes[MAX_PAREDES], char mapa_juego[MAX_FIL_MAPA][MAX_COL_MAPA], int tope_pared);

/*
 * POST-CONDICIONES: Cambia en la posicion indicada del mapa por otro elemento
 */
void cambiar_elemento_mapa(char mapa_juego[MAX_FIL_MAPA][MAX_COL_MAPA], int fil, int col, char elemento);

/*
 * POST-CONDICIONES: Rellena el mapa con la posicion inicial del jugador
 */
void cargar_posicion_inicial_jugador_juego(coordenada_t pos_inicial_jugador, char mapa_juego[MAX_FIL_MAPA][MAX_COL_MAPA]);

/*
 * POST-CONDICIONES: Actualiza la posicion del jugador en el mapa
 */
void cargar_posicion_jugador(coordenada_t posicion_jugador, char mapa_juego[MAX_FIL_MAPA][MAX_COL_MAPA]);

/*
 * PRE-CONDICIONES: Los obstaculos deben estar inicializados (no puede estar vacio el vector obstaculos)
 * POST-CONDICIONES: Rellena el mapa con la posicion de los obstaculos
 */
void cargar_obstaculos(objeto_t obstaculos[MAX_OBSTACULOS], char mapa_juego[MAX_FIL_MAPA][MAX_COL_MAPA], int tope_obstaculos);

/*
 * PRE-CONDICIONES: Las herramientas deben estar inicializadas (no puede estar vacio el vector herramientas)
 * POST-CONDICIONES: Rellena el mapa con la posicion de las herramientas
 */
void cargar_herramientas(objeto_t herramientas[MAX_HERRAMIENTAS], char mapa_juego[MAX_FIL_MAPA][MAX_COL_MAPA], int tope_pared);

/*
 * PRE-CONDICIONES: Los papeleos deben estar inicializados (no puede estar vacio el vector papeleos)
 * POST-CONDICIONES: Rellena el mapa con la posicion de los papeleos
 */
void cargar_papeleos(papeleo_t papeleos[MAX_PAPELEOS], char mapa_juego[MAX_FIL_MAPA][MAX_COL_MAPA], int tope_papeleos);

/*
 * PRE-CONDICIONES: El nivel_actual deberia estar entre los posibles (3 en este caso), mapa_juego deberia estar ya relleno con valores
 * POST-CONDICIONES: carga el mapa con todos los valores iniciales del nivel
 */
void cargar_mapa(nivel_t *nivel, char mapa_juego[MAX_FIL_MAPA][MAX_COL_MAPA], int nivel_actual, jugador_t *jugador, char amigo);

/*
 * PRE-CONDICIONES: El nivel_actual deberia estar entre los posibles (3 en este caso)
 * POST-CONDICIONES: Define una posicion aleatoria a una pared
 */
void crear_pared(coordenada_t *pared, int nivel_actual);

/*
 * PRE-CONDICIONES: El nivel_actual deberia estar entre los posibles (3 en este caso)
 * POST-CONDICIONES: Crea una pared en una posicion aleatoria, verificando que esta este libre, y lo coloca en el mapa
 */
void generar_pared(char mapa_juego[MAX_FIL_MAPA][MAX_COL_MAPA], coordenada_t paredes[MAX_PAREDES], int *tope_paredes, int nivel_actual);

/*
 * POST-CONDICIONES: Actualiza el mapa del juego con los nuevos datos
 */
void actualizar_mapa(nivel_t *nivel, char mapa_juego[MAX_FIL_MAPA][MAX_COL_MAPA], coordenada_t posicion_jugador);

/*
 * PRE-CONDICIONES: El nivel_actual deberia estar entre los posibles (3 en este caso)
 * POST-CONDICIONES: Define una posicion aleatoria y el id a un papeleo, ademas de asignarle recolectado como falso
 */
void crear_papeleo(papeleo_t *papeleo, int papeleo_id, int nivel_actual);

/*
 * PRE-CONDICIONES: El nivel_actual deberia estar entre los posibles (3 en este caso), mapa_juego deberia estar ya relleno con valores
 * POST-CONDICIONES: Muestra el mapa verdadero del juego por pantalla,
 */
void mostrar_mapa(char mapa_juego[MAX_FIL_MAPA][MAX_COL_MAPA], int nivel_actual);

/*
 * PRE-CONDICIONES: El nivel_actual deberia estar entre los posibles (3 en este caso)
 * POST-CONDICIONES: Define una posicion inicial al jugador, junto con sus movimientos y herramientas. Tambien recibe su regalo dependiendo del personaje que obtuvo
 */
void inicializar_jugador(jugador_t *jugador, int nivel_actual, coordenada_t pos_inicial, char amigo);

#endif /* __CARGAR_MAPA_H__ */