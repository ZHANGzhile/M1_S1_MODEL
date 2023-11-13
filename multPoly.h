/*
    Auteur :
        ZHOU    runlin      28717281
        ZHANG   zhile       21201131
        XU      mengqian    21306077
*/

#include "fastFourierTransforme.h"

// 结果储存在polyA
void NaiveMultPoly(struct numComplex *polyA, struct numComplex *polyB);
void fftMultPoly(struct numComplex *polyA, struct numComplex *polyB);
