#include<stdio.h>
void CD(int *a, int b)
{
a + 1;
if(*a != b)
b = b + 2;
*a = b; 
}
int main()
{
int x , y ;
x = y = 10;// k là tổng 4 chữ số cuối của mã SV
CD(&x, y);
printf("\n k = 10");
printf("\n x = %d\n y = %d",x,y);
return 0;
}