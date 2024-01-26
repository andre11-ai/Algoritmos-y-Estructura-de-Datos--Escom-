/* 
    Cola estática. Se implementa directamente en un arreglo.
    Por ser estática, incluirá reglas especiales:
    El índice cero del arreglo indica el tamaño de la cola (no
    debería conocerse, lo hemos incluido con fines prácticos).
    El índice 1 del arreglo indica el elemento en el frente de
    la cola.
    El índice 2 del arreglo indica el último elemento de la
    cola.
    Si la cola tiene un sólo elemento los índices rear y front
    serán iguales.
    Si la cola está vacía los índices se cruzan:
       rear == (front - 1)
*/

#include <stdio.h>

const int maxsize = 4096;

int isemptyqueue(int *);
int frontqueue(int *);
int * enqueue(int *, int);
int * dequeue(int *);

int isemptyqueue(int * myqueue)
{
   if(myqueue[0] == 0)
   {
      myqueue[1] = 4;   /*  front  */
      myqueue[2] = 3;   /*  rear   */
      return(1);
   }
   else
      return(0);
}

int frontqueue(int * myqueue)
{
   if(isemptyqueue(myqueue))
   {
      puts("Error: Intenta observar una estructura vacía.\
 Función: frontqueue.");
      return(-1);
   }
   else
      return(myqueue[myqueue[1]]);
}

int * enqueue(int * myqueue, int id)
{
   if(isemptyqueue(myqueue)) ;    /* just start the queue */
   myqueue[2] = myqueue[2] + 1;   /* update rear location */
   myqueue[myqueue[2]] = id;
   myqueue[0] = myqueue[0] + 1;   /* update volume */
   return(myqueue);
}

int * dequeue(int * myqueue)
{
   if(isemptyqueue(myqueue))
   {
      puts("Error: Acceso a estructura vacía. Función: dequeue.");
      return(myqueue);
   }
   else
   {
      myqueue[0] = myqueue[0] - 1;   /*  update volume  */
      myqueue[myqueue[1]] = 0;       /*  removed from queue  */
      myqueue[1] = myqueue[1] + 1;   /*  update front location */
      return(myqueue);
   }
}

