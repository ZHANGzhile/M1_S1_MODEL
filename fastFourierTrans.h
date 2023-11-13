/*
    Auteur :
        ZHOU    runlin      28717281
        ZHANG   zhile       21201131
        XU      mengqian    21306077
*/

#ifndef FASTFOURIERTRANS
#define FASTFOURIERTRANS
#include "utils.h"

// 将数组扩展至2^k次方
void extenstionVec(struct numComplex *num, int k); 

void fft(struct numComplex *num);
void fftInverse(struct numComplex *num);

#endif