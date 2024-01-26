#include <stdio.h>

void main(){
    int i , * apu;
    apu = &i;
    puts("Teclea un entero");
    scanf("%i", apu);
    /*scanf("%i", &i)*/
    printf("Valor de i:%d \n", i);
    printf("Valor de i: %d \n", *apu);
    printf("Direccion de i: %p \n", apu);
    printf("Direccion de i: %p \n", &i);
}