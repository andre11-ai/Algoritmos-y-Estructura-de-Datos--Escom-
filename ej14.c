#include <stdio.h>

int suma(int);

void main(){
    int num;
    puts("Escribe una secuencia de numeros y termina en 0");
    scanf("%d", &num);
    printf("\n Suma: %d",suma(num));

}

int suma(int num){
    int extra=0;
    if(num==0)
    return(0);
    else{
        scanf("%d",&extra);
        return(suma(extra)+num);
    }
}