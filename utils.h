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

// poly的实质是size大小的数组
struct polynomial{
    struct numComplex* data;
    int size;
};


// affichage
void printComplexNumberVec(struct numComplex *numVec, int size);

// generate complex number
struct numComplex* randomConsVec(int size);
struct numComplex zeroComplexNum();

// init for polynomial
/*
    该部分的目的是为了方便管理poly对象，属于代码优化的一部分
    方便对象的管理以及内存管理，简化运行逻辑
    可以写入遇到的困难
    ** ZHOU a faire **
*/
// 创建大小为size的poly vide
struct polynomial createPoly(int size);
// 删除对象
void delPoly(struct polynomial *poly);
// 对poly对象的一些操作：添加，删除等操作
void addElement(struct numComplex el, struct polynomial *poly);
void subElement(struct numComplex el, struct polynomial *poly);

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