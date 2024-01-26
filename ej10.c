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
      sub(car - 1);
      putchar(car);
   } 
}
