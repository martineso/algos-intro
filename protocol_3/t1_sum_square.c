#include <stdio.h>

int sum_square (int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += i * i;
    }
    return sum;
}

int sum_square_2 (int n) {
    int sum = 0;
    for (int i = 2; i < n; i += 2) {
        sum += (i * i) - 2 * i;
    }
    return sum;
}

int sum_square_3 (int n) {
    int sum = 0;
    for (int i = 3; i < n; i += 3) {
        sum += (i * i * i) - 3 * i;
    }
    return sum;
}

int main () {
    
    int sum = sum_square(3);
    printf("Sum %d \n", sum);

    sum = sum_square_2(6);
    printf("Sum %d \n", sum);
    return 0;
}