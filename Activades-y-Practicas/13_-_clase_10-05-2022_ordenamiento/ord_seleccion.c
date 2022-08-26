/* Seleccion */
void ordenar_por_seleccion(int vector[MAX], int tope){
    int aux;
    int minimo;

    for (int i = 0; i < tope - 1; i++){
        minimo = i;
        for (int j = i+1; j < tope; j++){
            if (vector[minimo] > vector[j]){
                minimo = j;
            }
        }
        aux = vector[minimo];
        vector[minimo] = vector[i];
        vector[i] = aux;
    }
}
