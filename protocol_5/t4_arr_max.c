#include <stdio.h>
#include <stdlib.h>

// O(n) time complexity
// Finds the max element of unsorted array of integers
int arr_max (int* arr, int arr_len) {
    int max = arr[0];
    for (int i = 0; i < arr_len; i++) {
        if (max < arr[i]) {
            max = arr[i];
        }
    }

    return max;
}

int main () {

    printf("Enter the size of the array: \n");
    char line[256];
    int arr_len;
    int* arr = NULL;
    if (fgets(line, sizeof(line), stdin)) {
        if (1 == sscanf(line, "%d", &arr_len)) {
            arr = malloc(arr_len * sizeof(int));

            int el;
            printf("Enter the array elements followed by enter: \n");
            for (int i = 0; i < arr_len; i++) {
                if (fgets(line, sizeof(line), stdin)) {
                    if (1 == sscanf(line, "%d", &el)) {
                        arr[i] = el;
                    }
                }
            }
        }
    }

    printf("Max %d", arr_max(arr, arr_len));
    free(arr);
    return 0;
}