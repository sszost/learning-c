// keyword counting program using binary tree structure
#include <stdio.h>
#include "../str/str-ptr.h"
#include "../alloc/alloc.h"

#define MAXWORD 40

struct tnode
{
  char *word; //text
  int count;
  struct tnode *left;
  struct tnode *right;
};

int getword(FILE *file, char *s, int lim); // from ../common/getword.c
struct tnode *tree(struct tnode *, char *);
void treeprint(struct tnode *);
struct tnode *talloc();

int main(int argc, char *argv[])
{
  char word[MAXWORD];
  FILE *file;
  struct tnode *n;

  n = NULL;
  file = fopen("../text.txt", "r");

  while (getword(file, word, MAXWORD))
    n = tree(n, strlower(word));

  treeprint(n);

  return 0;
}

struct tnode *tree(struct tnode *p, char *w)
{
  int cond;

  if (p == NULL)
  {
    p = talloc();
    p->word = strsave(w);
    p->count = 1;
    p->left = p->right = NULL;
  }
  else if ((cond = strcomp(w, p->word)) == 0)
    p->count++;
  else if (cond < 0)
    p->left = tree(p->left, w);
  else
    p->right = tree(p->right, w);

  return p;
}

void treeprint(struct tnode *t)
{
  if (t != NULL)
  {
    treeprint(t->left);
    printf("%4d %s\n", t->count, t->word);
    treeprint(t->right);
  }
}

struct tnode *talloc()
{
  // expilcitly coerce the pointer into the desired type with cast
  return (struct tnode *)alloc(sizeof(struct tnode));
}