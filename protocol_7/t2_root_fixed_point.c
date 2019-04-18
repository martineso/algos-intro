#include <stdio.h>
#include <math.h>

double f(double x)
{
  return (double)(pow(x, 4.0) - x - 10);
}

// Not convergent
double g(double x)
{
  return (double)(10.0 / (pow(x, 3.0) - 1));
}

// Convergent
double g2(double x)
{
  return (double)(pow((x + 10), 0.25));
}

// Fixed point iteration algorithm
// Link - https://mat.iitm.ac.in/home/sryedida/public_html/caimna/transcendental/iteration%20methods/fixed-point/iteration.html

double root(double (*f)(double), double (*g)(double), double x0, int n, double tol)
{
  int step = 0;
  double current, x1;

  do
  {
    x1 = g(x0);
    step++;
    current = x0;
    x0 = x1;
  } while (fabs(x1 - g(current)) < tol && step <= n);

  return x1;
}

int main()
{
  const double e = 0.000001;

  printf("Root fixed point iteration - %f\n", root(f, g2, 2.0, 10, e));
  printf("test");
  return 0;
}