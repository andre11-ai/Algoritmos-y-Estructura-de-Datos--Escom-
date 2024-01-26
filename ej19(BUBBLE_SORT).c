#include <stdio.h>

void lee(char *);
void imprime(char *);
int recorre(char *);
void bubble(char *);
void intercambia(char *, char *);

void main(){
	char palab[255];
	lee(palab);
	bubble(palab);
	imprime(palab);
}

void lee(char *vec){
	if((*vec = getchar()) == '\n')	
		*vec = '\0';
	else
		lee(vec + 1);
}

void imprime(char *vec){
	if(putchar(*vec) == '\0') 
		;
	else
		imprime(vec + 1);	
}

void bubble(char *vec){
	if(recorre(vec))
		bubble(vec);
}

int recorre(char *vec){
	if((*vec) == '\0')
		return (0);
	else
	if(*(vec+1) == '\0')
		return (0);
	else	
	if(*vec > *(vec + 1))	
		{
			intercambia(vec, vec + 1);
			return(recorre(vec + 1) + 1);			
		}
		else
			return(recorre(vec + 1));	
}

void intercambia(char *alfa, char *beta){
	char extra = *alfa;
	*alfa = *beta;
	*beta = extra;
}