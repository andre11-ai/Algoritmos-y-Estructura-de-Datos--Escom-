#include <stdio.h>

int sucesor(int *);
 
void main(){
    int i, *apu;
    apu = &i;
    puts(" Teclea un entero");
    scanf("%i", apu); /*("%i", &i)*/
    sucesor(&i);
    printf("EL sucesor de i: %d \n", i);
    sucesor(apu);
    printf("Sucesor del sucesor de i: %d \n", i);
}

int sucesor(int * direccion){
    *direccion = *direccion+1;
    return(*direccion);
}