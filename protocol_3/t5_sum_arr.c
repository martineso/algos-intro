#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long int sum_arr(long long int *a, int a_len, long long int *b, int b_len)
{
    a_len = a_len - 1;
    b_len = b_len - 1;

    int smaller_arr_len = a_len <= b_len ? a_len : b_len;
    int larger_arr_len = a_len >= b_len ? a_len : b_len;
    long long int *smaller_arr;
    long long int *larger_arr;

    if (smaller_arr_len == b_len)
    {
        smaller_arr = b;
        larger_arr = a;
    }
    else
    {
        smaller_arr = a;
        larger_arr = b;
    }

    int sum_arr_index = larger_arr_len;
    long long int *sum_arr = (long long int *)malloc((larger_arr_len + 1) * sizeof(long long int));

    long long int sum = 0;
    int carry = 0;

    int larger_arr_index = larger_arr_len;
    int smaller_arr_index = smaller_arr_len;
    // We can sum the two arrays up to smaller_arr_len
    for (; smaller_arr_index >= 0; smaller_arr_index--)
    {
        sum = smaller_arr[smaller_arr_index] + larger_arr[larger_arr_index--] + carry;
        sum_arr[sum_arr_index--] = sum % 10;
        carry = sum / 10;
    }

    for (; larger_arr_index >= 0; larger_arr_index--)
    {
        sum = larger_arr[larger_arr_index] + carry;
        sum_arr[sum_arr_index--] = sum % 10;
        carry = sum / 10;
    }

    // Calculate total
    int multiplier = 1;
    sum = 0;

    for (int i = larger_arr_len; i >= 0; i--)
    {
        sum += sum_arr[i] * multiplier;
        multiplier *= 10;
    }

    free(sum_arr);
    return sum;
}

int main()
{

    long long int a[] = {1, 2, 3};
    long long int b[] = {1, 2, 3, 4, 5};
    int a_size = sizeof(a) / sizeof(a[0]);
    int b_size = sizeof(b) / sizeof(b[0]);

    printf("Sum is %d", sum_arr(a, a_size, b, b_size));
    return 0;
}