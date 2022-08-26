#include <stdio.h>

const char ESPADA = 'E';
const char BASTO = 'B';
const char ORO = 'O';
const char COPA = 'C';
const char AURORA = 'A';
const char MALEFICA = 'M';

typedef struct carta{
	int numero;
	char palo;
}carta_t;

typedef struct cartas_jugador{
	carta_t carta_1;
	carta_t carta_2;
	carta_t carta_3;
}cartas_jugador_t;

typedef struct mano{
	cartas_jugador_t cartas_aurora;
	cartas_jugador_t cartas_malefica;
}mano_t;



/*
pre:Las cartas NO pueden ser iguales y el palo debe ser valido(E,B,C,O)
post:Devuelve el ganador 
*/
int jugador_ganador(carta_t carta_j1, carta_t carta_j2){
    
    int ganador = -1;
    if(carta_j1.numero > carta_j2.numero){
       ganador = 2;
    }else if(carta_j1.numero < carta_j2.numero){
    	ganador = 1;
    }else{
    	if(carta_j1.palo == ESPADA){
    		ganador = 1;
    	}else if((carta_j1.palo == BASTO)&&(carta_j2.palo!=ESPADA)){
    		ganador = 1;
    	}else if((carta_j1.palo == ORO)&&(carta_j2.palo == COPA)){
    		ganador = 1;
    	}else{
    		ganador = 2;
    	}
    }

    return ganador;
}


/*
pre: Las cartas de la mano tiene palos validos (B,E,O,C).No hay cartas repetidas.
post:Nos devuelve el jugador ganador de la mano
*/
char ganador_mano(mano_t mano){

	int puntaje_j1 = 0;
	char ganador = ' ';
	if(jugador_ganador(mano.cartas_aurora.carta_1,mano.cartas_malefica.carta_1)==1){
		puntaje_j1++;
	}
	if(jugador_ganador(mano.cartas_aurora.carta_2,mano.cartas_malefica.carta_2)==1){
		puntaje_j1++;
	}
	if(jugador_ganador(mano.cartas_aurora.carta_3,mano.cartas_malefica.carta_3)==1){
		puntaje_j1++;
	}

	if(puntaje_j1>=2){
		ganador = AURORA;
	}else{
		ganador = MALEFICA;
	}

	return ganador;

    
}





int main(){
    /*
	carta_t carta_j1;
	carta_t carta_j2;

	carta_j1.numero = 8;
	carta_j1.palo = BASTO;

	carta_j2.numero = 8;
	carta_j2.palo = ESPADA;
	*/
	mano_t mano;
	mano.cartas_aurora.carta_1.numero = 1;
	mano.cartas_aurora.carta_1.palo = BASTO;
	mano.cartas_aurora.carta_2.numero = 2;
	mano.cartas_aurora.carta_2.palo = ESPADA;
	mano.cartas_aurora.carta_3.numero = 3;
	mano.cartas_aurora.carta_3.palo = BASTO;
	mano.cartas_malefica.carta_1.numero = 4;
	mano.cartas_malefica.carta_1.palo = ESPADA;
	mano.cartas_malefica.carta_2.numero = 5;
	mano.cartas_malefica.carta_2.palo = BASTO;
	mano.cartas_malefica.carta_3.numero = 6;
	mano.cartas_malefica.carta_3.palo = ORO;

    
    printf("%c\n",ganador_mano(mano));
	


	return 0;
}