// string functions unsing pointers

//append string t to the end of s
void strcaten(char *s, char *t)
{
  char *sc = s, *tc = t;
  while (*sc)
    sc++;
  while (*sc++ = *tc++)
    ;
}

int strcomp(char *s, char *t)
{
  for (; *s == *t; s++, t++)
    if (!*s) // *s == '\0'
      return 0;
  return *s - *t;
}

// copy string s to destination d
void strcopy(char *s, char *d)
{
  while (*d++ = *s++)
    ;
}

// get string lenght
int strl(char *s)
{
  char *p = s;
  while (*p)
    p++;
  return p - s;
}

char *strlower(char *s)
{
  char *c;

  c = s;
  while (*c)
  {
    if (*c >= 'A' && *c <= 'Z')
      *c = *c + 'a' - 'A';
    c++;
  }
  return s;
}


// reverse string in place
void reverse(char *s, int len)
{
  char c, *b = s, *e = s + len - 1;
  do
  {
    c = *b;
    *b = *e;
    *e = c;

  } while (++b < --e);
}
