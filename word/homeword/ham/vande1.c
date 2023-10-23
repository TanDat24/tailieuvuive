#include<stdio.h>
#include<math.h>
void doulble_pow (int a, int m );
int main(int argc, char const *argv[])
{
    float kq;
    int a;
    int m;
    printf("\nNhap gia tri cua a: ");
    scanf("%d", &a);
    printf("\nNhap gia tri cua m: ");
    scanf("%d", &m);
    
        kq = pow(a,m);
        printf("\nKet qua cua %d^%d la %.2f", a, m, kq);
    
    
    
    return 0;
}
