/*
Mate estaba planeando su última operación como espía, hasta que se dio cuenta que el teléfono por donde se comunica la agencia, estaba pinchado, por lo que todos sus enemigos estaban escuchando su plan.
Para evitar que tengan más información, decidieron comenzar a hablar sólo con las vocales. De esta forma, el plan sería secreto y sólo ellas podían entenderlo.

Implementar un procedimiento que, dado un plan, elimine todas las consonantes existentes en él.

Ejemplo:

Si el plan es “Entrar de incognito”, debe quedar “Ea e ioio”.
*/
#include <string.h>
#include <stdio.h>
#define MAX_PLAN 50
// Aca van las constantes

void cifrar_plan(char plan[MAX_PLAN], char cadena_aux[MAX_PLAN]) {
	int j;
	for (int i = 0; i < strlen(plan); i++){
    	if (plan[i] != 'a' && plan[i] != 'e' && plan[i] != 'i' && plan[i] != 'o' && plan[i] != 'u' && plan[i] != 'A' && plan[i] != 'E' && plan[i] != 'I' && plan[i] != 'O' && plan[i] != 'U'){
        	cadena_aux[j] = plan[i];
        	j++;
    	}
	}
	cadena_aux[j] = '\0';
}


int main(){
    char cadena[MAX_PLAN] = "Entrar de incognito";
    char cadena_aux[MAX_PLAN];
    cifrar_plan(cadena,cadena_aux);
    for (int i = 0; i <strlen(cadena); i++){
        printf("%c", cadena[i]);
    }
    printf("\n");
    for (int i = 0; i <strlen(cadena_aux); i++){
        printf("%c", cadena_aux[i]);
    }
    

}
