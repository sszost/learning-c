#include <stdio.h>
#include "str.h"

// string functions using array notiation

// reverse string in place
void reverse(char s[])
{
  int c, i, j;
  for (int i = 0, j = strl(s) - 1; i < j; i++, j--)
  {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}

// get string lenght, regular version
int strl(char s[])
{
  int i;
  for (i = 0; s[i] != '\0'; ++i)
    ;
  return i;
}

// copy array s to array d, we assume the same length
void strcopy(char s[], char d[])
{
  int i = 0;
  while ((d[i] = s[i]) != '\0')
    ++i;
}

// copare character strings s and t
// return number indictating lexograpic value of s to t
int strcomp(char s[], char t[])
{
  int i;
  i = 0;
  while (s[i] == t[i])
    if (s[i++] == '\0')
      return 0;
  return s[i] - t[i];
}

// remove all chars in s1 which match any char in s2
void squeeze(char s1[], char s2[])
{
  int i, j;
  for (i = j = 0; s1[i] != '\0'; ++i)
    if (!isin(s2, s1[i]))
      s1[j++] = s1[i];
  s1[j] = '\0';
}

// is character c present in string s
int isin(char s[], int c)
{
  for (int i = 0; s[i] != '\0'; ++i)
    if (s[i] == c)
      return 1;
  return 0;
}

// return first index of occurence of any char from s2 in s1
int any(char s1[], char s2[])
{
  int i, j;

  for (i = 0; s1[i] != '\0'; ++i)
    for (j = 0; s2[j] != '\0'; ++j)
      if (s1[i] == s2[j])
        return i;
  return -1;
}

// print string as a matrix of width n
void prints(char s[], int n)
{
  for (int i = 0; s[i] != '\0'; ++i)
    printf("%c%c", s[i], (i % n == n - 1 || s[i + 1] == '\0') ? '\n' : ' ');
}