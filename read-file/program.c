#include <stdio.h>

#define MAXLINE 1000

void readfile(char s[]);

int main(int argc, char *argv[])
{
  if (argc > 0)
  {
    //(argv[1])
  }

  char s[MAXLINE];

  return 0;
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