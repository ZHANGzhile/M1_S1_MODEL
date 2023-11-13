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

    struct numComplex* ls = malloc(sizeof(struct numComplex)*6);
    struct numComplex el1 = {1, 0};
    struct numComplex el2 = {2, 0};
    struct numComplex el3 = {4, 0};
    struct numComplex el4 = {8, 0};
    struct numComplex el5 = {16, 0};
    struct numComplex el6 = {32, 0};
    ls[0] = el1;
    ls[1] = el2;
    ls[2] = el3;
    ls[3] = el4;
    ls[4] = el5;
    ls[5] = el6;
    struct numComplex* ls_res = fft(ls, 6);
    printComplexNumberVec(ls_res, 8);

    // liberer le memoire
    //free(fft_res);
    free(ls_res);
    free(numVec);
    free(primitiveList);

    // les tests pour multPoly

    // creer deux polynomial random
    printf("---------------------------------------------------------------\n");
    int sizeA = rand()%10;
    struct numComplex *polyA = randomConsVec(sizeA);
    printComplexNumberVec(polyA, sizeA);
    
    printf("---------------------------------------------------------------\n");
    int sizeB = rand()%10;
    struct numComplex *polyB = randomConsVec(sizeB);
    printComplexNumberVec(polyB, sizeB);

    printf("---------------------------------------------------------------\n");
    struct numComplex *multPoly = NaiveMultPoly(polyA, sizeA, polyB, sizeB);
    printComplexNumberVec(multPoly, sizeA+sizeB-1);

    printf("---------------------------------------------------------------\n");
    struct numComplex *multFFTpoly = fftMultPoly(polyA, sizeA, polyB, sizeB);
    printComplexNumberVec(multFFTpoly, sizeA+sizeB-1);

    free(multPoly);
    free(multFFTpoly);

    return 0;
}