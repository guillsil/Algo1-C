/*
Llegó un nuevo juguete llamado Kiki a la casa de Andy. Kiki solo sabe hablar kikiakanoko y como Woody quiere acercarse a él para formar una amistad, decide aprender a hablarlo.
Luego de escucharlo hablar por unas horas se dio cuenta de algo:
Después de cada vocal, se agrega la letra "k" y se repite la vocal.

-Implementar un procedimiento que traduzca una frase a kikiakanoko.

Ejemplo:
"Eres un juguete"
"Ekerekes ukun jukugukueketeke"
*/
#include <string.h>
#include<stdio.h>
#define MAX_FRASE 50
const char  KIKI = 'K';

void insertar_caracter_al_string(char *original, char *subcadena, int indice){
    // El inicio es copiar la original N caracteres definidos por posición
    char inicio[MAX_FRASE] = "";
    strncpy(inicio, original, indice);
    // El final es copiar desde la posición N caracteres definidos por los sobrantes
    char fin[MAX_FRASE] = "";
    strncpy(fin, original + indice, strlen(original) - indice);
    // Agregar la subcadena al inicio
    strcat(inicio, subcadena);
    // Y agregar el fin a la anterior cadena, es decir, al inicio
    strcat(inicio, fin);
    // Copiarla dentro de la cadena recibida
    strcpy(original, inicio);
}

void traducir_frase(char frase_woody[MAX_FRASE]) {
    
    int longitud = strlen(frase_woody);
	for (int i = 0; i < longitud; i++){
    	if (frase_woody[i] == 'a' || frase_woody[i] == 'e' || frase_woody[i] == 'i' || frase_woody[i] == 'o' || frase_woody[i] == 'u' || frase_woody[i] == 'A' || frase_woody[i] == 'E' || frase_woody[i] == 'I' || frase_woody[i] == 'O' || frase_woody[i] == 'U'){  
        insertar_caracter_al_string(frase_woody, "K", i);
        insertar_caracter_al_string(frase_woody, "g", i-1);
    	}
	}
    for (int i = 0; i < strlen(frase_woody); i++){
        printf("%c", frase_woody[i]);
    }
    
}


int main(){
    char frase_woody[MAX_FRASE] = "Eres un juguete";
    traducir_frase(frase_woody);    
}
