#include <stdio.h>

void sub(char);
void main(){
    puts("Dame un digito");
    sub(getchar());
}

void sub(char car){
    if(car >='0'){
        putchar(car);
        sub(car-1);
        putchar(car);
    }
}