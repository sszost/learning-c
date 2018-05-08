#include <stdio.h>
#include "convert.h"

int atoi(char *s);

int main(int argc, char *argv[])
{
  if (argc > 0)
  {
    //(argv[1])
  }
  char r[] = "420420";
  printf("%d\n", atoi(r));

  char s[] = " -240";
  printf("%d\n", atoi(s) + 20);

  char c[20];
  itoa(-5371, c);
  printf("%s\n", c);

  char h[20];
  itoh(-317547, h);
  printf("%s\n", h);

  double d = atof(" -2.2420e+012");
  printf("%f\n", d);

  return 0;
}
