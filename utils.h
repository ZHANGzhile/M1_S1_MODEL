/*
    Auteur :
        ZHOU    runlin      28717281
        ZHANG   zhile       21201131
        XU      mengqian    21306077
*/

#ifndef UTILS
#define UTILS
#include <stdio.h>

struct numComplex {
    double real;        // 实数部
    double complex;     // 虚数部
};

void printComplexNumber(struct numComplex num);
struct numComplex addComplexNumber(struct numComplex numA, struct numComplex numB);     // 复数加法
struct numComplex multComplexNumber(struct numComplex numA, struct numComplex numB);    // 复数乘法

#endif