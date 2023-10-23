#include<stdio.h>

int main(int argc, char const *argv[])
{
    int n;
    int arr[n];
    int trungBinhCong = 0;
        if (n<0)
        {
            printf("\nNHap sai!!!");
            for (int i = 1; i <= n; i++)
            {
                printf("\nNhap so nguyen: ");
                scanf("%d", &arr[i]);
                trungBinhCong = trungBinhCong + (n[i]);
            }
            printf("\ntrung binh cong cua day so nay la: %d", trungBinhCong);
            
        }
        
    return 0;
}
