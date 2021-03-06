// sorting lines but using function pointers for comparison
// two functions to compare strings numerically or lexographically
// core sort algorithm can be reused 
#include <stdio.h>
#include "../common/common.h"
#include "../alloc/alloc.h"
#include "../str/str-ptr.h"
#include "../convert/convert.h"

#define LINES 100
#define MAXLINE 1000

void sort(char *[], int, int, int (*)(char *, char *), void (*)(char *[], char *[]));
int numcomp(char *, char *);
int lexcomp(char *, char *);
char *strsave(char *);
void swap(char *[], char *[]);

int main(int argc, char *argv[])
{
  FILE *file;
  char *lineptr[LINES], line[MAXLINE], *s;
  int nlines;
  int reverse = 0, number = 0;

  while (--argc > 0 && (*++argv)[0] == '-')
    for (s = argv[0] + 1; *s; s++)
      switch (*s)
      {
      case 'r':
        reverse = 1;
        break;
      case 'n':
        number = 1;
        break;
      default:
        printf("find: illegal option %c\n", *s);
        argc = 0;
        break;
      }

  if (argc != 1)
  {
    printf("Usage: sort -n -r file\n");
    return 0;
  }
  else
    file = fopen(*argv, "r");

  nlines = 0;

  while (getlinefile(file, line, MAXLINE) > 0)
    lineptr[nlines++] = strsave(line);

  if (number)
    sort(lineptr, nlines, reverse, numcomp, swap);
  else
    sort(lineptr, nlines, reverse, lexcomp, swap);

  char **p = lineptr;
  while (--nlines >= 0)
    printf("%s", *p++);

  return 0;
}

// shell sort
void sort(char *v[], int nl, int r, int (*comp)(char *, char *), void (*exch)(char *[], char *[]))
{
  int gap, i, j, c;

  for (gap = nl / 2; gap > 0; gap /= 2)
    for (i = gap; i < nl; ++i)
      for (j = i - gap; j >= 0; j -= gap)
      {
        c = (*comp)(v[j], v[j + gap]);
        if (r ? c >= 0 : c <= 0)
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
