/*
    Auteur :
        ZHOU    runlin      28717281
        ZHANG   zhile       21201131
        XU      mengqian    21306077
*/

#include <time.h>
#include "utils.h"
#include "fastFourierTrans.h"
#include "multPoly.h"

int main(){
    // tests for random data
    printf("---------------------------------------------------------------\n");
    printf("test for func : randomConsVecNum\n");
    int size = rand()%10;
    struct numComplex *numVec = randomConsVec(size);
    printComplexNumberVec(numVec, size);

    //tests for primitiveRoot
    printf("---------------------------------------------------------------\n");
    printf("test for func : primitiveRoot\n");
    int pri_size = 7;
    struct numComplex *primitiveList = primitiveRoot(pri_size);
    printComplexNumberVec(primitiveList, pri_size);

    printf("---------------------------------------------------------------\n");
    printf("test for func : fft and fftInverse\n");
    //struct numComplex* fft_res = fft(numVec, size);
    //printComplexNumberVec(fft_res, size);

    struct numComplex* ls = malloc(sizeof(struct numComplex)*4);
    struct numComplex el1 = {1, 0};
    struct numComplex el2 = {2, 0};
    struct numComplex el3 = {3, 0};
    struct numComplex el4 = {4, 0};
    ls[0] = el1;
    ls[1] = el2;
    ls[2] = el3;
    ls[3] = el4;
    //struct numComplex* ls_res = fft(ls, 4);
    struct numComplex* ls_res_inverse = fftInverse(ls, 4);
    //printComplexNumberVec(ls_res, 4);
    printComplexNumberVec(ls_res_inverse, 4);

    // liberer le memoire
    //free(fft_res);
    //free(ls_res);
    free(numVec);
    free(primitiveList);
    free(ls_res_inverse);

    return 0;
}