#include <stdio.h>
#include <float.h>

#include "timeit.h"

// DBL_MIN (minimum positive value)  
// DBL_MAX (maximum negative value) 
// DBL_DIG (number of digit precision)

extern double _deviation_from_mean(double x, double mean);

double deviation_from_mean(double x, double mean) {
    return (x - mean);
}

int main() {

    double a = 10.2;
    double b = 3.6;
    double result = _deviation_from_mean(a,b);

    printf("%.2f", result);

    return 0;
}