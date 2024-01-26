/*
    Corrida: Debes teclear una frase o secuencia de caracteres
             y terminar con el carácter q.
    La llamada recursiva de la función debe estar asociada a
    algún mecanismo que la detenga, este usualmente es un if
    ya sea que la llamada se encuentre dentro del cuerpo del
    if o en el cuerpo del else.
*/

#include <stdio.h>

void frena_con_q();

void main()
{
   frena_con_q();
}

void frena_con_q()
{
   putchar('.');
   if(getchar() < 'q')   /*  este if debe detener la recursión  */
      frena_con_q();    /*  la llamada depende del éxito del if  */
}