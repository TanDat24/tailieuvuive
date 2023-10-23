#include<stdio.h>
#include<math.h>
#include<conio.h>
int main() {
    int x = 0;
    printf("\nNhap so tien: ");
    scanf("%d", &x);

    int soto_500 = 0;
    int soto_200 = 0;
    int soto_100 = 0;
    int soto_50 = 0;

    for (int i = 1; i > 0; )
    {
        if ( x == 0)
        {
            break;
        }
        if (x >= 500)
        {
            x -= 500;
            soto_500++;
        }
        else if ((x <500) && (x >= 200))
        {
            x -= 200;
            soto_200++;
        }
        else if ((x <200) && (x >= 100))
        {
            x -= 100;
            soto_100++;
        }
        else if ((x <100) &&(x >= 50))
        {
            x -= 50;
            soto_50++;
        }
    }
        printf("\nSo to 500 %d to\n", soto_500);
        printf("\nSo to 200 %d to\n", soto_200);
        printf("\nSo to 100 %d to\n", soto_100);
        printf("\nSo to 50 %d to\n", soto_50);
        getch();
    
}