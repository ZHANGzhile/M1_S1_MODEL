/*
    Auteur :
        ZHOU    runlin      28717281
        ZHANG   zhile       21201131
        XU      mengqian    21306077
*/

#include "fastFourierTrans.h"

struct numComplex* NaiveMultPoly(struct numComplex *polyA, int sizeA, struct numComplex *polyB, int sizeB);
struct numComplex* fftMultPoly(struct numComplex *polyA, int sizeA, struct numComplex *polyB, int sizeB);
