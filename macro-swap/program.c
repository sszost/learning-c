#include <stdio.h>

// we name temporary variable SWAP to avoid naming conflicts
// with local variable named for example temp
// (it breaks if x is temp or y is temp and SWAP is temp)
#define SWAP(x, y) \
  {                \
    int SWAP = x;  \
    x = y;         \
    y = SWAP;      \
  }                \
  while (0) // it's a canonical form for macros which addresses the problem of an invalid ; in an if/else construct.

int main(int argc, char *argv[])
{
  if (argc > 0)
  {
    //(argv[1])
  }
  int x = 20, y = 4;
  SWAP(x, y);
  printf("%d %d\n", x, y);

  return 0;
}