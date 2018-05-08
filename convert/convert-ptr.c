// number<->string conversions using pointers

// convert string to integer, using pointers
int atoi(char *s)
{
  int n, sign; 

  sign = 1;
  n = 0;

  while (*s == ' ' || *s == '\t' || *s == '\n')
    s++; // skip white space

  if (*s == '+' || *s == '-')
    sign = (*s++ == '+') ? 1 : -1;

  while (*s >= '0' && *s <= '9')
    n = 10 * n + *s++ - '0';
  return sign * n;
}