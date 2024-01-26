#include <stdio.h>

void min_may();

void main()
{
   min_may();
}

void min_may()
{
   char letra;
   letra = getchar();
   if(letra == '\n')
       ;
   else
   {
      if((letra >= 'a') && (letra <= 'z'))
          letra = letra - 32;
      putchar(letra);
      min_may();
   }
}
