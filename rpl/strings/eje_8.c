/* 

*/

#include <string.h>
#define MAX_PALABRA 50
#define MAX_DIAS 10
#define MAX_MESES 20
// Aca van las constantes

void inicializar_mese_y_dia(char dias[MAX_DIAS], char meses[MAX_MESES]){
    char meses[0] = "enero";
    char meses[1] = "febrero";
    char meses[2] = "marzo";
    char meses[3] = "abril";
    char meses[4] = "mayo";
    char meses[5] = "junio";
    char meses[6] = "julio";
    char meses[7] = "agosto";
    char meses[8] = "septiembre";
    char meses[9] = "octubre";
    char meses[10] = "noviembre";
    char meses[11] = "diciembre";
    char dias[0] = "lunes";
    char dias[1] = "martes";
    char dias[2] = "miercoles";
    char dias[3] = "jueves";
    char dias[4] = "viernes";
    char dias[5] = "sabado";
    char dias[6] = "domingo";
}

void cambiar_palabra(char palabra[MAX_PALABRA]) {
	char dias[MAX_DIAS];
	char meses[MAX_MESES];
    inicializar_mese_y_dia(dias, meses);
	for(int i=0; i < strlen(palabra); i++){
		if(palabra[i] == dias[0] || palabra[i] == dias[1] || palabra[i] == dias[3] || palabra[i] == dias[5]){
			strcat(palabra[i], "ardo");
		}else if(palabra[i] == dias[2] || palabra[i] == dias[4] || palabra[i] == dias[6]){
			if(palabra[i] == dias[2]){
				strcat(palabra[i], "mi");
			}else if(palabra[i] == dias[4]){
				strcat(palabra[i], "vi");
			}else{
				strcat(palabra[i], "do");
			}

		}

		if(palabra[i] == meses[0] || palabra[i] == meses[2] || palabra[i] == meses[3] || palabra[i] == meses[4] || palabra[i] == meses[5] || palabra[i] == meses[6]){
			strcat(palabra[i], "duki");
		}else if(palabra[i] == meses[1] || palabra[i] == meses[7] || palabra[i] == meses[8] || palabra[i] == meses[9] || palabra[i] == meses[10] || palabra[i] == meses[11] ){
			if(palabra[i] == meses[1]){
				strcat(palabra[i], "ro");
			}else if(palabra[i] == meses[7]){
				strcat(palabra[i], "to");
			}else if(palabra[i] == meses[8] || palabra[i] == meses[9] || palabra[i] == meses[10] || palabra[i] == meses[11]){
				strcat(palabra[i], "re");
			}
		}

	}
	
}

int main(){
    char palabras[MAX_PALABRA] = "lunes";

    return 0;
}