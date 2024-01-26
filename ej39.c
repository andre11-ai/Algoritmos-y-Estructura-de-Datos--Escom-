/* Recoge uno o varios enteros (o ninguno) del teclado y los
   ingresa en la cola para luego sacarlos, antes de salir de
   la cola revisa el frente y:
 - si el frente es cero, �ste s�lo abandona la cola y se ignora,
 - si el frente es par, �ste se divide entre tres y el cociente
   ingresa en la cola,
 - si el frente es impar, este se multiplica por dos y el
   producto reingresa en la cola.
   El proceso termina cuando la cola est� vac�a.
*/

#include <stdio.h>
#include "ej38.c"

void llena(int *);
void circula(int *);

void main()
{
   int myqueue[maxsize], inutil;
   myqueue[0] = 0;  /* inicializa la estructura, vac�a la cola */
   inutil = isemptyqueue(myqueue);  /* inicializa los �ndices */
   puts("Escribe una secuencia de n�meros entre 1 y 100 y\
 termina con un 0: ");
   llena(myqueue);
   circula(myqueue);
}

void llena(int * myqueue)
{
   int k;
   scanf("%d", &k);
   if(k)
      llena(enqueue(myqueue, k));
}

void circula(int * myqueue)
{
   int k;
   if(isemptyqueue(myqueue))
      puts(" La cola est� vac�a.");
   else
   {
      k = frontqueue(myqueue);
      printf(" %d ", k);
      if(k % 2)  /*  si al frente de la cola hay un n�mero impar */
         circula(enqueue(dequeue(myqueue), k * 2));
      else       /*  si al frente de la cola hay un n�mero par  */
      if(k > 0)
         circula(enqueue(dequeue(myqueue), k / 3));
      else
         circula(dequeue(myqueue));
   }
}
