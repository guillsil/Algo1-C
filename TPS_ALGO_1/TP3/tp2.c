#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include"utiles.h"
#include"papeleo.h"
#include"tp2.h"
/*

*/
void intercambiar_objeto(char terreno[MAX_FIL][MAX_COL], char objeto, int fil_objeto, int col_objeto){
    terreno[fil_objeto][col_objeto] = objeto;
}

/* 
//Pre:recibe dos coordenadas y si las mismas son iguales
//Post:devuelve  true si las mismas son iguales en caso contrario un false
*/
bool es_coordenada_igual(coordenada_t l, coordenada_t g){
    return (l.fil == g.fil && l.col == g.col);
}
/* 
Pre: pide las coordenadas del vector paredes junto a su tope y la coordenada del objeto a comparar;
Post:busca en el vector paredes si coincide con alguna posision del objeto, devuelve true si coincide con una las paredes.
*/
bool es_pared(nivel_t* nivel, coordenada_t objeto){
    bool existe = false;
    for (int j = 0; j < nivel->tope_paredes; j++){
        if (es_coordenada_igual(nivel->paredes[j], objeto)){
            existe = true;
        }   
    }
    return existe;
}
/*
Pre:Recibe la matriz terreno y una coordenada
Post:Devuelve true si la coodenada recibida se encuentra vacia en la matriz, en cualquier otro caso devuelve false
*/
bool es_coordenada_valida(char terreno[MAX_FIL][MAX_COL], coordenada_t posicion){
    return terreno[posicion.fil][posicion.col] == ESPACIO;
}
/*
Pre:Función que recibe dos coordenadas, 
Post:devuelve true si las coordenadas son iguales, sino false.
*/
int distancia_manhatann(coordenada_t a, coordenada_t b){
    int distancia;
    distancia = abs(a.fil - b.fil) + abs(a.col - b.col);
    return distancia;
}

/* 
//Pre:recibe el vector del objeto a comparar , los vectores herramientas, obstaculos  con sus respectivos topes
//Post:si no encuentra ningun elemento devolvera un true.
*/
bool es_coordenada_libre(coordenada_t objeto, nivel_t nivel){
    bool disponible= true;
    if ((buscar_objeto(nivel.herramientas, nivel.tope_herramientas, objeto) != -1 || buscar_objeto(nivel.obstaculos, nivel.tope_obstaculos, objeto)!= -1)){
        disponible = false;
    }
    return disponible;
}
/*

*/
char posicionar_objeto(char terreno[MAX_FIL][MAX_COL], int fil_objeto, int col_objeto){
    return terreno[fil_objeto][col_objeto];
}
/* 
//Pre:Dados dos numeros, un max y un min, que representa el rango a crear de una coordenada,  
//Post:vevolvera una coordenada aleatoria entre ambos extremos , los cuales no pueden ser mayores ni menores a sus extremos 
*/
coordenada_t coordenada_aleatoria(int max_fil, int max_col){
    coordenada_t posicion_aleatoria;
    posicion_aleatoria.fil = rand() % max_fil;
    posicion_aleatoria.col = rand() % max_col;
    return posicion_aleatoria;
}
/*
    recibe una matriz y una coordenada
Pre:la matriz debe estar completa 
Post: se encarga de ver si en todos los lados de las coordenadas(arriba, abajo, derecha, izquierda) la coordenada esta cerca de una pared en caso afirmativo devuelve true.
*/
bool verificador_de_lados(char terreno[MAX_FIL][MAX_COL], coordenada_t posicion){
    return ((terreno[posicion.fil - 1][posicion.col] == PARED) || (terreno[posicion.fil + 1][posicion.col] == PARED) || (terreno[posicion.fil][posicion.col - 1] == PARED) || (terreno[posicion.fil][posicion.col + 1] == PARED));
}
/*  
Pre:recibe la matriz terreno y una coordenada
Post:verifica las dos funciones es_coordenada_valida y verificador_de_lados en caso que ambas esteen correctas devolvera un true.
*/
bool fuegos_adyacentes(char terreno[MAX_FIL][MAX_COL], coordenada_t posicion){
    return es_coordenada_valida(terreno, posicion) && verificador_de_lados(terreno, posicion);
}
/* 
//Pre:recibe el nivel(el nivel tiene que estar entre 0 y 2) en el cual se encuentra el juego 
//Post: y muestra la dimension del mismo la cual debe estar entre 22, 17, 12
*/
void dimension_matriz(int* dimension, int nivel){
    if (nivel == NIVEL_1){
        *dimension = SIZE_NIVEL_1;
    } else if (nivel == NIVEL_2){
        *dimension = SIZE_NIVEL_2;
    } else if (nivel == NIVEL_3){
        *dimension = SIZE_NIVEL_3;
    }
}
/*
Pre:Recibe el struct objeto_t , el tipo de objeto a crear y la dimension de la matriz
Post:Devolvera una coordenada aleatoria de acuerdo la dimension antes suministrada.
*/
void generar_herramientas_y_obstaculos(objeto_t* elemento, char tipo, int dimension){
    elemento->posicion = coordenada_aleatoria(dimension, dimension);
    elemento->tipo = tipo;
}
/* 
Pre:Recibe el struct de papaleo_t , el id del papeleo y la dimension del nivel a crear
Post:Asiganara un valor al id , una coordenada aleatoria al papeleo y lo pondra en recolectado = false.
*/
void generar_papeleos(papeleo_t* papeleo, int id_papeleo, int dimension){
    papeleo->id_papeleo = id_papeleo;
    papeleo->posicion = coordenada_aleatoria(dimension, dimension);
    papeleo->recolectado = false;
}
/* 
Pre:Recibe la matriz terreno, el objeto a crear , con su tipo ,el struct del objeto con su tope, y la dimension del correspondiente nivel
Post:Cargara el tipo de objeto a la matriz , y en caso de ser fuego tendra que verificar que se cumpla lo de abyacencia con las paredes
*/
void generar_elemento(char terreno[MAX_FIL][MAX_COL], int objeto_crear, char tipo,  objeto_t objeto[MAX_OBJETOS], int *tope_objeto, int dimension){
    if(tipo != FUEGO){
        for (int i = (*tope_objeto); i < objeto_crear; i++){
        do{
            generar_herramientas_y_obstaculos(&objeto[i], tipo, dimension);
        } while (!es_coordenada_valida(terreno, objeto[i].posicion));

        (*tope_objeto)++;
        terreno[objeto[i].posicion.fil][objeto[i].posicion.col] = objeto[i].tipo;
        }
    }else if(tipo == FUEGO){
        for (int i = (*tope_objeto); i < objeto_crear; i++){
        do{
            generar_herramientas_y_obstaculos(&objeto[i], tipo, dimension);
        } while (!fuegos_adyacentes(terreno, objeto[i].posicion));

        (*tope_objeto)++;
        terreno[objeto[i].posicion.fil][objeto[i].posicion.col] = objeto[i].tipo;
        }
    }
    
}
/* 
//Pre:Recibe la matriz terreno , el struct objeto_t juntoa su tope y el numero del nivel.
//Post:Inicializa las cantidades de herramientas segun el nivel y genera las herramientas .
*/
void inicializar_herramientas(char terreno[MAX_FIL][MAX_COL], objeto_t herramientas[MAX_HERRAMIENTAS], int *tope_herramientas, int numero_nivel){
    int cantidad_botellas, cantidad_interruptores, herramienta_crear, dimension;
    dimension_matriz(&dimension, numero_nivel);
    if (numero_nivel == NIVEL_1){
        cantidad_botellas = CANTIDAD_BOTELLAS_1;
        cantidad_interruptores = CANTIDAD_INTERRUPTORES_1;
    } else if(numero_nivel == NIVEL_2){
        cantidad_botellas = CANTIDAD_BOTELLAS_2;
        cantidad_interruptores = CANTIDAD_INTERRUPTORES_2;
    } else if(numero_nivel == NIVEL_3){
        cantidad_interruptores = CANTIDAD_INTERRUPTORES_3;
        cantidad_botellas = CANTIDAD_BOTELLAS_3;
    } 
    herramienta_crear = cantidad_interruptores + (*tope_herramientas);
    generar_elemento(terreno, herramienta_crear, INTERRUPTORES, herramientas, tope_herramientas, dimension);
    herramienta_crear = cantidad_botellas + (*tope_herramientas);
    generar_elemento(terreno, herramienta_crear, BOTELLAS, herramientas, tope_herramientas, dimension);
} 
/* 
Pre:Recibe la matriz terreno, el struct de juego por referencia para ser cambiado por sus valores correspondientes segun el nivel que corresponda
Post:Genera los obstaculos de acuerdo al nivel, cantidad y tipo.
*/
void inicializar_obstaculos(char terreno[MAX_FIL][MAX_COL], objeto_t obstaculos[MAX_OBSTACULOS], int *tope_obstaculo, int numero_nivel, int cant_fuego){
    int cantidad_medias, cantidad_fuego, dimension,obstaculos_crear;
    dimension_matriz(&dimension, numero_nivel);
    if (numero_nivel == NIVEL_1){
        cantidad_medias = CANTIDAD_MEDIAS_1;
        cantidad_fuego = cant_fuego;
    }else if(numero_nivel == NIVEL_2){
        cantidad_medias = CANTIDAD_MEDIAS_2;
        cantidad_fuego = cant_fuego;
    }else if(numero_nivel == NIVEL_3){
        cantidad_medias = CANTIDAD_MEDIAS_3;
        cantidad_fuego = cant_fuego;
    }
    obstaculos_crear = cantidad_fuego + (*tope_obstaculo);
    generar_elemento(terreno, obstaculos_crear, FUEGO, obstaculos, tope_obstaculo, dimension);
    obstaculos_crear = cantidad_medias + (*tope_obstaculo);
    generar_elemento(terreno, obstaculos_crear,MEDIAS, obstaculos, tope_obstaculo, dimension);
}
/* 
Pre:Recibe la matriz terreno , los papeleos junto a su tope , el nivel la cantidad de papeleo que ya viene determinado segun el nivel
Post:Cargara la cantidad de papeleos segun el nivel en la matriz y verificara que esta no se imprima sobre otro objeto o pared.
*/
void inicializar_papeleos(char terreno[MAX_FIL][MAX_COL], papeleo_t papeleos[MAX_PAPELEOS], int *tope_papeleos, int numero_nivel, int cant_papeleo){
    int dimension;
    dimension_matriz(&dimension, numero_nivel);
    for (int i = 0; i < cant_papeleo; i++){
        do{
            generar_papeleos(&papeleos[i], i, dimension);
        } while (!es_coordenada_valida(terreno, papeleos[i].posicion));
        (*tope_papeleos)++;
        terreno[papeleos[i].posicion.fil][papeleos[i].posicion.col] = PAPELEO;
    }
}
/*
Pre:Recibe el nivel, y las cantidades de fuegos y papeleos ,si los personajes no son Stith o Olaf
Post:Completara las cantidades prederteminadas para cada nivel.
*/
void asignar_cantidades_de_fuegos_y_papeleos_predermiminado(int numero_nivel, int* cant_fuego, int* cant_papeleo){
     if(numero_nivel == NIVEL_1){
        *cant_fuego = CANTIDAD_FUEGOS_1;
        *cant_papeleo = CANTIDAD_PAPELEO_1;
    }else if(numero_nivel == NIVEL_2){
        *cant_fuego = CANTIDAD_FUEGOS_2;
        *cant_papeleo = CANTIDAD_PAPELEO_2;
     }else if(numero_nivel == NIVEL_3){
        *cant_fuego = CANTIDAD_FUEGOS_3;
        *cant_papeleo = CANTIDAD_PAPELEO_3;
     }
}
/*
Pre:Recibe el nivel, y las cantidades de fuegos y papeleos ,si los personajes no son Jasmin o Rayo
Post::Completara las cantidades prederteminadas para cada nivel.
*/
void asignar_obsequio_al_personaje_normal(int nivel,int*  cant_martillo, int* cant_movimiento){
    if(nivel == NIVEL_1){
        *cant_martillo = CANTIDAD_MARTILLOS_1;
        *cant_movimiento = CANTIDAD_MOVIMIENTO_NIVEL_1;
    }else if(nivel == NIVEL_2){
        *cant_martillo = CANTIDAD_MARTILLOS_2;
        *cant_movimiento = CANTIDAD_MOVIMIENTO_NIVEL_2;
    }else if(nivel == NIVEL_3){
        *cant_martillo = CANTIDAD_MARTILLOS_3;
        *cant_movimiento = CANTIDAD_MOVIMIENTO_NIVEL_3;
    }
}
/*
Pre:En caso que los personajes sean Stitch o Olaf 
Post:Se Aplicara los obsequios siguientes:
Stitch:Restara dos fuegos del primer nivel y uno del segundo nivel.
Olaf:Restara un papeleo del ultimo nivel.
*/
void asignar_cantidades_de_fuegos_y_papeleos(int nivel,char amigo_pide_favor, int* cant_fuego, int* cant_papeleo){
    if(amigo_pide_favor == PERSONAJE_OLAF || amigo_pide_favor == PERSONAJE_STITCH){
        if(nivel == NIVEL_1){
            *cant_fuego = (CANTIDAD_FUEGOS_1 - FUEGO_BORRAR_PRIMER_N);
            *cant_papeleo = CANTIDAD_PAPELEO_1;
        }else if(nivel == NIVEL_2){
            *cant_fuego = (CANTIDAD_FUEGOS_2 - FUEGO_BORRAR_SEGUNDO_N);
            *cant_papeleo = CANTIDAD_PAPELEO_2;
        }else if(nivel == NIVEL_3){
            *cant_fuego = CANTIDAD_FUEGOS_3;
            *cant_papeleo = (CANTIDAD_PAPELEO_3 - PAPELEO_RESTAR_TERCER_N);
        }
    }
}
/*
Pre:En caso que los personajes sean Jasmin o Rayo.
Post:Se Aplicara los obsequios siguientes:
Jasmin:un martillo extra por cada nivel.
Rayo:10 movimientos extras en el primer nivel.
*/
void asignar_obsequio_al_personaje(int nivel,char amigo_pide_favor,int*  cant_martillo, int* cant_movimiento){
    if(amigo_pide_favor == PERSONAJE_JASMIN || amigo_pide_favor == PERSONAJE_RAYO){
        if(nivel == NIVEL_1){
            *cant_martillo = CANTIDAD_MARTILLOS_1 + MARTILLO_EXTRA;
            *cant_movimiento = CANTIDAD_MOVIMIENTO_NIVEL_1 + MOVIMIENTO_EXTRA_PRIMER_N;
        }else if(nivel == NIVEL_2){
            *cant_martillo = CANTIDAD_MARTILLOS_2 + MARTILLO_EXTRA;
            *cant_movimiento = CANTIDAD_MOVIMIENTO_NIVEL_2;
        }else if(nivel == NIVEL_3){
            *cant_martillo = CANTIDAD_MARTILLOS_3 + MARTILLO_EXTRA;
            *cant_movimiento = CANTIDAD_MOVIMIENTO_NIVEL_3;
        }    
    }
}
/* 
Pre:recive el struct de juego, el nivel, la pos_jugador y las cantidades de martillos y movimientos
Post:aplicara los obsequios en caso que el personaje sea Jasmin o Rayo, tambien carga los demas elementos de la mochila 
 */
void inicialilizar_personaje(jugador_t* jugador, int nivel_actual,coordenada_t pos_jugador,  int  cant_martillo, int cant_movimiento){    
    if (nivel_actual == NIVEL_1){
        jugador->movimientos = cant_movimiento;
        jugador->martillos = cant_martillo;
        jugador->posicion = pos_jugador;
        jugador->extintores = CANTIDAD_EXTINTORES_1;
        jugador->ahuyenta_randall = false;
    } else if(nivel_actual == NIVEL_2){
        jugador->movimientos = cant_movimiento;
        jugador->martillos = cant_martillo;
        jugador->posicion = pos_jugador;
        jugador->extintores = CANTIDAD_EXTINTORES_2;
        jugador->ahuyenta_randall = false;
    } else if (nivel_actual == NIVEL_3){
        jugador->movimientos = cant_movimiento;
        jugador->martillos = cant_martillo;
        jugador->posicion = pos_jugador;
        jugador->extintores = CANTIDAD_EXTINTORES_3;
        jugador->ahuyenta_randall = false;
    }
}
/* 
//Pre:
//Post:Muestra el obsequio obtenido en pantalla
*/
void obsequio_del_jugador(char personaje_tp1, char nombre[MAX_LETRAS], char obsequio[MAX_LETRAS]){
    if (personaje_tp1 == PERSONAJE_JASMIN){
        strcpy(obsequio, "Tenes un martillo extra por cada nivel");
        strcpy(nombre, "JASMIN");       
    } else if(personaje_tp1 == PERSONAJE_OLAF ){
        strcpy(obsequio, "Se te extinguen dos fuegos fuego del primer nivel y uno del segundo");
        strcpy(nombre, "OLAF");
    } else if(personaje_tp1 == PERSONAJE_RAYO){
        strcpy(obsequio, "Tenes 10 movimientos al iniciar el nivel");
        strcpy(nombre, "RAYO");
    } else if(personaje_tp1 == PERSONAJE_STITCH){
        strcpy(obsequio, "Tenes una pistolita , la cual quema un papeleo del último nivel");
        strcpy(nombre,"STITCH");
    }
}
/* 
//Pre:recibe un vector objeto con el tope y la coordenada a comparar 
//Post:si en el caso de que se encuentre una coordenada del vector objeto similar al de la posicion pasada entonces 
    devolvera la posicion del objeto que coincidieron y en caso contrario devolvera un -1.
*/
int buscar_objeto(objeto_t objeto[MAX_OBJETOS], int tope, coordenada_t posicion){
    int posicion_objeto = NO_ENCONTRADO, i = 0;
    bool econtrado = false;
    while ((i<tope) && (econtrado == false)){
        if (es_coordenada_igual(posicion, objeto[i].posicion)== true){
            posicion_objeto =i;
            econtrado = true;
        }
        i++;
    }
    return posicion_objeto;
}
/*
Pre:Recibe la matriz terreno , el struct del objeto junto a su tope
Post:Se encarga de rellenar la matriz con el objeto recibido.
*/
void mostrar_objeto(char terreno[MAX_FIL][MAX_COL], objeto_t objeto[MAX_OBSTACULOS], int tope_objeto){
    for (int i = 0; i < tope_objeto; i++){
        terreno[objeto[i].posicion.fil][objeto[i].posicion.col] = objeto[i].tipo;
    }
}
/* 
Pre:Recibe la matriz terreno , el struct de papeleo_t junto a su tope
Post: Muestra los papeleos en la matriz.
*/
void mostrar_papeleos(char terreno[MAX_FIL][MAX_COL], papeleo_t papeleos[MAX_PAPELEOS], int tope_papeleos){
    for (int i = 0; i < tope_papeleos; i++){
        terreno[papeleos[i].posicion.fil][papeleos[i].posicion.col] = PAPELEO;
    }
}
/*
Pre:Recibe el struct juego_t
Post:Se encargara de imprimir en la consola el obsequio obtenido, las cantidades de herramientas en la mochila y el personaje que se le asigno al principio.
*/
void mostrar_datos_a_jugador(juego_t juego){
    char nombre[MAX_LETRAS];
    char obsequio[MAX_LETRAS];
    obsequio_del_jugador(juego.personaje_tp1, nombre, obsequio);
    printf("-----------------------------------------------------------------\n");
    printf("-------------   Tu PERSONAJE ES : %s  -----------------------\n", nombre);
    printf("-----------------------------------------------------------------\n");
    printf("-----------------------------------------------------------------\n");
    printf("----TU OBSEQUIO ES: %s-------\n", obsequio);
    printf("-----------------------------------------------------------------\n");
    printf("-----------------------------------------------------------------\n");
    printf("--------------   CANTIDAD DE MARTILLOS: %i -----------------------\n", juego.jugador.martillos);
    printf("-----------------------------------------------------------------\n");  
    printf("-----------------------------------------------------------------\n");
    printf("--------------  CANTIDAD DE EXTINTORES: %i -----------------------\n", juego.jugador.extintores);
    printf("-----------------------------------------------------------------\n");  
}
/* 
Pre:Recibe la matriz terreno y la pos_jugador
Post:Muestra al perosnaje en la matriz
*/
void mostrar_jugador(char terreno[MAX_FIL][MAX_COL], coordenada_t pos_jugador){
    terreno[pos_jugador.fil][pos_jugador.col] = PERSONAJE_JUEGO;

}
/* 
//Pre:Recibe la matriz con la dimension de del nivel a mostrar (la dimension debe ser 22, 17, 12)
//Post:Mostrara en la pantalla un espacio , para que que la matriz noce inicie con basura
*/
void mostrar_terreno(char terreno[MAX_FIL][MAX_COL], int dimension){
    for (int i = 0; i < dimension; i++){
        for (int j = 0; j <dimension; j++){
            terreno[i][j] = ESPACIO;
        }
    }
}
/* 
Pre:Le ingresa la matriz terreno , las coordenadas de las paredes junto a su tope.
Post:Mostrara las paredes en la matriz.
*/
void mostrar_paredes(char terreno[MAX_FIL][MAX_COL], coordenada_t paredes[MAX_PAREDES],int tope_pared){
    for (int i = 0; i < tope_pared; i++){
        terreno[paredes[i].fil][paredes[i].col] = PARED;
    }
}
/*
Pre:Recibe la matriz terreno y el numero del nivel
Post:Inprimira todo los puesto en la matriz en el terreno de juego.
*/
void mostrar_todo(char terreno[MAX_FIL][MAX_COL], int numero_nivel){
    int dimension;
    dimension_matriz(&dimension, numero_nivel);
    for (int i = 0; i < dimension; i++){
        printf("| ");
        for (int j = 0; j < dimension; j++){
            printf("%c", terreno[i][j]);
            printf(" ");
        }
        printf("\n");
    }
}
/*
Pre:Le ingresa el struct juego_t , el personaje_tp1 y las cantidades de los martillos y movimientos
Post:Segun el personaje del tp anterior le asigna el valor a la cantidad de martillos y movimiento, en el caso que el personaje sea Jasmin agregara un martillo extra en cada nivel , si es el Rayo 10 movimientos extras para el primer nivel, cualquier otro distinto a estos se le aplicara las cantidades prederteminadas
*/
void comprobar_obsequio_al_personaje(juego_t juego, char personaje_tp1, int* cant_martillo, int* cant_movimiento){
    if(personaje_tp1 == PERSONAJE_JASMIN || personaje_tp1 == PERSONAJE_RAYO ){
        asignar_obsequio_al_personaje(juego.nivel_actual, personaje_tp1, cant_martillo, cant_movimiento);
    }else if(personaje_tp1 == PERSONAJE_OLAF || personaje_tp1 == PERSONAJE_STITCH){
        asignar_obsequio_al_personaje_normal(juego.nivel_actual, cant_martillo, cant_movimiento);
    }
}
/*
Pre:Le ingresa el personaje obtenido , las cantidades de fuegos y papeleos que fueron creados anteriormente segun el nivel , tambien recibe el nivel.
Post:Si el personaje es Olaf o Sitch, entonce s se aplica lo siguiente:
Olaf:extingue dos fuegos del primer nivel y uno del segundo.
Stitch:con su pistolita elimina un papeleo del ultimo nivel. 
*/
void comprobar_obsequio_objetos(char personaje_tp1, int* cant_fuego, int* cant_papeleo, int numero_nivel){
    if(personaje_tp1 == PERSONAJE_OLAF || personaje_tp1 == PERSONAJE_STITCH){
        asignar_cantidades_de_fuegos_y_papeleos(numero_nivel, personaje_tp1, cant_fuego, cant_papeleo);
    }else if(personaje_tp1 == PERSONAJE_JASMIN || personaje_tp1 == PERSONAJE_RAYO ){
        asignar_cantidades_de_fuegos_y_papeleos_predermiminado(numero_nivel, cant_fuego, cant_papeleo);
    }
}


/*
Pre:Recibe la matriz terreno el nivel el struct de niveles y las cantidades de fuego y papeleo .
Post:Se encargara de mostrar(pone los objetos, paredes y al jugador en la matriz) e inicializar las funciones que se inician en inicializar_nivel.
*/
void mostrar_elementos_e_inicializar(char terreno[MAX_FIL][MAX_COL], int numero_nivel, nivel_t* nivel, char personaje_tp1){
    int dimension, cant_fuego, cant_papeleo;
    comprobar_obsequio_objetos(personaje_tp1, &cant_fuego, &cant_papeleo, numero_nivel);
    dimension_matriz(&dimension, numero_nivel);
    mostrar_terreno(terreno, dimension);
    mostrar_paredes(terreno, nivel->paredes, nivel->tope_paredes);
    mostrar_jugador(terreno, nivel->pos_inicial_jugador); 

    inicializar_obstaculos(terreno, nivel->obstaculos, &nivel->tope_obstaculos, numero_nivel, cant_fuego);
    inicializar_herramientas(terreno, nivel->herramientas, &nivel->tope_herramientas, numero_nivel);
    inicializar_papeleos(terreno, nivel->papeleos, &nivel->tope_papeleos, numero_nivel, cant_papeleo);   
}

void refrescar_terreno(char terreno[MAX_FIL][MAX_COL], coordenada_t pos_jugador, int numero_nivel, nivel_t* nivel, char personaje_tp1){
    int dimension, cant_fuego, cant_papeleo;
    comprobar_obsequio_objetos(personaje_tp1, &cant_fuego, &cant_papeleo, numero_nivel);
    dimension_matriz(&dimension, numero_nivel);
    
    mostrar_paredes(terreno, nivel->paredes, nivel->tope_paredes);
    //actualizo el jugador
    mostrar_jugador(terreno, nivel->pos_inicial_jugador);
    inicializar_obstaculos(terreno, nivel->obstaculos, &nivel->tope_obstaculos, numero_nivel, cant_fuego);
    inicializar_herramientas(terreno, nivel->herramientas, &nivel->tope_herramientas, numero_nivel);
    inicializar_papeleos(terreno, nivel->papeleos, &nivel->tope_papeleos, numero_nivel, cant_papeleo);
    

}
/*
Pre:Le ingresa el struct juego_t , el nivel puede ser hasta 3
Post:Inicializa el nivel, con todas sus elmentos a definir.
*/
void inicializar_cada_nivel(juego_t* juego){
    for (int i = 1; i <= MAX_NIVELES; i++){
        juego->nivel_actual = i;
        inicializar_nivel(&juego->niveles[juego->nivel_actual-1], juego->nivel_actual, juego->personaje_tp1);
    }
}
/*
Pre:Recibela matriz terreno, el struct nivel_t con el numero de nivel
Post:Se encarga de llamar a todas las funciones siguientes (mostrar_terreno, mostrar_paredes, mostrar_jugador, mostrar_objeto, mostrar_papeleos), los cuales rellenan la matriz terreno[MAX_FIL][MAX_COL].
*/
void inicializar_todo(char terreno[MAX_FIL][MAX_COL], nivel_t *nivel , int numero_nivel){
    int dimension;
    dimension_matriz(&dimension, numero_nivel);

    mostrar_terreno(terreno, dimension);
    mostrar_paredes(terreno, nivel->paredes, nivel->tope_paredes);
    mostrar_jugador(terreno, nivel->pos_inicial_jugador);
    mostrar_objeto(terreno, nivel->obstaculos, nivel->tope_obstaculos);
    mostrar_objeto(terreno, nivel->herramientas, nivel->tope_herramientas);
    mostrar_papeleos(terreno, nivel->papeleos, nivel->tope_papeleos);    
}