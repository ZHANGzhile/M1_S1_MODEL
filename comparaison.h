/*
    Auteur :
        ZHOU    runlin      28717281
        ZHANG   zhile       21201131
        XU      mengqian    21306077
*/

#ifndef COMPARAISION
#define COMPARAISION
#include "utils.h"
#include "fastFourierTrans.h"
#include "multPoly.h"

//Ouvre le fichier et enregistre les paramètres dans le fichier
void exportResults(int* sizes, double* naive_times, double* fft_times, int num_points);
//Calculer le temps de fonctionnement
double measureTime(struct polynomial (*function)(struct polynomial, struct polynomial), struct polynomial polyA, struct polynomial polyB);
//Enregistre le temps d'exécution de NaiveMultPoly et fftMultPoly à partir de n=1 respectivement et stocke-les dans des fichiers
void runBenchmarks(int n);


#endif