#include<stdio.h>
#define max 1000

void input_Arr(int a[max], int &n) {
    printf("\nNhap so luong mang: "); scanf("%d", &n);
    while (a<0)
    {
        printf("\nNhap sai!! nhap mang > 0:");scanf("%d", &n);
    }
    for (int i = 0; i < n; i++)
    {
        printf("\na[%d]", i+1);
        scanf("%d", &a[i]);
    }
    

}

int main(int argc, char const *argv[])
{
    
    int chon;
    int a[];
    int n;
    do
    {
        printf("\n1.Tao mang");
        switch (chon)
        {
        case 1: {
            input_Arr(a[],n);
        }
            break;
        
        }
    } while (chon < 100);
    
    return 0;
}
