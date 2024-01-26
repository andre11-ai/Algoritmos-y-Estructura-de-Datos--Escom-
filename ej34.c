/*
    Ejemplo de corrida:
        ( 1 + ( 5 - 3 ) ) * ( 3 + ( 2 * 2 ) ) - 1
*/

#include <stdio.h>
/*
   #include "ej32.c"  ... isempty, newstack, pop, push, top
      no debe ser incluida pues ya fue incluida en ej33.c
*/
#include "ej33.c"  /* Lukas, lee, jerarqu�a, verifica */

STACK intermedio(STACK, STACK); /* vac�a una pila en otra */
int evalua(STACK, STACK);

void main()
{
   char exp[300];
   puts("Expresi�n aritm�tica, +,-,*,/,(,):");
   lee(exp);
/*
   verifica(Lukas(newstack(), newstack(), exp, 0));
*/
/*
   verifica(intermedio(Lukas(newstack(),newstack(),exp,0),newstack()));
*/
   printf(" Resultado: %d",
             evalua(intermedio(Lukas(newstack(), newstack(), exp, 0),
                               newstack()),
                    newstack()));
}

STACK intermedio(STACK pili, STACK acum)
{
    if(isemptystack(pili))
       return(acum);
    else
    {
       acum = push(acum, top(pili)->elem, top(pili)->flag);
       return(intermedio(pop(pili),acum));
    }
}

int evalua(STACK pili, STACK auxi)
{
   int der, izq;
   if(isemptystack(pili))
      return(top(auxi) -> elem);
   else
   if(top(pili) -> flag)    /* en el tope hay un n�mero */
      auxi = push(auxi, top(pili)->elem, top(pili)->flag);
   else  /*  en el tope de la pila pili hay un operador */
   {
      der = top(auxi) -> elem;
      auxi = pop(auxi);
      izq = top(auxi) -> elem; 
      auxi = pop(auxi);
      if(top(pili) -> elem == '+')
         auxi = push(auxi, izq + der, 1);
      if(top(pili) -> elem == '-')
         auxi = push(auxi, izq - der, 1);
      if(top(pili) -> elem == '*')
         auxi = push(auxi, izq * der, 1);
      if(top(pili) -> elem == '/')
         auxi = push(auxi, izq / der, 1);
   }
   return(evalua(pop(pili), auxi));
}
