/*
    Transforma una secuencia de caracteres, dígitos, a un
    entero. Repite el proceso para varios enteros hasta
    encontrar un retorno de carro.
    Ejemplo de corrida:
      (146 + 275) * 513
*/

#include <stdio.h>
#include "ej30.c"     /*  contiene el tda pila de caracteres  */

STACK llenapila(STACK);
int char2int(STACK, char);
void vaciapila(STACK);

void main()
{
   puts("teclea varios enteros y termina con Intro");
   vaciapila(llenapila(newstack()));
}

STACK llenapila(STACK pili)
{
   char tempo;
   if((tempo = getchar()) == '\n')
      return(pili);
   else
   if((tempo >= '0') && (tempo <= '9'))
   {
      pili = push(pili, 0);
      if(char2int(pili, tempo) == -1)
         return(pili);
      else
      {
         pili = llenapila(pili);
         return(pili);
      }
   }
   else
      return(llenapila(pili));
}

int char2int(STACK pili, char cara)
{
   int extra = 0;
   if(cara == '\n')
      return(-1);
   if((cara < '0') || (cara > '9'))  /* no es dígito */
      return(top(pili));
   else
   {
      extra = top(pili) * 10 + (int)(cara - '0');
      pili = pop(pili);
      pili = push(pili, extra);
      return(char2int(pili, getchar()));
   }
}

void vaciapila(STACK pili)
{
   if(isemptystack(pili))
      ;
   else
   {
      printf("  %d, ", top(pili));
      vaciapila(pop(pili));
   }
}
