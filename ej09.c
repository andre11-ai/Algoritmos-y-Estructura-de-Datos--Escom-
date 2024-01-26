#include <stdio.h>

void sub1(char);
void sub2(char);
void sub3(char);
void sub4(char);
void sub5(char);
void sub6(char);
void sub7(char);
void sub8(char);

void main()
{
    puts("Dame un dígito:  ");
    sub1(getchar());
}

void sub1(char car)
{
   if(car >= '0')
   {
      sub2(car - 1);
      putchar(car);
   } 
}

void sub2(char car)
{
   if(car >= '0')
   {
      sub3(car - 1);
      putchar(car);
   }
}

void sub3(char car)
{
   if(car >= '0')
   {
      sub4(car - 1);
      putchar(car);
   } 
}

void sub4(char car)
{
   if(car >= '0')
   {
      sub5(car - 1);
      putchar(car);
   } 
}

void sub5(char car)
{
   if(car >= '0')
   {
      sub6(car - 1);
      putchar(car);
   } 
}

void sub6(char car)
{
   if(car >= '0')
   {
      sub7(car - 1);
      putchar(car);
   } 
}

void sub7(char car)
{
   if(car >= '0')
   {
      sub8(car - 1);
      putchar(car);
   } 
}

void sub8(char car)
{
   if(car >= '0')
   {
/*      sub9(car - 1);   */
      putchar(car);
   } 
}
