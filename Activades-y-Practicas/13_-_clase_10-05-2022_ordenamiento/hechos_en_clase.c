/* Insercion */
for (int i = 0; i < tope; i++){
	int aux = vector[i];
	int j = i - 1;
	while (j >= 0 && vector[j] > aux) {
		vector[j+1] = vector[j];
		j--;
	}
	vector[j+1] = aux;
}

/* Selesion */
for (int i = 0; i < tope - 1; i++){
	int posicion_minimo = i;
	for (int j = i + 1; j < tope; j++){
		if (vector[j] < vector[posicion_minimo]){
			posicion_minimo = j;
		}
	}
	int auxiliar = vector[i];
	vector[i] = vector[posicion_minimo];
	vector[posicion_minimo] = auxiliar;
}

/* Burbujeo */
for (int j = 0; j < tope - 1; j++){
	for (int i = 0; i < tope - 1 - j; i++){
		if (vector[i] > vector[i+1]) {
			int auxiliar = vector[i];
			vector[i] = vector[i+1];
			vector[i+1] = auxiliar;
		}
	}
}












