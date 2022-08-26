// Muriel (la humana de Coraje) tiene una forma muy obsesiva de guardar sus botones.

// Los guarda en una matriz de caracteres donde cada posición representa un lugar para guardar un botón, siguiendo la siguiente convención :

// Caracter '-' : Dicha posición está vacía.
// Caracter 'V' : Dicha posición tiene un botón verde.
// Caracter 'A' : Dicha posición tiene un botón azul.
// Caracter 'R' : Dicha posición tiene un botón rojo.
// Caracter 'B' : Dicha posición tiene un botón blanco.
// Caracter 'N' : Dicha posición tiene un botón negro.
// Ella busca que su matriz de botones cumpla con las siguientes condiciones :

// La cantidad de botones en cada fila debe ser par.
// Las filas impares solo pueden tener botones blancos.
// Cada columna debe tener más botones azules que rojos (Muriel es de Bokita).

// SE PIDE
// Implementar una función que reciba una matriz de 30x30 y devuelva true si los botones están guardados como quiere Muriel o false en caso contrario.

#define MAX_FILAS 30
#define MAX_COLUMNAS 30

#define BOTON_VERDE 'V'
#define BOTON_AZUL 'A'
#define BOTON_ROJO 'R'
#define BOTON_NEGRO 'N'
#define BOTON_BLANCO 'B'
#define VACIO '-'

bool es_boton(char boton){
    return (boton != VACIO);
}

bool es_fila_impar(int fila) {
    return (fila % 2 == 1);
}


bool columna_ordenada(char matriz[MAX_FILAS][MAX_COLUMNAS], int tope_filas, int columna) {
    int botones_azules = 0;
    int botones_rojos = 0;

    for (int i = 0; i < tope_filas; i++) {
        if (matriz[i][columna] == BOTON_AZUL) {
            botones_azules++;
        } else if (matriz[i][columna] == BOTON_ROJO) {
            botones_rojos++;
        }
    }

    return (botones_azules > botones_rojos);
}


bool esta_ordenada(char matriz[MAX_FILAS][MAX_COLUMNAS], int tope_filas, int tope_columnas) {
    int botones_totales = 0;

    bool esta_ordenada = true;

    int i = 0;
    int j = 0;
    while (i < tope_filas && esta_ordenada) {
        // recorre todo una fila
        while (j < tope_columnas && esta_ordenada) {
            if (es_boton(matriz[i][j])) {
                botones_totales++;
                if (es_fila_impar(i) && matriz[i][j] != BOTON_BLANCO) {
                    esta_ordenada = false;
                }
            }
            j++;
        }
        // aca termina de recorrer la fila
        if (es_fila_impar(botones_totales)) {
            esta_ordenada = false;
        }
        i++;
        botones_totales = 0;
    }

    j = 0;
    while (j < tope_columnas && esta_ordenada) {
        
        if (!columna_ordenada(matriz, tope_filas, j)) {
            esta_ordenada = false;
        }
        j++;
    }

    return esta_ordenada;
}