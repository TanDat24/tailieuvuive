#include<stdio.h>
#include<math.h> 
int nhap(int a,int b);
int tinh(int UCLN, int BCNN);
int main(int argc, char const *argv[])
{
    int a, b, UCLN, BCNN;
    printf("\nNhap vao so nguyen duong a: ");
    scanf("%d",&a);

    printf("\nNhap vao so nguyen duong b: ");
    scanf("%d",&b);

    nhap(&a,&b);

    tinh(UCLN,BCNN);


    return 0;
}

int nhap(int a, int b) {
    do
    {
        if (a<0 || b<0)
        {
            printf("\nNhap sai!!! nhap lai:");
            printf("\nNhap vao so nguyen duong a: ");
            scanf("%d",&a);

            printf("\nNhap vao so nguyen duong b: ");
            scanf("%d",&b);

        }
        return(a,b);
        
    } while (a<0 || b<0);
}

int tinh(int UCLN, int BCNN) {
    if (a == 0 && b ==0)
    {
        printf("\nKhong ton tai UCLN!");
    } else if (a==0 || b ==0)
    {
        printf("\nUCLN la %d", (a == 0) ? b : a);
    } else
    {
        int bc = a * b;
        while (a != b)
        {
            if (a > b)
            {
                a = a -b;
            } else {
                b = b- a;
            }
        }
            printf("\nUCLN cua la : %d",a);
            printf("\nBCNN cua la : %d",bc/a);
    }
}