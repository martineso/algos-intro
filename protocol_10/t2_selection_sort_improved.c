#include <stdlib.h>
#include <stdio.h>
#include "../helpers/print_arr.h"

void swap(int *arr, int a, int b)
{
  int temp = arr[a];
  arr[a] = arr[b];
  arr[b] = temp;
}

void selection_sort_improved(int *arr, int arr_len)
{
  int min, max, max_val;
  for (int i = 0, k = arr_len - 1; i < k; i++, k--)
  {
    max = k;
    min = i;
    for (int j = i; j <= k; j++)
    {
      if (arr[j] < arr[min])
      {
        min = j;
      }
      if (arr[j] > arr[max])
      {
        max_val = arr[j];
        max = j;
      }
    }

    // Swap elements
    swap(arr, min, i);

    if (arr[min] == max_val)
    {
      swap(arr, k, min);
    }
    else
    {
      swap(arr, k, max);
    }
  }
}

int main()
{
  int arr[] = {3, 11, 2, 9, 1, 5, 12};
  int arr_len = sizeof(arr) / sizeof(arr[0]);

  printf("Input arr: ");
  print_arr(arr, arr_len);

  selection_sort_improved(arr, arr_len);

  printf("Sorted arr: ");
  print_arr(arr, arr_len);
  return 0;
}
