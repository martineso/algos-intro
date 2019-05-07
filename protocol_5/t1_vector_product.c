#include <stdio.h>

int dot_product (int* a, int a_len, int* b, int b_len) {
    // Dot product defined only for vectors of the same space
    if (a_len != b_len) {
        return -1;
    }
    
    int product = 0;
    for (int i = 0; i < a_len; i++) {
        product += a[i] * b[i];
    }

    return product;
}

int main (void) {

    int a[] = {1, 2, 3};
    int b[] = {1, 2, 3};

    printf("Product %d", dot_product(a, 3, b, 3));
    return 0;
}