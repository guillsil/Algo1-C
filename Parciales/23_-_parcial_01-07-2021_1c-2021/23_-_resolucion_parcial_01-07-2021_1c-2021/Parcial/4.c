#define CINCUENTA 50 // El nombre de la constante no es descriptivo
// #define MAX_DIRECCION 50

typedef struct casa {
	char direccion[CINCUENTA];
	int anio_construccion;
} casa_t;

// Faltan pre y pos:
// Pre: Recibe un vector con las casas y su tope correspondiente.
// Pos: Devuelve la casa con anio_construccion menor.
casa_t casa_mas_antigua (casa_t casas [MAX_CASAS], int t) { // "t" no es descriptivo, mejor "tope"

	int anio_mas_antigua = 2000; // 2000 es un numero arbitrario y puede generar problemas
	// int anio_mas_antigua = casas[0].anio_construccion;
	casa_t mas_antigua;

	for (i = 1; i < t; i++) { // Arranca desde 1 en lugar de 0
		if (casas[i].anio_construccion < anio_mas_antigua) {
			anio_mas_antigua = casas[i].anio_construccion;
			mas_antigua = casas[i];
		}
		i++; // El bucle for ya incrementa el i, con esto nos salteamos casa por medio
	}
	return mas_antigua;
}