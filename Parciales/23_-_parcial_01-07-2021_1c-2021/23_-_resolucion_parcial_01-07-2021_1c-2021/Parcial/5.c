#include <stdbool.h>

#define MAX_LUGAR 50
#define MAX_PESADILLAS

#define SOLEADO 'S'
#define NUBLADO 'N'
#define TORMENTA 'T'

#define PARDO 'G'
#define POLAR 'P'
#define CHLOE 'C'

typedef struct fecha {
	int dia;
	int mes;
	int anio;
} fecha_t;

typedef struct pesadilla {
	fecha_t fecha;
	char lugar[MAX_LUGAR];
	char clima;
	int sufrimiento;
	char cazador;
	bool estaba_acompañado;
	bool esta_terapeuta_enterado;
} pesadilla_t;

// Pre: Recibe el vector de pesadillas y su correspondiente tope.
// Pos: Devuelve el porcentaje de pesadillas en las cuales el cazador fue POLAR y el clima NUBLADO.
int porcentaje_nublado_polar(pesadilla_t pesadillas[MAX_PESADILLAS], int tope_pesadillas) {
	int coincidencias = 0;
	for (int i = 0; i < tope_pesadillas; i++) {
		if (cazador == POLAR && clima == NUBLADO) {
			coincidencias++;
		}
	}

	return (coincidencias / tope_pesadillas) * 100;
}