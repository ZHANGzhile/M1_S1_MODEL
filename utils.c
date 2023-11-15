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

void printPoly(struct polynomial poly){
    for (int i = 0; i < poly.cpt; i++){
        printComplexNumber(poly.data[i]);
    }
}
// fin de la partie : affichage

// debut de la partie : gestion des structures
    // gestion pour numComplex
struct numComplex creatComplexNum(double real, double imaginary){
    struct numComplex res = {real, imaginary};
    return res;
}

struct numComplex zeroComplexNum(){
    return creatComplexNum(0, 0);
}

struct numComplex randomConsNumber(){
    return creatComplexNum(rand()%10, rand()%10);
} 

int isEqNum(struct numComplex numA, struct numComplex numB){
    if (numA.real == numB.real && numA.imaginary == numB.imaginary){
        return 1;
    }
    return 0;
}

    // gestion pour polynomial
struct polynomial createPoly(int size){
    struct polynomial res;
    res.data = malloc(sizeof(struct numComplex)*size);
    res.cpt = 0;
    res.size = size;
    return res;
}

struct polynomial createRandomPoly(int size){
    struct polynomial res = createPoly(size);
    for (int i = 0; i < res.size; i++){
        addElement(randomConsNumber(), &res);
    }
    return res;
}

void delPoly(struct polynomial poly){
    free(poly.data);
}

int addElement(struct numComplex el, struct polynomial* poly){
    if (poly->cpt == poly->size){
        printf("Err : failed to add element \n");
        return 0;
    }
    poly->data[poly->cpt] = el;
    poly->cpt++;
    return 1;
}

int subElement(int index, struct polynomial* poly){
    if (poly->cpt >= index){
        for (int i = index; i < poly->cpt-1; i++){
            poly->data[i] = poly->data[i+1];
        }
        poly->cpt--;
        return 1;
    }
    printf(" Err : no such element or this poly is empty \n");
    return 0;
}

int isEqPoly(struct polynomial polyA, struct polynomial polyB){
    if (polyA.cpt != polyB.cpt){
        return 0;
    }
    for(int i = 0; i < polyA.cpt; i++){
        if (! isEqNum(polyA.data[i], polyB.data[i])){
            return 0;
        }
    }
    return 1;
}
// fin de la partie : gestion des structures

// debut de la partie : arithmétique élémentaire pour complex number
struct numComplex addComplexNumber(struct numComplex numA, struct numComplex numB){
    struct numComplex res = {numA.real + numB.real, numA.imaginary + numB.imaginary };
    return res;
}

struct numComplex multComplexNumber(struct numComplex numA, struct numComplex numB){
    struct numComplex res = { numA.real*numB.real - numA.imaginary*numB.imaginary, 
                              numA.imaginary*numB.real + numA.real*numB.imaginary
                            };
    return res;
}

struct numComplex divComplexNum(int n, struct numComplex num){
    struct numComplex res;
    res.real = (double)(num.real/n);
    res.imaginary = (double)(num.imaginary/n);
    return res;
}

struct polynomial rootList(int n){
    struct polynomial res = createPoly(n);
    
    // debut de init
    // 将1+0i填入数组头部
    addElement(creatComplexNum(1, 0), &res);
    
    // 判断模式
    struct numComplex primitive = creatComplexNum(cos(2*M_PI/n), sin(2*M_PI/n));
    // fin de init
    
    struct numComplex curr = primitive;  
    // boucle forte pour remplir les valeurs
    for (int cpt = 1; cpt < n; cpt++){
        addElement(curr, &res);
        curr = multComplexNumber(curr, primitive);
    }
    
    return res;
}

int getNearestK(int size){
    int k = log2(size);
    if (pow(2, k) < size){
        k += 1;
    }
    return k;
}

// fin de la partie : arithmétique élémentaire pour complex number