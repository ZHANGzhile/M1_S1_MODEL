/*
    Auteur :
        ZHOU    runlin      28717281
        ZHANG   zhile       21201131
        XU      mengqian    21306077
*/

#ifndef UTILS
#define UTILS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct numComplex {
    double real;        // 实数部
    double imaginary;     // 虚数部
};

// affichage
void printComplexNumberVec(struct numComplex *numVec, int size);

// generate complex number
struct numComplex* randomConsVec(int size);
struct numComplex zeroComplexNum();

// calculations for complex number
struct numComplex addComplexNumber(struct numComplex numA, struct numComplex numB);      
struct numComplex multComplexNumber(struct numComplex numA, struct numComplex numB);  
struct numComplex divComplexNum(int n, struct numComplex num);
/*
    返回primitive nth root of unity的0, 1, 2, ..., n-1次方
    mode == 1: primivite的一次方，默认为: e^(2*i*pi/n)
    mode == 0: primivite的一次方，默认为: e^(-2*i*pi/n) 
    也就是说mode 0返回inverse fft的omega, mode 1返回正常fft
*/ 
// 使用动态规划
struct numComplex* primitiveRoot(int n);
#endif