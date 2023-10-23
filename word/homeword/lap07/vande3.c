#include<stdio.h>

int main(int argc, char const *argv[])
{
    char s[] = "uertydfghjjjjjjj3467";
    int i =0;
    int nguyenA = 0;
    int phuA = 0;
    int kiTuSo = 0;
    while (s[i++] !='\0')
    {
        if (s[i] == 'a' || s[i] == 'o' || s[i] == 'e'|| s[i] == 'u' || s[i] == 'i') 
        {
            nguyenA++;
        } else if ( s[i] >= 'a' && s[i] <= 'z')
        {
            phuA++;
        } else if ( s[i] >= '0' && s[i] <= '9')
        {
            kiTuSo++;
        }
    }
    printf("\nNguy am la: %d", nguyenA);
    printf("\nPhu am la: %d", phuA);
    printf("\nKi tu so la: %d", kiTuSo);
    
    return 0;
}
