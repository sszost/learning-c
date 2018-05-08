#include <stdio.h>
// #include "atof.h"
#include "../convert/convert.h"
#include "getop.h"
#include "define.h"

#define MAXVAL 100 // max depth of val stack

double push(double);
double pop();
void clear();

// externals
static int sp = 0;         // stack pointer
static double val[MAXVAL]; // value stack

int main(int argc, char *argv[])
{
  if (argc > 0)
  {
    //(argv[1])
  }

  int type;
  char s[MAXOP];
  double op2;

  while ((type = getop(s, MAXOP)) != EOF)
  {
    switch (type)
    {
    case NUMBER:
      push(atof(s));
      break;
    case '+':
      push(pop() + pop());
      break;
    case '*':
      push(pop() * pop());
      break;
    case '-':
      op2 = pop();
      // we cannot guarantee the order in which function arguments are executed
      // so we have to store result of pop in a separate variable
      push(pop() - op2);
      break;
    case '/':
      op2 = pop();
      if (op2 != 0.0)
        push(pop() / op2);
      else
        printf("zero divisor popped\n");
      break;
    case '=':
      printf("\t%f\n", push(pop()));
      break;
    case 'c':
      clear();
      break;
    case 'p':
      for (int i = 0; i < sp; ++i)
        printf("%f ", val[i]);
      printf("\n");
      break;
    case TOOBIG:
      printf("%.20s ... is too long\n", s);
      break;
    default:
      printf("unknown command %c\n", type);
      break;
    }
  }

  return 0;
}

double push(double f)
{
  if (sp < MAXVAL)
  {
    return val[sp++] = f;
  }
  else
  {
    printf("error: stack full\n");
    clear();
    return 0;
  }
}

double pop()
{
  if (sp > 0)
  {
    return val[--sp];
  }
  else
  {
    printf("error: stack empty\n");
    clear();
    return 0;
  }
}

void clear()
{
  sp = 0;
}