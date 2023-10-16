/*
    Auteur :
        ZHOU runlin 28717281
        ZHANG zhile 21201131
*/


#ifndef UTILS_H
#define UTILS_H

#include "LU_fac.h"
#include <mpfr.h>
#define MAX 4

struct MatrixMpfr{
    int tailleMAX;
    mpfr_t data[MAX][MAX];
};

struct MatrixDouble{
    int tailleMAX;
    double data[MAX][MAX];
};

// section MPFR
void printMatriceMpfr(struct MatrixMpfr matrix);
void printVectorMpfr(mpfr_t vec[MAX]);

/*
    initMode == 0 : init une matrix null
    initMode == 1 : init une matrix identifiant

    precision : precision des nombre dans la matrix
    roundingMode : 
        1 - MPFR_RNDN ("Round to nearest")
        2 - MPFR_RNDZ ("Round toward zero")
        3 - MPFR_RNDU ("Round toward plus infinity")
        4 - MPFR_RNDD ("Round toward minus infinity")
*/
struct MatrixMpfr initMatrix(int initMode, int precision, int roundingMode, int taille);
void deleteMatrix(struct MatrixMpfr matrix);        // liberer les espaces de matrix 

void printMatriceDouble(struct MatrixMpfr matrix);
void printVectorDouble(mpfr_t vec[MAX]);
#endif