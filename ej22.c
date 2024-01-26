#include <stdio.h>
#include <malloc.h>

struct nodo{

    char val;
    struct nodo * ptr;

};

void main(){

    struct nodo * ancla;
    ancla = malloc(sizeof(struct nodo));
    ancla -> val = 'E';
    ancla -> ptr = NULL;
    putchar(ancla -> val);
}