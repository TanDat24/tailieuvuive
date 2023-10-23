#include<stdio.h>
#include<math.h>
#define max 1000

int snt(int n);
int scp(int n);
int sdx(int n);
int sb3(int n);

int main(int argc, char const *argv[])
{
    int k, n, a[1000];
    printf("\nNhap vao so phan tu mang: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }

// xuất các số nguyên tố
    for (int i = 0; i < n; i++)
    {
        if (snt(a[i]) == 1)
        {
            printf("\nCac so nguyen to trong dai la: %d", a[i]);
        }
    }

    // xuất các số chính phương

    for (int i = 0; i < n; i++)
    {
        if (scp(a[i] == 1))
        {
            printf("\nCac so chinh phuong trong dai : %d", a[i]);
        }
    }

    // Xuất các số đảo

    for (int i = 0; i < n; i++)
    {
        int nSodao = sdx(a[i]);
        if (a[i] == nSodao)
        {
            printf("\nSo doi xung la: %d",a[i]);
        }
        
    }
    
    
    
    return 0;
}

int snt(int n) {
    for (int i = 2; i <= n; i++)
    {
        if (n%i == 0) return 0;
        return 1;
    }
}

int scp(int n) {
    if (sqrt(n)==(int)sqrt(n)) return 1;
    else return 0;
    
}

int sdx(int n) {
    int nRem;
    int nSodao = 0;
    while (n != 0)
    {
        nRem = n%10;

        nSodao /= 10;

        nSodao = (nSodao*10) + nRem;
    }
    return nSodao;
    
}