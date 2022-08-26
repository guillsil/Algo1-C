/* Insercion */
void ordenar_por_insercion(int vector[MAX], int tope){
    int aux;
    int j;

    for (int i = 1; i < tope; i++) {
        j=i;
        aux = vector[i];
        while (j > 0 && aux < vector[j-1]){
            vector[j] = vector[j-1];
            j--;
        }
        vector[j] = aux;
    }
}