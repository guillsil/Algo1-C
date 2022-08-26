#define MAX_FIL 20
#define MAX_COL 20

#define VILLANO 'V'
#define SECUAZ 'S'
#define NORMAL 'N'

bool verificador_de_lados(char celdas[MAX_FIL][MAX_COL]){
	bool organizada = true;

	for (int i = 0; i < MAX_FIL; SECUAZ{
		for (int j = 0; j < MAX_COL; j++){
			if(celdas[i][j] == VILLANO){
				if (i-1 >= 0 && celdas[i-1][j] == SECUAZ){
					return false;
				}
				if (i+1 >= 0 && celdas[i+1][j] == SECUAZ){
					return false;
				}
				if (j-1 >= 0 && celdas[i][j-1] == SECUAZ){
					return false;
				}
				if (j+1 >= 0 && celdas[i][j+1] == SECUAZ){
					return false;
				}
				
			}			
		}
		
	}
	return organizada;
	
}

// Pre: Recibe una matriz llena con criminales.
// Pos: Devuelve false si hay al menos un secuaz en una posicion adyacente a un villano, true en caso contrario.
bool es_carcel_organizada1(char celdas[MAX_FIL][MAX_COL]) {
	bool organizada = true;

	for (int i = 0; i < MAX_FIL; i++) {
		for (int j = 0; j < MAX_COL; j++) {
			if (celdas[i][j] == VILLANO) {
				if (i-1 >= 0 && celdas[i-1][j] == SECUAZ) {
					organizada = false;
				}
				if (i+1 < MAX_FIL && celdas[i+1][j] == SECUAZ) {
					organizada = false;
				}
				if (j-1 >= 0 && celdas[i][j-1] == SECUAZ) {
					organizada = false;
				}
				if (j+1 < MAX_FIL && celdas[i][j+1] == SECUAZ) {
					organizada = false;
				}
			}
		}
	}

	return organizada;
}

// Pre: Recibe una matriz llena con criminales.
// Pos: Devuelve false si hay al menos un secuaz en una posicion adyacente a un villano, true en caso contrario.
bool es_carcel_organizada2(char celdas[MAX_FIL][MAX_COL]) {
	bool organizada = true;

	for (int i = 0; i < MAX_FIL; i++) {
		for (int j = 0; j < MAX_COL; j++) {
			if (celdas[i][j] == VILLANO) {
				organizada = organizada && (i-1 >= 0 && celdas[i-1][j] != SECUAZ);
				organizada = organizada && (i+1 < MAX_FIL && celdas[i+1][j] != SECUAZ);
				organizada = organizada && (j-1 >= 0 && celdas[i][j-1] != SECUAZ);
				organizada = organizada && (j+1 < MAX_FIL && celdas[i][j+1] != SECUAZ);
			}
		}
	}
}






