/*

Phil, un sátiro entrenador de héroes, tiene el sueño de entrenar al mayor héroe que Grecia ha visto y tiene al candidato perfecto: Hércules. El problema es que Hércules es un simple adolescente que no puede controlar su endiosada fuerza, por lo que Phil deberá prepararlo para que esté apto para salvar a los ciudadanos griegos.

Es por esto que Phil te encargó preparar su patio delantero en un avanzado gimnasio en el que Hércules se entrenará. Se pide:

    Implementar una función que inicialice todo el patio con mancuernas (“M”).

*/
#include <stdio.h>
#define MAX_TERRENO 10
#define MANCUERNAS M
// Aqui van las constantes...

void inicializar_gimnasio(char gimnasio[MAX_TERRENO][MAX_TERRENO], int tope){
	for(int i = 0;i < tope; i++){
		for(int j = 0;j < tope; j++){
			gimnasio[i][j]= 'M';
            printf("%c", gimnasio[i][j]);	
		}
        printf("\n");
	}
}

int main(){
    char gimnasio[MAX_TERRENO][MAX_TERRENO];
    int tope = 10;
    inicializar_gimnasio(gimnasio, tope);

    return 0;

}
