#include <stdio.h>
#include <malloc.h>

struct nodo{

    char val;
    struct nodo * ptr;

};

void main(){

    struct nodo * ancla;
    /*PRIMER NODO  */
    ancla = malloc(sizeof(struct nodo));
    ancla -> val = 'E';
    ancla -> ptr = NULL;
    putchar(ancla -> val);
    /*SEGUNDO NODO  */
    ancla -> ptr = malloc(sizeof(struct nodo));
    ancla -> ptr -> val = 'G';
    ancla -> ptr -> ptr = NULL;
    putchar(ancla -> ptr -> val);
}