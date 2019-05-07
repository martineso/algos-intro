#include <stdio.h>
#include <stdlib.h>

int* append_arr (int* a, int a_len, int* b, int b_len) {
    int* out = malloc( (a_len + b_len) * sizeof(int) );

    for (int i = 0; i < a_len + b_len; i++) {
        if (i < a_len) {
            out[i] = a[i];
        } else {
            out[i] = b[i - b_len - 1];
        }
    }

    return out;
}

int main () {
    int a_len = 4;
    int b_len = 3;
    int a[] = {1,2,3,4};
    int b[] = {5,6,7};
    int* merged = append_arr(a, a_len, b, b_len);

    printf("Merged arr: \n");
    printf("[ ");
    for (int i = 0; i < a_len + b_len; i++) {
        printf("%d ", merged[i]);
    }
    printf("]");

    free(merged);
    return 0;
}