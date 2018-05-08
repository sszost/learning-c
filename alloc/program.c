#include <stdio.h>
#include "alloc.h"
#include "../str/str-ptr.h"

char *strsave(char *);

int main(int argc, char *argv[])
{
  if (argc > 0)
  {
    //(argv[1])
  }

  char *p = strsave("this is string saved by alloc()"); 
  printalloc(60);
  return 0;
}

char *strsave(char *s)
{
  char *p;
  if ((p = alloc(strl(s) + 1)) > 0)
    strcopy(s, p);
  return p;
}
