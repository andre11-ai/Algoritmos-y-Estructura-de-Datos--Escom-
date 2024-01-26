#include <stdio.h>
#include <malloc.h>

struct nodo
{
   char val;
   struct nodo * ptr;
};

struct nodo * llena(void);
void imprime(struct nodo *);
struct nodo * examenA(struct nodo *, char); 

 void main()
 {
    struct nodo *ancla;
    puts("Dame una frase seguida de Enter: ");
    ancla = llena();
    imprime(ancla);
    puts(" ... teclea una letra: ");
    ancla = examenA(ancla, getchar());
    imprime(ancla);
 }

 struct nodo * examenA(struct nodo * secuencia, char c)
 {
    struct nodo * nuevo;
    if(secuencia -> ptr == NULL)
    {
       puts("No se encontraron letras iguales juntas.");
       return(secuencia);
    }
    else
    if(secuencia -> val == secuencia -> ptr -> val)
    {
       nuevo = malloc(sizeof(struct nodo));
       if(nuevo == NULL)
       {
          puts("Memoria insuficiente. Función: examenA.");
          return(secuencia);
       }
       nuevo -> val = c;
       nuevo -> ptr = secuencia -> ptr;
       secuencia -> ptr = nuevo;
       return(secuencia);
    }
    else
    {
       secuencia -> ptr = examenA(secuencia -> ptr, c);
       return(secuencia);
    }
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
    if(celda == NULL)
       putchar('\n');
    else
    {
       putchar(celda -> val);
       imprime(celda -> ptr);
    }
 }
