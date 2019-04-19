#include <stdio.h>
#include <math.h>

double f(double x)
{
  return x * x * x - x - 2;
}

// Root finding method for polynomial
// Pseudo-code -> https://en.wikipedia.org/wiki/Bisection_method
double root_bisection(double (*f)(double), double a, double b, int n, double tol)
{
  double root;

  if (f(a) * f(b) >= 0.00)
  {
    printf("Invalid range [a-b]\n");
    return 0.0;
  }

  int step = 0;
  double c;
  while (step <= n)
  {
    printf("a is %f b is %f\n", a, b);
    c = (a + b) / 2;

    if (f(c) == 0.00 || ((b - a) / 2 < tol))
    {
      root = c;
      break;
    }
    step++;

    if (f(c) * f(a) >= 0.00)
    {
      a = c;
    }
    else
    {
      b = c;
    }
  }

  return root;
}

int main()
{

  const double tol = 0.0001;
  double a = 1.0, b = 2.0;
  double n = 15; 
  double root = root_bisection(f, a, b, 15, tol);

  printf("Root is %f\n", root);
  return 0;
}