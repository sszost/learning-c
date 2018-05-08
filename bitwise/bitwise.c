#include <stdio.h>
#include "bitwise.h"

unsigned countbits(unsigned x)
{
  if (!x)
    return 0;
  int i = 1;
  while (x &= x - 1) // remove rightmost 1-bit from int
    ++i;
  return i;
}

// invert n bits that begin at position p
// (right aligned, meaning bit position 0 is at the right end)
unsigned invert(unsigned x, unsigned p, unsigned n)
{
  // p = 11, n = 8
  // 1001 1110 1010 [0010 1111] 0001 = x
  // 0000 0000 0000 [1111 1111] 0000 = mask
  // 1001 1110 1010 [1101 0000] 0001 = x // xor, 0=copy, 1=invert

  unsigned s = sizeof(unsigned) * 8; // 32
  // because of result being promoted to int we need to cast to unsigned
  return x ^ ((unsigned)(~0 << s - n) >> s - p - 1);
}

// get n bits from position p (right aligned)
unsigned getbits(unsigned x, unsigned p, unsigned n)
{
  // p = 11, n = 8
  // 1001 1110 1010 [0010 1111] 0001 = x
  // 0000 0000 0000 0000 [1111 1111] = mask
  // 0000 0000 0000 0000 [0010 1111]

  return ((x >> (p + 1 - n)) & ~(~0 << n));
}

// get n bits from positon p (left aligned)
unsigned getbitsl(unsigned x, unsigned p, unsigned n)
{
  // p = 11, n = 8
  // 1001 [1110 1010] 0010 1111 0001 = x
  // [1111 1111] 0000 0000 0000 0000 = mask
  // [1110 1010] 0000 0000 0000 0000  

  unsigned s = sizeof(unsigned) * 8;
  return ((x << (p + 1 - n)) & (~0 << s - n));
}

// 'rotate' (like a belt) integer n bits to the right
unsigned rightrot(unsigned x, unsigned n)
{
  // 1010 0100 1001 [1111 0101] >> 8
  // [1111 0101] 1010 0110 1001

  unsigned s = sizeof(unsigned) * 8;
  return ((x >> n) | (x << s - n));
}

// print bits of int up to 16 bit
void printb(unsigned x)
{
  short i = 0;
  //mask, 1 and 15 zeros
  unsigned m = 1 << sizeof(unsigned) * 8 - 1;
  // move all right and its 0
  while (m > 0)
  {
    // printf("%u", x & m ? 1 : 0); // use ternary and bitwise and to check if bit is 0 or 1
    printf("%u", !!(x & m)); // use double negation, to convert usigned to 1 or 0
    m >>= 1;                 // shift 1bit right
    if (!(++i % 4))
      printf(" "); // spacing of 4bit
  }
  printf("\n");
}