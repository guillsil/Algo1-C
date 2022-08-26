#include <stdio.h>
#include <stdbool.h>

const char OLAF = 'O', STITCH = 'S', JASMIN = 'J', RAYO_MCQUEEN = 'R';
const char TRINEO = 'T', NAVE_ESPACIAL = 'N', CAMION = 'C', ALFOMBRA = 'A';
const char BOLAS_DE_NIEVE = 'B', PIUM_PIUM = 'P', KUCHAU = 'K', GENIO = 'G';
const unsigned int MAX_NOTA = 10, MIN_NOTA = 1;
const unsigned int MAX_HORA = 23, MIN_HORA = 0;
const unsigned int MAX_MINUTO = 59, MIN_MINUTO = 0;
const float LIMITE_HORARIO_PARCIAL = 15.30f;
const unsigned int PUNTAJE_MAXIMO_PRIMER_GRUPO = 41, PUNTAJE_MAXIMO_SEGUNDO_GRUPO = 68;
const unsigned int PUNTAJE_1_PREGUNTA_TRANSPORTE = 10, PUNTAJE_2_PREGUNTA_TRANSPORTE = 20;
const unsigned int PUNTAJE_MEDIDA_BOLAS_NIEVE = 3, PUNTAJE_MEDIDA_PIUM_PIUM = 6, PUNTAJE_MEDIDA_KUCHAU = 9, PUNTAJE_MEDIDA_GENIO = 12;
const unsigned int MULTIPLICADOR_NOTA_BAJA = 1, MULTIPLICADOR_NOTA_MEDIA = 2, MULTIPLICADOR_NOTA_ALTA = 3, MULTIPLICADOR_NOTA_MUY_ALTA = 4;

/*
 * POST-CONDICIONES: Si el transporte recibido es uno de los 4 posibles definidos en las constantes, devuelve verdadero, si no devuelve falso
 */
bool es_posible_transporte(char transporte)
{
    return transporte == TRINEO || transporte == NAVE_ESPACIAL || transporte == CAMION || transporte == ALFOMBRA;
}
/*
 * POST-CONDICIONES: Si la medida recibida es una de las 4 posibles definidas en las constantes, devuelve verdadero, si no devuelve falso
 */
bool es_posible_medida_contra_manifestacion(char medida)
{
    return medida == BOLAS_DE_NIEVE || medida == PIUM_PIUM || medida == KUCHAU || medida == GENIO;
}
/*
 * POST-CONDICIONES: Si la hora recibida se encuentra entre los limites establecidos en las constantes, devuelve verdadero, si no devuelve falso
 */
bool es_posible_hora_llegada(unsigned int hora)
{
    return hora >= MIN_HORA && hora <= MAX_HORA;
}
/*
 * POST-CONDICIONES: Si el minuto recibido se encuentra entre los limites establecidos en las constantes, devuelve verdadero, si no devuelve falso
 */
bool es_posible_minuto_llegada(unsigned int minuto)
{
    return minuto >= MIN_MINUTO && minuto <= MAX_MINUTO;
}

/*
 * POST-CONDICIONES: Si la nota recibida se encuentra entre los limites establecidos, devuelve verdadero, si no devuelve falso
 */
bool es_posible_nota_parcial(unsigned int nota)
{
    return nota >= MIN_NOTA && nota <= MAX_NOTA;
}
/*
 * POST-CONDICIONES: Pide al usuario el transporte que va a utilizar
 */
void pedir_transporte(char *transporte)
{
    do
    {
        printf("Elija su transporte entre los posibles: (Trineo (T), Camion (C), Nave Espacial (N), Alfombra (A)) \n");

        scanf(" %c", transporte);
    } while (!es_posible_transporte((*transporte)));

    printf("perfecto, pero se ve una manifestacion a lo lejos... \n");
}

/*
 * PRE-CONDICIONES: el transporte que se elige debe estar entre uno de los 4 establecidos en las constantes
 * POST-CONDICIONES: Devuelve el primer puntaje a utilizar en la eleccion del personaje
 */
unsigned int transporte_a_usar(char transporte)
{
    unsigned int puntaje_a_devolver;

    if (transporte == TRINEO || transporte == NAVE_ESPACIAL)
    {
        puntaje_a_devolver = PUNTAJE_1_PREGUNTA_TRANSPORTE;
    }
    else if (transporte == CAMION || transporte == ALFOMBRA)
    {
        puntaje_a_devolver = PUNTAJE_2_PREGUNTA_TRANSPORTE;
    }
    else
    {
        puntaje_a_devolver = 0;
    }

    return puntaje_a_devolver;
}

/*
 * POST-CONDICIONES: Pide al usuario la medida que va a tomar contra la manifestacion
 */

void pedir_medida_contra_manifestacion(char *medida)
{
    do
    {
        printf("Elija la medida a tomar contra la manifestacion, podes elegir entre (Bolas de nieve (B), Pium pium (P), Kuchau (K), Genio (G)) \n");

        scanf(" %c", medida);
    } while (!es_posible_medida_contra_manifestacion(*medida));
}

/*
 * PRE-CONDICIONES: la medida que se le pasa debe estar entre una de las 4 establecidas en las constantes
 * POST-CONDICIONES: Devuelve el segundo puntaje a utilizar en la eleccion del personaje
 */

unsigned int medida_contra_manifestacion(char medida)
{
    unsigned int puntaje_a_devolver;

    if (medida == BOLAS_DE_NIEVE)
    {
        puntaje_a_devolver = PUNTAJE_MEDIDA_BOLAS_NIEVE;
    }
    else if (medida == PIUM_PIUM)
    {
        puntaje_a_devolver = PUNTAJE_MEDIDA_PIUM_PIUM;
    }
    else if (medida == KUCHAU)
    {
        puntaje_a_devolver = PUNTAJE_MEDIDA_KUCHAU;
    }
    else if (medida == GENIO)
    {
        puntaje_a_devolver = PUNTAJE_MEDIDA_GENIO;
    }
    else
    {
        puntaje_a_devolver = 0;
    }

    return puntaje_a_devolver;
}

/*
 * POST-CONDICIONES: verifica que horario este entre 0 y 23.59
 */
void pedir_horario_llegada_parcial(float *horario)
{
    unsigned int hora = 100;

    unsigned int minuto = 100;

    do
    {
        printf("A que hora llegaste al parcial? entre 0 y 23 \n");

        scanf(" %f", horario);

        hora = (unsigned int)(*horario);

        minuto = (unsigned int)(100 * ((*horario) - (float)(hora)));

    } while (!es_posible_hora_llegada(hora) || !es_posible_minuto_llegada(minuto));
}

/*
 * POST-CONDICIONES: redondea la nota hacia abajo como numero entero
 */
void pedir_nota_parcial(float *nota)
{
    do
    {
        printf("Coloca tu nota del parcial (entre 1 y 10) \n");

        scanf(" %f", nota);

    } while (!es_posible_nota_parcial((unsigned int)(*nota)));

    unsigned int nota_casting = (unsigned int)(*nota);

    (*nota) = (float)nota_casting;
}

/*
 * PRE-CONDICIONES: nota debe estar entre 1 y 10
 * POST-CONDICIONES: La funcion devuelve un valor multiplicador del puntaje segun la nota del usuario
 */

unsigned int nota_parcial(float nota)
{
    unsigned int multiplicador;

    if (nota <= 3)
    {
        multiplicador = MULTIPLICADOR_NOTA_BAJA;
    }
    else if (nota <= 6)
    {
        multiplicador = MULTIPLICADOR_NOTA_MEDIA;
    }
    else if (nota == 7 || nota == 8)
    {
        multiplicador = MULTIPLICADOR_NOTA_ALTA;
    }
    else if (nota == 9 || nota == 10)
    {
        multiplicador = MULTIPLICADOR_NOTA_MUY_ALTA;
    }
    else
    {
        multiplicador = 0;
    }

    return multiplicador;
}

/*
 * PRE-CONDICIONES: puntaje deberia estar entre 13 y 68, horario
 deberia estar entre 0 y 23.59
 * POST-CONDICIONES: Muestra el personaje que le toca al usuario
 */

char decidir_personaje(unsigned int puntaje, float horario)
{
    char personaje_elegido;

    if (puntaje <= PUNTAJE_MAXIMO_PRIMER_GRUPO)
    {
        if (horario <= LIMITE_HORARIO_PARCIAL)
        {
            printf("Con un puntaje de %i puntos se definio al azulado -Stitch- \n", puntaje);

            personaje_elegido = STITCH;
        }
        else if (horario > LIMITE_HORARIO_PARCIAL)
        {
            printf("Con un puntaje de %i puntos se definio al congelado -Olaf- \n", puntaje);

            personaje_elegido = OLAF;
        }
    }
    else if (puntaje <= PUNTAJE_MAXIMO_SEGUNDO_GRUPO)
    {
        if (horario <= LIMITE_HORARIO_PARCIAL)
        {
            printf("Con un puntaje de %i puntos se definio a la princesa -Jasmín- \n", puntaje);

            personaje_elegido = JASMIN;
        }
        else if (horario > LIMITE_HORARIO_PARCIAL)
        {
            printf("Con un puntaje de %i puntos se definio al único e inigualable -Rayo McQueen- \n", puntaje);

            personaje_elegido = RAYO_MCQUEEN;
        }
    }

    return personaje_elegido;
}

char decidir_personaje_tp1()
{
    char transporte;

    char medida;

    float horario;

    float nota;

    pedir_transporte(&transporte);

    pedir_medida_contra_manifestacion(&medida);

    pedir_horario_llegada_parcial(&horario);

    pedir_nota_parcial(&nota);

    unsigned int pregunta_transporte = transporte_a_usar(transporte);

    unsigned int pregunta_manifestacion = medida_contra_manifestacion(medida);

    unsigned int pregunta_nota_parcial = nota_parcial(nota);

    unsigned int puntaje = pregunta_transporte + (pregunta_manifestacion * pregunta_nota_parcial);

    return decidir_personaje(puntaje, horario);
}
