#include <stdio.h>
#include <math.h>
int main() {
    int d, m, y, nd, nm, ny;
    printf("\nnhap so thang: ");
    scanf("%d", &m);
    if (m>0||m<12)
    {
       switch (m)
       {
       case 1: case 3: case 5: case 7: case 8: case 10: case 12:
       printf("\nThang nay co 31 ngay."); 
        break;
       case 4: case 6: case 9: case 11:
       printf("\nThang nay co 30 ngay.");
       case 2:
       printf("\nNhap so nam: ");
       scanf("%d", &y);
       if (y%4==0)
       
        printf("\nThang nay co 29 ngay.");
        else 
        printf("\nThang nay co 28 ngay.");
       
       }

       
       
    }
    else printf("\nKhong co thang nay!!!");

        
    
    

    return 0;
}