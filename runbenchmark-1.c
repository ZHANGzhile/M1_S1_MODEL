#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utils.h"
#include "multPoly.h"
#include "fastFourierTrans.h"



void exportResultsToFile(int* sizes, double* naive_times, double* fft_times, int num_points) {
    FILE* file = fopen("results.dat", "w");
    printf("hhh\n");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < num_points; i++) {
        fprintf(file, "%d %f %f\n", sizes[i], naive_times[i], fft_times[i]);
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
    int num_points = n;
    int sizes[num_points];
    double naive_times[num_points];
    double fft_times[num_points];
    printf("hhh\n");
    for (int i = 0; i < num_points; i++) {
        int size = i ;  // Start from size= 0

        sizes[i] = size;

        struct polynomial polyA = createRandomPoly(size);
        struct polynomial polyB = createRandomPoly(size);

        double naiveTime = measureTime(NaiveMultPoly, polyA, polyB);
        double fftTime = measureTime(fftMultPoly, polyA, polyB);

        naive_times[i] = naiveTime;
        fft_times[i] = fftTime;

        delPoly(polyA);
        delPoly(polyB);
    }

    exportResultsToFile(sizes, naive_times, fft_times, num_points);
}

int main() {
    int n = 10;  // Set the desired value of n
    runBenchmarks(n);
    printf("hhhh\n");

    // Plot the results using gnuplot
    FILE* gnuplotPipe = popen("gnuplot -persistent", "w");
    fprintf(gnuplotPipe, "plot 'results.dat' using 1:2 with linespoints title 'Naive MultPoly', \
                                    'results.dat' using 1:3 with linespoints title 'FFT MultPoly'\n");
    fclose(gnuplotPipe);

    return 0;
}
