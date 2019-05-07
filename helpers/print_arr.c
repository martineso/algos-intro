#include <stdio.h>
#include "print_arr.h"

void print_arr(int *arr, int arr_len)
{
    printf("[ ");
    for (int i = 0; i < arr_len; i++)
    {
        if (i == arr_len - 1)
        {
            printf("%d", arr[i]);
            printf(" ]\n");
        }
        else
        {
            printf("%d, ", arr[i]);
        }
    }
};

void print_arrf(double *arr, int arr_len)
{
    printf("[ ");
    for (int i = 0; i < arr_len; i++)
    {
        if (i == arr_len - 1)
        {
            printf("%f", arr[i]);
            printf(" ]\n");
        }
        else
        {
            printf("%f, ", arr[i]);
        }
    }
};