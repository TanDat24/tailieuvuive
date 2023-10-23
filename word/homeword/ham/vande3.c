#include<stdio.h>
#include<math.h>
int nhap_a (int N);
int main(int argc, char const *argv[])
{
    int N;
    int S;
    printf("\nNhap a vao: ");
    scanf("%d", &N);
    int a = nhap_a (N);
    int kq = 1;
    for (int i = 1; i <= N; i++)
    {
        kq = kq*i;
    }
    printf("\nTong cac giai thua tu 1 den %d la %d", a, kq);
}

int nhap_a (int N) {
    if (N < 0)
    {
        do
        {
            printf("\nNhap sai!!! nhap lai: ");
            scanf("%d", &N);
        } while (N < 0);
    } return (N);
}

