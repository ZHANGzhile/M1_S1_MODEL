#include "LU_fac.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    struct Matrix myMatrix = {
        .tailleMAX = MAX,
        .data = {{8,44,20,76},{6,9,5,19},{2,19,10,23},{2,3,1,5}}
    };
    struct Matrix res, L, U;
    res = LU_decompose(myMatrix);
    L = get_L(res);
    U = get_U(res);
    
    for (int i=0; i<myMatrix.tailleMAX; i++){
        for (int j=0; j<myMatrix.tailleMAX; j++){
            printf("%f ", res.data[i][j]);
        }
        printf("\n");
    }
    for (int i=0; i<myMatrix.tailleMAX; i++){
        for (int j=0; j<myMatrix.tailleMAX; j++){
            printf("%f ", L.data[i][j]);
        }
        printf("\n");
    }
    for (int i=0; i<myMatrix.tailleMAX; i++){
        for (int j=0; j<myMatrix.tailleMAX; j++){
            printf("%f ", U.data[i][j]);
        }
        printf("\n");
    }
    return 0;
}