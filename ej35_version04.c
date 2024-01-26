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
TREE insert_version2(TREE, int);
TREE insert_version3(TREE, int);
void inorder(TREE);
int ismember(TREE, int);
void llena(TREE);

void main()
{
   TREE arbi = newtree();
   llena(arbi);
   inorder(arbi);
}

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

TREE insert_version2(TREE arbi, int i)
{
   if(isemptytree(arbi))
   {
      arbi = malloc(sizeof(struct node));
      arbi -> item = i;
      arbi -> left = NULL;
      arbi -> right = NULL;
      return(arbi);
   }
}

TREE insert_version3(TREE arbi, int i)
{
   if(isemptytree(arbi))
   {
      arbi = malloc(sizeof(struct node));
      arbi -> item = i;
      arbi -> left = NULL;
      arbi -> right = NULL;
      return(arbi);
   }
   else
   if(i <= arbi -> item)
   {
      arbi -> left = insert_version3(arbi -> left, i);
      return(arbi);
   }
   else
   {
      arbi -> right = insert_version3(arbi -> right, i);
      return(arbi);
   }
}

int ismember(TREE arbi, int i)
{
   if(isemptytree(arbi))
      return(0);
   else
   if(i == arbi -> item)
      return(1);
   else
   if(i <= arbi -> item)
      return(ismember(arbi -> left, i));
   else
      return(ismember(arbi -> right, i));
}

void llena(TREE arbi)
{
   int i;
   scanf("%d", &i);
   if(i == 0)
      ;
   else
   {
      arbi = insert_version3(arbi, i);
      llena(arbi);
   }
}
