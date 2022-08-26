#include <stdio.h>

#define MAX_CANALES 50
#define NUMERO_DESEADO 37


// Pre: Recibe el vector de canales y el indice del canal que se tiene que ver.
// Pos: Devuelve la cantidad de veces que se cambio de canal hasta ver NUMERO_DESEADO en la tele.
int cambios_de_canal_rec(int canales[MAX_CANALES], int indice) {
	if (canales[indice] == NUMERO_DESEADO) {
		return 0;
	}

	return 1 + cambios_de_canal(canales, canales[indice]);
}

int cambios_de_canal(int canales[MAX_CANALES], int indice){
	return cambios_de_canal_rec(canales, indice);
}