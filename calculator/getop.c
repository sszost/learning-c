#include <stdio.h>
#include "define.h"

#define BUFSIZE 100

// function declarations
static int getch();
static void ungetch(int);

// externals
static char buf[BUFSIZE]; // buffer for our input
static int bufp = 0;      // pointer to our buffer, next free position

int getop(char s[], int lim)
{
  int i, c;

  // read character and skip white space
  while ((c = getch()) == ' ' || c == '\t' || c == '\n')
    ;

  // if c is NOT a number and NOT a delimiter, return it (maybe operator?)
  if (c != '.' && (c < '0' || c > '9'))
    return c;

  // set first char to c
  s[0] = c;

  // read our number
  for (i = 1; (c = getchar()) >= '0' && c <= '9'; ++i)
    if (i < lim)
      s[i] = c;

  // get fraction
  if (c == '.')
  {
    if (i < lim)
      s[i] = c;
    for (i++; (c = getchar()) >= '0' && c <= '9'; ++i)
      if (i < lim)
        s[i] = c;
  }

  if (i < lim)
  {
    ungetch(c); // we read too much, save to buffer
    s[i] = '\0';
    return NUMBER;
  }
  else // its too big skip the rest of the line
  {
    while (c != '\n' && c != EOF)
      c = getchar();
    s[lim - 1] = '\0';
    return TOOBIG;
  }
}

// get (a possibly pushed back) character
int getch()
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
  if (bufp > BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}