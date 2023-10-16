
struct Matrix LU_decompose(struct Matrix a){
    for (int i = 0; i < a.tailleMAX; i++){
        for (int j = 0; j < a.tailleMAX; j++){
            // go to u-op
            if (i <= j){
                double somme = 0;
                for (int k = 0; k < i; k++)
                    somme += a.data[i][k]*a.data[k][j];
                a.data[i][j] -= somme;
            }
            // go to l-op
            else {
                double somme = 0;
                for (int k = 0; k < j; k++)
                    somme += a.data[i][k]*a.data[k][j];
                a.data[i][j] -= somme;
                a.data[i][j] /= a.data[j][j];
            }
        }
    }
    return a;
}


struct Matrix get_U(struct Matrix a){
    struct Matrix res = {
        .tailleMAX = a.tailleMAX
    };
    for (int i = 0; i < a.tailleMAX; i++){
        for (int j = 0; j < a.tailleMAX; j++){
            if (i <= j) 
                res.data[i][j] = a.data[i][j];
            else 
                res.data[i][j] = 0;
        }
    }
    return res;
}

struct Matrix get_L(struct Matrix a){
    struct Matrix res = {
        .tailleMAX = a.tailleMAX
    };
    for (int i = 0; i < a.tailleMAX; i++){
        for (int j = 0; j < a.tailleMAX; j++){
            if (i > j)
                res.data[i][j] = a.data[i][j];
            else if (i == j){
                res.data[i][j] = 1;
            }
            else 
                res.data[i][j] = 0;
        }
    }
    return res;
}

void swapRows(double arr[MAX][MAX], int i, int j){
    for (int k = 0; k < MAX; k++){
        int temp = arr[i][k];
        arr[i][k] = arr[j][k];
        arr[j][k] = temp;
    }
}

void swapCols(double arr[MAX][MAX], int i, int j){
    for (int k = 0; k < MAX; k++){
        int temp = arr[k][i];
        arr[k][i] = arr[k][j];
        arr[k][j] = temp;
    }
}

struct Matrix PLUQ_decompose(struct Matrix a, struct Matrix* p, struct Matrix* q){
    int max_i = 0, max_j = 0, max_nb = a.data[0][0];

    for (int i = 0; i < a.tailleMAX; i++){
        for (int j = 0; j < a.tailleMAX; j++){
            if (max_nb < a.data[i][j]){
                max_nb = a.data[i][j];
                max_i = i;
                max_j = j;
            }
        }
    }

    // switch row 0, i
    swapRows(p->data, 0, max_i);
    swapRows(a.data, 0, max_i);
    // switch col 0, j
    swapRows(p->data, 0, max_j);
    swapCols(a.data, 0, max_j);

    a = LU_decompose(a);
    return a;
}

void solveLinaireSys(double vec[MAX], struct Matrix a, double x[MAX]){
    /* 
        vec - stocker les resultats de sys 
        sys : a * vec = x 
    */ 

    struct Matrix res, L, U;
    res = LU_decompose(a);
    L = get_L(res);
    U = get_U(res);
    
}

mpfr_t* matrixProduitTrans(struct Matrix a, double vec[MAX]){
    mpfr_t *dest = malloc(sizeof(mpfr_t)*MAX);

    for (int i = 0; i < a.tailleMAX; i++) {
        for (int j = 0; j < a.tailleMAX; j++) {
            if (a.data[i][j] == 1){
                dest[i] = vec[j];
            }
        }
    }

    return dest;
}

mpfr_t* upperTriangleSysAlgo(struct Matrix a, double vec[MAX]){
    mpfr_t* dest = malloc(sizeof(mpfr_t)*MAX);

    // copier b à x
    memcpy(dest, vec, MAX*sizeof(double));
    for (int i = 0; i < MAX; i++){
        printf("%.6f ", dest[i]);
    }
    printf("\n");

    // substitution of sys
    for (int i = a.tailleMAX-1; i >= 0; i--) {
        dest[i] = (double)dest[i]/a.data[i][i];
        for (int j = i-1; j >= 0; j--) {
            dest[j] -= dest[i]*a.data[j][i]; 
        }
    }

    return dest;
}

void matrixTranspose(struct Matrix* matrix){
    for (int i = 0; i < matrix->tailleMAX; i++) {
        for (int j = i+1; j < matrix->tailleMAX; j++) {
            double curr = matrix->data[i][j];
            matrix->data[i][j] = matrix->data[j][i];
            matrix->data[j][i] = curr;
        }
    }
}