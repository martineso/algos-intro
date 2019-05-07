#include <stdio.h>
#include "arr_max.h"

// O(n) time complexity
// Finds the max element of unsorted array of integers
int arr_max(int *arr, int arr_len)
{
  int max = arr[0];
  for (int i = 0; i < arr_len; i++)
  {
    if (max < arr[i])
    {
      max = arr[i];
    }
  }

  return max;
};
