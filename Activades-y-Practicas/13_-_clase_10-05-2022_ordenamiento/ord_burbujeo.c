/* Burbujeo */
void ordenar_por_burbujeo(int vector[MAX], int tope){
    int aux;
    for (int i = 1; i < tope; i++) {
        for (int j = 0; j < tope - i; j++){
            if (vector[j] > vector[j+1]){
                aux = vector[j];
                vector[j] = vector[j+1];
                vector[j+1] = aux;
            }
        }

    }
}
