// get word from file, return EOF and line number
#include <stdio.h>

// symbols
#define BUFSIZE 100
#define LETTER 'a'
#define DIGIT '0'

// function declarations
int type(int);
int getch(FILE *);
void ungetch(int);

// externals
static char buf[BUFSIZE]; // buffer for our input
static int bufp = 0;      // pointer to our buffer, next free position

// get word from file into s, return 0 if reached end, 1 otherwise
int getword(FILE *file, char *s, int lim, int *ln)
{
  int c;

  // skip white space and special characters
  while ((c = getch(file)) != EOF && type(c) != LETTER)
    if (c == '\n')
      (*ln)++;
  ungetch(c); // we read too much

  while (--lim > 0 && (c = getch(file)) != EOF && type(c) == LETTER)
    *s++ = c;
  *s = '\0';
  ungetch(c); // this might be a new line char

  return (c == EOF) ? 0 : 1;
}

// return 1 if c is a letter, 0 otherwise
int type(int c)
{
  if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
    return LETTER;
  else if (c >= '0' && c <= '9')
    return DIGIT;
  else
    return c;
}

// get (a possibly pushed back) character
int getch(FILE *file)
{
  return (bufp > 0) ? buf[--bufp] : getc(file);
}

void ungetch(int c)
{
  if (bufp > BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}