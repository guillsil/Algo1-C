/* 
Mr. Increible quiere infiltrarse en la computadora de Sindrome para revisar sus planes, pero se dió cuenta que hay una nueva prueba antes de poder acceder. Esta prueba consiste en escuchar un código, descifrar qué es lo que dice, y dar una respuesta correcta. Mr. Increible, inmediatamente notó que la frase está dicha de derecha a izquierda, pero le cuesta mucho darla vuelta para poder identificar qué es lo que dice.

Implementar un procedimiento que invierta la frase escuchada para ayudar a Mr. Increible

Ejemplo:

Si se escucha la frase “odavirp oirotarobaL”, debe quedar “Laboratorio privado”
*/
#include <string.h>
#include<stdio.h>
#define MAX_FRASE 40

void intercambiar_frase(char frase[MAX_FRASE]) {
	int longitud = strlen(frase);

	for(int i = 0; i < longitud/2; i++){
		char temporaly = frase[i];
		frase[i] = frase[longitud -i -1];
		frase[longitud -i -1] = temporaly;
	}

    for (int i = 0; i < strlen(frase); i++){
        printf("%c", frase[i]);
    }
}
int main(){
    char frase[MAX_FRASE]= "odavirp oirotarobaL";
    intercambiar_frase(frase);
}