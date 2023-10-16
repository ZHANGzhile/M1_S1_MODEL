/*
    Auteur :
        ZHOU runlin 28717281
        ZHANG zhile 21201131
*/

#include "LU_fac.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// struct Matrix LU_decompose(struct Matrix a){
//     for (int i = 0; i < a.tailleMAX; i++){
//         for (int j = 0; j < a.tailleMAX; j++){
//             // go to u-op
//             if (i <= j){
//                 double somme = 0;
//                 for (int k = 0; k < i; k++)
//                     somme += a.data[i][k]*a.data[k][j];
//                 a.data[i][j] -= somme;
//             }
//             // go to l-op
//             else {
//                 double somme = 0;
//                 for (int k = 0; k < j; k++)
//                     somme += a.data[i][k]*a.data[k][j];
//                 a.data[i][j] -= somme;
//                 a.data[i][j] /= a.data[j][j];
//             }
//         }
//     }
//     return a;
// }