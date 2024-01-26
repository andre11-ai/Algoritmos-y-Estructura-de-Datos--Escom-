/*
     Implementa un stack de caracteres.
     S�lo incluye la implementaci�n del tda pila (sin uso).
     Se usar� como biblioteca.
*/

#include <stdio.h>
#include <malloc.h>

struct nodo
{
   char elem;
   struct nodo * sig;   
};

typedef struct nodo * STACK;

int isemptystack(STACK);
STACK newstack(void);
char top(STACK);
STACK pop(STACK);
STACK push(STACK, char);

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
      ancla -> elem = '\0';
      ancla -> sig = NULL;
   }
   return(ancla);
}

char top(STACK pili)
{
   if(isemptystack(pili))  
   {
      puts("Error de acceso a tope. Estructura vac�a.");
      return('\0');  /*  ... o que?  */
   }
   else
      return(pili -> sig -> elem);
}

STACK pop(STACK pili)
{
   if(isemptystack(pili))  
   {
      puts("Error de aplicaci�n pop. Estructura vac�a.");
      return(pili);  /*  ... o que?  */
   }
   else
      pili -> sig = pili -> sig -> sig;
   return(pili);
}

STACK push(STACK pili, char val)
{
   STACK agrega;
   agrega = malloc(sizeof(struct nodo));
   if(agrega == NULL)
   {
      puts("Problema grave en push. Memoria agotada.");
      return(pili);
   }
   agrega -> elem = val;
   agrega -> sig = pili -> sig;
   pili -> sig = agrega;
   return(pili);
}
