#include <stdio.h>
#include "../common/common.h"
#include "../str/str-ptr.h"

#define MAXLINE 1000

void fold(char[], char[], int);

int main()
{
  char line[MAXLINE];
  char input[MAXLINE];
  char output[MAXLINE];
  FILE *file;

  file = fopen("../text.txt", "r");
  *output = *input = '\0';

  while (getlinefile(file, line, MAXLINE) > 0)
    strcaten(input, line);

  fold(input, output, 24);
  printf("%s\n", output);

  return 0;
}

void fold(char s[], char d[], int n)
{
  int i, l, w;

  for (i = 0, l = 0, w = 0; s[i] != '\0'; ++i, ++l)
  {
    if (l < n)
    {
      if (s[i] == ' ' || s[i] == '\n')
        w = i;
      if (s[i] == '\n')
        d[i] == ' ';
      else
        d[i] = s[i];
    }
    else
    {
      i = w;
      d[i] = '\n';
      l = 0;
    }
  }
}