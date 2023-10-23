#include<stdio.h>
#include<conio.h>
int main() {
    int h, w;
    printf("\nNhap chieu dai va chieu rong: ");
    scanf("%d%d", &h, &w);
    for (int i = 1; i <= h ; i++)
    {
        for (int k = 1; k <= w; k++)
        {
            if (i == 1 || k == 1 || i == h || k == w)
            {
                printf("*");
            } else {
                printf("*"); // đổi đấu * thành chuỗi rỗng sẽ ra hinh hộp rổng
            }
            
        }
        printf("\n");
    }
    
}