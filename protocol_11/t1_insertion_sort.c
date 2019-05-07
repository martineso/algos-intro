#include <stdio.h>
#include "../helpers/print_arr.h"

// Insertion sort iterative approach
// https://en.wikipedia.org/wiki/Insertion_sort
// Time-complexity: O(n^2)
// Space-complexity: O(n)
void insertion_sort(int *arr, int arr_len)
{
  int i, j, current; 
  i = 1;
  while (i < arr_len) {
    current = arr[i];
    j = i - 1;
    while (j >= 0 && arr[j] > current) {
      arr[j+1] = arr[j];
      --j;
    }
    arr[j+1] = current;
    ++i;
  }
}

int main()
{
  int arr[] = {3, 11, 2, 9, 1, 5, 12};
  int arr_len = sizeof(arr) / sizeof(arr[0]);

  printf("Input arr: ");
  print_arr(arr, arr_len);

  insertion_sort(arr, arr_len);

  printf("Sorted arr: ");
  print_arr(arr, arr_len);
  return 0;
}