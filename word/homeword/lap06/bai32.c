#include<stdio.h>

int main() {
    int chon, N;

    do
    {
        printf("\nNhap N: ");
        scanf("%d", &N);
        printf("\nMenu");
        printf("\n1. Tinh tong cac so tu 1 den N: ");
        printf("\n2. Tinh tong cac so chan: ");
        printf("\n3. Tinh tong cac so tu nhien chia het cho 3 la <= N: ");
        printf("\n4. Tinh tong binh phuong cac so le tu 1 den N: ");
        printf("\nChon cong viec:");
        scanf("%d", &chon);
        switch (chon)
        {
        case 1: {
            int sum = 0;
            for (int i = 1; i <= N; i++)
            {
                sum += i;
            }
            printf("\nTong tu 1 den %d la: %d", N, sum);
            
        } break;
        case 2: {
            int sum_chan = 0;
            for (int i = 1; i <= N; i++)
            {
                if (i%2 == 0)
                {
                    sum_chan +=i;
                }
            }
            printf("\nTong cac so chan: %d", sum_chan);
            
        } break;
        case 3: {
                int sum_chia3 = 0;
                for (int i = 1; i <= N; i++)
                {
                    if (i%3 ==0)
                    {
                        sum_chia3 +=i;
                    }
                }
                    printf("\nTong cac so chia het cho 3 nho hon bang %d la: %d", N, sum_chia3);
                
        } break;
        case 4: {
                int sum_le = 0;
                for (int i = 1; i <= N; i++)
                {
                    if (i%2 != 0)
                    {
                        sum_le = sum_le + i*i;
                    }
                }
                    printf("\nTong binh phuong cac so le tu 1 den %d: %d", N, sum_le);
                
        } break;
        }
    } while (chon<4);
    return 0;
}