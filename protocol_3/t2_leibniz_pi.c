#include <stdio.h>
#include <math.h>

double pi_leibniz (int n) {
    double pi = 0.0;
    for (int i = 1; i < n; i++) {
        pi += pow(-1, i+1) / (2*i - 1);
    }

    return pi;
}

int main () {
    // A lot of iterations are necessary to achieve a good precision
    int n = 10000000;
    double pi = pi_leibniz(n) * 4;
    printf("Pi after %d iterations is %f", n, pi);

    return 0;
}