#include <stdio.h>

void llena(char *, char);
void agrega_terminador(char *);

void main(){
    char vector [32]={"...............................\0"};
    puts(vector);
    agrega_terminador(vector+10);
    puts(vector);
    llena(vector, '0');
    puts(vector);
    llena(vector +1, '1');
    puts(vector);
}

void llena(char * vec, char c){
    if(c < ':'){
        *vec=c;
        llena(vec+2, c+2);
    }
}

void agrega_terminador(char * vec){
    * vec = '\0';
}