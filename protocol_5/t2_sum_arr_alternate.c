#include <stdio.h>
#include <math.h>

int arr_sum_alterate (int* arr, int arr_len) {

    int sum = 0;
    int sign = -1;
    for (int i = 0; i < arr_len; i++) {
        sign = pow(-1, i + 1);
        sum += sign * arr[i];
    }
    return sum;
}

int main () {
    int arr[] = {1, 4, 9, 16, 9, 7, 4, 9, 11};
    int arr_len = 9;

    printf("Sum = %d", arr_sum_alterate(arr, arr_len));
    return 0;
}