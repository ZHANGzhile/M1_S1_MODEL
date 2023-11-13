/*
    Auteur :
        ZHOU    runlin      28717281
        ZHANG   zhile       21201131
        XU      mengqian    21306077
*/

#include "utils.h"

// debut de la partie : affichage
void printComplexNumber(struct numComplex num){
    if (num.imaginary >= 0)
        printf("%f + %f i\n", num.real, num.imaginary);
    else{
        printf("%f - %f i\n", num.real, -num.imaginary);
    }
}

void printComplexNumberVec(struct numComplex *numVec, int size){
    for (int i = 0; i < size; i++){
        printComplexNumber(numVec[i]);
    }
}
// fin de la partie : affichage

// debut de la partie : generate complex number
struct numComplex randomConsNumber(){
    struct numComplex res = {rand()%10, rand()%10};
    return res;
}   

struct numComplex* randomConsVec(int size){
    struct numComplex* res = malloc(sizeof(struct numComplex)*size);
    for (int i = 0; i < size; i++){
        res[i] = randomConsNumber();
    }
    return res;
}

struct numComplex zeroComplexNum(){
    struct numComplex res = {0, 0};
    return res;
}
// fin de la partie : generate complex number

// debut de la partie : calculations for complex number
struct numComplex addComplexNumber(struct numComplex numA, struct numComplex numB){
    struct numComplex res = {numA.real + numB.real, numA.imaginary + numB.imaginary };
    return res;
}

struct numComplex multComplexNumber(struct numComplex numA, struct numComplex numB){
    struct numComplex res = {numA.real*numB.real - numA.imaginary*numB.imaginary, numA.imaginary*numB.real + numA.real*numB.imaginary};
    return res;
}

struct numComplex divComplexNum(int n, struct numComplex num){
    struct numComplex res;
    res.real = (double)(num.real/n);
    res.imaginary = (double)(num.imaginary/n);
    return res;
}

struct numComplex* primitiveRoot(int n){
    struct numComplex* res = malloc(sizeof(struct numComplex)*n);
    
    // debut de init
    // 将1+0i填入数组头部
    struct numComplex one = {1, 0};
    res[0] = one;
    
    // 判断模式
    struct numComplex primitive = {cos(2*M_PI/n), sin(2*M_PI/n)};
    // fin de init
    
    struct numComplex curr = primitive;  
    // boucle forte pour remplir les valeurs
    for (int cpt = 1; cpt < n; cpt++){
        res[cpt] = curr;
        curr = multComplexNumber(curr, primitive);
    }
    
    return res;
}
// fin de la partie : calculations for complex number