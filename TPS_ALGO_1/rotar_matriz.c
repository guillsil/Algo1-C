#include <stdio.h>
#include <stdio.h>
#include <stdlib.h> //Para poder usar abs

typedef struct coordenada {
	int fil;
	int col;
} coordenada_t;

/* void dar_vuelta(char terreno[MAX_FIL][MAX_COL], int fil, int col){    
    int matriz_horario[col][fil];
    int matriz_anti_horario[col][fil];
    //anti horario
    int y = 0;
    for (int i = 0; i < fil; i++){
        int t = col - 1;
        for (int j = 0; j < col; j++){
            matriz_anti_horario[y][t++] = terreno[i][j];
        }
        y--;
    }
    //horario
    int k = fil - 1;
    for (int i = 0; i < fil; i++){
        int t = 0;
        for (int j = 0; j < col; j++){
            matriz_horario[t++][k] = terreno[i][j];
        }
        k--;
    }
    printf("\nMatriz No Rotada: \n");
    for (int i = 0; i < col; i++){
        printf("| ");
        for (int j = 0; j < fil; j++){
            printf("%d ", terreno[i][j]);
        }
        printf(" |\n");
    }
    printf("\nMatriz Rotada: \n");
    for (int i = 0; i < col; i++){
        printf("| ");
        for (int j = 0; j < fil; j++){
            printf("%d ", matriz_horario[i][j]);
        }
        printf(" |\n");
    }
    printf("\nMatriz Anti Rotada: \n");
    for (int i = 0; i < col; i++){
        printf("| ");
        for (int j = 0; j < fil; j++){
            printf("%d ", matriz_anti_horario[i][j]);
        }
        printf(" |\n");
    }
} */
 
int main(){
    int fil = 5, col = 5;
    int m[5][5] ={{1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}};
    m[1][2] = 0;
    
    int matriz_horario[col][fil];
    int matriz_anti_horario[col][fil];

     
    //anti horario
    /* int y = col+1;
    for (int i = 0; i < fil; i++){
        int t = 0;
        for (int j = 0; j < col; j++){
            matriz_anti_horario[y][t--] = m[i][j];
        }
        y--;
    } */
    //horario
    int k = fil - 1;
    for (int i = 0; i < fil; i++){
        int t = 0;
        for (int j = 0; j < col; j++){
            matriz_horario[t++][k] = m[i][j];
        }
        k--;
    }




    printf("\nMatriz No Rotada: \n");
    for (int i = 0; i < col; i++){
        printf("| ");
        for (int j = 0; j < fil; j++){
            printf("%d ", m[i][j]);
        }
        printf(" |\n");
    }
    //sentido horario
    printf("\nMatriz Rotada: \n");
    for(int i=0 ; i<fil ; i++){
        printf("| ");
        for(int j = col-1; j >= 0 ; j--){
            matriz_horario[j][i] = m[j][i]; 
            printf("%d ",matriz_horario[j][i]);
        }
        printf(" |\n");
    }
    //sentido anti horario
    printf("\nMatriz Anti Rotada: \n");
    for(int i = fil-1 ; i >= 0 ; i--){
        printf("| ");
        for(int j=0 ; j<= col-1 ; j++){
            matriz_anti_horario[j][i] = m[j][i];
            printf("%d ",matriz_anti_horario[j][i]);
        }
    printf(" |\n");
    }
    return 0;
}

/* void dar_vuelta(char terreno[MAX_FIL][MAX_COL], int topes_fil, int topes_col, nivel_t* nivel, int numero_nivel){    
    char terreno_aux[MAX_FIL][MAX_COL];

    int k = topes_fil - 1;
    for (int i = 0; i < topes_fil; i++){
        int t = 0;
        for (int j = 0; j < topes_col; j++){
            terreno_aux[t++][k] = terreno[i][j];
        }
        k--;
    }

    printf("\nMatriz Rotada: \n");
    for (int i = 0; i < topes_col; i++){
        printf("| ");
        for (int j = 0; j < topes_fil; j++){
            printf("%d ", terreno_aux[i][j]);
        }
        printf(" |\n");
    }
}
*/
/*
int main(){
    char matriz[3][3];
    //sea 'a' una coordenada de una matriz de 5x6
    coordenada_t a;
    a.fil = 2;
    a.col = 2;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            matriz[i][j] = 'a';
        }
    }
    matriz[a.fil][a.col] = 'b';

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf("%c", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    coordenada_t a_rot_horario = {a.col, abs(a.fil - 3)};

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf("%c", matriz[i][j]);
        }
        printf("\n");
    }
    return 0;
}
*/