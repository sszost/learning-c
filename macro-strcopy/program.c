#include <stdio.h>

#define STRCPY(x, y)              \
  {                               \
    char *STRCPX = x;             \
    char *STRCPY = y;             \
    while (*STRCPX++ = *STRCPY++) \
      ;                           \
  }                               \
  while (0)

int main(int argc, char *argv[])
{
  if (argc > 0)
  {
    //(argv[1])
  }
  char s[] = "something";
  char c[] = "copy";
  STRCPY(s, c);
  printf("%s\n", s);

  return 0;
}