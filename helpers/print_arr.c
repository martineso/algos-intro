#include <stdio.h>
#include "print_arr.h"

void print_arr (int* arr, int arr_len) {
    printf("[ ");
    for (int i = 0; i < arr_len; i++) {
        if (i == arr_len - 1) {
            printf("%d", arr[i]);
            printf(" ]");
        } else {
            printf("%d, ", arr[i]);
        }
    }
};