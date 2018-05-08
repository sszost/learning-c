// get list of integers fron input and save them in array

#include <stdio.h>

#define SIZE 20

static int getint(int *);

int main(int argc, char *argv[])
{
  int n, v, arr[SIZE];

  for (n = 0; n < SIZE && getint(&v) != EOF; n++)
    arr[n] = v;

  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);

  return 0;
}

int getint(int *pn)
{
  int c, sign;
  while ((c = getchar()) == ' ' || c == '\n' || c == '\t')
    ; // skip white space

  sign = 1;
  if (c == '+' || c == '-')
  {
    sign = (c == '+') ? 1 : -1;
    c = getchar();
  }

  for (*pn = 0; c >= '0' && c <= '9'; c = getchar())
    *pn = 10 * *pn + c - '0';

  *pn *= sign;

  return c;
}