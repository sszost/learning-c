#include <stdio.h>

int main(int argc, char *argv[])
{
  if (argc > 0)
  {
    //(argv[1])
  }

  printf("char - %d bit\n\n", sizeof(char) * 8);

  printf("signed char - %d bit\n\n", sizeof(signed char) * 8);

  printf("unsigned char - %d bit\n\n", sizeof(unsigned char) * 8);

  printf("short - %d bit\n", sizeof(short) * 8);
  printf("short int - %d bit\n", sizeof(short int) * 8);
  printf("signed short - %d bit\n", sizeof(signed short) * 8);
  printf("signed short int - %d bit\n\n", sizeof(signed short int) * 8);

  printf("unsigned short - %d bit\n", sizeof(unsigned short) * 8);
  printf("unsigned short int - %d bit\n\n", sizeof(unsigned short int) * 8);

  printf("int - %d bit\n", sizeof(int) * 8);
  printf("signed - %d bit\n", sizeof(signed) * 8);
  printf("signed int - %d bit\n\n", sizeof(signed int) * 8);

  printf("unsigned - %d bit\n", sizeof(unsigned) * 8);
  printf("unsigned int - %d bit\n\n", sizeof(unsigned int) * 8);

  printf("long - %d bit\n", sizeof(long) * 8);
  printf("long int - %d bit\n", sizeof(long int) * 8);
  printf("signed long - %d bit\n", sizeof(signed long) * 8);
  printf("signed long int - %d bit\n\n", sizeof(signed long int) * 8);

  printf("unsigned long - %d bit\n", sizeof(unsigned long) * 8);
  printf("unsigned long int - %d bit\n\n", sizeof(unsigned long int) * 8);

  printf("long long - %d bit\n", sizeof(long long) * 8);
  printf("long long int - %d bit\n", sizeof(long long int) * 8);
  printf("signed long long - %d bit\n", sizeof(signed long long) * 8);
  printf("signed long long int - %d bit\n\n", sizeof(signed long long int) * 8);

  printf("unsigned long long - %d bit\n", sizeof(unsigned long long) * 8);
  printf("unsigned long long int - %d bit\n\n", sizeof(unsigned long long int) * 8);

  printf("float - %d bit\n\n", sizeof(float) * 8);

  printf("double - %d bit\n\n", sizeof(double) * 8);
  
  printf("long double - %d bit\n\n", sizeof(long double) * 8);

  return 0;
}