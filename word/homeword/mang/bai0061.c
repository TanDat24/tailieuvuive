#include<stdio.h>
#include<math.h>
#define max 100
int main(int argc, char const *argv[])
{
    int a[max], n;
    int S = 0;
    printf("\nNhap so luong mang:");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("\nNhap so a[%d]: ", i + 1);
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    } 
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= i)
        {
            printf("\ngia tri moi la: %d", a[i]+10);
        }
    }
    

    
    return 0;
}
