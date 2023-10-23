#include<stdio.h>

int main(int argc, char const *argv[])
{
    int n;
    float s = 0;
    printf("\nNhap so n: ");
    scanf("%d", &n);
    do
    {
        if (n < 1)
        {
            printf("\nNHap n phai lon hon bang 1! Nhap lai: ");
            scanf("%d", &n);
        } 
    } while (n < 1);
    for (int i = 1; i <= n; i++)
    {
        s = s + 1.0/i;
        printf("\nTong cua 1 + 1/2 +...+1/%d bang: %.2f", i, s);
    }
    return 0;
}
