#include "../str/str.h"

// convert string to integer
int atoi(char s[])
{
  int i, n, sign;
  for (i = 0; s[i] == ' ' || s[i] == '\t' || s[i] == '\n'; ++i)
    ; // skip white space

  sign = 1;
  if (s[i] == '+' || s[i] == '-')
    sign = (s[i++] == '+') ? 1 : -1;

  for (n = 0; s[i] >= '0' && s[i] <= '9'; ++i)
    n = 10 * n + s[i] - '0';
  return sign * n;
}

// convert integer to string
void itoa(int n, char s[])
{
  int i, sign;

  if ((sign = n) < 0)
    n = -n;

  i = 0;

  do
    s[i++] = n % 10 + '0';
  while ((n /= 10) > 0);

  if (sign < 0)
    s[i++] = '-';

  s[i] = '\0';
  reverse(s);
}

// convert string to double
double atof(char s[])
{
  double val, power, expo, epower;
  int i, j, sign, esign;

  // ignore whitespace
  for (i = 0; s[i] == ' ' || s[i] == '\t' || s[i] == '\n'; ++i)
    ;
  // check sign
  sign = 1;
  if (s[i] == '-' || s[i] == '+')
    sign = (s[i++] == '+') ? 1 : -1;

  // 10 * val, moves digit to the left, then we add new digit
  for (val = 0; s[i] >= '0' && s[i] <= '9'; ++i)
    val = 10 * val + s[i] - '0';

  // check if we have decimal point
  if (s[i] == '.')
    ++i;
  
  // calculate values after decimal point
  for (power = 1; s[i] >= '0' && s[i] <= '9'; ++i)
  {
    val = 10 * val + s[i] - '0';
    power *= 10;
  }

  // check if we have E notation
  if (s[i] == 'e' || s[i] == 'E')
    ++i;

  // assume positve e power, check for sign
  esign = 1;
  if (s[i] == '-' || s[i] == '+')
    esign = (s[i++] == '+') ? 1 : -1;

  // calculate our power exponent
  for (epower = 0; s[i] >= '0' && s[i] <= '9'; ++i)
    epower = 10 * epower + s[i] - '0';

  // get our exponent value 
  for (expo = 1, j = 0; j < epower; ++j)
    expo *= 10;

  // if its negative inverse
  if (esign < 0)
    expo = 1 / expo;

  //there is no need for braces because sign is always 1
  return sign * val / power * expo;
}

// convert hexadecimal string to integer
int htoi(char s[])
{
  int i, n, m;

  n = 0;
  for (i = 0; s[i] >= '0' && s[i] <= '9' || s[i] >= 'A' && s[i] <= 'F' || s[i] >= 'a' && s[i] <= 'f'; ++i)
  {
    if (s[i] >= '0' && s[i] <= '9')
      m = '0';
    else if (s[i] >= 'A' && s[i] <= 'F')
      m = '7';
    else if (s[i] >= 'a' && s[i] <= 'f')
      m = 'W';
    n = 16 * n + s[i] - m;
  }
  return n;
}

// convert integer to hexadecimal string
void itoh(int n, char s[])
{
  int i, r, sign;

  if ((sign = n) < 0)
    n = -n;

  i = 0;

  do
  {
    r = n % 16;
    if (r < 10)
      s[i++] = r + '0';
    else
      s[i++] = r - 10 + 'A';
  } while ((n /= 16) > 0);

  if (sign < 0)
    s[i++] = '-';

  s[i] = '\0';

  reverse(s);
}