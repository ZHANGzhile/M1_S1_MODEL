# ifndef LU_FAC_H

#define MAX 4

struct Matrix{
    int tailleMAX;
    double data[MAX][MAX];
};


struct Matrix LU_decompose(struct Matrix a);

struct Matrix get_U(struct Matrix a);

struct Matrix get_L(struct Matrix a);

struct Matrix PLUQ_decompose(struct Matrix a, struct Matrix* p, struct Matrix* q);

void swapCols(double arr[MAX][MAX], int i, int j);
void swapRows(double arr[MAX][MAX], int i, int j);
# endif