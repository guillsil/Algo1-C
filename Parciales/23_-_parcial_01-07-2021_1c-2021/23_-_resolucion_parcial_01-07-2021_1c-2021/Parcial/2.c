#include<stdbool.h>
#include<string.h>

#define MAX_NOMBRE 25
#define MAX_VECTOR 100
#define MOJOJOJO "Mojojojo"

typedef struct enemigo {
	char nombre[MAX_NOMBRE];
	bool tiene_superpoderes;
	int veces_derrotado;
	int veces_ganadas;
} enemigo_t;


// Pre: Recibe un vector con los enemigos y su respectivo tope.
// Pos: Suma 1 al campo veces_derrotado del registro cuyo nombre es MOJOJOJO.
void sumar_derrota_mojojojo(enemigo_t enemigos[MAX_VECTOR], int tope_enemigos) {
	int i = 0;
	bool encontrado = false;
	while (i < tope_enemigos && !encontrado) {
		if (!strcmp(enemigos[i].nombre, MOJOJOJO)) {
			enemigos[i].veces_derrotado++;
			encontrado = true;
		}
		i++;
	}
}