/*
Hércules, aún en Tebas, se encuentra peleando con Hidra, un monstruo acuático capaz de regenerar dos cabezas por cada una que perdía. Es esta capacidad la que le está dando un dolor de cabeza a Hércules, ya que no sabe cómo lidiar con el monstruo. Afortunadamente, Phil se encuentra una vez más para asistir a Hércules, y se dio cuenta del patrón que sigue la regeneración de las cabezas.

Si se piensa al cuerpo de la Hidra como una matriz, donde cada nueva cabeza está representada por un entero (su id), un largo (que se ocupará horizontalmente), y que los lugares vacíos están representados por un 0, Phil puede intentar predecir dónde aparecerán nuevas cabezas, ayudando a Hércules a anticipar movimientos. Es por esto que se pide:

    Implementar una función que dada la matriz, el id de una cabeza, su largo y la fila donde Phil cree que aparecerá esta nueva cabeza, cargue en la matriz el id de la cabeza en la fila que se predice, respetando su largo.

Tener en cuenta:

    Las cabezas se regeneran única y exclusivamente horizontalmente.
    El id que nos pasen es un id válido, esto quiere decir que no va a ser negativo ni 0 (cero).
    La fila donde se predice la regeneración siempre va a estar completamente vacía.
    El largo de la cabeza no excederá los límites del cuerpo de la Hidra (si se tiene una matriz de 5 columnas, una nueva cabeza no podrá tener un largo mayor a 5).
    Las cabezas empiezan a regenerarse desde la columna 0. Esto quiere decir que si una cabeza es de largo 3, entonces va a ocupar los casilleros 0, 1 y 2 de la fila pedida.

Ejemplo:

Teniendo una hidra de 4x4 sin predicciones:

0000
0000
0000

Y teniendo que posicionar la serpiente de id 3, de largo 2 en la fila 1, tendríamos que tener como resultado una matriz:

0000
3300
0000
*/

#include <stdio.h>
#define MAX_FILAS 10
#define MAX_COLUMNAS 10

void predecir_cabeza(unsigned int hidra[MAX_FILAS][MAX_COLUMNAS], unsigned int tope_fil, unsigned int tope_col, unsigned int id, unsigned int largo, int fila){
    for(int i= 0; i<tope_fil; i++){  
        for(int j = 0; j<tope_col; j++){
            for (int i = 0; i < largo; i++){
                hidra[fila][i] = id;
            }
            printf("%i", hidra[i][j]);
        }
        printf("\n");
    }
}
int main(){
    unsigned int hidra[MAX_FILAS][MAX_COLUMNAS] = {
        {0, 0 , 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0 , 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0 , 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0 , 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0 , 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0 , 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0 , 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0 , 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0 , 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0 , 0, 0, 0, 0, 0, 0, 0, 0}

    };
    unsigned int tope_fil = 10;
    unsigned int tope_col = 10;
    unsigned int id = 6;
    unsigned int largo = 2;
    int fila = 0;
    predecir_cabeza(hidra, tope_fil, tope_col, id, largo, fila);


}