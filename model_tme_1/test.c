#include "LU_fac.h"
#include <stdio.h>
#include <stdlib.h>

void print_Matrice(struct Matrix matrix){
    for (int i=0; i < matrix.tailleMAX; i++){
        for (int j=0; j < matrix.tailleMAX; j++){
            printf("%.6f ", matrix.data[i][j]);
        }
        printf("\n");
    }
}  

void print_vector(double vec[MAX]){
    for (int i = 0; i < MAX; i++){
        printf("%.6f ", vec[i]);
    }
    printf("\n");
}

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
    double vec[MAX] = {22, 76, 99, 256};
    // fin du init

    // lancer les tests
    printf("The original matrix a :\n");
    print_Matrice(myMatrix);

    res = PLUQ_decompose(myMatrix, &initP, &initQ);
    L = get_L(res);
    U = get_U(res);
    
    printf("\nThe original matrix a :\n");
    print_Matrice(res);

    printf("\nLU decomposition in Compact Format :\n");
    print_Matrice(res);

    printf("\nThe matrix L :\n");
    print_Matrice(L);

    printf("\nThe matrix U :\n");
    print_Matrice(U);

    printf("\nMatrix transpose de a\n");
    matrixTranspose(&myMatrix);
    print_Matrice(myMatrix);

    struct Matrix P = {
        .tailleMAX = MAX,
        .data = {{0,0,0,1},{0,1,0,0},{0,0,1,0},{1,0,0,0}}
    };
    double* dest;
    dest = matrixProduitTrans(P, vec);
    print_vector(dest);

    struct Matrix U_test = {
        .tailleMAX = MAX,
        .data = {{8,44,20,76},{0,-24,-10,-38},{0,0,5/3,-26/3},{0,0,0,-24/5}}
    };
    double y[MAX] = {256, -116, (double)-11/3, (double)-24/5};
    dest = upperTriangleSysAlgo(U_test, y);
    print_vector(dest);
    return 0;
}