#include <stdio.h>
#include <string.h>

#define MAX_CANCIONES 40
#define MAX_ALBUMES 30
#define MAX_NOMBRE_CANCION 100

const char ROCK = 'R';
const char POP = 'P';
const char CUMBIA = 'C';

const int NO_ENCONTRADO = -1;

typedef	struct genero {
	char nombre;
} genero_t;

typedef struct cancion {
	int dni;
	char nombre[MAX_NOMBRE_CANCION];
	int duracion; // En segundos
	genero_t genero;
} cancion_t;

typedef struct album {
	genero_t genero;
	cancion_t canciones[MAX_CANCIONES];
	int cantidad_canciones;
} album_t;


// Pre: -
// Pos: Devuelve el índice de la cancion en el vector canciones del album.
// 		O NO_ENCONTRADO en caso de no existir.
int posicion_cancion(album_t album, int dni_buscado) {
	int posicion = NO_ENCONTRADO;

	for (int i = 0; i < album.cantidad_canciones; i++) {
		if (album.canciones[i].dni == dni_buscado) {
			posicion = i;
		}
	}

	return posicion;
}


// Pre: tope debe ser positivo y menor que MAX_CANCIONES
// Pos: Devuelve el índice de la cancion con nombre nombre_buscado en el vector canciones.
//		O NO_ENCONTRADO en caso de no existir.
int posicion_cancion_nombre(cancion_t canciones[MAX_CANCIONES],
							int tope,
							char nombre_buscado[MAX_NOMBRE_CANCION]) {
	int posicion = NO_ENCONTRADO;
	int i = 0;

	while (i < tope && posicion == NO_ENCONTRADO) {
		if (strcmp(canciones[i].nombre, nombre_buscado) == 0) {
			posicion = i;
		}
		i++;
	}

	return posicion;
}


// Pre: canciones debe tener al menos una cancion. tope debe ser positivo y menor que MAX_CANCIONES
// Pos: Devuelve la cancion con el nombre más largo.
cancion_t cancion_titulo_mas_largo(cancion_t canciones[MAX_CANCIONES], int tope) {
	int mas_largo = 0;
	cancion_t cancion_mas_larga;

	for (int i = 0; i < tope; i++) {
		if (strlen(canciones[i].nombre) > mas_largo) {
			cancion_mas_larga = canciones[i];
			mas_largo = strlen(canciones[i].nombre);
		}
	}

	return cancion_mas_larga;
}


int main() {
	album_t fuerza_natural, ahi_vamos;
	fuerza_natural.genero.nombre = ROCK;
	ahi_vamos.genero.nombre = ROCK;

	cancion_t cactus, dejavu, adios;
	cactus.dni = 32;
	cactus.duracion = 200;
	cactus.genero.nombre = ROCK;
	strcpy(cactus.nombre, "Cactus");

	dejavu.dni = 452;
	dejavu.duracion = 240;
	dejavu.genero.nombre = POP;
	strcpy(dejavu.nombre, "Deja Vu");

	fuerza_natural.canciones[0] = cactus;
	fuerza_natural.canciones[1] = dejavu;
	fuerza_natural.cantidad_canciones = 2;

	adios.dni = 234;
	adios.duracion = 324;
	adios.genero.nombre = ROCK;
	strcpy(adios.nombre, "Adiós");

	ahi_vamos.canciones[0] = adios;
	ahi_vamos.canciones[1].dni = 523;
	ahi_vamos.canciones[1].duracion = 321;
	ahi_vamos.canciones[1].genero.nombre = ROCK;
	strcpy(ahi_vamos.canciones[1].nombre, "Crimen");
	ahi_vamos.cantidad_canciones = 2;

	char no_existe[MAX_NOMBRE_CANCION];
	strcpy(no_existe, "Blablabla");

	int indice = posicion_cancion_nombre(fuerza_natural.canciones,
										 fuerza_natural.cantidad_canciones,
										 adios.nombre);

	printf("Mi canción está en la posición del vector %i\n", indice);

	cancion_t cancion_larga = cancion_titulo_mas_largo(fuerza_natural.canciones,
											fuerza_natural.cantidad_canciones);
	printf("La canción con nombre más largo es %s\n", cancion_larga.nombre);

	album_t albumes[MAX_ALBUMES];
	albumes[0] = fuerza_natural;
	albumes[1] = ahi_vamos;

	int cantidad_albumes = 2;

	printf("Nombre del género de la segunda canción del primer álbum: %c\n", albumes[0].canciones[1].genero.nombre);

	return 0;
}