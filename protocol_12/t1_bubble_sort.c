#include <stdlib.h>
#include <stdio.h>
#include "../helpers/print_arr.h"

void swap(int *arr, int a, int b)
{
  int temp = arr[a];
  arr[a] = arr[b];
  arr[b] = temp;
}

void bubble_sort(int *arr, int arr_len)
{
  int swapped = 1;
  int n = arr_len;
  while (swapped)
  {
    swapped = 0;
    for (int i = 1; i < n; i++)
    {
      if (arr[i - 1] > arr[i])
      {
        swap(arr, i - 1, i);
        swapped = 1;
      }
    }
    --n;
  }
}

int main()
{
  int arr[] = {3, 11, 2, 9, 1, 5, 12};
  int arr_len = sizeof(arr) / sizeof(arr[0]);

  printf("Input arr: ");
  print_arr(arr, arr_len);

  bubble_sort(arr, arr_len);

  printf("Sorted arr: ");
  print_arr(arr, arr_len);

  return 0;
}
