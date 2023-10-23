#include<stdio.h>

int main() {
    int n;
    int giaiThua = 1;
    do
    {
        printf("\nNhap so can tinh giai thua: ");
        scanf("%d", &n);
        if (n<0)
        {
            printf("\nHay nhap so nguyen duong!!");
        }
    } while (n<0);
    for (int i = 1; i <= n; i++)
    {
        giaiThua = giaiThua*i;
    }
    printf("%d! = %d\n", n, giaiThua);
    
    
} 