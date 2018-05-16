// simple memory allocation for string

#include <stdio.h>

#define ALLOCSIZE 99000 // size of available space
#define NUL 0          // null pointer

// private external variables
static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf; // next free positions, equivalent to &allocbuf[0]

// return pointer to n characters
char *alloc(int n)
{
  // fits
  if (allocp + n <= allocbuf + ALLOCSIZE)
  {
    allocp += n;       // increase pointer to next free position
    return allocp - n; // return old position
  }
  else
    return NUL; // not enough room
}

// take string off the stack
void free(char *p)
{
  if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
    allocp = p;
}

char *strsave(char *s)
{
  char *p, *t, *c;

  t = s;
  while (*t)
    t++;

  p = alloc((t - s) + 1);
  if ((c = p) > 0)
    while (*c++ = *s++)
      ;
  return p;
}

// print first n characters of allocbuf
void printalloc(int n)
{
  char *c = allocbuf;
  while (n--)
    printf("%c", *c++);
}