#include <stdio.h>
#include <stdbool.h>

const int STITCH = 720;

void pedir_lilo(char* letra_lilo){
	printf("Lilo lilo, decime tu letra\n");
	scanf(" %c",letra_lilo);
}

void pedir_stitch(char* letra_stitch){
	printf("Stitch ch ch, decime tu letra\n");
	scanf(" %c",letra_stitch);
}


void imprimir_divisores(int numero_lilo){
	for(int i=1;i<=numero_lilo;i++){
		if(STITCH%i == 0){
			printf("Yeyy %i es divisor\n",i);
		}
	}

}

bool es_numero_valido(int numero_lilo){
	/*if(numero_lilo > 0 && numero_lilo < STITCH){
		return true;
	}else{
		return false;
	}*/

	return (numero_lilo > 0 && numero_lilo < STITCH);
}

void pedir_numerito(int* numero_lilo){
	printf("Lilo decime un numero!!\n");
	scanf("%i",numero_lilo);
	while(!es_numero_valido(*numero_lilo)){
		printf("Lilo decime un numero!!\n");
		scanf("%i",numero_lilo);
	}
}

int main(){
	/*char letra_lilo;
	pedir_lilo(&letra_lilo);
	char letra_stitch;
	pedir_stitch(&letra_stitch);

	printf("La letra de Lilo es %c y la de Stitch es %c\n",letra_lilo, letra_stitch);

	while(letra_lilo+1 != letra_stitch){
		pedir_stitch(&letra_stitch);
	}
*/

	int numero_lilo;
	pedir_numerito(&numero_lilo);
	imprimir_divisores(numero_lilo);

	return 0;

}