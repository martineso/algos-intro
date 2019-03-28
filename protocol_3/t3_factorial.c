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

int main () {
    int n = 5;
    printf("Factorial of %d is %d", n, factorial(n));
    return 0;
}

