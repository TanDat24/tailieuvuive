#include<stdio.h>
#include<math.h>
#define max 1000

int main(int argc, char const *argv[])
{
    int chon;
    int k, n, a[1000];
    printf("\nNhap vao so phan tu mang: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }
    
    do
    {
        printf("\nMenu");
        printf("\n1. Tao dai so");
        printf("\n2. In dai so");
        printf("\n3. Tinh tong cac so chinh phuong");
        printf("\n4. Thoat");
        printf("\nChon cong viec: ");
        scanf("%d", &chon);
        switch (chon)
        {
            case 1: {
                    printf("\nCac so nguyen to trong mang: ");
                    for (int i = 2; i <= n; i++)
                    {
                        if (n%i == 0) return(0);
                        return(1);
                        
                    }
                    
               }
        
            break;

            case 2: {

            }
            break;

            case 3: {

            }
            break;

            case 4: {

            }
            break;
        }
    } while (chon < 4);
    
}


