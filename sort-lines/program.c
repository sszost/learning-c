// read input file and sort lines according to length

#include <stdio.h>
#include "../common/common.h"
#include "../alloc/alloc.h"
#include "../str/str-ptr.h"

#define LINES 100
#define MAXLINE 1000

char *strsave(char *);
void shell_sort(char *[], int);
void writelines(char *[], int);

int main(int argc, char *argv[])
{
  if (argc > 0)
  {
    //(argv[1])
  }

  FILE *file;
  char *lineptr[LINES], line[MAXLINE];
  int nlines;

  file = fopen("../text.txt", "r");
  nlines = 0;

  while (getlinefile(file, line, MAXLINE) > 0)
    lineptr[nlines++] = strsave(line);

  shell_sort(lineptr, nlines);

  char **p = lineptr;
  while (--nlines > 0)
    printf("%s", *p++);

  // writelines(lineptr, nlines);

  return 0;
}

void writelines(char *lineptr[], int nlines)
{
  while (--nlines > 0)
    printf("%s", *lineptr++);
}

char *strsave(char *s)
{
  char *p;
  if ((p = alloc(strl(s) + 1)) > 0)
    strcopy(s, p);
  return p;
}

void shell_sort(char *a[], int n)
{
  int gap, i, j;
  char *temp;

  for (gap = n / 2; gap > 0; gap /= 2)
    for (i = gap; i < n; ++i)
      for (j = i - gap; j >= 0 && strl(a[j]) > strl(a[j + gap]); j -= gap)
      {
        temp = a[j];
        a[j] = a[j + gap];
        a[j + gap] = temp;
      }
}
