#include <stdio.h>
#include <stdlib.h>
#include "../helpers/print_arr.h"

int* _merge_arr (int* a, int a_len, int* b, int b_len) {
    int merge_len = a_len + b_len;
    int* merged = malloc( merge_len * sizeof(int) );
    // We know that a_len >= b_len
    int min_len = a_len <= b_len ? a_len : b_len;
    int i = 0;
    int a_index = 0;
    int b_index = 0;
    while (i < min_len) {
        merged[i++] = a[a_index++];
        merged[i++] = b[b_index++];
    }

    if (a_len != b_len) {
        while (a_index < a_len) {
            merged[i++] = a[a_index++];
        }
    }

    return merged;
}

int* merge_arr (int* a, int a_len, int* b, int b_len) {
    if (a_len >= b_len) {
        return _merge_arr (a, a_len, b, b_len);
    }
    return _merge_arr (b, b_len, a, a_len);
}

int main () {

    int a[] = {1, 4, 9, 16, 9, 7, 4};
    int a_len = 7;
    int b[] = {1, 4, 9, 16, 9, 7};
    int b_len = 6;

    int* merged = merge_arr(a, a_len, b, b_len);
    print_arr(merged, a_len+b_len);
    return 0;
}