#include <stdio.h>
#include <stdbool.h>

const int CORTE_ANIO_ABURRIDO = 2000;

// Pre: anio tiene que ser positivo, el anio no puede ser mayor al actual
// Pos: Devuelve true si anio es menor a CORTE_ANIO_ABURRIDO, false sino
bool es_anio_cool(int anio) {
	return anio < CORTE_ANIO_ABURRIDO;
}

// Pre: -
// Pos:	Pide al usuario su inicial y la imprime por pantalla
void pedir_e_imprimir_inicial_usuario() {
	printf("Hola! Cual es tu inicial?\n");

	char inicial_usuario;
	scanf(" %c", &inicial_usuario);

	printf("Hola! Tu inicial es %c\n", inicial_usuario);
}

// Pre: -
// Pos: Pide al usuario su año de nacimiento hasta que sea cool
void pedir_anio_nacimiento() {
	printf("Cual es tu año de nacimiento?\n");

	int anio;
	scanf(" %i", &anio);

	int contador = 0;

	while (!es_anio_cool(anio) && contador < 3) {
		printf("Che, ese año no es cool, ingresa otro año\n");
		scanf(" %i", &anio);
		contador++;
	}

	printf("Tu año cool es %i\n", anio);
}

int main() {
	pedir_e_imprimir_inicial_usuario();

	pedir_anio_nacimiento();

	return 0;
}