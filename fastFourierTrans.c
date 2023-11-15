/*
    Auteur :
        ZHOU    runlin      28717281
        ZHANG   zhile       21201131
        XU      mengqian    21306077
*/

#include "fastFourierTrans.h"

int isValideK(int cpt, int k){
    if (pow(2, k) >= cpt){
        return 1;
    }
    printf("Err : invalide k for exetension \n");
    return 0;
}

struct polynomial extenstionVec(struct polynomial poly, int k) {
    struct polynomial res = createPoly(pow(2, k));
    // 扩展至2^k项, 用0填充
    if(isValideK(poly.cpt, k)){
        // create new obj
        int i;
        // copier the original data
        for (i = 0; i < poly.cpt; i++){
            addElement(poly.data[i], &res);
        }
        for (; i < pow(2, k); i++){
            addElement(zeroComplexNum(), &res);
        }
    }
    delPoly(poly);
    return res;
}

struct polynomial coreFFT(struct polynomial poly){
    struct polynomial res = createPoly(poly.size);
    if (poly.cpt == 1){
        addElement(poly.data[0], &res);
    }
    else{
        // Split p into p_odd and p_even
        struct polynomial p_odd = createPoly(poly.size/2);
        struct polynomial p_even = createPoly(poly.size/2);
        for (int i = 0; i < poly.size/2; i++){
            addElement(poly.data[2*i+1], &p_odd);
            addElement(poly.data[2*i], &p_even);
        }
        // 迭代部分
        p_odd = coreFFT(p_odd);
        p_even = coreFFT(p_even);
        
        // 回代部分
        struct polynomial primitiveList = rootList(poly.size);
        for (int i = 0; i < poly.size/2; i++){      
            res.data[i] = addComplexNumber(p_even.data[i], 
                                            multComplexNumber((primitiveList.data[i]), p_odd.data[i])
                                        );
            res.data[poly.size/2+i] = addComplexNumber(p_even.data[i], 
                                            multComplexNumber(primitiveList.data[poly.size/2+i], p_odd.data[i])
                                        );
            res.cpt += 2;
        }

        // 释放内存
        delPoly(p_odd);
        delPoly(p_even);
        delPoly(primitiveList);
    }
    delPoly(poly);
    return res;
}

struct polynomial fft(struct polynomial poly, int k){
    // 先拓展, 判断k的值
    //struct polynomial res = createPoly(pow(2, k));
    if (isValideK(poly.cpt, k)){
        poly = extenstionVec(poly, k);
        poly= coreFFT(poly);
    }
    return poly;
}   

struct polynomial fftInverse(struct polynomial poly, int k){
    poly = fft(poly, k);
    // inverse fft 最后需要乘1/n
    struct polynomial res = createPoly(poly.size); 
    // 放入第一个元素 P(1)
    addElement(divComplexNum(poly.size, poly.data[0]), &res); 
    for (int i = 1; i < poly.size; i++){
        addElement(divComplexNum(poly.size, poly.data[poly.size-i]), &res); //将i位改成size-i
    }
    delPoly(poly);
    return res;
}
