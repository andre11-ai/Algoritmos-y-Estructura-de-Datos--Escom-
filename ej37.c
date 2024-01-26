#include <stdio.h>
#include "ej36.c"

void main()
{
   TREE arbi = newtree();
   puts("Teclea secuencia de enteros, termina con cero: ");
   arbi = llena(arbi);
   inorder(arbi);
   printf("\n volumen: %d ", vol(arbi));
}
