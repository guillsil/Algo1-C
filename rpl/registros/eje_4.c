/*
El renombrado profesor Derek Knight dicta clases en la gran Monster University. Gracias a la llegada de la virtualidad y a un gran incremento de notas por parte de sus estudiantes de forma sospechosa, sospecha que estos se están copiando. Por lo que usando sus contactos en Whatsapp Inc. ha interceptado los mensajes que se envían por un grupo de estudiantes.

    Estos mensajes contienen la siguiente información:
        Si tiene palabras relacionadas con el colegio (bool).
        Cantidad de palabras que contiene (int).
        Cantidad de respuestas al mensaje (int).
        Si el autor es sospechoso (bool).

    Dado un mensaje del tipo mensaje_t, calcular y devolver el índice de probabilidad de que sea un mensaje con la intención de copiarse.

Aclaración:

Sabemos la probabilidad de copiarse según las siguientes reglas:

    Todo mensaje empieza con una probabilidad de copia de 5 puntos.
    Si el mensaje tiene palabras relacionadas al colegio, la probabilidad aumenta 2 puntos, sino disminuye 2 puntos.
    Si el mensaje es muy largo (tiene más de 50 palabras, estricto) la probabilidad aumenta 2 puntos, sino disminuye 1 punto.
    Si el mensaje tiene una alta cantidad de respuestas (más que 3, estricto) la probabilidad aumenta 2 puntos, sino se mantiene igual.
    Si el mensaje fue escrito por un alumno cuyas calificaciones aumentaron (aka: autor sospechoso), la probabilidad aumenta 3 puntos, sino disminuye 1 punto.

Ejemplo:

Si tenemos la siguiente información del mensaje:

    tiene_palabras_de_colegio = true. (aumenta 2).
    cantidad_de_palabras = 50. (disminuye 1).
    cantidad_de_respuestas = 2. (mantiene).
    autor_sospechoso = true. (aumenta 3).

La probabilidad nos quedaría:
5 + 2 - 1 + 0 + 3 = 9

Y por lo tanto, nuestra función devolvería 9.

Recuerden los 5 puntos iniciales. 
*/
#include <stdio.h>
#include "solucion.h"
#define PROBABILIDAD_CON_LA_QUE_ARRANCA 5
#define MAX_PREGUNTAS 5
// Aca deberian ir las constantes.

typedef struct mensaje {
    bool tiene_palabras_de_colegio;
    int cantidad_de_palabras;
    int cantidad_de_respuestas;
    bool autor_sospechoso;
} mensaje_t;

int indice_de_probabilidad_de_copia(mensaje_t mensaje){
    int indice_de_probabilidad[MAX_PREGUNTAS];
    indice_de_probabilidad[0]=PROBABILIDAD_CON_LA_QUE_ARRANCA;
    if(mensaje.tiene_palabras_de_colegio == true){
        indice_de_probabilidad[1]=2;
    }else{
        indice_de_probabilidad[1]=-2;
    }
    if(mensaje.cantidad_de_palabras > 50){
        indice_de_probabilidad[2]=2;
    }else{
        indice_de_probabilidad[2]=-1;
    }
    if(mensaje.cantidad_de_respuestas >3){
        indice_de_probabilidad[3]=2;
    }else{
        indice_de_probabilidad[3]=0;
    }
    if(mensaje.autor_sospechoso == true){
        indice_de_probabilidad[4]=3;
    }else{
        indice_de_probabilidad[4]=-1;
    }
    return (indice_de_probabilidad[0]+indice_de_probabilidad[1]+indice_de_probabilidad[2]+indice_de_probabilidad[3]+indice_de_probabilidad[4]);

}