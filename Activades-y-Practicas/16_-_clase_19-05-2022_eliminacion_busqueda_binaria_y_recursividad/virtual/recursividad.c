#include <stdio.h>
#include <stdbool.h>

#define NO_ENCONTRADO -1
#define MAX_CHICOS 100
//
//post: devolvera false si noce encontro el numero del chico en caso contrario un true
bool esta_chico_rec(int chicos[MAX_CHICOS], int tope_chicos, int posicion, int numero_chico) {
    //caso base 1
    if (posicion >= tope_chicos) {
        return false;
    }
    //caso base 2
    if (chicos[posicion] ==  numero_chico) {
        return true;
    }
    //llamado a la funcion recursiva y proceso
    return esta_chico_rec(chicos, tope_chicos, posicion+1, numero_chico);
}
//pre: la posicion inicial debe ser 0(lo asumo)
bool esta_chico(int chicos[MAX_CHICOS], int tope_chicos, int numero_chico) {
    return esta_chico_rec(chicos, tope_chicos, 0, numero_chico);
}


//post:devolvera la suma del todos las componentes del vector , empezara a sumar desde la pos_inicial = o hasta el tope
int suma_chicos_rec(int chicos[MAX_CHICOS], int tope_chicos, int posicion) {
    //caso base    
    if (posicion >= tope_chicos) {
        return 0;
    }
    //llamado a la funcion recursiva  y proceso
    return chicos[posicion] + suma_chicos_rec(chicos, tope_chicos, posicion+1);
}
//
int suma_chicos(int chicos[MAX_CHICOS], int tope_chicos) {
    return suma_chicos_rec(chicos, tope_chicos, 0);
}

// devolvera la suma del todos las componentes del vector , empezara a sumar desde atras hacia adelante
int suma_chicos_invertida(int chicos[MAX_CHICOS], int posicion) {
    //caso base
    if (posicion < 0) {
        return 0;
    }
    //llamado a la funcion recursiva
    return chicos[posicion] + suma_chicos_invertida(chicos, posicion-1);
}

int chicos_impares_rec(int chicos[MAX_CHICOS], int tope_chicos, int posicion) {
    //caso base
    if (posicion >= tope_chicos) {
        return 0;
    }
    //llamado a la funcion recursiva y proceso
    if ((chicos[posicion] % 2) == 0) { // par
        return chicos_impares_rec(chicos, tope_chicos, posicion+1);
    } else { // impar
        return 1 + chicos_impares_rec(chicos, tope_chicos, posicion+1);
    }
}

int chicos_impares(int chicos[MAX_CHICOS], int tope_chicos) {
    return chicos_impares_rec(chicos, tope_chicos, 0);
}

int chicos_pares_rec(int chicos[MAX_CHICOS], int tope_chicos, int posicion){
    //caso base
    if(posicion >= tope_chicos){
        return 0;
    }
    //llamado a la funcion recursiva y proceso
    if((chicos[posicion] % 2) == 0){
        return 1 + chicos_pares_rec(chicos, tope_chicos, posicion+1);
    }else{
        return chicos_pares_rec(chicos, tope_chicos, posicion+1);
    }
}

int chicos_pares(int chicos[MAX_CHICOS], int tope_chicos){
    return chicos_pares_rec(chicos, tope_chicos, 0);
}

// int contar(int chicos[MAX_CHICOS], int tope_chicos) {
//     int contador = 0;
//     for (int i = 0; i < tope_chicos; i++) {
//         if ((chicos[posicion] % 2) != 0) {
//             contador++;
//         }
//     }
//     return contador;
// }

int busqueda_binaria_rec(int chicos[MAX_CHICOS], int fin, int inicio, int numero_chico) {
    int centro = (fin+inicio)/2;
    //caso base1
    if (inicio > fin) {
        return NO_ENCONTRADO;
    }
    //caso base 2
    if (chicos[centro] == numero_chico) {
        return centro;
    }
    //llamado a la funcion recursiva y proceso
    if (chicos[centro] < numero_chico) {
        return busqueda_binaria_rec(chicos, fin, centro+1, numero_chico);
    } 
    return busqueda_binaria_rec(chicos, centro-1, inicio, numero_chico);
}

int busqueda_binaria(int chicos[MAX_CHICOS], int tope_chicos, int numero_chico) {
    return busqueda_binaria_rec(chicos, tope_chicos, 0, numero_chico);
}


int main(){

    int chicos[MAX_CHICOS] = {2, 6, 8, 1, 9, 5, 3, 10, 34, 7, 22, 91, 31 };
    int chicos_ordenados[MAX_CHICOS] = {1, 2, 3, 5, 6, 7, 8, 9, 10, 22, 31, 34, 91};
    
    int tope_chicos = 13;

    int numero_chico = 6;

    if (esta_chico(chicos, tope_chicos, numero_chico) == true){
        printf("SI se encuentra el chico: %i\n", numero_chico);
    } else{
        printf("NO encuentra el chico: %i\n", numero_chico);
    } 
    int suma = suma_chicos(chicos, tope_chicos);
    printf("La suma normal es: %i\n", suma);
    printf("\n");
    int suma_invertida = suma_chicos_invertida(chicos, tope_chicos);
    printf("La suma invertida es: %i\n", suma);
    printf("\n");
    int impares = chicos_impares(chicos, tope_chicos);
    printf("Los impares son: %i\n", impares);
    printf("\n");
    int pares = chicos_pares(chicos, tope_chicos);
    printf("Los pares son: %i\n", pares);
    printf("\n");
    int posicion = busqueda_binaria(chicos_ordenados, tope_chicos, numero_chico);
    printf("La posicion es: %i\n", posicion);

    return 0;
}




