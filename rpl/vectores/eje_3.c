/*  
Oliver y su pandilla se tienen que enfrentar a Sykes y sus dobermans, quienes secuestraron a Jenny. Es por esto que deciden organizarse para poder hacerles frente. Considerando que solo Dodger, Einstein, y Francis son aptos para pelear, deciden averiguar quién es el más hábil para que, en caso de que haya una pelea, éste luche primero.

Considerando que las habilidades de los perros se dividen en inteligencia (posición 0), resistencia física (posición 1), agilidad (posición 2), y fuerza (posición 3), y que la capacidad de pelea se calcula como la suma de la inteligencia, el triple de la resistencia física, el doble de la agilidad, y la fuerza, se pide:

    Implementar una función que calcule la capacidad de pelea de cada perro, y devuelva la habilidad del que peleará primero.

Ejemplo:

    Si se reciben los vectores Dodger: [4,3,8,2], Einstein: [5,1,9,3] y Francis: [4,8,7,1], siendo el resultado de cada uno 31, 29 y 43 respectivamente, se debe devolver 43.

*/

#include <stdio.h>
const int MAX_HABILIDADES = 4;

int habilidad(int habilidad[MAX_HABILIDADES]){
	int capacidad;
	capacidad = (habilidad[0] + (3*habilidad[1]) + (2*habilidad[2]) + habilidad[3]);
	return capacidad;
}

int perro_mas_habilidoso(int habilidades_dodger[MAX_HABILIDADES], int habilidades_einstein[MAX_HABILIDADES], int habilidades_francis[MAX_HABILIDADES]) {
	int capacidad_dodger = 0;
	int capacidad_einstein = 0;
	int capacidad_francis = 0;
	
	capacidad_dodger = habilidad(habilidades_dodger);
	capacidad_einstein = habilidad(habilidades_einstein);
	capacidad_francis = habilidad(habilidades_francis);

	if(capacidad_dodger > capacidad_einstein || capacidad_dodger > capacidad_francis){
		return capacidad_dodger;
	}else if(capacidad_einstein > capacidad_dodger || capacidad_einstein > capacidad_francis){
		return capacidad_einstein;
	}else if(capacidad_francis > capacidad_dodger || capacidad_francis > capacidad_einstein){
		return capacidad_francis;
	}
}

int main(){
    int habilidades_dodger[MAX_HABILIDADES]= {5,6,7};
    int habilidades_einstein[MAX_HABILIDADES]= {8,9,0};
    int habilidades_francis[MAX_HABILIDADES]= {4,7,9};
    int capacidad = perro_mas_habilidoso(habilidades_dodger, habilidades_einstein, habilidades_francis);
    printf("%i", capacidad);


    return 0;
}