#include <stdio.h>
#include <math.h>

int factorial (int n) {
    int factorial = 1;
    while (n > 0) {
        factorial *= n;
        n--;
    }
    return factorial;
}

long double custom_sin (double x, int limit) {
    long double sin_res = 0.0;
    long double quotient;

    for (int i = 0; i < limit; i++) {
        quotient = pow(-1, i) * (double)pow(x, (2 * i + 1));
        sin_res += quotient / factorial(2 * i + 1);
    }

    return sin_res;
}

int main () {
    const double x = 180.00;

    long double sin_res = custom_sin(x, 2000);

    printf("Sine of %f is %.2f", x, sin_res);
    return 0;
}