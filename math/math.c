//newtonian square root approximation
double sqrt(double n)
{
  double x, p, f;

  // f(x)/f'(x) --> x^2-n / 2x
  for (f = x = 1, p = 1e-7; (f < 0 ? -f : f) > p; x -= f)
    f = (x * x - n) / (n * 2);
  return x;
}

int power(int x, int n)
{
  int p;
  for (p = 1; n > 0 ; --n)
    p *= x;
  return p;
}