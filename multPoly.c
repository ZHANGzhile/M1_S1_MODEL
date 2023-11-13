/*
    Auteur :
        ZHOU    runlin      28717281
        ZHANG   zhile       21201131
        XU      mengqian    21306077
*/

#include "multPoly.h"

struct numComplex* NaiveMultPoly(struct numComplex *polyA, int sizeA, struct numComplex *polyB, int sizeB){
    int size = sizeA + sizeB - 1;
    struct numComplex *res = malloc(sizeof(struct numComplex)*size);
    for (int i = 0; i < size; i++){
        res[i] = zeroComplexNum();
    }

    for (int i = 0; i < sizeA; i++){
        for (int j = 0; j < sizeB; j++){
            res[i+j] = addComplexNumber(res[i+j], multComplexNumber(polyA[i], polyB[j]));
        }
    }
    return res;
}

struct numComplex* fftMultPoly(struct numComplex *polyA, int sizeA, struct numComplex *polyB, int sizeB){
    int k = log2(sizeA+sizeB-1);
    int size = pow(2, k+1);
    // Compute the FFTs of P and Q with omega a primitive nth root of unity,
    struct numComplex *resP = fft(polyA, size);
    struct numComplex *resQ = fft(polyB, size);
    struct numComplex *stocker = malloc(sizeof(struct numComplex)*(size));

    // Multiply coefficient by coefficient these FFTs to get the FFT of R, where R = PQ
    for (int i = 0; i < size; i++){
        stocker[i] = multComplexNumber(resP[i], resQ[i]);
    }

    // Compute the inverse FFT of the FFT of R to retrieve R
    stocker = fftInverse(stocker, size);
    struct numComplex *res = malloc(sizeof(struct numComplex)*(sizeA+sizeB-1));
    res[0] = stocker[0];
    for(int i = 0; i < sizeA+sizeB-1; i++){
        res[i] = stocker[size-i];
    }

    free(stocker);
    free(resP);
    free(resQ);

    return res;
}