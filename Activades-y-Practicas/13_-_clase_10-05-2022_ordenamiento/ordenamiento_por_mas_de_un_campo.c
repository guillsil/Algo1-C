/* Burbujeo */
typedef struct carta {
    int numero;
    char palo; // B < C < E < O
} carta_t;

/*
 * Pre:
 * - Los palos son B, C, E y O
 * - Los numeros de la cartas están entre el 1 y el 12
 * Post: 
 * - Devuelve 1 si carta_uno es mayor a carta_2
 * - Devuelve -1 si carta_uno es menor a carta_2
 * - Devuelve 0 si carta_uno es igual a carta_2
 */
int comparacion_de_cartas(carta_t carta_uno, carta_t carta_dos){
    if (carta_uno.numero > carta_dos.numero) {
        return 1;
    } else if (carta_uno.numero < carta_dos.numero) {
        return -1;
    } else { // son el mismo numero!!
        if (carta_uno.palo > carta_dos.palo){
            return 1;
        } else if (carta_uno.palo < carta_dos.palo) {
            return -1;
        } else {
            return 0;
        }
    }
}



void ordenar_por_burbujeo(carta_t cartas[MAX], int tope){
    int aux;
    for (int i = 1; i < tope; i++) {
        for (int j = 0; j < tope - i; j++){
            int comparacion = comparacion_de_cartas(cartas[j], cartas[j+1]);
            if (comparacion < 0){
                aux = vector[j];
                vector[j] = vector[j+1];
                vector[j+1] = aux;
            }
        }

    }
}












