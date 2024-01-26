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
TREE insert(TREE, int);
void inorder(TREE);
int ismember(TREE, int);
TREE llena(TREE);
int vol(TREE);
int height(TREE);

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

TREE insert(TREE arbi, int i)
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
      arbi -> left = insert(arbi -> left, i);
      return(arbi);
   }
   else
   {
      arbi -> right = insert(arbi -> right, i);
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

TREE llena(TREE arbi)
{
   int i;
   scanf("%d", &i);
   if(i == 0)
      return(arbi);
   else
   {
      arbi = insert(arbi, i);
      return(arbi = llena(arbi));
   }
}

int vol(TREE arbi)
{
   if(isemptytree(arbi))
      return(0);
   else
      return(vol(arbi -> left) + vol(arbi -> right) + 1);
}

/*  versi�n eficiente  */
int height(TREE arbi)
{
   int i, d;
   if(isemptytree(arbi))
      return(-1);
   else
   {
      i = height(arbi -> left);
      d = height(arbi -> right);
      if(i > d)
         return(i + 1);
      else
         return(d + 1);
   }
}

/*    versi�n ineficiente
int height(TREE arbi)
{
   if(isemptytree(arbi))
      return(-1);
   else
   if( height(arbi -> left) > height(arbi -> right) )
      return(height(arbi -> left) + 1);
   else
      return(height(arbi -> right) + 1);
}

*/
