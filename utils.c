/*
    Auteur :
        ZHOU    runlin      28717281
        ZHANG   zhile       21201131
        XU      mengqian    21306077
*/

#include "utils.h"

void printComplexNumber(struct numComplex num){
    printf("%.6f + %.6fi\n", num.real, num.complex);
}

struct numComplex addComplexNumber(struct numComplex numA, struct numComplex numB){
    struct numComplex res = {numA.real + numB.real, numA.complex + numB.complex};
    return res;
}

struct numComplex multComplexNumber(struct numComplex numA, struct numComplex numB){
    struct numComplex res = {numA.real*numB.real - numA.complex*numB.complex, numA.complex*numB.real + numA.real*numB.complex};
    return res;
}