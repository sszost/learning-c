#include <stdio.h>

char *month_name(int);

int main(int argc, char *argv[])
{
  if (argc > 0)
  {
    //(argv[1])
  }

  printf("%s\n", month_name(5));

  return 0;
}

char *month_name(int n)
{
  // array of pointers to to chars (variable length char arrays)
  static char *months[] = {
      "invalid month",
      "january",
      "february",
      "march",
      "april",
      "may",
      "june",
      "july",
      "august",
      "september",
      "october",
      "november",
      "december"};
  return (n > 0 && n <= 12)
             ? months[n]
             : months[0];
}