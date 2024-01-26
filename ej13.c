#include <stdio.h>

int regresa_primer_impar(int);

void main(){
    int num;
    puts("Escribe una secuencia de numeros y termina en 0");
    scanf("%d", &num);
    printf("\n Impar: %d", regresa_primer_impar(num));

}

int regresa_primer_impar(int num){
    int extra=0;
    if(num%2)  /*if((num/2)==1)*/
    return(num);
    else{
        scanf("%d", &extra);
        return(regresa_primer_impar(extra));
    }
}