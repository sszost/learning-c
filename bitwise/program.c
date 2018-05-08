#include <stdio.h>
#include "bitwise.h"

int main(int argc, char *argv[])
{
  if (argc > 0)
  {
    //(argv[1])
  }

  unsigned x = 1608081369;
  printf("%u\n", countbits(x));
  printb(x);
  printb(invert(x, 11, 8));
  printb(getbits(x, 11, 8));
  printb(getbitsl(x, 11, 8));
  printb(rightrot(x, 8));
  return 0;
}
