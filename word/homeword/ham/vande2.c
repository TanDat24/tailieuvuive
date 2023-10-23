#include<stdio.h>
#include<math.h>

int main(int argc, char const *argv[])
{
    float a;
    double kq;
    printf("\nNhap so muon can ra vao: ");
    scanf("%f", &a);
    kq = sqrt(a);
    printf("kq la: %.2f", kq);
    return 0;
}
