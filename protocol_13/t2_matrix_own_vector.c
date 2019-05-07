#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../helpers/print_arr.h"
#define N 3

double round_2_dec(double num, int precision)
{
  double dp = 10.00;
  if (precision > 1)
  {
    dp = pow(dp, (double)precision);
  }

  return ceilf(num * dp) / dp;
}

// Multiplies matrices of size mxn where n is = 3
void multiply_matrices(double matrix_a[N][N], int matrix_a_rows, double matrix_b[N][N], int matrix_b_rows, double matrix_res[N][N])
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

void copy_square_matrix(double source_matrix[N][N], double dest_matrix[N][N])
{
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      dest_matrix[i][j] = source_matrix[i][j];
    }
  }
}

void print_matrix(double matrix[N][N])
{
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      printf("%.4lf\t", matrix[i][j]);
    }
    printf("\n");
  }
}

int compare_vectors(double *v_1, int v1_len, double *v_2, int v2_len, int precision)
{
  int are_equal = 0;

  if (v1_len != v2_len)
  {
    return 0;
  }

  for (int i = 0; i < v2_len; i++)
  {
    double rounded = round_2_dec(v_1[i] - v_2[i], precision);
    if (fabs(rounded) == 0.0000)
    {
      are_equal = 1;
    }
    else
    {
      are_equal = 0;
    }
  }

  return are_equal;
}

double *calculate_own_vector(double matrix[N][N])
{
  double row_sums[N];
  double sum = 0;
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      sum += matrix[i][j];
    }
    row_sums[i] = sum;
    sum = 0;
  }

  double total_sum = 0;
  for (int i = 0; i < N; i++)
  {
    total_sum += row_sums[i];
  }

  double *own_vector = malloc(N * sizeof(double));
  for (int i = 0; i < N; i++)
  {
    own_vector[i] = row_sums[i] / total_sum;
  }

  return own_vector;
}

double *matrix_vector(double matrix[N][N])
{
  double *own_vector_1, *own_vector_2;
  double sq_matrix_1[N][N];
  double sq_matrix_2[N][N];

  // 4 decimal points
  int float_precision = 4;
  int done = 0;
  int i = 0;

  while (!done)
  {
    multiply_matrices(matrix, N, matrix, N, sq_matrix_1);
    printf("sq_matrix_1 \n");
    print_matrix(sq_matrix_1);
    own_vector_1 = calculate_own_vector(sq_matrix_1);

    printf("own_vector_1 at iterations %i\t", i);
    print_arrf(own_vector_1, N);

    multiply_matrices(sq_matrix_1, N, sq_matrix_1, N, sq_matrix_2);
    printf("sq_matrix_2 \n");
    print_matrix(sq_matrix_2);
    own_vector_2 = calculate_own_vector(sq_matrix_2);

    printf("own_vector_2 at iterations %i\t", i);
    print_arrf(own_vector_2, N);
    int are_equal = compare_vectors(own_vector_1, N, own_vector_2, N, float_precision);
    if (are_equal)
    {
      done = 1;
    }

    copy_square_matrix(sq_matrix_1, matrix);
    copy_square_matrix(sq_matrix_2, sq_matrix_1);
    i++;
  }

  free(own_vector_1);
  return own_vector_2;
}

int main()
{
  double matrix[N][N] = {
      {1.0000, 0.5000, 3.0000},
      {2.0000, 1.0000, 4.0000},
      {0.3333, 0.2500, 1.0000},
  };
  double *own_vector = matrix_vector(matrix);

  print_arrf(own_vector, N);
  free(own_vector);
  return 0;
}