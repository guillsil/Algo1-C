/*
Jane le está enseñando frases en Español a Tarzán pero a él todavía le cuesta bastante pronunciar.
Para hacer esto más divertido, decidieron implementar una función que puntúe la pronunciación de Tarzán:

Una función que dado lo que dijo Jane y lo que dijo Tarzán, devuelva:

    5 si Tarzán repitió exactamente lo que dijo Jane
    2 si Tarzán se equivocó pero al menos la longitud de la frase fue correcta
    0 si Tarzán dijo cualquier cosa

*/
#include <string.h>
#define MAX_FRASE 40
#define REPITIO_CORRECTAMENTE 5
#define REPITIO_MAS_O_MENOS 2
#define CUALQUIER_COSA 0
// Aca van las constantes

int puntos_frase(char frase_jane[MAX_FRASE], char frase_tarzan[MAX_FRASE]) {
	if(strcmp(frase_jane, frase_tarzan)==0){
		return REPITIO_CORRECTAMENTE;
	}else if(strlen(frase_jane) == strlen(frase_tarzan)){
		return REPITIO_MAS_O_MENOS;
	}else{
		return CUALQUIER_COSA;
	}
}