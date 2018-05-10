#include <stdio.h>
#include "../common/common.h"
#include "../alloc/alloc.h"
#include "../str/str-ptr.h"
#include "../convert/convert.h"

#define LINES 100
#define MAXLINE 1000

void sort(char *[], int, int (*)(char *, char *), void (*)(char *[], char *[]));
int numcomp(char *, char *);
int lexcomp(char *, char *);
char *strsave(char *);
void swap(char *[], char *[]);

int main(int argc, char *argv[])
{
  FILE *file;
  char *lineptr[LINES], line[MAXLINE];
  int nlines;

  file = fopen("../numbers.txt", "r");
  nlines = 0;

  while (getlinefile(file, line, MAXLINE) > 0)
    lineptr[nlines++] = strsave(line);

  sort(lineptr, nlines, numcomp, swap);
  // sort(lineptr, nlines, lexcomp, swap);

  char **p = lineptr;
  while (--nlines >= 0)
    printf("%s", *p++);

  return 0;
}

// shell sort
void sort(char *v[], int n, int (*comp)(char *, char *), void (*exch)(char *[], char *[]))
{
  int gap, i, j;

  for (gap = n / 2; gap > 0; gap /= 2)
    for (i = gap; i < n; ++i)
      for (j = i - gap; j >= 0; j -= gap)
      {
        if ((*comp)(v[j], v[j + gap]) <= 0)
          break;
        (*exch)(&v[j], &v[j + gap]);
      }
}

// compare strings numerically
int numcomp(char *s1, char *s2)
{
  double v1, v2;
  v1 = atof(s1);
  v2 = atof(s2);

  if (v1 < v2)
    return -1;
  else if (v1 > v2)
    return 1;
  else
    return 0;
}

// compare stirngs lexograpically
int lexcomp(char *s, char *t)
{
  for (; *s == *t; s++, t++)
    if (*s == '\0')
      return 0;
  return *s - *t;
}

void swap(char *px[], char *py[])
{
  char *temp;

  temp = *px;
  *px = *py;
  *py = temp;
}

char *strsave(char *s)
{
  char *p;
  if ((p = alloc(strl(s) + 1)) > 0)
    strcopy(s, p);
  return p;
}
