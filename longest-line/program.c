#include <stdio.h>
#include "../common/common.h"
#include "../str/str.h"

// read input and print line with maximum length

#define MAXLINE 1000

int main()
{
  int len, max;

  char line[MAXLINE];
  char save[MAXLINE];

  max = 0;
  while ((len = getlinelim(line, MAXLINE)) > 0)
  {
    if (len > max)
    {
      max = len;
      strcopy(line, save);
    }
  }

  if (max > 0)
    printf("%s\n", save);

  return 0;
}
