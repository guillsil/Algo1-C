#ifndef _BIBLIOTECA_C_
#define _BIBLIOTECA_C_

#define RESPUESTA_OLAF "Olaf"
#define RESPUESTA_STITCH "Stitch"
#define RESPUESTA_JASMIN "Jasmín"
#define RESPUESTA_RAYO "Rayo McQueen"


//Pre:Las repuestas validas son unicamente T, N, C,A.
//Post:Te sumo los puntos correspondientes a la variabl contador en base a la respuesta ingresada
int pregunta_transporte();

//Pre:Las repuestas validas son unicamente B, P, K,G
//Post:Te sumo los puntos correspondientes a la variable contador en base a la respuesta ingresada
int pregunta_poder();

//Pre:La hora ingresada debe ser valida es decir la hora tine que estar entre 1 y 23 y los minutos de 1 a 60.
//Post:Guardo esa hora para luego usarla en otro procediemiento.
float pregunta_hora_llegada();

//Pre:La calificacion debe ser entre 1 y 10
//Post:Guardo esa califiacacion  para luego usarla en otro procediemiento.
int pregunta_nota_examen();

//Pre:-
//Post:Realizo la ecuacion que determinara el puntaje global.
int calculo_puntaje(int contador1, int contador2, int contador4);

//Pre:El puntaje como minimo debe ser mayor a 13 y menor o igual a 43 
//Post:Te digo que personaje sos en base a los puntos obtenidos
void determinacion_team1(int puntaje, float contador3, char* personaje_obtenido);

//Pre:El puntaje  debe ser mayor a 43 y menor o igual a 68
//Post:Te digo que personaje sos en base a los puntos obtenidos
void determinacion_team2(int puntaje, float contador3, char* personaje_obtenido);
//Pre:-
//Post:si respondiste todas las preguntas correctamente , gurdo las respuesta a las variables contador y te hago tu saludo personalizado 
void programa_tp1(char* personaje_obtenido);

#endif // _BIBLIOTECA_C_

