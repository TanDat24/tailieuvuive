#include<stdio.h>

int main(int argc, char const *argv[])
{
    int a;
    int s=0;
    do
    {
        printf("\nNhap so tien: ");
        scanf("%d", &a);
        if (a >= 0)
        {
        s=s+a;
        }
        
        printf("tong la: %d", s);
    } while (a>0);
    
    return 0;
}
