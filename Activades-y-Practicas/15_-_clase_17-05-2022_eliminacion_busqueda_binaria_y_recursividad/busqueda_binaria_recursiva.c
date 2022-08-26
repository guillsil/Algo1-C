int busqueda_binaria_rec(int vector[MAX_ELEMENTOS], int inicio, int fin, int buscado){

	/* Caso base 1 */
	if (inicio > fin) return NO_EXISTE;

	int centro = (inicio + fin) / 2;
	/* Caso base 2 */
	if (vector[centro] == buscado) {
		return centro;
	}

	/* Llamada(s) recursiva(s) */
	if (vector[centro] > buscado) {
		return busqueda_binaria_rec(vector, inicio, centro-1, buscado);
	}else if(vector[centro] < buscado) {
		return busqueda_binaria_rec(vector, centro+1, fin, buscado);
	}
}

int busqueda_binaria(int vector[MAX_ELEMENTOS], int tope, int buscado){
	return busqueda_binaria_rec(vector, 0, tope-1, buscado);
}
