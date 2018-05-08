#include <stdio.h>
#include "math.h"

int main(int argc, char *argv[])
{
  if (argc > 0)
  {
    //(argv[1])
  }

  int a = power(2, 8);
  printf("%d\n", a);
  double b = sqrt(a);
  printf("%f\n", b);

  return 0;
}