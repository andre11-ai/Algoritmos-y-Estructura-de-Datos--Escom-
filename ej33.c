/*
  Para correr este programa debes quitar el comentario de la
  funci�n main. despu�s de probar la corrida debes regresar
  el comentario para que este programa sea s�lo una biblioteca.
  Ejemplos de corrida:
      (183 + 17) * 154
      (12 + 34) * (56 + 78)
  Para generar el c�digo ej32.c se modific� el programa ej30.c
  la biblioteca ej32.c tiene dos miembros de tipo int, el miembro
  que se agreg� (flag) es para inidcar si el valor (elem) es
  operador u operando.
  En este programa, la funci�n Lukas toma dos pilas, la primera
  es s�lo un acumulador de apoyo y la segunda almacena la
  expresi�n en notaci�n posfija en orden reversa. el par�metro
  adicional, el entero, es una bandera que indica si la lectura
  de un operando (un n�mero) est� en progreso.
*/

#include <stdio.h>
#include "ej32.c"
/*
    El archivo ej32.c  contiene la pila extendida.
    Contiene dos miembros enteros: int elem, int flag.
*/

STACK Lukas(STACK, STACK, char[], int);
void lee(char []);
int jrq(char);
void verifica(STACK);

/*
void main()
{
   char exp[300];
   lee(exp);
   verifica(Lukas(newstack(), newstack(), exp, 0));
}
*/

void lee(char vec[])  /* esta versi�n elimina lo espacios */
{
   char c;
   c = getchar();
   if(c == '\n')
      vec[0] = '\0';
   else
   if(c == ' ')
      lee(vec);
   else
   {
      vec[0] = c;
      lee(vec + 1);
   }
}

/* lee_oprnd sirve para saber si en el tope de la pila hay     */
/* un operando, quiz�s hay un operando en proceso de lectura   */
/* STACK -> flag == 1, es un operando, es decir, un n�mero */
/* STACK -> flag == 0, es un operador, un s�mbolo (+, *, -, /) */
STACK Lukas(STACK pili, STACK posf, char exp[], int lee_oprnd)
{
   char c = exp[0];
   int i, operando = ((c >= '0') && (c <= '9'));
   if(c == '\0')   /* el arreglo ya est� vac�o */
      if(isemptystack(pili))   /* y la pila est� vac�a vac�a */
      {
         puts("\nTermin� notaci�n polaca reversa.");
         return(posf);
      }
      else
      {
         if(top(pili) -> flag)  /* hay un operando en el tope de pili */
         {
            printf(" %d ", top(pili) -> elem);
            posf = push(posf, top(pili) -> elem, 1);
         }
         else   /* en el tope de pili hay un operador */
         {
            putchar((char)(top(pili) -> elem));
            putchar(' ');
            posf = push(posf, top(pili) -> elem, 0);
         }
         return(Lukas(pop(pili), posf, exp, 0));
      }
   else    /* el arreglo no est� vac�o */
   if(operando)  /* si el sig. car�c. es un d�gito */
   {
      if(lee_oprnd)   /* en el tope de pili hay un n�mero */
      {
         i = top(pili) -> elem * 10 + (int)(c - '0');
         pili = push(pop(pili), i, 1);
      }
      else     /* en el tope de pili no hay un n�mero */
         pili = push(pili, (int)(c - '0'), 1);
      return(Lukas(pili, posf, exp + 1, 1));
   }
   else    /* el siguiente car�cter no es un d�gito */
   if(lee_oprnd)  /* ... pero en el tope de pili hay un n�mero */
   {
      printf(" %d ", top(pili) -> elem);
      posf = push(posf, top(pili) -> elem, 1);
      return(Lukas(pop(pili), posf, exp, 0));
   }
/*    ya consideramos todos casos de d�gitos y operandos   */
   else
   if( c == '(')  /*   || isemptystack(pili))   */
   {
      pili = push(pili, (int)c, 0);
      return(Lukas(pili, posf, exp + 1, 0));
   }
   else
   if(c == ')')
   {
      if(top(pili) -> elem == (int)'(')
         return(Lukas(pop(pili), posf, exp + 1, 0));
      else
      {
         putchar((char)top(pili) -> elem);
         putchar(' ');
         posf = push(posf, top(pili) -> elem , 0);
         return(Lukas(pop(pili), posf, exp, 0));
      }
   }
   else
   if(isemptystack(pili))
   {
      pili = push(pili, (int)c, 0);
      return(Lukas(pili, posf, exp + 1, 0));
   }
   else
   if(jrq(c) >= jrq((char)top(pili) -> elem))
   {
      pili = push(pili, (int)c, 0);
      return(Lukas(pili, posf, exp + 1, 0));
   }
   else
   {
      putchar((char)top(pili) -> elem);
      putchar(' ');
      posf = push(posf, top(pili) -> elem, 0);
      pili = push(pop(pili), (int)c, 0);
      return(Lukas(pili, posf, exp + 1, 0));
   }
}

int jrq(char c)
{
   if(c == '(')
      return(0);
   if((c == '+') || (c == '-') || (c == '?'))
      return(1);
   if((c == '*') || (c == '/'))
      return(2);
}

void verifica(STACK posf)
{
   if(isemptystack(posf))
      puts(" Empty");
   else
   {
      if(top(posf) -> flag)
         printf(" pop: %d\n", top(posf) -> elem);
      else
         printf(" pop: %c\n", top(posf) -> elem);
      verifica(pop(posf));
   }
}

/*     imprime la pila en reversa
void verifica(STACK posf)
{
   STACK tmp;
   if(isemptystack(posf))
      ;
   else
   {
      tmp = top(posf);
      verifica(pop(posf));
      if(tmp -> flag)
         printf(" pop: %d\n", tmp -> elem);
      else
         printf(" pop: %c\n", (char)tmp -> elem);
   }
}
*/