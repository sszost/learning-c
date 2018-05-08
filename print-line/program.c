#include <stdio.h>

#define MAX 1000

void prints(char *);
void readfile(char[]);

int main(int argc, char *argv[])
{
  if (argc > 0)
  {
    //(argv[1])
  }

  char s[MAX];
  readfile(s);
  prints(s);

  return 0;
}

// get line into s return length
void prints(char *s)
{
  int i = 0;
  while (*s != '\0')
  {
    if (*s == '\n')
    {
      printf("\n%d ", ++i);
      s++;
    }
    else
      printf("%c", *s++);
  }
}

void readfile(char s[])
{
  FILE *file;
  file = fopen("../text.txt", "r");
  int i = 0, c;
  while ((c = getc(file)) != EOF)
    s[i++] = c;
  // s[i] = '\0';
}