#include "LU_fac.h"
#include <stdio.h>
#include <stdlib.h>

struct Matrix LU_decompose(struct Matrix a){
    for (int i = 0; i < a.tailleMAX; i++){
        for (int j = 0; j < a.tailleMAX; j++){
            // go to u-op
            if (i <= j){
                double somme = 0;
                for (int k = 0; k < i; k++)
                    somme += a.data[i][k]*a.data[k][j];
                a.data[i][j] -= somme;
            }
            // go to l-op
            else {
                double somme = 0;
                for (int k = 0; k < j; k++)
                    somme += a.data[i][k]*a.data[k][j];
                a.data[i][j] -= somme;
                a.data[i][j] /= a.data[j][j];
            }
        }
    }
    return a;
}


struct Matrix get_U(struct Matrix a){
    struct Matrix res = {
        .tailleMAX = a.tailleMAX
    };
    for (int i = 0; i < a.tailleMAX; i++){
        for (int j = 0; j < a.tailleMAX; j++){
            if (i <= j) 
                res.data[i][j] = a.data[i][j];
            else 
                res.data[i][j] = 0;
        }
    }
    return res;
}

struct Matrix get_L(struct Matrix a){
    struct Matrix res = {
        .tailleMAX = a.tailleMAX
    };
    for (int i = 0; i < a.tailleMAX; i++){
        for (int j = 0; j < a.tailleMAX; j++){
            if (i > j)
                res.data[i][j] = a.data[i][j];
            else if (i == j){
                res.data[i][j] = 1;
            }
            else 
                res.data[i][j] = 0;
        }
    }
    return res;
}

struct Matrix PLUQ_decompose(struct Matrix a, struct Matrix p, struct Matrix q){
    return a;
}
