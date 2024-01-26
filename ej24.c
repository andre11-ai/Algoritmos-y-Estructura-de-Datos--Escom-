#include <stdio.h>
#include <malloc.h>

struct nodo
{
   char val;
   struct nodo * ptr;
};

struct nodo * llena();
void imprime(struct nodo *);

 void main()
 {
    struct nodo *ancla;
    puts("Dame una frasecita: ");
    ancla = llena();
    imprime(ancla);
 }

 struct nodo * llena()
 {
    char c;
    struct nodo * celda;
    c = getchar();
    if(c == '\n')
       return(NULL);
    else
    {
       celda = malloc(sizeof(struct nodo));
       celda -> val = c;
       celda -> ptr = llena();
       return(celda);
    }
 }

 void imprime(struct nodo * celda)
 {
    putchar(celda -> val);
    if(celda -> ptr == NULL)
       putchar('\n');
    else
       imprime(celda -> ptr);
 }
