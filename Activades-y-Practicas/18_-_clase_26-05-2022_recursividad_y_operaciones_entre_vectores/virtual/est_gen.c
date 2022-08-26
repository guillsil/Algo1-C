void operacion(jugador_t pilon_pinocho[MAX_PILON], int tope_pinocho, 
    jugador_t pilon_pp_grillo[MAX_PILON], int tope_pp_grillo,
    jugador_t resultado[MAX_PILON], int *tope_resultado) {

    *tope_resultado = 0;

    int pos_grillo = 0;
    int pos_pinocho = 0;

    while (pos_grillo < tope_pp_grillo && pos_pinocho < tope_pinocho) {
        jugador_t pinocho = pilon_pinocho[pos_pinocho];
        jugador_t pp_grillo = pilon_pp_grillo[pos_grillo];
        
        if (pinocho.id == pp_grillo.id) {
        } else if (pinocho.id > pp_grillo.id) {
        } else {
        }
    }

    // aca depende de la operacion si hay mas whiles o no
}