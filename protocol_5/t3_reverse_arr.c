#include <stdio.h>

// Mutating
void reverse_arr (int* arr, int arr_len) {
    int temp;
    for (int i = 0; i < arr_len / 2; i++) {
        temp = arr[i];
        arr[i] = arr[arr_len - i - 1];
        arr[arr_len - i - 1] = temp;
    }
}

int main () {

    int arr[] = {1, 4, 9, 16, 9, 7, 4};
    int arr_len = 7;

    reverse_arr(arr, arr_len);
    printf("Arr reversed \n");
    for (int i = 0; i < arr_len; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}