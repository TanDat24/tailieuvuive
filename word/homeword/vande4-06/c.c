
#include <stdio.h>

int main() {
    int n500 = 100, n200 = 100, n100 = 100, n50 = 200, i = 0;
    long int tien;
    do
    {
        printf("\nNhap so tien can rut: ");
        scanf("%ld", &tien);
        if (tien < 0 || tien%50000 != 0)
        {
            printf("\nNhap sai. Nhap lai!!!");
        }
    } while (tien < 0 || tien%50000 != 0);

    for (int t500 = 0; t500 <= n500; t500++)
        for (int t200 = 0; t200 <= n200; t200++)
            for (int t100 = 0; t100 <= n100; t100++)
                for (int t50 = 0; t50 <= n50; t50++)
                    if (t500*500000 + t200*200000 + t100*100000 + t50*50000 == tien)
                    {
                        i++;
                        printf("\nPhuong an %d:%d to 500 + %d to 200 + %d to 100 + %d to 50");
                    }
    return 0;
    
}