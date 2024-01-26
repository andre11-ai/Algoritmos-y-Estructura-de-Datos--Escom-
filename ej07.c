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
      putchar(car);
      sub2(car - 1);
   } 
}

void sub2(char car)
{
   if(car >= '0')
   {
      putchar(car);
      sub3(car - 1);
   }
}

void sub3(char car)
{
   if(car >= '0')
   {
      putchar(car);
      sub4(car - 1);
   } 
}

void sub4(char car)
{
   if(car >= '0')
   {
      putchar(car);
      sub5(car - 1);
   } 
}

void sub5(char car)
{
   if(car >= '0')
   {
      putchar(car);
      sub6(car - 1);
   } 
}

void sub6(char car)
{
   if(car >= '0')
   {
      putchar(car);
      sub7(car - 1);
   } 
}

void sub7(char car)
{
   if(car >= '0')
   {
      putchar(car);
      sub8(car - 1);
   } 
}

void sub8(char car)
{
   if(car >= '0')
   {
      putchar(car);
/*      sub9(car - 1);   */
   } 
}