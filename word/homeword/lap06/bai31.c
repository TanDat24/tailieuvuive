#include <stdio.h>

int main() {
    int a, b, uc;
    printf("\nNhap 2 so can tim uoc chung: ");
    scanf("%d%d", &a, &b);

    for ( uc = a; uc > 1; uc--)
    {
        if (a%uc ==0 && b%uc ==0)
        {
            printf("\nUCLN(%d,%d) = %d",a, b, uc);
            break;
        }
        
    }
    
}