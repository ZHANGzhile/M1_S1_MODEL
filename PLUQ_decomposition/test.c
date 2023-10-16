#include "LU_fac.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    struct MatrixMpfr matrix1 = initMatrix(1, 64, 1, MAX);
    struct MatrixMpfr matrix2 = initMatrix(0, 64, 1, MAX);
    printMatriceMpfr(matrix1);
    printMatriceMpfr(matrix2);
    deleteMatrix(matrix1);
    deleteMatrix(matrix2);
    
    return 0;
}