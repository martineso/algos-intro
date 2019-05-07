#include <stdlib.h>
#include <stdio.h>
#define N 3

// Multiplies matrices of size mxn where n is = 3
void multiply_matrices(int matrix_a[][N], int matrix_a_rows, int matrix_b[][N], int matrix_b_rows, int matrix_res[][N])
{
  if (matrix_a_rows != N)
  {
    printf("Invalid matrices size! matrix_a should have the same number of rows as matrix_b's columns!\n");
    return;
  }

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      matrix_res[i][j] = 0;
      for (int k = 0; k < N; k++)
      {
        matrix_res[i][j] += matrix_a[i][k] * matrix_b[k][j];
      }
    }
  }
}

int main()
{
  int matrix_a[][N] = {
      {1, 2, 3},
      {4, 5, 6},
      {7, 8, 9},
  };
  int matrix_b[][N] = {
      {4, 5, 6},
      {7, 8, 9},
      {1, 2, 3},
  };

  int result[N][3];

  multiply_matrices(matrix_a, 3, matrix_b, 3, result);
  printf("Multiplied matrix: \n");

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      printf("%d\t", result[i][j]);
    }
    printf("\n");
  }

  return 0;
}