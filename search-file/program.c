#include <stdio.h>
#include "../common/common.h"

#define MAXLINE 1000

int findidx(char[], char[]);

int main(int argc, char *argv[])
{
  if (argc > 0)
  {
    //(argv[1])
  }

  char line[MAXLINE];
  int n;
  FILE *file;

  file = fopen("../text.txt", "r");
  char s[] = "ips";
  n = 1;

  while (getlinefile(file, line, MAXLINE) > 0)
  {
    if (findidx(line, s) >= 0)
      printf("%d %s", n, line);
    n++;
  }

  return 0;
}

// return leftmost index of t in s, -1 in none
int findidx(char s[], char t[])
{
  int i, j, k;
  for (i = 0; s[i] != '\0'; ++i)
  {
    for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; ++j, ++k)
      ;
    if (t[k] == '\0')
      return i;
  }
  return -1;
}