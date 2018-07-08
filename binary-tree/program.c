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
void nodeprint(char *, struct tnode *);
void treeprint(struct tnode *);
struct tnode *talloc();

//sort by count
struct tnode *insertcount(struct tnode *p, struct tnode *c);
struct tnode *sortcount(struct tnode *s, struct tnode *d);

int main(int argc, char *argv[])
{
  char word[MAXWORD];
  FILE *file;
  struct tnode *root, *sorted;
  int iseof;

  root = sorted = NULL;
  file = fopen("../text.txt", "r");

  while (1)
  {
    iseof = getword(file, word, MAXWORD);
    root = tree(root, strlower(word));
    if (iseof)
      break;
  }

  sorted = sortcount(root, sorted);
  treeprint(sorted);

  return 0;
}

// insert node c into node p, count wise
struct tnode *insertcount(struct tnode *p, struct tnode *c)
{
  if (p == NULL)
    p = c;
  else if (p->count < c->count)
    p->left = insertcount(p->left, c);
  else
    p->right = insertcount(p->right, c);
  return p;
}

// in place sorting by count
struct tnode *sortcount(struct tnode *s, struct tnode *d)
{
  if (s != NULL)
  {
    d = sortcount(s->left, d);
    d = sortcount(s->right, d);
    d = insertcount(d, s);
    // remove references to avoid loops in tree
    s->left = NULL;
    s->right = NULL;
  }
  return d;
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

void nodeprint(char *m, struct tnode *n)
{
  if (n != NULL)
    printf("%s  %c <- %s -> %c\n", m, (n->left) ? '*' : 'N', n->word, (n->right) ? '*' : 'N');
  else
    printf("%s  node is NULL\n", m);
}

struct tnode *talloc()
{
  // expilcitly coerce the pointer into the desired type with cast
  return (struct tnode *)alloc(sizeof(struct tnode));
}