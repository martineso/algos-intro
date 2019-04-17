#include <stdio.h>

float f (float x) {
  return x*x*x - x*x + 2;
}

float root (float (*f_ptr)(float), float left, float right, float tol) {
  // Check if left and right have different signs
  if (left * right >= 0.00) {
    printf("Invalid range [a-b]\n");
    return 0.0;
  }

  float root;
  float step  = tol * 2;
  float curr_left = left, 
        curr_right = left + step;
  while (curr_right <= right) {

    // Check if the curr_left and curr_right are with different signs
    if ((f(curr_left) * f(curr_right)) < 0.0) {
      root = ((curr_left + curr_right) / 2);
    }

    curr_left = curr_right;
    curr_right += step;
  }
  
  return root;
}

int main () {
  
  printf("Root: %f\n", root(f, -2, 10, 0.01));
  return 0; 
}