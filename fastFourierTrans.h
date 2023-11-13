/*
    Auteur :
        ZHOU    runlin      28717281
        ZHANG   zhile       21201131
        XU      mengqian    21306077
*/

#ifndef FASTFOURIERTRANS
#define FASTFOURIERTRANS
#include "utils.h"

// 将数组扩展至2^k次方, 先对原数组进行复制，扩展部分用 (0+0i) 填充
struct numComplex* extenstionVec(struct numComplex *original, int size, int k); 

// 返回对应的数组 (n项 ！！！, degree max = n-1)
// 我们将在fft函数内部进行延展，然后去除延展出来的 (0+0i)
struct numComplex* fft(struct numComplex *num, int size);
struct numComplex* fftInverse(struct numComplex *num, int size);

#endif