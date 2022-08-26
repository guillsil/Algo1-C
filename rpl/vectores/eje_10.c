/*
En la guardería SunnySide, los juguetes tienen una lista con la cantidad de juguetes con los que jugaron lo largo de los días.

Los juguetes tiene ganas de nombrar un día como el "Dia del juego", pero quieren que el día que sea elegido sea muy especial y tenga un significado. Por lo que no tuvieron mejor idea que elegir el día con mayor juguetes agarrados para poder conmemorarlo.

Un día es considerado día record si la cantidad de juguetes con los que jugaron en un día es mayor o igual a cualquiera de los dias anteriores.

Teniendo un vector que represente los días en números de una semana (0=domingo,1=lunes,2=martes…), y cada posición represente la cantidad total de adopciones concretadas en ese día:

    Implementar una función que devuelva cuál es el día record de juego.

Aclaraciones

-En caso de empate entre dos días, se considerará el día más cercano a la fecha como el día ganador.

Ejemplo

Si se recibe el vector [54,12,23,8,30,60,44], la mayor cantidad de juguetes usado es 60, por lo que el día recor
*/
#include <stdio.h>
#define MAXIMOS_DIAS 7


int dia_record(int usados[MAXIMOS_DIAS], int tope){
    int mayor = usados[0], indice = 0;
    for (int i = 0; i < tope; i++){
        if (usados[i] > mayor) return i;
    }
}

int main(){
    int dias_juguetes[MAXIMOS_DIAS]= {3, 3, 7 ,8, 2, 90, 6};
    int tope = MAXIMOS_DIAS, indice;
    indice = dia_record(dias_juguetes, tope);
    printf("%i", indice);

    return 0;
}
