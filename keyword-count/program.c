// count number of keywords in a file
#include <stdio.h>
#include "../str/str-ptr.h"

// symbols
#define MAXWORD 20 // maximum length of word
#define BUFSIZE 100
#define LETTER 'a'
#define DIGIT '0'

struct key
{
  char *word;
  int count;
};

// function declarations
int type(int);
int getwordfile(FILE *, char[], int);
int getch(FILE *);
void ungetch(int);
int binary(char *, struct key[], int);
void sort(struct key[], int);

// externals
static char buf[BUFSIZE]; // buffer for our input
static int bufp = 0;      // pointer to our buffer, next free position

int main(int argc, char *argv[])
{
  char word[MAXWORD];
  int keys_arr_size, n;
  FILE *file;

  // our keywords
  struct key keys_arr[] = {
      {"aut", 0},
      {"non", 0},
      {"et", 0},
      {"vel", 0},
      {"eum", 0},
      {"sit", 0},
      {"sed", 0},
      {"qui", 0}};

  keys_arr_size = sizeof(keys_arr) / sizeof(struct key);
  sort(keys_arr, keys_arr_size);

  file = fopen("../text.txt", "r");
  while (getwordfile(file, word, MAXWORD))
    if ((n = binary(word, keys_arr, keys_arr_size)) >= 0)
      keys_arr[n].count++;

  for (int i = 0; i < keys_arr_size; i++)
    printf("%s %d\n", keys_arr[i].word, keys_arr[i].count);

  return 0;
}

// shell sort
void sort(struct key a[], int n)
{
  int gap, i, j;
  struct key temp;

  for (gap = n / 2; gap > 0; gap /= 2)
    for (i = gap; i < n; ++i)
      for (j = i - gap; j >= 0 && strcomp(a[j].word, a[j + gap].word) > 0; j -= gap)
      {
        temp = a[j];
        a[j] = a[j + gap];
        a[j + gap] = temp;
      }
}

// search for keyword in array
int binary(char *word, struct key arr[], int n)
{
  int low, high, mid, cond;

  low = 0;
  high = n - 1;
  while (low <= high)
  {
    mid = (low + high) / 2;
    if ((cond = strcomp(word, arr[mid].word)) < 0)
      high = mid - 1;
    else if (cond > 0)
      low = mid + 1;
    else
      return mid;
  }
  return -1;
}

// get word from file into s, return 0 if reached end, 1 otherwise
int getwordfile(FILE *file, char *s, int lim)
{
  int c;

  // skip white space and special characters
  while ((c = getch(file)) != EOF && type(c) != LETTER)
    ;
  ungetch(c); // we read too much
  while (--lim > 0 && (c = getch(file)) != EOF && type(c) == LETTER)
    *s++ = c;
  *s = '\0';
  return (c == EOF) ? 0 : 1;
}

// return 1 if c is a letter, 0 otherwise
int type(int c)
{
  if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z') return LETTER;
  else if ( c >= '0' && c <= '9') return DIGIT;
  else return c;
}

// get (a possibly pushed back) character
int getch(FILE *file)
{
  return (bufp > 0) ? buf[--bufp] : getc(file);
}

void ungetch(int c)
{
  if (bufp > BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}