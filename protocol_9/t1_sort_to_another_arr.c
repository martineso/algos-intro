#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../helpers/arr_max.h"
#include "../helpers/print_arr.h"

void sort_arr(int *arr, int arr_len)
{
  int max = arr_max(arr, arr_len);
  int sorted_arr_len = max + 1;
  int *sorted_arr = malloc(sorted_arr_len * sizeof(int));
  // Fill with 0s
  memset(sorted_arr, 0, sorted_arr_len * sizeof(int));

  int pos = 0;
  for (int i = 0; i < arr_len; i++)
  {
    pos = arr[i];
    sorted_arr[pos] = arr[i];
  }

  int index = 0;
  for (int i = 0; i < sorted_arr_len; i++)
  {
    if (sorted_arr[i])
    {
      arr[index] = sorted_arr[i];
      index++;
    }
  }

  free(sorted_arr);
}

int main()
{
  int arr[] = {3, 11, 2, 9, 1, 5};
  printf("Input arr: ");
  print_arr(arr, 6);
  printf("\n");

  sort_arr(arr, 6);

  printf("Sorted arr: ");
  print_arr(arr, 6);
  printf("\n");

  return 0;
}