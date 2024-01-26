#include <stdio.h>

void sub(char);

void main()
{
    puts("Dame un dígito:  ");
    sub(getchar());
}

void sub(char car)
{
   if(car >= '0')
   {
      putchar(car);
      sub(car - 1);
   } 
}
