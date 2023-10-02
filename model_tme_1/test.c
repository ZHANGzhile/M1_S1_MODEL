#include "LU_fac.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    // les donnees init
    struct Matrix myMatrix = {
        .tailleMAX = MAX,
        .data = {{2,3,1,5},{6,9,5,19},{2,19,10,23},{8,44,20,76}}
    };

    struct Matrix initP = {
        .tailleMAX = MAX,
        .data = {{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}}
    };

    struct Matrix initQ = {
        .tailleMAX = MAX,
        .data = {{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}}
    };

    struct Matrix res, L, U;
    res = LU_decompose(myMatrix);
    L = get_L(res);
    U = get_U(res);
    
    printf("The original matrix a :\n");
    for (int i=0; i<myMatrix.tailleMAX; i++){
        for (int j=0; j<myMatrix.tailleMAX; j++){
            printf("%f ", res.data[i][j]);
        }
        printf("\n");
    }

    printf("\nLU decomposition in Compact Format :\n");
    for (int i=0; i<myMatrix.tailleMAX; i++){
        for (int j=0; j<myMatrix.tailleMAX; j++){
            printf("%f ", res.data[i][j]);
        }
        printf("\n");
    }

    printf("\nThe matrix L :\n");
    for (int i=0; i<myMatrix.tailleMAX; i++){
        for (int j=0; j<myMatrix.tailleMAX; j++){
            printf("%f ", L.data[i][j]);
        }
        printf("\n");
    }

    printf("\nThe matrix U :\n");
    for (int i=0; i<myMatrix.tailleMAX; i++){
        for (int j=0; j<myMatrix.tailleMAX; j++){
            printf("%f ", U.data[i][j]);
        }
        printf("\n");
    }

    res = PLUQ_decompose(myMatrix, &initP, &initQ);
    L = get_L(res);
    U = get_U(res);
    
    printf("\nThe original matrix a :\n");
    for (int i=0; i<myMatrix.tailleMAX; i++){
        for (int j=0; j<myMatrix.tailleMAX; j++){
            printf("%f ", res.data[i][j]);
        }
        printf("\n");
    }

    printf("\nLU decomposition in Compact Format :\n");
    for (int i=0; i<myMatrix.tailleMAX; i++){
        for (int j=0; j<myMatrix.tailleMAX; j++){
            printf("%f ", res.data[i][j]);
        }
        printf("\n");
    }

    printf("\nThe matrix L :\n");
    for (int i=0; i<myMatrix.tailleMAX; i++){
        for (int j=0; j<myMatrix.tailleMAX; j++){
            printf("%f ", L.data[i][j]);
        }
        printf("\n");
    }

    printf("\nThe matrix U :\n");
    for (int i=0; i<myMatrix.tailleMAX; i++){
        for (int j=0; j<myMatrix.tailleMAX; j++){
            printf("%f ", U.data[i][j]);
        }
        printf("\n");
    }
    return 0;
}