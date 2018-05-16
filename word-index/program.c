// a basic cross-referencer, prints all words in document
// for each word, a list of the line numbers on which it occurs
#include <stdio.h>
#include "../str/str-ptr.h"
#include "../alloc/alloc.h"

#define MAXLINES 20
#define MAXWORD 40

struct tnode
{
  char *word; //text
  int lines[MAXLINES];
  int *linep;
  struct tnode *left;
  struct tnode *right;
};

int getword(FILE *, char *, int, int *); // from ../common/getword.c

struct tnode *treeprint(struct tnode *);
struct tnode *talloc();
struct tnode *tree(struct tnode *p, char *w, int ln);

int main(int argc, char *argv[])
{
  char word[MAXWORD];
  FILE *file;
  struct tnode *n;
  int ln;

  ln = 1;
  n = NULL;
  file = fopen("../text.txt", "r");

  // printf("size - %d\n", sizeof(struct tnode));

  while (getword(file, word, MAXWORD, &ln))
  {
    // if (ln < 4)
    //   printf("%d %s\n", ln, word);
    n = tree(n, strlower(word), ln);
  }
  treeprint(n);

  return 0;
}

struct tnode *tree(struct tnode *p, char *w, int ln)
{
  int cond;

  if (p == NULL)
  {
    p = talloc();
    p->linep = p->lines;
    p->word = strsave(w);
    *(p->linep)++ = ln;
    p->left = p->right = NULL;
  }
  else if ((cond = strcomp(w, p->word)) == 0)
    *(p->linep)++ = ln;
  else if (cond < 0)
    p->left = tree(p->left, w, ln);
  else
    p->right = tree(p->right, w, ln);

  return p;
}

struct tnode *treeprint(struct tnode *t)
{
  if (t != NULL)
  {
    treeprint(t->left);
    int *lp = t->lines;
    printf("%s ", t->word);
    while (lp < t->linep)
    {
      printf("%d%c", *lp, ((lp + 1) == t->linep) ? '\n' : ',');
      lp++;
    }
    treeprint(t->right);
  }
}

struct tnode *talloc()
{
  // expilcitly coerce the pointer into the desired type with cast
  return (struct tnode *)alloc(sizeof(struct tnode));
}