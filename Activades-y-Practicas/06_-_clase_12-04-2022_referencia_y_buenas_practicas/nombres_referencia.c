#include <stdio.h>
#include <stdbool.h>

const int CORTE_ANIO_ABURRIDO = 2000;

// Pre: anio tiene que ser positivo, el anio no puede ser mayor al actual
// Pos: Devuelve true si anio es menor a CORTE_ANIO_ABURRIDO, false sino
bool es_anio_cool(int anio) {
	return anio < CORTE_ANIO_ABURRIDO;
}

// Pre: -
// Pos:	Pide al usuario su inicial y la guarda en inicial_usuario
void pedir_inicial_usuario(char* inicial_usuario) {
	printf("Hola! Cual es tu inicial?\n");

	scanf(" %c", inicial_usuario);
}

// Pre: -
// Pos: Pide al usuario su año de nacimiento hasta que sea cool
//		y lo guarda en anio. Guarda en es_cool si el anio final es cool
void pedir_anio_nacimiento(int* anio, bool* es_cool) {
	printf("Cual es tu año de nacimiento?\n");

	scanf(" %i", anio);

	int contador = 0;
	printf("Año es: %d\n", *anio);

	while (!es_anio_cool(*anio) && contador < 3) {
		printf("Che, ese año no es cool, ingresa otro año\n");
		scanf(" %i", anio);
		contador++;
	}

	*es_cool = true;
	if (contador == 3) {
		printf("No te cansas de ser aburrido?\n");
		*es_cool = false;
	}
}

int main() {
	char inicial_usuario;
	pedir_inicial_usuario(&inicial_usuario);

	printf("Hola! Tu inicial es %c\n", inicial_usuario);

	int anio_nacimiento;
	bool es_cool;
	pedir_anio_nacimiento(&anio_nacimiento, &es_cool);

	if (es_cool) {
		printf("Tu año cool es %i\n", anio_nacimiento);
	} else {
		printf("Sos re aburrido\n");
	}

	return 0;
}