#include <stdio.h>
#include <malloc.h>

struct node
{
   int item;
   struct node * left;
   struct node * right;
};

typedef struct node * TREE;

TREE newtree(void);
int isemptytree(TREE);
TREE insert_version1(TREE, int);

TREE newtree()
{
   return(NULL);
}

int isemptytree(TREE arbi)
{
   if(arbi == NULL)
      return(1);
   else
      return(0);
}

TREE insert_version1(TREE arbi, int i)
{
   arbi = malloc(sizeof(struct node));
   arbi -> item = i;
   arbi -> left = NULL;
   arbi -> right = NULL;
   return(arbi);
}
