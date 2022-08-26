#include <stdio.h>
#include <stdbool.h>

#define MAX_FIL_CAMPO 30
#define MAX_COL_CAMPO 30

const char STITCH = 'S';
const char VACIO = '-';

void inicializar_campo(char campo[MAX_FIL_CAMPO][MAX_COL_CAMPO], int tope_fil, int tope_col, int fil_stitch, int col_stitch)
{
    for (int i = 0; i < tope_fil; i++)
    {
        for (int j = 0; j < tope_col; j++)
            campo[i][j] = VACIO;
    }

    campo[fil_stitch][col_stitch] = STITCH;
}

void imprimir_campo(char campo[MAX_FIL_CAMPO][MAX_COL_CAMPO], int tope_fil, int tope_col)
{
    for (int i = 0; i < tope_fil; i++)
    {
        for (int j = 0; j < tope_col; j++)
            printf(" %c ", campo[i][j]);
        printf("\n");
    }
    printf("\n");
    printf("\n");
    printf("\n");
}


bool encontre_stitch_rec_aux(char campo[MAX_FIL_CAMPO][MAX_COL_CAMPO], int tope_fil, int tope_col, int i, int j){
    //caso base
    if(i>= tope_fil){
        return false;
    }
    //caso base
    else if(j>=tope_col){
        j=0;
        return encontre_stitch_rec_aux(campo, tope_fil, tope_col, i+1, j);
    }
    //llamado a la funcion recuresiva y proceso
    else{
        if(campo[i][j] == STITCH){
            return true;
        }
        return encontre_stitch_rec_aux(campo, tope_fil, tope_col, i, j+1);
    }
}


bool encontre_stitch_rec(char campo[MAX_FIL_CAMPO][MAX_COL_CAMPO], int tope_fil, int tope_col){
    return encontre_stitch_rec_aux(campo, tope_fil, tope_col, 0, 0);
}




bool encontre_stitch_iterativo(char campo[MAX_FIL_CAMPO][MAX_COL_CAMPO], int tope_fil, int tope_col){
    bool esta= false;
    int i= 0;
    int j= 0;
    
    while(!esta && i<tope_fil){
        while(!esta && j<tope_col){
            if(campo[i][j]== STITCH)
                esta=true;
            else 
                j++;
        }
        j=0;
        i++;
    }
    return esta;
}


int main()
{
    char campo[MAX_FIL_CAMPO][MAX_COL_CAMPO];
    int tope_col = 20;
    int tope_fil = 20;
    int fil_stitch = 6;
    int col_stitch = 15;

    inicializar_campo(campo, tope_fil, tope_col, fil_stitch, col_stitch);
    imprimir_campo(campo, tope_fil, tope_col);

    if(!encontre_stitch_rec(campo, tope_fil, tope_col))
        printf("no lo encontre :( \n");
    else 
        printf("te encontre \n");

    return 0;
}