#include <stdio.h>
#include "../common/common.h"

#define MAX 1000

void detab(char[], char[], int n);

int main()
{
  char l[MAX];
  char c[MAX];
  while (getline(l) > 0)
  {
    printf("line - %s\n", l);
    detab(l, c, 4);
    printf("detab - %s\n", c);
  }

  return 0;
}

// replace tabs with spaces 
void detab(char s[], char c[], int n)
{
  int i = 0, j = 0;
  do
  {
    if (s[i] == '\t')
      for (int k = 0; k < n; ++k)
        c[j++] = ' ';
    else
      c[j++] = s[i];
  } while (s[i++] != '\0');
}
