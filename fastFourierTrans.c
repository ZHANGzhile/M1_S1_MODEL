/*
    Auteur :
        ZHOU    runlin      28717281
        ZHANG   zhile       21201131
        XU      mengqian    21306077
*/

#include "fastFourierTrans.h"

struct numComplex* extenstionVec(struct numComplex *original, int size, int k){
    // allouer l'espace du pointeur
    struct numComplex* res = malloc(sizeof(struct numComplex)*k);

    // copier le pointeur original
    for (int i = 0; i < size; i++){
        res[i] = original[i];
    }
    // 扩展至2^k项, 用0填充
    for (int i = size; i < pow(2, k); i++){
        res[i] = zeroComplexNum();
    }
    // liberer le pointeur
    free(original);

    return res;
}

struct numComplex* coreFFT(struct numComplex *num, int size){
    struct numComplex* res = malloc(sizeof(struct numComplex)*size);
    if (size == 1){
        // res[0] = sumComplexVec(num, size);
        res[0] = num[0];
    }
    else{
        // Split p into p_odd and p_even
        struct numComplex *p_odd = malloc(sizeof(struct numComplex)*size/2);
        struct numComplex *p_even = malloc(sizeof(struct numComplex)*size/2);
        for (int i = 0; i < size/2; i++){
            p_odd[i] = num[2*i+1];
            p_even[i] = num[2*i];
        }
        // 迭代部分
        p_odd = coreFFT(p_odd, size/2);
        p_even = coreFFT(p_even, size/2);
        
        // 回代部分
        struct numComplex *primitiveList = primitiveRoot(size);
        for (int i = 0; i < size/2; i++){
            res[i] = addComplexNumber(p_even[i], multComplexNumber((primitiveList[i]), p_odd[i]));
            res[size/2+i] = addComplexNumber(p_even[i], multComplexNumber(primitiveList[size/2+i], p_odd[i]));
        }

        // 释放内存
        free(p_odd);
        free(p_even);
        free(primitiveList);
    }
    free(num);
    return res;
}

struct numComplex* fft(struct numComplex *num, int size){
    // 先拓展
    // 判断k的值
    int k = log2(size);
    if (pow(2, k) < size){
        k += 1;
        num = extenstionVec(num, size, k);
    }
    struct numComplex *res = coreFFT(num, size);
    return res;
}   

struct numComplex* fftInverse(struct numComplex *num, int size){
    struct numComplex *res_fft = fft(num, size);
    struct numComplex *res = malloc(sizeof(struct numComplex)*size);
    // inverse fft 最后需要乘1/n
    res[0] = divComplexNum(size, res_fft[0]);
    for (int i = 1; i < size; i++){
        res[i] = divComplexNum(size, res_fft[i]);
    }
    free(res_fft);
    return res;
}
