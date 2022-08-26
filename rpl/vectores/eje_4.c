/* 
Alex se volvió fanática de la astrología por lo que empezó a leer libros y buscar información de cada signo. Para probar sus conocimientos, quiso hacerles unas preguntas a Justin y Max y tratar de adivinar de qué signo son. Para facilitarse el trabajo, les hizo las preguntas a los dos al mismo tiempo y en cada posición de un vector fue marcando S si ambos respondieron que sí, N si ambos respondieron que no, J si sólo Justin respondió que sí, y M si sólo Max respondió que sí.
Tiene como información adicional que los signos de ambos solamente pueden ser piscis, libra, acuario o cáncer.

-Implementar una función que calcule cuántas respuestas positivas tuvieron tanto Justin como Max, y a partir de este resultado, retorne true si son del mismo signo, o false en caso contrario.

Entre 0 y 2: Libra.
Entre 3 y 5: Piscis.
Entre 6 y 8: Acuario.
Más de 8: Cáncer.
*/
#include <stdio.h>
#include <stdbool.h>
#define MAX_RESPUESTAS 300

void asignar_signo(int sig, char signo[MAX_RESPUESTAS]){
	if(sig >0 && sig <3){
		strcpy(signo, "Libra");
	}else if(sig >2 && sig <6){
		strcpy(signo, "Piscis");
	}else if(sig >5 && sig <9){
		strcpy(signo, "Acuario");
	}else{
		strcpy(signo, "Cáncer");
	}

}

void completar_si_o_no(int* si_m, int* si_j, char respuestas[MAX_RESPUESTAS]){
	int ambos_si = respuestas[0];
	int ambos_no = respuestas[1];
	int solo_j = respuestas[2];
	int solo_m = respuestas[3];
	*si_m = ambos_si + solo_m;
	*si_j =ambos_si + solo_j;
}
int es_igual(char signo_m[MAX_RESPUESTAS], char signo_j[MAX_RESPUESTAS]){
	int iguales = strcmp(signo_m,signo_j);
	return iguales;

}

bool tienen_mismo_signo(char respuestas[MAX_RESPUESTAS], int tope_respuestas) {
	char signo_m[MAX_RESPUESTAS];
	char signo_j[MAX_RESPUESTAS];
	int si_m;
	int si_j;
	int iguales;
	completar_si_o_no(si_m, si_j, respuestas);
	asignar_signo(si_m, signo_m);
	asignar_signo(si_j, signo_j);
	iguales = es_igual(signo_m, signo_j);
	printf("%i", iguales);
}