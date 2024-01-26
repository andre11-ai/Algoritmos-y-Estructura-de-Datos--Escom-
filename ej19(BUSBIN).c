#include <stdio.h>

int busbin(int *, int, int, int);
int lee(int*);

void main(){
	int vec[255], objetivo;
	puts("Proporciona el nuemero que se buscara en la secuencia asendente y termina con un 0");
	scanf("%d", &objetivo);
	printf("La posicion de objetivo es :%d\n", busbin(vec, 0, lee(vec) - 1, objetivo));
}

int lee(int *vec){
	scanf("%d", vec);
	if(*vec == 0)
		return (0);
	else
		return(lee(vec + 1) + 1);
}

int busbin(int *vec, int izq, int der, int objetivo){
	int mitad = (izq + der) / 2;	
	if(izq > der)
		return (-1);
	else
	if(izq == der)
		if(*(vec + izq) == objetivo)
			return (izq);
		else		
			return(-1);
	else
	if(*(vec + mitad) == objetivo)
		return (mitad);
	else
	if(*(vec + mitad) < objetivo)
		return(busbin(vec, mitad + 1, der, objetivo));
	else
		return(busbin(vec, izq, mitad - 1, objetivo));				
}