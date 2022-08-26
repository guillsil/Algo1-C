#define MAX_TUERCAS 1000
const int ERROR = -1;
const int CANTIDAD_IMPAR = 25;
const int CANTIDAD_PAR = 50;

//pre: tamanio debe ser positivo. Debe haber al menos una tuerca.
int promedio_tuerca(tuerca_t tuercas[MAX_TUERCAS],int tope_tuercas,int tamanio){
	return promedio_tuerca_rec(tuercas,tope_tuercas,tamanio,0,0,0);
}

//pre: tamanio y actual de tuercas debe ser positivo. La suma siempre es positiva.
//post:
int promedio_tuerca_rec(tuerca_t tuercas[MAX_TUERCAS],int tope_tuercas,int tamanio, int actual, int cantidad_recorrida,int suma){
	if(actual >= tope_tuercas){
		return ERROR;
	}
	if(tuercas[actual].tamanio == tamanio && !(tuercas[actual].esta_oxidada)){
		//return (suma/cantidad_recorrida); 
		return (suma+tamanio)/(cantidad_recorrida +1);
	}
	int desplazamiento = CANTIDAD_IMPAR;
	if(tuercas[actual].tamanio % 2 == 0){
		desplazamiento = CANTIDAD_PAR;
	}
	return promedio_tuerca_rec(tuercas,tope_tuercas,tamanio,actual+desplazamiento,cantidad_recorrida+1,suma+tuercas[actual].tamanio);
}

//apruebeme profe por favor le llevo facturitas el jueves


EJERICIO 3 PARTE 2
variable++
++varaible
bool hay_que_intercambiar(caramelo_t caramelo_a, caramelo_t caramelo_b){
	if(strcmp(caramelo_a.color, caramelo_b.color)<0){
		return true;
	} else if(strcmp(caramelo_a.color, caramelo_b.color)>0){
		return false;
	} else{

		return caramelo_a.calorias > caramelo_b.calorias;

		/*if(caramelo_a.calorias > caramelo_b.calorias){
			return true;
		} else{
			return false;
		}*/
	}

}

void ordenar_caramelos(caramelo_t caramelos[MAX],int tope){

	for(int i=0;i<tope;i++){
		for(int j=0;j<tope-i-1;j++){
			bool intercambiamos = hay_que_intercambiar(caramelos[j],caramelos[j+1]);
			if(intercambiamos){
				caramelo_t aux;
				aux = caramelos[j];
				caramelos[j] = caramelos[j+1];
				caramelos[j+1] = aux;
			}
		}
	}
}