#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utils.h"
#include "multPoly.h"
#include "fastFourierTrans.h"

void exportResults(int* sizes, double* naive_times, double* fft_times, int num_points) {
    FILE* file = fopen("benchmark_results.csv", "w");

    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "Size,NaiveTime,FFTTime\n");

    for (int i = 0; i < num_points; i++) {
        fprintf(file, "%d,%f,%f\n", sizes[i], naive_times[i], fft_times[i]);
    }

    fclose(file);
}
// Function to measure the time taken by a function
double measureTime(struct polynomial (*function)(struct polynomial, struct polynomial), struct polynomial polyA, struct polynomial polyB) {
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    function(polyA, polyB);
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    return cpu_time_used;
}

void runBenchmarks(int n) {
    int sizes[n];
    for (int i = 0; i < n; i++) {
        sizes[i] = i + 1;
    }

    int num_points = n;

    double naive_times[num_points];
    double fft_times[num_points];

    for (int i = 0; i < num_points; i++) {
        int size = sizes[i];

        struct polynomial polyA = createRandomPoly(size);
        struct polynomial polyB = createRandomPoly(size);

        double naiveTime = measureTime(NaiveMultPoly, polyA, polyB);
        double fftTime = measureTime(fftMultPoly, polyA, polyB);

        naive_times[i] = naiveTime;
        fft_times[i] = fftTime;

        //delPoly(polyA);
        //delPoly(polyB);
    }

    exportResults(sizes, naive_times, fft_times, num_points);
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    runBenchmarks(n);

    return 0;
}
