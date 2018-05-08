#include <stdio.h>
#include "../str/str.h"

int main()
{
  char s[] = "absabqabubbebabaeazbae";
  char c[] = "ab";

  squeeze(s, c);
  printf("%s\n", s);
  printf("%d\n", any(s, "abq"));

  return 0;
}

