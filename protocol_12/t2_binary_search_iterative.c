#include <stdlib.h>
#include <stdio.h>
#include "../helpers/print_arr.h"

// Looks for a integer in an array via the binary search algorithm
// Returns the index of the found element or -1 if it is not found
// Time complexity: O(log(n))
// Space complexity: O(n)
int binary_search(int *arr, int arr_len, int needle)
{
  int found_index = -1;
  int left = 0;
  int right = arr_len - 1;
  int mid = (left + right) / 2;
  while (left <= right)
  {

    if (arr[mid] == needle)
    {
      found_index = mid;
      break;
    }

    if (arr[mid] < needle)
    {
      left = mid + 1;
    }
    else
    {
      right = mid - 1;
    }

    mid = (left + right) / 2;
  }

  return found_index;
}

int main()
{
  int arr[] = {1, 2, 3, 5, 9, 11, 12};
  int arr_len = sizeof(arr) / sizeof(arr[0]);

  printf("Input arr: ");
  print_arr(arr, arr_len);

  int look_for = 1;
  printf("Looking for %d\n", look_for);
  printf("Element found at index: %d\n", binary_search(arr, arr_len, look_for));

  look_for = 12;
  printf("Looking for %d\n", look_for);
  printf("Element found at index: %d\n", binary_search(arr, arr_len, look_for));

  look_for = 10;
  printf("Looking for %d\n", look_for);
  printf("Element found at index: %d\n", binary_search(arr, arr_len, look_for));

  return 0;
}