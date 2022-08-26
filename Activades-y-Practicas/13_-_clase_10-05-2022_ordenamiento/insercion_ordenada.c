/* Inserción Ordenada */

int aux = 3;
int j = tope - 1;
while (j >= 0 && vector[j] > aux) {
	vector[j+1] = vector[j];
	j--;
}
vector[j+1] = aux;