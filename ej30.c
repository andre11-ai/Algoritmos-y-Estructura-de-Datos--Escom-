/*
     Implementa un stack de números enteros.
     Sólo incluye la implementación del tda pila (sin uso).
     Se usará como biblioteca.
*/

#include <stdio.h>
#include <malloc.h>

struct nodo
{
   int dato;
   struct nodo * sig;   
};

typedef struct nodo * STACK;

int isemptystack(STACK);
STACK newstack(void);
int top(STACK);
STACK pop(STACK);
STACK push(STACK, int);

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
      ancla -> dato = 0;
      ancla -> sig = NULL;
   }
   return(ancla);
}

int top(STACK pili)
{
   if(isemptystack(pili))  
   {
      puts("Error de acceso a tope. Estructura vacía.");
      return(0);  /*  ... o que?  */
   }
   else
      return(pili -> sig -> dato);
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

STACK push(STACK pili, int val)
{
   STACK agrega;
   agrega = malloc(sizeof(struct nodo));
   if(agrega == NULL)
   {
      puts("Problema grave en push. Memoria agotada.");
      return(pili);
   }
   agrega -> dato = val;
   agrega -> sig = pili -> sig;
   pili -> sig = agrega;
   return(pili);
}
