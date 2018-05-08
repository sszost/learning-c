#include <stdio.h>

#define SIZE 100

int main(int argc, char *argv[])
{
  if (argc > 0)
  {
    //(argv[1])
  }

  // ascii
  // 10 - line feed(enter)
  // 32 - space

  int c, n, arr[SIZE];

  n = 0;
  
  while ((c = getchar()) != EOF)
    arr[n++] = c;

  for (int i = 0; i < n; i++)
  {
    printf("%d %c\n", arr[i], arr[i]);
  }

  return 0;
}