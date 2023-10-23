#include<stdio.h>
#include<math.h>

int tinhTong(int n) {
    int s = 0;
    for (int i = 0; i <= n; i++)
        s += i;
        return s;
}

int xinChao() {
    printf("\nXin chao !");
}

int main(int argc, char const *argv[])
{   int n;
    printf("\nNhap so can tinh tong: ");
    scanf("%d", &n);
    int kq = tinhTong(n);
    printf("kq la: %d", kq);
    xinChao();
    return 0;
}

