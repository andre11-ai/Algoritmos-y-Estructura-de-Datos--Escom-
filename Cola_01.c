/*Cola dinamica intento 1*/
#include <stdio.h>
#include <malloc.h>

struct node
{
	int elem;	
	struct node * sig;
};

typedef struct node * QUEUE;

int isemptyqueue(QUEUE);
QUEUE newqueue(void);
int frontqueue(QUEUE);
QUEUE enqueue(QUEUE, int);
QUEUE dequeue(QUEUE);
void printqueue(QUEUE);

/*void main() PRUEBA COLA
{
	QUEUE cola = newqueue();
	if(isemptyqueue(cola))
		puts("Si esta vacia, vamos bien\n");
	cola = enqueue(cola, 69);	
	if(isemptyqueue(cola))
		puts("Oh no... esta vacia");
	else
		printf("Frente: %d \n", frontqueue(cola));
	cola = enqueue(cola, 420);
	puts("Metimos 420");	
	printf("Frente: %d \n", frontqueue(cola));
	cola = enqueue(cola, 70);	
	puts("Metimos 70");
	printf("Frente: %d \n", frontqueue(cola));
	cola = enqueue(cola, 60);	
	puts("Metimos 60");
	printf("Frente: %d \n", frontqueue(cola));
	printqueue(cola -> sig);
	cola = dequeue(cola);
	puts("\nHacemos 'DEQUEUE'");
	printf("Frente: %d \n", frontqueue(cola));
	cola = dequeue(cola);
	puts("\nHacemos 'DEQUEUE'");
	printf("Frente: %d \n", frontqueue(cola));
	cola = dequeue(cola);
	puts("\nHacemos 'DEQUEUE'");
	printf("Frente: %d \n", frontqueue(cola));
	cola = dequeue(cola);
	puts("\nHacemos 'DEQUEUE'");
	if(isemptyqueue(cola))
		puts("Perfecto, la cola esta vacia");
	else
		puts("No funciona dequeue");
}
*/
int isemptyqueue(QUEUE myqueue)
{
	return(myqueue -> sig == NULL);		
}

QUEUE newqueue()
{
	QUEUE ancla;
	ancla = malloc(sizeof(struct node));	
	if(ancla == NULL)
		puts("ERROR... Memoria Agotada");
	else
		{
			ancla -> elem = 0;
			ancla -> sig  = NULL;
		}
	return(ancla);
}

int frontqueue(QUEUE myqueue)
{
	if(isemptyqueue(myqueue))	
		{
			puts("Error, la cola esta vacia");
			return(-1);
		}
	else
		return(myqueue -> sig -> elem);
}

QUEUE dequeue(QUEUE myqueue)
{
	if(isemptyqueue(myqueue))	
		{
			puts("Error, la cola esta vacia");
			return(myqueue);	
		}
	else
		{
			myqueue -> sig = myqueue -> sig -> sig;
			return(myqueue); 
		}
}

QUEUE enqueue(QUEUE myqueue, int val)
{
    if (myqueue->sig == NULL)
    {
        QUEUE aux = malloc(sizeof(struct node));
        if (aux == NULL)
        {
            puts("ERROR... Memoria Agotada");
            return myqueue; 
        }

        aux -> elem = val;
        aux -> sig = NULL;
        myqueue -> sig = aux;
        return myqueue;
    }
    else
    {
        myqueue -> sig = enqueue(myqueue->sig, val);
        return (myqueue);
    }
}

void printqueue(QUEUE myqueue)
{
	if(myqueue == NULL)
		;
	else
	{
		printf(" %d ,", myqueue -> elem);	
		printqueue(myqueue -> sig);
	}
	
}