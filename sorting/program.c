#include <stdio.h>
#include "sorting.h"
#include "../common/common.h"
#include "../str/str.h"

#define MAX 1000

int main(int argc, char *argv[])
{
  if (argc > 0)
  {
    //(argv[1])
  }

  char a[] = "Sed ut perspiciatis unde omnis iste natus error sit";
  char b[MAX], c[MAX];

  printf("%s\n", a);
  strcopy(a, b);
  selection_sort(b, c);
  prints(c, 20);

  int p = binary_search('S', c);
  printf("%d\n", p);

  shell_sort(a);
  prints(a, 10);

  return 0;
}
