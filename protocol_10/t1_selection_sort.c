#include <stdlib.h>
#include <stdio.h>
#include "../helpers/print_arr.h"

void selection_sort(int *arr, int arr_len)
{
  int min, temp;
  for (int i = 0; i < arr_len - 1; i++)
  {
    min = i;
    for (int j = i + 1; j < arr_len; j++)
    {
      if (arr[j] < arr[min])
      {
        min = j;
      }
    }

    // Swap elements 
    temp = arr[i];
    arr[i] = arr[min];
    arr[min] = temp;
  }
}

int main()
{
  int arr[] = {3, 11, 2, 9, 1, 5, 12};
  int arr_len = sizeof(arr) / sizeof(arr[0]);

  printf("Input arr: ");
  print_arr(arr, arr_len);
  
  selection_sort(arr, arr_len);

  printf("Sorted arr: ");
  print_arr(arr, arr_len);
  return 0;
}