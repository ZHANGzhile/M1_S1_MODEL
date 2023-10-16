/*
    Auteur :
        ZHOU runlin 28717281
        ZHANG zhile 21201131
*/

#include "utils.h"
#include "stdio.h"

void print_number(mpfr_t num){
    // creer une chaine de caracteres assez grand 
    char str[100];  
    // en utilisent mpfr_sprintf pour changer les nombres a chaine de caracteres
    mpfr_sprintf(str, "%.10Rf", num); 
    printf("%s ", str);
}

void printMatriceMpfr(struct MatrixMpfr matrix){
    for (int i=0; i < matrix.tailleMAX; i++){
        printVectorMpfr(matrix.data[i]);
    }
}  

void printVectorMpfr(mpfr_t vec[MAX]){
    for (int i = 0; i < MAX; i++){
        print_number(vec[i]);
    }
    printf("\n");
}

void chooseRoundingMode(mpfr_t num, int goal, int roundingMode){
    switch (roundingMode){
    case 1:
        mpfr_set_d(num, goal, MPFR_RNDN);
        break;
    case 2:
        mpfr_set_d(num, goal, MPFR_RNDZ);
        break;
    case 3:
        mpfr_set_d(num, goal, MPFR_RNDN);
        break;
    case 4:
        mpfr_set_d(num, goal, MPFR_RNDU);
        break;
    default:
        mpfr_set_d(num, goal, MPFR_RNDD);
        break;
    }
}

struct MatrixMpfr initMatrix(int initMode, int precision, int roundingMode, int taille){
    struct MatrixMpfr matrix;
    matrix.tailleMAX = taille;

    for (int i = 0; i < matrix.tailleMAX; i++){
        for (int j = 0; j < matrix.tailleMAX; j++){
            // init les element
            mpfr_init2(matrix.data[i][j], precision); 
            if (i == j && initMode == 1){
                chooseRoundingMode(matrix.data[i][j], 1, roundingMode);
            } else{
                chooseRoundingMode(matrix.data[i][j], 0, roundingMode);
            }
        }
    }
    return matrix;
}

void deleteMatrix(struct MatrixMpfr matrix){
    for (int i = 0; i < matrix.tailleMAX; i++) {
        for (int j = 0; j < matrix.tailleMAX; j++) {
            // liberer tous les elements
            mpfr_clear(matrix.data[i][j]); 
        }
    }
}