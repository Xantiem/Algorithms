#include <stdio.h>
#include <time.h>

extern double _deviation_from_mean(double x, double mean);

double deviation_from_mean(double x, double mean) {
    return (x - mean);
}

int main() {

    clock_t start = clock();

    // do stuff
    for (int i = 0; i < 1000; i++)
        deviation_from_mean(i, i+1);

    clock_t end = clock();
    double time_taken = ((double)end - (double)start) / CLOCKS_PER_SEC * 1000000;
    printf("time taken: %.2f us (microseconds)/n", time_taken);

    start = clock();

    // do stuff
    for (int i = 0; i < 1000; i++)
        _deviation_from_mean(i, i+1);

    end = clock();
    time_taken = ((double)end - (double)start) / CLOCKS_PER_SEC * 1000000;
    printf("time taken: %.2f us (microseconds)/n", time_taken);

    return 0;

    // averaging a 6 microsecond improvement in performance
}