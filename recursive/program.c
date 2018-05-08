// various recursive functions 

#include <stdio.h>
#include <string.h>

void printd(int);
void itoa(int, char[]);
void append(char, char[]);
void reverse(char[], int);
void reverse_print(char[]);
void reverse_string(char *, int, int);

int main(int argc, char *argv[])
{
  if (argc > 0)
  {
    //(argv[1])
  }
  printd(12345);

  char s[20] = "";
  itoa(12345, s);

  printf("\n%s\n", s);

  reverse_print("reverse");

  char x[] = "reverse";
  reverse(x, strlen(x));
  printf("\nReversed: %s\n", x);

  return 0;
}

// print decimal number
void printd(int n)
{
  int i;
  if (n < 0)
  {
    n = -n;
    putchar('-');
  }
  if ((i = n / 10) != 0) // divide by 10, so move comma to the left 1234 = 123
    printd(i);
  putchar(n % 10 + '0'); // modulo 10, so get last digit 1234 % 10 = 4, + '0' converts it to char
}

// convert integer to string
void itoa(int n, char s[])
{
  int i;
  if (n < 0)
  {
    n = -n;
    append('-', s);
  }
  if ((i = n / 10) != 0)
    itoa(i, s);
  append(n % 10 + '0', s);
}

// reverse string
void reverse(char s[], int len)
{
  char c;
  if (len-- < 2)
  {
    return;
  }
  c = s[0];
  s[0] = s[len];
  s[len] = c;
  // it this call we pass a pointer to string increased by one
  // because our 'substring' is shorter we have do decrase len by one
  reverse(s + 1, len - 1);
}

// print string in reverse
void reverse_print(char s[])
{
  if (*s) // its not an end character
  {
    reverse_print(s + 1);
    printf("%c", *s);
  }
}

// reverse string in place
void reverse_string(char *x, int b, int e)
{
  char c;
  if (b >= e)
    return;

  c = *(x + b);
  *(x + b) = *(x + e);
  *(x + e) = c;

  reverse_string(x, ++b, --e);
}

// append character to string
void append(char c, char s[])
{
  int i;

  for (i = 0; s[i] != '\0'; ++i)
    ;
  s[i++] = c;
  s[i] = '\0';
}
