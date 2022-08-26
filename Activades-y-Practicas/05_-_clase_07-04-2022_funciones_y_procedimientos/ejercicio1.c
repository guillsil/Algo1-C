#include <stdio.h>

const int ID_DORMILON = 1;
const int ID_GRUNION = 2;
const int ID_TONTIN = 3;
const char DORMILON = 'D';
const char GRUNION = 'G';
const char TONTIN = 'T';
const char ERROR = 'E';


char enano(int id_enano){
	if(id_enano == ID_DORMILON){
		return DORMILON;
	} else if(id_enano == ID_GRUNION){
		return GRUNION;
	}else if(id_enano == ID_TONTIN){
		return TONTIN;
	}else{
		return ERROR;
	}
}

int main(){

	int id_consulta = 3;
	char enanito_fiestero = enano(id_consulta);
	printf("Te toco ser %c\n",enanito_fiestero);
	return 0;
}