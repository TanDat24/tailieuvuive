#include <stdio.h>
#include <math.h>

int main() {
    float n, mark;
    printf("nhap diem = ");
    scanf("%f", &n);
    mark=n*4/10;
    printf("diem theo thang 4 la: %.2f", mark);
    if (n<0 || n >10)
    {
        printf("\nKhong hop le");
    } else
    if (mark==4)
    {
        printf(" - Diem A");
    } else if (mark>=3.5 && mark<4)
    {
        printf(" - Diem B+");
    } else if (mark>=3 && mark<3.5)
    {
        printf(" - Diem B");
    } else if (mark>=2.5 && mark<3)
    {
        printf(" - Diem C+");
    } else if (mark>=2 && mark<2.5)
    {
        printf(" - Diem C");
    } else if (mark>=1.5 && mark<2)
    {
        printf(" - Diem D+");
    } else if (mark>=1 && mark<1.5)
    {
        printf(" - Diem D");
    } else if (mark<1)
    {
        printf(" - Diem F");
    } 
    
    return 0;
    

}
