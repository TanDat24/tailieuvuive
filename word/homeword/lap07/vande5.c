#include<stdio.h>
#include<math.h>

int main(int argc, char const *argv[])
{
    float Y;
    int i;
    float X;
    float M;
    float Date;
    printf("\nNhap so tien da gui: ");
    scanf("%f", &Y);
    printf("\nNhap so lai suat tren 1 thang: ");
    scanf("%f", &X);
    printf("\nNhap so tien lai can su dung: ");
    scanf("%f", &M);
    i =0;
    X = X/100;
    do
    {
        Date = Y*pow((1 + X), i);
        i++;
        
        
        
    } while (Date < M);
    printf("\nSo thang toi thieu de co so tien la: %d", i);
    return 0;
}
