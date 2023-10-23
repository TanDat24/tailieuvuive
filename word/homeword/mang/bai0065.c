#include<stdio.h>
#define max 100
int main(int argc, char const *argv[])
{
    int a[max];
    int n;
    int x;
    int i;
    printf("\nNhap so luong phan tu mang: ");
    scanf("%d", &n);
    do
    {
        if (n<0)
        {
            printf("\nNhap sai!!Nhap lai: ");
            scanf("%d", &n);
        }
        
    } while (a < 0);
    for (int i = 0; i < n; i++)
    {
        printf("\nNhap a[%d] = ", i+1);
        scanf("%d", &a[i]);
    }
    int b;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j= i + 1 ; j < n; j++)
        {
               if (a[i] > a[j])
               {
                b = a[i];
                a[i]=a[j];
                a[j] = b;
               }
                
        }
        
    }
    
    printf("\nMang duoc sap xep lai la: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", a[i]);
    }
    return 0;
}
