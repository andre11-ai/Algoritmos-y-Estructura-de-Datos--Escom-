#include <stdio.h>
#include "Cola_01.c"

QUEUE leeNum (QUEUE);
void impCola(QUEUE);

void main()
{
	QUEUE myqueue;
	puts("Dame una secuencia de numero y termina con 0");
	myqueue = leeNum(newqueue());
	puts("Ok entonces la cola quedara como...");
	impCola(myqueue);
	
}

QUEUE leeNum(QUEUE myqueue)
{
	int aux;
	scanf("%d", &aux);
	if(aux == 0)	
		return (myqueue);
	else
	{
		enqueue(myqueue, aux);
		myqueue -> sig = leeNum(myqueue -> sig); 	
		return(myqueue);
	}	
}

void impCola(QUEUE myqueue)
{
	if(isemptyqueue(myqueue))
	;
	else
	{
		printf(" %d, ", frontqueue(myqueue));
		myqueue = dequeue(myqueue);
		impCola(myqueue);	
	}
}
