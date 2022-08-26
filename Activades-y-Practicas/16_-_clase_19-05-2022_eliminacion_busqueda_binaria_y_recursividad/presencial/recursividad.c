#include <stdio.h>
#include <stdbool.h>

#define MAX_NUMEROS 10
const int NO_ENCONTRADO = -1;
int fibonacci(int n){
	if(n <= 1){
		return n;
	}
	return fibonacci(n-1)+fibonacci(n-2);
}

bool esta_el_numero(int organizacion[MAX_NUMEROS],int tope,int numero_a_buscar, int i){
	if(i==tope){
		return false;
	}

	if(organizacion[i]==numero_a_buscar){
		return true;
	}

	return esta_el_numero(organizacion,tope,numero_a_buscar,i+1);
}

/*int suma_de_chicos(int organizacion[MAX_NUMEROS], int tope, int n){
	if(n== tope){
		return 0;
	}

	return suma_de_chicos(organizacion,tope,n+1) + organizacion[n];
}*/

//segunda forma
int suma_de_chicos(int organizacion[MAX_NUMEROS], int tope, int n, int total){
	if(n== tope){
		return total;
	}
	total= total + organizacion[n];
	return suma_de_chicos(organizacion,tope,n+1,total);
}

int cantidad_impares(int organizacion[MAX_NUMEROS],int tope,int i){
	if(i == tope){
		return 0;
	}
	int contador_impares = 0;
	if(organizacion[i] % 2 != 0){
		contador_impares = 1;
	}

	return cantidad_impares(organizacion,tope,i+1)+contador_impares;
}

int busqueda_binaria(int organizacion[MAX_NUMEROS],int inicio, int fin, int buscado){
	int medio = (inicio+fin)/2;

	if(inicio > fin){
		return NO_ENCONTRADO;
	}
	if(organizacion[medio] == buscado){
		return medio;
	}
	if(organizacion[medio] < buscado){
		return busqueda_binaria(organizacion,medio+1,fin,buscado);
	}
	if(organizacion[medio] > buscado){
		return busqueda_binaria(organizacion,inicio,medio-1,buscado);
	}
}

int main(){
	//printf("%i\n",fibonacci(100));
	int organizacion[MAX_NUMEROS] = {2,3,4,5,8};
	int tope = 5;
	bool esta = esta_el_numero(organizacion,tope,9,0);
	if(esta == true){
		printf("Siiiii estaaaa wujuuuu\n");
	}
	else{
		printf("u.u no esta perdon\n");
	}

	printf(" cantidad de chicos %i\n",suma_de_chicos(organizacion,tope,0,0));
	
	printf("La cantidad de impares es %i\n",cantidad_impares(organizacion,tope,0));
	
	printf("La posicion es %i\n",busqueda_binaria(organizacion,0,tope,5));
	
	return 0;
}