// print last 10 lines from input
// optional argument -n for custom number of characters

#include <stdio.h>
#include "../convert/convert.h"
#define MAX 1000

int main(int argc, char *argv[])
{
  char input[MAX];
  int c, lim = MAX, n = 10, number = 0;
  char *s, *p;

  while (--argc > 0 && (*++argv)[0] == '-')
    for (s = argv[0] + 1; *s; s++)
      switch (*s)
      {
      case 'n':
        number = 1;
        break;
      default:
        printf("tail: illegal option %c\n", *s);
        argc = 0;
        break;
      }

  if (argc == 1 && number)
    n = atoi(*argv);

  for (p = input; --lim > 0 && (c = getchar()) != EOF; p++)
    *p = c;
  *p = '\0';

  printf("%s\n", (n >= p - input) ? input : p - n - 1);

  return 0;
}