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
int isleaf(TREE);
TREE insert_version1(TREE, int);
void inorder(TREE);

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

int isleaf(TREE arbi)
{
   if((arbi -> left == NULL) && (arbi -> right))
      return(1);     /*  si es una hoja  */
   else
      return(0);     /*  no es una hoja  */
}

void inorder(TREE arbi)
{
   if(isemptytree(arbi))
      ;
   else
   {
      inorder(arbi -> left);
      printf(" %d, ", arbi -> item);
      inorder(arbi -> right);
   }
}


TREE insert_version1(TREE arbi, int i)
{
   arbi = malloc(sizeof(struct node));
   arbi -> item = i;
   arbi -> left = NULL;
   arbi -> right = NULL;
   return(arbi);
}
