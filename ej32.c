/*
     Sólo incluye la implementación del tda pila (sin uso).
     El registro cuenta con tres elementos, dos enteros y un
     apuntador, el usario es responsable del uso de cada uno.
     El código se usará como biblioteca.
*/

#include <stdio.h>
#include <malloc.h>

struct nodo
{
   int elem;
   int flag;
   struct nodo * sig;
};

typedef struct nodo * STACK;

int isemptystack(STACK);
STACK newstack(void);
STACK top(STACK);
STACK pop(STACK);
STACK push(STACK, int, int);  /* (pila, elem, flag) */

int isemptystack(STACK pili)
{
   return(pili -> sig == NULL); 
}

STACK newstack()
{
   STACK ancla;
   ancla = malloc(sizeof(struct nodo));
   if(ancla == NULL)
      puts("Problema grave en pila nueva. Memoria agotada.");
   else
   {
      ancla -> elem = 0;
      ancla -> flag = 0;
      ancla -> sig = NULL;
   }
   return(ancla);
}

STACK top(STACK pili)
{
   if(isemptystack(pili))  
   {
      puts("Error de acceso a tope. Estructura vacía.");
      return(NULL);  /*  ... o que?  */
   }
   else
      return(pili -> sig);
}

STACK pop(STACK pili)
{
   if(isemptystack(pili))
   {
      puts("Error de aplicación pop. Estructura vacía.");
      return(pili);  /*  ... o que?  */
   }
   else
      pili -> sig = pili -> sig -> sig;
      return(pili);
}

STACK push(STACK pili, int val, int estado)
{
   STACK agrega;
   agrega = malloc(sizeof(struct nodo));
   if(agrega == NULL)
   {
      puts("Problema grave en push. Memoria agotada.");
      return(pili);
   }
   agrega -> elem = val;
   agrega -> flag = estado;
   agrega -> sig = pili -> sig;
   pili -> sig = agrega;
   return(pili);
}
