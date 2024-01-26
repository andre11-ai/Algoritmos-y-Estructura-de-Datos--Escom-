#include <stdio.h>

void leer(char *);
void est(char *);
void comp(char *, char *);

void main(){
    char arl[255], arl2[255];
    puts("Escribe dos cadenas para compararlas ");
    leer(arl);
    leer(arl2);
    comp(arl,arl2);
    est(arl);
    puts("");
    est(arl2);
}

void leer(char * arl){
    if((*arl = getchar()) == '\n')
    *arl = '\0';
    else 
    leer(arl + 1);
}

void est(char * arl){
    if(putchar(*arl) == '\0');
    else
    est(arl + 1);
}

void comp(char *arl, char *arl2){
    if((*arl) != (*arl2))
    puts("No son iguales");
    else 
    if((*arl == '\0') && (*arl2 == '\0'))
    puts("Son iguales");
    else 
    comp(arl+1, arl2+1);
}