// count number of words, lines and characters from input
#include <stdio.h>

#define YES 1
#define NO 0

int main()
{
  int c, nw, nl, nc, inword;

  inword = NO;
  nw = nl = nc = 0;
  while ((c = getchar()) != EOF)
  {
    ++nc;
    if (c == '\n')
      ++nl;
    if (c == ' ' || c == '\n' || c == '\t')
      inword = NO;
    else if (!inword)
    {
      inword = YES;
      ++nw;
    }
  }
  printf("%d %d %d\n", nw, nl, nc);

  return 0;
}