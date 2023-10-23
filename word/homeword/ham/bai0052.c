#include<stdio.h>
#include<math.h> 
void tinh(int &min, int &max, int n, int a);
int main(int argc, char const *argv[])
{
    int n, a;
    int min = 9;
    int max = 0;
    printf("\nNhap vao so nguyen duong: ");
    scanf("%d", &n);

    // while ( n > 0)
    // {
    //     a = n%10;
    //     if (a > max)
    //     {
    //         max = a;
    //     } if (a < min)
    //     {
    //         min = a;
    //     }
    //     n = n/10;
        
    // }
    tinh(min, max, n, a);
    printf("\nSo lon nhat: %d", max);
    printf("\nSo nho nhat: %d", min);
    
    
    return 0;
}

void tinh(int min, int max, int n, int a) {
     while ( n > 0)
    {
        a = n%10;
        if (a > max)
        {
            max = a;
        } if (a < min)
        {
            min = a;
        }
        n = n/10;
        
    }
}