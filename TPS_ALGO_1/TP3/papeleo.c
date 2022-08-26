#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include"utiles.h"
#include"papeleo.h"
#include"tp1.h"
#include"tp2.h"

#define JUEGO_PERDIDO -1
#define JUEGO_GANADO 1
#define JUGANDO 0
#define NIVEL_GANADO 1
#define NO_SE_ENCONTRO -1

const char MOVIMIENTO_DERECHA = 'D', MOVIMIENTO_IZQUIERDA = 'A', ROTACION_HORARIA = 'E', ROTACION_ANTI_HORARIA = 'Q';
const char UTILIZAR_EXTINTOR = 'C', UTILIZAR_MARTILLO = 'Z', MARTILLAR_ABAJO = 'S', MARTILLAR_ARRIBA = 'W', MARTILLAR_DERECHA = 'D', MARTILLAR_IZQUIERDA = 'A';
const char MOVIMIENTO_ARRIBA = 'W', MOVIMIENTO_ABAJO = 'S';
const int divisible_randall_nivel_1 = 7, divisible_randall_nivel_2 = 5, divisible_randall_nivel_3 = 3;
const int CANTIDADES_PAREDES_1 = 40,CANTIDADES_PAREDES_2 = 30, CANTIDADES_PAREDES_3 = 20; 

bool checkear_movimiento(char terreno[MAX_FIL][MAX_COL], int fil, int col){
    return(posicionar_objeto(terreno, fil, col) != PARED);
}

void eliminar_objeto(objeto_t objeto[MAX_OBJETOS], int* tope_objeto, coordenada_t posicion_a_eliminar){
    int pos_objeto = buscar_objeto(objeto, (*tope_objeto), posicion_a_eliminar);

    for(int i=pos_objeto ; i < (*tope_objeto) - 1 ; i++){
        objeto[i] = objeto[i+1];
    }
    (*tope_objeto) --;
}

bool se_pasa_del_rango(coordenada_t posicion, int max_fil, int max_col){
    return ((posicion.fil >0)&&(posicion.fil < max_fil)&&(posicion.col >0)&&(posicion.col < max_fil));
}

char sobra_espacio(char terreno[MAX_FIL][MAX_COL], coordenada_t pos){
    return terreno[pos.fil][pos.col] == ESPACIO;
}

void obtener_pared(coordenada_t* pared, int nivel_actual){
    int dimension;
    dimension_matriz(&dimension, nivel_actual);
    (*pared) = coordenada_aleatoria(dimension, dimension);
}

void generar_paredes(char terreno[MAX_FIL][MAX_COL], int* tope_paredes, coordenada_t paredes[MAX_PAREDES], int nivel_actual){
     do{
        obtener_pared(&paredes[*tope_paredes], nivel_actual);
    }while(!sobra_espacio(terreno, paredes[*tope_paredes]));
    terreno[paredes[*tope_paredes].fil][paredes[*tope_paredes].col] = PARED;
    (*tope_paredes)++;
}

void verificar_paredes(char terreno[MAX_FIL][MAX_COL], nivel_t* niveles,int numero_nivel, int mov_realizados){
    if (numero_nivel == NIVEL_1 && mov_realizados <= MAX_PAREDES_1){
        generar_paredes(terreno, &(niveles->tope_paredes), niveles->paredes, numero_nivel);
    }else if(numero_nivel == NIVEL_2 && mov_realizados <= MAX_PAREDES_2){
         generar_paredes(terreno, &(niveles->tope_paredes), niveles->paredes, numero_nivel);
    }else if(numero_nivel == NIVEL_3 && mov_realizados <= MAX_PAREDES_3){
         generar_paredes(terreno, &(niveles->tope_paredes), niveles->paredes, numero_nivel);
    }
    
}


void accion_rotacion(char terreno[MAX_FIL][MAX_COL], nivel_t* niveles, coordenada_t* pos_jugador,int numero_nivel, char movimiento, char personaje_tp1){
    int dimension, max_fil, max_col, aux;
    dimension_matriz(&dimension, numero_nivel);
    mostrar_terreno(terreno, dimension);
    max_fil=dimension-1;
    max_col=dimension-1;
    if(movimiento == ROTACION_HORARIA){
        aux = pos_jugador->col;
        pos_jugador->col = abs((pos_jugador->fil-dimension));
        pos_jugador->fil = aux;
        for (int i = 0; i < niveles->tope_paredes; i++){
            aux = niveles->paredes[i].col;
            niveles->paredes[i].col = abs((niveles->paredes[i].fil - max_fil));
            niveles->paredes[i].fil = aux;
        }
        for (int i = 0; i < niveles->tope_obstaculos; i++){
            aux = niveles->obstaculos[i].posicion.col;
            niveles->obstaculos[i].posicion.col = abs(niveles->obstaculos[i].posicion.fil - max_fil);
            niveles->obstaculos[i].posicion.fil = aux;
        }
        for (int i = 0; i < niveles->tope_herramientas; i++){
            aux = niveles->herramientas[i].posicion.col;
            niveles->herramientas[i].posicion.col = abs(niveles->herramientas[i].posicion.fil - max_fil);
            niveles->herramientas[i].posicion.fil = aux;
        }
        for (int i = 0; i < niveles->tope_papeleos; i++){
            aux = niveles->papeleos[i].posicion.col;
            niveles->papeleos[i].posicion.col = abs(niveles->papeleos[i].posicion.fil - max_fil);
            niveles->papeleos[i].posicion.fil = aux;
        }
    }
    else if (movimiento == ROTACION_ANTI_HORARIA)
    {
        aux = (pos_jugador->fil);

        pos_jugador->fil = abs((pos_jugador->col - max_col));

        pos_jugador->col = aux;

        for (int i = 0; i < niveles->tope_paredes; i++)
        {
            aux = niveles->paredes[i].fil;

            niveles->paredes[i].fil = abs(niveles->paredes[i].col - max_col);

            niveles->paredes[i].col = aux;
        }
        for (int i = 0; i < niveles->tope_obstaculos; i++)
        {
            aux = niveles->obstaculos[i].posicion.fil;

            niveles->obstaculos[i].posicion.fil = abs(niveles->obstaculos[i].posicion.col - max_col);

            niveles->obstaculos[i].posicion.col = aux;
        }
        for (int i = 0; i < niveles->tope_herramientas; i++)
        {
            aux = niveles->herramientas[i].posicion.fil;

            niveles->herramientas[i].posicion.fil = abs(niveles->herramientas[i].posicion.col - max_col);

            niveles->herramientas[i].posicion.col = aux;
        }
        for (int i = 0; i < niveles->tope_papeleos; i++)
        {
            aux = niveles->papeleos[i].posicion.fil;

            niveles->papeleos[i].posicion.fil = abs(niveles->papeleos[i].posicion.col - max_col);

            niveles->papeleos[i].posicion.col = aux;
        }
    }
    refrescar_terreno(terreno, *pos_jugador, numero_nivel, niveles, personaje_tp1);
}
        

void accion_movimiento(char terreno[MAX_FIL][MAX_COL], juego_t* juego, char movimiento){
    bool pudo_hacer_el_ansiado_movimiento = false;
    if((movimiento == MOVIMIENTO_DERECHA) && checkear_movimiento(terreno, juego->jugador.posicion.fil, juego->jugador.posicion.col+1)){
        pudo_hacer_el_ansiado_movimiento = true;
        intercambiar_objeto(terreno, ESPACIO, juego->jugador.posicion.fil, juego->jugador.posicion.col);
        juego->jugador.posicion.col++;
        juego->jugador.movimientos--;
        juego->jugador.movimientos_realizados++;
    }else if((movimiento == MOVIMIENTO_IZQUIERDA) && checkear_movimiento(terreno, juego->jugador.posicion.fil, juego->jugador.posicion.col-1)){
        pudo_hacer_el_ansiado_movimiento = true;
        intercambiar_objeto(terreno, ESPACIO, juego->jugador.posicion.fil, juego->jugador.posicion.col);
        juego->jugador.posicion.col--;
        juego->jugador.movimientos--;
        juego->jugador.movimientos_realizados++;
    }else if(movimiento == ROTACION_ANTI_HORARIA){

        pudo_hacer_el_ansiado_movimiento = true;
        accion_rotacion(terreno, &(juego->niveles[juego->nivel_actual-1]), &(juego->jugador.posicion), juego->nivel_actual ,movimiento, juego->personaje_tp1);

        intercambiar_objeto(terreno, ESPACIO, juego->jugador.posicion.fil, juego->jugador.posicion.col);

        juego->jugador.movimientos--;
        juego->jugador.movimientos_realizados++;
    }else if(movimiento == ROTACION_HORARIA){
        pudo_hacer_el_ansiado_movimiento = true;
        accion_rotacion(terreno, &(juego->niveles[juego->nivel_actual-1]), &(juego->jugador.posicion), juego->nivel_actual ,movimiento, juego->personaje_tp1);
        intercambiar_objeto(terreno, ESPACIO, juego->jugador.posicion.fil, juego->jugador.posicion.col);

        juego->jugador.movimientos--;
        juego->jugador.movimientos_realizados++;
    }else{
        printf("NO SE PUDO MOVER");
    }

    if(pudo_hacer_el_ansiado_movimiento){
        verificar_paredes(terreno, &(juego->niveles[juego->nivel_actual-1]), juego->nivel_actual, juego->jugador.movimientos_realizados);
    }
}



void controlar_papeleo(char terreno[MAX_FIL][MAX_COL], papeleo_t papeleos[MAX_PAPELEOS], coordenada_t pos_jugador, int* cantidad_papeleos){
    if(posicionar_objeto(terreno, pos_jugador.fil, pos_jugador.col) == (char)(48 + *cantidad_papeleos)){
        papeleos[*cantidad_papeleos].recolectado = true;

        *cantidad_papeleos = *cantidad_papeleos + 1;
    }
}

void verificar_objetoi(char terreno[MAX_FIL][MAX_COL], juego_t* juego, int* cantidad_papeleos){
    int fil_jugador=juego->jugador.posicion.fil;
    int col_jugador=juego->jugador.posicion.col;
    if(posicionar_objeto(terreno, fil_jugador, col_jugador) == MEDIAS){
        juego->jugador.movimientos -=MOVIMIENTO_CHOCAR_CON_MEDIA;
    }else if(posicionar_objeto(terreno, fil_jugador, col_jugador)==FUEGO){
        juego->jugador.movimientos -=MAX_MOVIMIENTOS;
    }else if(posicionar_objeto(terreno, fil_jugador, col_jugador)==INTERRUPTORES){
        juego->jugador.ahuyenta_randall = !(juego->jugador.ahuyenta_randall);
    }else if(posicionar_objeto(terreno, fil_jugador, col_jugador)==BOTELLAS){
        juego->jugador.movimientos +=MOVIMIENTO_CHOCAR_BOTELLAS;
    }else if(posicionar_objeto(terreno, fil_jugador, col_jugador)==(char)(*cantidad_papeleos + 48)){
        controlar_papeleo(terreno, juego->niveles[juego->nivel_actual-1].papeleos, juego->jugador.posicion, cantidad_papeleos);
    }
}

/*
* Moverá el personaje , y realizará la acción necesaria en caso de chocar con un elemento
*/

void the_gravedad(char terreno[MAX_FIL][MAX_COL], juego_t* juego, int* cantidad_papeleos){
    verificar_objetoi(terreno, juego, cantidad_papeleos);
    int fil_jugador= juego->jugador.posicion.fil; 
    int j = juego->jugador.posicion.fil;
    int dimension;
    bool toco_el_piso = false;
    dimension_matriz(&dimension, juego->nivel_actual);
    while (j < dimension && !toco_el_piso){
        if(posicionar_objeto(terreno, juego->jugador.posicion.fil+1, juego->jugador.posicion.col) == PARED){
            intercambiar_objeto(terreno, ESPACIO, fil_jugador, juego->jugador.posicion.col);
            toco_el_piso = true;
        }else{
            juego->jugador.posicion.fil++;
        }
        verificar_objetoi(terreno, juego, cantidad_papeleos);
        j++;
    }
}


bool se_junto_todos_los_papeleos(papeleo_t papeleos[MAX_PAPELEOS], int tope_papeleos){
    bool se_recolecto = false;
    for (int i = 0; i < tope_papeleos; i++){
        if ((papeleos[i].recolectado == true)){
            se_recolecto = true;
        }
    }
    return se_recolecto;
}



/*
 * El nivel se dará por terminado , si se reolectan todos los papeleos en el mismo.
 * Devolverá:
 * -> 0 si el estado es jugando.
 * -> 1 si el estado es ganado.
 */
int estado_nivel(papeleo_t papeleos[MAX_PAPELEOS], int tope_papeleos){
    int j =0;
    bool posee_todos_los_papeleos = false;
    int papeleo_necesario = tope_papeleos;
    int papeleo_conseguidos = 0;
    int estado_del_juego_actual = JUGANDO;

    while((j < tope_papeleos ) && !(posee_todos_los_papeleos)){
        if (papeleos[j].recolectado){
            papeleo_conseguidos++;      
        }
        if(papeleo_conseguidos<papeleo_necesario){
            posee_todos_los_papeleos = true;
            estado_del_juego_actual = JUEGO_GANADO;
        }
        j++;
    }
    return estado_del_juego_actual;
}
bool hay_pared_al_borde(coordenada_t pared, int max_fil, int max_col){
    return((pared.col==0 || pared.fil==0 || pared.col== max_col - 1 || pared.fil  == max_fil - 1 ));
}
/*
 * Recibe un juego con todas sus estructuras válidas.
 *
 * El juego se dará por ganado , si terminó todos los niveles. O perdido , si el personaje queda
 * sin movimientos.
 * Devolverá:
 * -> 0 si el estado es jugando.
 * -> -1 si el estado es perdido.
 * -> 1 si el estado es ganado.
*/
int estado_juego(juego_t juego){
    int estado_del_juego_actual = JUGANDO;
    if(juego.jugador.movimientos<= 0){
        estado_del_juego_actual = JUEGO_PERDIDO;
        return estado_del_juego_actual;
    }
    //VERIFICO EL ULTIMO NIVEL
    if(estado_nivel(juego.niveles[MAX_NIVELES-1].papeleos, juego.niveles[MAX_NIVELES-1].tope_papeleos) == JUEGO_GANADO){
        estado_del_juego_actual = JUEGO_GANADO;
        return estado_del_juego_actual;
    }else{
        estado_del_juego_actual = JUGANDO;
        return estado_del_juego_actual;
    }
}

void transportar_papeleo(char terreno[MAX_FIL][MAX_COL], int numero_nivel, papeleo_t papeleos[MAX_PAPELEOS], int tope_papeleos){
    int papeleo_aleatorio = rand()%(tope_papeleos);
    int dimension;
    dimension_matriz(&dimension, numero_nivel);
    do{
        if(!papeleos[papeleo_aleatorio].recolectado){
            intercambiar_objeto(terreno, ESPACIO, papeleos[papeleo_aleatorio].posicion.fil, papeleos[papeleo_aleatorio].posicion.col);
            generar_papeleos(&papeleos[papeleo_aleatorio], papeleo_aleatorio,dimension);
        }else{
            papeleo_aleatorio = rand() % (tope_papeleos);
        }
        
    }while(sobra_espacio(terreno, papeleos[papeleo_aleatorio].posicion));
    
}

void accion_randall(char terreno[MAX_FIL][MAX_COL],jugador_t jugador, int numero_nivel, papeleo_t papeleos [MAX_PAPELEOS], int tope_papeleo){
    if((numero_nivel == NIVEL_1) && (jugador.movimientos_realizados !=0) && !(jugador.ahuyenta_randall) && (jugador.movimientos_realizados % divisible_randall_nivel_1 == 0)){
       transportar_papeleo(terreno, numero_nivel, papeleos, tope_papeleo); 
    }else if((numero_nivel == NIVEL_2) && (jugador.movimientos_realizados !=0) && !(jugador.ahuyenta_randall) && (jugador.movimientos_realizados % divisible_randall_nivel_2 == 0)){
        transportar_papeleo(terreno, numero_nivel, papeleos, tope_papeleo);
    }else if((numero_nivel == NIVEL_3) && (jugador.movimientos_realizados !=0) && !(jugador.ahuyenta_randall) && (jugador.movimientos_realizados % divisible_randall_nivel_3 == 0)){
        transportar_papeleo(terreno, numero_nivel, papeleos, tope_papeleo);
    }
}

int indice_de_la_pared(coordenada_t pared[MAX_PAREDES], int tope_paredes, int fil_pared, int col_pared){
    int j = 0;
    bool se_encontro = false;
    while (j < tope_paredes && se_encontro == true){
        if (pared[j].fil == fil_pared && pared[j].col == col_pared){
            se_encontro = true;

        }
        j++;
    }
    return (j-1);
}

int indice_del_fuego(objeto_t obstaculos[MAX_OBSTACULOS], int tope_obstaculos, int fil_fuego, int col_fuego){
    int j = 0;
    bool se_encontro = false;
    while (j < tope_obstaculos && se_encontro == true){
        if ((obstaculos[j].posicion.fil == fil_fuego) && (obstaculos[j].posicion.col == col_fuego)){
            se_encontro = true;
        }
        j++;
    }
    return (j-1);
}


int pos_cercana_a_la_pared(char terreno[MAX_FIL][MAX_COL], coordenada_t paredes[MAX_PAREDES], int tope_paredes, int numero_nivel, char movimiento, coordenada_t pos_jugador){
    int indicador = NO_SE_ENCONTRO, dimension;
    dimension_matriz(&dimension, numero_nivel);
    if(movimiento == MARTILLAR_ABAJO || movimiento == MARTILLAR_ARRIBA || movimiento == MARTILLAR_DERECHA || movimiento == MARTILLAR_IZQUIERDA){
        if(movimiento == MARTILLAR_ARRIBA && posicionar_objeto(terreno, pos_jugador.fil-1, pos_jugador.col) == PARED){
            indicador = indice_de_la_pared(paredes, tope_paredes, pos_jugador.fil-1, pos_jugador.col);
        }else if(movimiento == MARTILLAR_ABAJO && posicionar_objeto(terreno, pos_jugador.fil+1, pos_jugador.col) == PARED){
            indicador = indice_de_la_pared(paredes, tope_paredes,pos_jugador.fil+1, pos_jugador.col);
        }else if(movimiento == MARTILLAR_DERECHA && posicionar_objeto(terreno, pos_jugador.fil, pos_jugador.col+1) == PARED){
            indicador = indice_de_la_pared(paredes, tope_paredes,pos_jugador.fil, pos_jugador.col+1);
        }else if(movimiento == MARTILLAR_IZQUIERDA && posicionar_objeto(terreno, pos_jugador.fil, pos_jugador.col-1) == PARED){
            indicador = indice_de_la_pared(paredes, tope_paredes,pos_jugador.fil, pos_jugador.col-1);
        }
        if (!hay_pared_al_borde(paredes[indicador], dimension, dimension)){
            return indicador;
        }
    }
    return NO_SE_ENCONTRO;
}

void eliminar_pared(char terreno[MAX_FIL][MAX_COL], int numero_nivel, nivel_t* niveles,jugador_t* jugador, char movimiento_martillo){
    int pared = pos_cercana_a_la_pared(terreno, niveles->paredes, niveles->tope_paredes, numero_nivel, movimiento_martillo, jugador->posicion); 
    if(pared != NO_SE_ENCONTRO){
        intercambiar_objeto(terreno, ESPACIO, niveles->paredes[pared].fil, niveles->paredes[pared].col);

        niveles->paredes[pared] = niveles->paredes[niveles->tope_paredes-1];
        niveles->tope_paredes--;
        jugador->martillos =jugador->martillos-1;
    }else{
        printf("NO SE PUDO REALIZAR LA ACCION , INTENTALO DE VUELTA");
    }
}

void accion_martillo(char terreno[MAX_FIL][MAX_COL], juego_t* juego){
    char movimiento_martillo;
    if(juego->jugador.martillos<=0){
        printf("NO TIENES NINGUN MARTILLO, VETE DE AQUÍ");
    }else{
        printf("Hacia donde deseas realizar el movimiento del martillo\n");
        printf("Martillar izquierda: ’A’.\nMartillar derecha: ’D’.\nMartillar hacia arriba: 'W'.\nMartillar hacia abajo: 'S'.\n");
        scanf(" %c", &movimiento_martillo);
        eliminar_pared(terreno , juego->nivel_actual, &(juego->niveles[juego->nivel_actual-1]), &(juego->jugador), movimiento_martillo);
    }

}


int pos_cercana_fuego(char terreno[MAX_FIL][MAX_COL], objeto_t obstaculo[MAX_OBSTACULOS], int tope_obstaculo, char movimiento, coordenada_t pos_jugador){
    int indicador;
    if(movimiento == MOVIMIENTO_DERECHA || movimiento == MOVIMIENTO_IZQUIERDA || movimiento == MOVIMIENTO_ARRIBA){
        if(movimiento == MOVIMIENTO_ARRIBA && posicionar_objeto(terreno, pos_jugador.fil-1, pos_jugador.col) == FUEGO){
            indicador = indice_del_fuego(obstaculo, tope_obstaculo, pos_jugador.fil-1, pos_jugador.col);
            
        }else if(movimiento == MOVIMIENTO_DERECHA && posicionar_objeto(terreno, pos_jugador.fil, pos_jugador.col+1) == FUEGO){
            indicador = indice_del_fuego(obstaculo, tope_obstaculo, pos_jugador.fil, pos_jugador.col+1);

        }else if(movimiento == MOVIMIENTO_IZQUIERDA && posicionar_objeto(terreno, pos_jugador.fil, pos_jugador.col-1) == FUEGO){
            indicador = indice_del_fuego(obstaculo, tope_obstaculo, pos_jugador.fil, pos_jugador.col-1);
        }
    }
    return indicador;
}

void desaparecer_fuego(char terreno[MAX_FIL][MAX_COL], juego_t* juego, char movimiento, int numero_nivel){
    int fuego = pos_cercana_fuego(terreno, juego->niveles[juego->nivel_actual-1].obstaculos, juego->niveles[juego->nivel_actual-1].tope_obstaculos, movimiento, juego->jugador.posicion);
    int dimension;
    dimension_matriz(&dimension, numero_nivel);
    if(fuego != NO_SE_ENCONTRO){
        intercambiar_objeto(terreno, ESPACIO, juego->niveles[juego->nivel_actual-1].obstaculos[fuego].posicion.fil, juego->niveles[juego->nivel_actual-1].obstaculos[fuego].posicion.col);
        juego->niveles[juego->nivel_actual-1].obstaculos[fuego] = juego->niveles[juego->nivel_actual-1].obstaculos[juego->niveles[juego->nivel_actual-1].tope_obstaculos-1];
        juego->jugador.extintores = juego->jugador.extintores-1;
        juego->niveles[juego->nivel_actual-1].tope_obstaculos--;
    }else{
        printf("NO SE PUDO REALIZAR LA ACCION , INTENTALO DE VUELTA");
    }
}

void accion_extintor(char terreno[MAX_FIL][MAX_COL], juego_t* juego){
    char movimiento;
    if(juego->jugador.extintores<=0){
        printf("no tienes suficientes extintores");
    }else{
        printf("En que direccion deseas eliminar el FUEGO.\n ARRIBA 'W'.\n Abajo 'S'.\n DERECHA 'D'.\n IZQUIERDA 'I'.\n");
        scanf(" %c", &movimiento);
        desaparecer_fuego(terreno, juego, movimiento, juego->nivel_actual);
    }


}

void realizar_jugada(juego_t* juego){
    char movimiento;
    char terreno[MAX_FIL][MAX_COL];
    int papeleos_conseguidos, estado_actual_del_juego = JUGANDO, j=NIVEL_1;
    while (j <= MAX_NIVELES && !(estado_actual_del_juego == JUEGO_PERDIDO)){
        papeleos_conseguidos = 0;
        juego->nivel_actual = j;
        int estado_actual_del_nivel = JUGANDO;
        mostrar_elementos_e_inicializar(terreno, juego->nivel_actual, &(juego->niveles[juego->nivel_actual-1]), juego->personaje_tp1);
        while(estado_actual_del_nivel == JUGANDO && !(estado_actual_del_juego == JUEGO_PERDIDO)){
            the_gravedad(terreno, juego, &papeleos_conseguidos);
            accion_randall(terreno, juego->jugador, juego->nivel_actual, juego->niveles[juego->nivel_actual-1].papeleos, juego->niveles[juego->nivel_actual-1].tope_papeleos);
            estado_actual_del_juego = estado_juego(*juego);
            refrescar_terreno(terreno, juego->jugador.posicion,juego->nivel_actual, &(juego->niveles[juego->nivel_actual-1]), juego->personaje_tp1);

            estado_actual_del_nivel = estado_nivel(juego->niveles[juego->nivel_actual-1].papeleos, juego->niveles[juego->nivel_actual-1].tope_papeleos);
            estado_actual_del_juego = estado_juego(*juego);

            mostrar_todo(terreno, juego->nivel_actual);

            printf("ingresa un movimiento: \n");
            printf("movimiento restantes: %i\n", juego->jugador.movimientos);
            printf("movimientos realizados: %i\n", juego->jugador.movimientos_realizados);
            printf("Martillos disponibles: %i\n", juego->jugador.martillos);
            printf("Extintores disponibles: %i\n", juego->jugador.extintores);
            
            if(estado_actual_del_juego !=JUEGO_PERDIDO){
                scanf(" %c", &movimiento);    
            }
            if(movimiento == MOVIMIENTO_DERECHA){
                accion_movimiento(terreno, juego, movimiento);
            }else if(movimiento == MOVIMIENTO_IZQUIERDA){
                accion_movimiento(terreno, juego, movimiento);
            }else if(movimiento == ROTACION_HORARIA){   
                accion_movimiento(terreno, juego, movimiento);
            }else if(movimiento == ROTACION_ANTI_HORARIA){
                accion_movimiento(terreno, juego, movimiento);
            }else if(movimiento == UTILIZAR_MARTILLO){
                accion_martillo(terreno, juego);
            }else if(movimiento == UTILIZAR_EXTINTOR){
                accion_extintor(terreno, juego);
            }else{
                printf("esta tecla no esta disponible");
            }
            system("clear");
        }
        j++;
    }
}

/* 
//Pre:
 * Inicializará un nivel, cargando toda la información inicial, las paredes,
 * los objetos, los papeleos y la posición inicial del jugador en dicho nivel.
//Post:
*/
void inicializar_nivel(nivel_t* nivel, int numero_nivel, char personaje_tp1){
    char terreno[MAX_FIL][MAX_COL];
    int cant_fuego, cant_papeleo, dimension;
    dimension_matriz(&dimension, numero_nivel);

    nivel->tope_paredes = 0;
    nivel->tope_herramientas = 0;
    nivel->tope_obstaculos = 0;
    nivel->tope_papeleos = 0;

    obtener_paredes(numero_nivel, nivel->paredes, &nivel->tope_paredes, &nivel->pos_inicial_jugador);

    comprobar_obsequio_objetos(personaje_tp1, &cant_fuego, &cant_papeleo, numero_nivel);
    
    mostrar_elementos_e_inicializar(terreno, numero_nivel, nivel, personaje_tp1);
}
/*
Inicializará el juego, cargando toda la información inicial, los datos del jugador, 
el personaje resultado del tp anterior, y los 3 niveles. El campo "nivel_actual"
comienza en 1.
*/
void inicializar_juego(juego_t* juego, char personaje_tp1){
    int cant_martillo, cant_movimiento, dimension = 0;
    dimension_matriz(&dimension, juego->nivel_actual);
    juego->personaje_tp1 = personaje_tp1;

    inicializar_cada_nivel(juego);
    juego->nivel_actual = 1;
    juego->jugador.movimientos_realizados = 0;

    comprobar_obsequio_al_personaje(*juego, personaje_tp1, &cant_martillo, &cant_movimiento);
    
    inicialilizar_personaje(&juego->jugador, juego->nivel_actual, juego->niveles[juego->nivel_actual-1].pos_inicial_jugador, cant_martillo, cant_movimiento);
    realizar_jugada(juego);
}
/*
Pre:los niveles entre (1, 2, 3)
Procedimiento que recibe el juego e imprime toda su información por pantalla.
Post:muestra en la terminar todo lo correspondiente al juego
*/
void imprimir_terreno(juego_t juego){
    int dimension = 0;
    char terreno[MAX_FIL][MAX_COL];
    dimension_matriz(&dimension, juego.nivel_actual);
    //mostrar_datos_a_jugador(juego);

    inicializar_todo(terreno, &(juego.niveles[juego.nivel_actual-1]), juego.nivel_actual);

    mostrar_todo(terreno, juego.nivel_actual);
    
}







