#include <stdio.h>

void mygets(char *);
void myputs(char *);

void main(){
    char vector[255];
    mygets(vector);
    myputs(vector);
}

void myputs(char *car){
    if(*car == '\n')
    ;
    else{
        putchar(*car);
        myputs(car+1);
    }
}

void mygets(char *car){
    *car = getchar();
    if(*car == '\n')
    *car = '\0';
    
    else
    mygets(car+1);
}