#include <stdio.h>

/* PUNTOS INFINITOS 

 La tarea que deberá ejecutar la función recursiva, la
    talacha, debe acompañar a la función.

*/



void puntitos();

void main(){
    puntitos();
}

void puntitos(){
    putchar('.');
    puntitos();
}