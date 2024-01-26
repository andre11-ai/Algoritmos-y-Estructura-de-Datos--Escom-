/*
    Revisa par�ntesis balanceados a trav�s del tda pila.
*/

#include <stdio.h>
#include "ej28.c"        /*  contiene el tda pila  */

int balanparent(STACK, char);

void main()
{
    puts("Dame una expresi�n con par�ntesis redondos: ");
    if(balanparent(newstack(), getchar()))
       puts("Secuencia balanceada");
    else
       puts("No est� balanceada.");
}

int balanparent(STACK pili, char car)
{
   if(car == '\n')
      if(isemptystack(pili))
         return(1);  /* balanceada */
      else
         return(0);  /* no balanaceada */
   else
   {
      printf("Revisando: %c \n", car);
      if(car == '(')
         return(balanparent(push(pili, car), getchar()));
      else
      if(car == ')')
      {
         if(isemptystack(pili))
            return(0);   /*  fin: no balanceada  */
         else
            return(balanparent(pop(pili), getchar()));
      }
      else
         return(balanparent(pili, getchar()));
   }
}
