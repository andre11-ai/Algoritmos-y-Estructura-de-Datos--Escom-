#include <stdio.h>

/*  La función putchar imprime un carácter en el monitor  */

void main(){
    putchar('A');
    putchar('\007');
    putchar(putchar(putchar('A')+1)+1);

}