#include<stdio.h>

int main(int argc, char const *argv[])
{
    char ch;
    scanf("%c", &ch);
    int nguyenA =0;
    int phuA = 0;
    int kiTuSo = 0;

    if (ch>='a' && ch <='z')
    {
        switch (ch)
        {
        case 'a':
        case 'o':
        case 'e':
        case 'u':
        case 'i': nguyenA++; break;
        
        default: phuA++;
        }
    } else if (ch < 0 || ch > 9)
    {
        kiTuSo++;
    }
    
    
    printf("\nSo nguyen am : %d", nguyenA);
    printf("\nSo phu am : %d", phuA);
    printf("\nSo ki tu so : %d", kiTuSo);
    
    return 0;
}
