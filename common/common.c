#include <stdio.h>

// get line into s, return length
int getline(char s[])
{
  int i, c;
  for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  s[i] = '\0';
  return i;
}

int getlineptr(char *s)
{
  int c;
  char *p = s;
  while ((c = getchar()) != EOF && c != '\n')
    *p++ = c;
  return p - s;
}

int getlinelim(char s[], int lim)
{
  int c, i;
  i = 0;
  while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
    s[i++] = c;
  if (c == '\n')
    s[i++] = c;
  s[i] = '\0';
  return i;
}

// get line from file into s, return length
int getlinefile(FILE *file, char s[], int lim)
{
  int i = 0, c;
  while (--lim > 0 && (c = getc(file)) != EOF && c != '\n')
    s[i++] = c;

  if (c == '\n')
    s[i++] = c;

  s[i] = '\0';
  return i;
}

// convert character to lowercase
// this works because uppercase and lowercase letters
// are fixed distance from each other and each alphabet
// is contigous
int lower(int c)
{
  return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}

// return lefmost index of t in s, -1 otherwise 
int idx(char *s, char *t)
{
  char *p;
  for (p = s; *p; p++)
  {
    for (; *p == *t; t++)
      ;
    if (*t == '\0')
      return p - s;
  }
  return -1;
}