#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<conio.h>
#define max 100

//giải phương trinh bật 2
int giaiPT(float a, float b, float c,float &x1, float &x2){
 float delta = b*b - 4*a*c;
 if(delta<0){
 x1=x2=0.0;
 return 0;
 }
 else if(delta==0){
 x1 = x2 = -b/(2*a);
 return 1;
 }
 else{
 delta = sqrt(delta);
 x1 = (-b + delta) / (2*a);
 x2 = (-b - delta) / (2*a);
 return 2;
 }
}

//hoán vị
void hoanvi(int a, int b) 
{
    int temp = a;
    a = b;
    b = temp;
}

//Nhap
void Nhap(int a[max], int &n) {
    printf("\nNhap so luong phan tu n = ");
    do{
        scanf("%d", &n);
        if(n <= 0){
        printf("\nNhap lai n = ");
        }
    }while(n <= 0);
}

//số đảo
int soDao(int n) {
    int tmp;
    int res = 0;
    while (n>0)
    {
        tmp = n%10;
        res = res*10+tmp;
        n=n/10;
    }
    return res;
}
//Kiểm tra xem 1 số có phải là số đối xứng
int soDoiXung(int n) {
    int flag = 0;
    if (soDao(n) == n) flag = 1;
        return flag;
}

//giai thừa
int gt(int b) { 
    int S=1;
    for (int i = 1; i <= b; i++)
    {
        S = S*i;
    }
    
    return S;
}

int main() {
    int chon;
    do
    {
        printf("\nMenu");
        printf("\n1.Bai 4, 5, 6, 7, 8 trang 140 - 141 chuong 8");
        printf("\n2.Bai tap 3 trang 155 chuong 9(cau lenh lap). Ham nhan vao mot so nguyen duong n va thuc hien:");
        printf("\n3.Bai tap 4 trang 156 chuong 9(cau lenh lap). Ham nhan vao mot so nguyen duong n va thuc hien: ");
        printf("\n4.thoat");
        printf("\nChon cong viec: ");
        scanf("%d", &chon);
            switch (chon){
            case 1:{
                int chon1;
                    do
                    {
                        printf("\nBai 4, 5, 6, 7, 8 trang 140 - 141 chuong 8:");
                        printf("\n1.Viet ham chuyen doi ky tu hoa sang ky tu thuong");
                        printf("\n2.Viet thu tuc giai phuong trinh bac nhat");
                        printf("\n3.Viet thu tuc giai phuong trinh bac hai");
                        printf("\n4.Viet ham tra ve gia tri nho nhat cua 4 so nguyen");
                        printf("\n5.Viet thu tuc hoan vi hai so nguyen");
                        printf("\n6.Viet thu tuc sap xep 4 so nguyen tang dan");
                        printf("\n7.Thoat");   
                        printf("\nChon cong viec: ");
                        scanf("%d",&chon1);
                            switch (chon1)
                            {
                            case 1:{
                                char str[100];
                                printf("\nNhap Chu hoa: ");
                                scanf("\n%s", str);
                                for (int i = 0; i < strlen(str); i++) {
                                    if (str[i] >= 'A' && str[i] <= 'Z') {
                                        str[i] += 32;
                                    }
                                }
                                printf("Chu thuong la: %s", str);
                            }break;
                            case 2:{
                                float a,b;
                                printf("\nNhap he so a: ");
                                scanf("%f",&a);
                                printf("\nNhap he so b: ");
                                scanf("%f",&b);
                                if(a==0){      
                                    if(b==0){   
                                        printf("\nPhuong trinh vo so nghiem");
                                    }else{       
                                        printf("\nPhuong trinh vo nghiem");
                                    }
                                }else{         
                                    printf("\nPhuong trinh co nghiem x=%g",-b/a);
                                }
                            }break;
                            case 3:{
                                float a,b,c;
                                float x1, x2;
                                do
                                {
                                    printf("\nNhap he so a(a khac 0): ");
                                    scanf("%f",&a);
                                    printf("\nNhap he so b: ");
                                    scanf("%f",&b);
                                    printf("\nNhap he so c: ");
                                    scanf("%f",&c);
                                } while (!a);
                                int numNo = giaiPT(a,b,c,x1,x2);
                                    if(numNo == 0) {
                                        printf("Phuong trinh da cho vo nghiem");
                                    }else if(numNo == 1){
                                        printf("Phuong trinh da cho co nghiem kep x=%.4f",x1);
                                    }else{
                                        printf("Phuong trinh da cho co hai nghiem phan biet\nx1=%.4f \nx2=%.4f",x1,x2);
                                    }
                            }break;
                            case 4:{
                                int a, b, c, d, min, min1, min2;
                                printf("Nhap vao so thu nhat: "); scanf("%d", &a);
                                printf("Nhap vao so thu hai: ");scanf("%d", &b);
                                printf("Nhap vao so thu ba: ");scanf("%d", &c);
                                printf("Nhap vao so thu tu: ");scanf("%d", &d);
                                    min1=a;
                                    min2=c;
                                        if(a>b)
                                            min1=b;
                                        if(c>d)
                                            min2=d;
                                    min=min1;
                                    if(min1>min2)
                                    min=min2;
                                printf("\nSo nho nhat trong 4 so la: %d", min);
                            }break;
                            case 5:{
                                int a, b;
                                printf("\nNhap so a: ");
                                scanf("%d", &a);
                                printf("\nNhap so b: ");
                                scanf("%d", &b);
                                printf("Truoc khi hoan vi:\na = %d \nb = %d\n", a, b);

                                hoanvi(a, b);

                                printf("Sau khi hoan vi:\na = %d\nb = %d \n", a, b);
                            }break;
                            case 6:{
                                int a[100];
                                int n;
                                Nhap(a,n);
                                for(int i = 0; i < n; i++){
                                    printf("\nNhap a[%d] = ",i);
                                    scanf("%d", &a[i]);
                                }   
                                int tg;
                                for(int i = 0; i < n - 1; i++){
                                    for(int j = i + 1; j < n; j++){
                                        if(a[i] > a[j]){
                                            // Hoan vi 2 so a[i] va a[j]
                                            tg = a[i];
                                            a[i] = a[j];
                                            a[j] = tg;        
                                        }
                                    }
                                }
                                printf("\nMang da sap xep la: ");
                                    for(int i = 0; i < n; i++){
                                        printf("%5d", a[i]);
                                    }
                            }break;
                            case 7:{}break;
                            }
                    } while (chon1<7);
                    
            }break;
            case 2:{
                int chon2;
                    do
                    {
                        printf("\nBai tap 3 trang 155 chuong 9(cau lenh lap). Ham nhan vao mot so nguyen duong n va thuc hien:");
                        printf("\n1.tra ve so dao cua so do");
                        printf("\n2.Co phai la so doi xung?");
                        printf("\n3.Co phai la so chinh phuong?");
                        printf("\n4.Co phai la so nguyen to?");
                        printf("\n5.Tong cac chu so le");
                        printf("\n6.Tong cac chu so nguyen to");
                        printf("\n7.Tong cac so chinh phuong");
                        printf("\n8.Thoat");
                        printf("\nChon bai lam: ");
                        scanf("%d",&chon2);
                            switch (chon2){
                            case 1:{
                                int n;
                                printf("\nNhap so n: "); scanf("%d", &n);
                                printf("\nSo dao lai la: %d",soDao(n));
                            }break;
                            case 2:{
                                int n;
                                printf(">> Nhap so tu nhien: ");
                                scanf("%d",&n);
                                int check = soDoiXung(n);
                                if( check == 1 ) printf("%d la so doi xung\n", n);
                                else printf("%d khong phai la so doi xung\n", n);
                            }break;
                            case 3:{
                                int n;
                                printf("\nNhap n: ");
                                scanf("%d", &n);
                                int i = 0;
                                while(i*i <= n){
                                if(i*i == n){
                                printf("\n%d la so chinh phuong!", n);
                                return 0;
                                }
                                ++i;
                                }
                                printf("\n%d khong phai so chinh phuong!", n);
                            }break;
                            case 4:{
                                int n;
                                printf("\nNhap n = ");
                                scanf("%d", &n);
                                if(n < 2){
                                    printf("\n%d khong phai so nguyen to", n);
                                    return 0;
                                }
                                int count = 0;
                                for(int i = 2; i <= sqrt(n); i++){
                                    if(n % i == 0){
                                        count++;
                                    }
                                }
                                if(count == 0){
                                    printf("\n%d la so nguyen to", n);
                                }else{
                                    printf("\n%d khong phai so nguyen to", n);
                                }
                            }break;
                            case 5:{
                                int n;
                                    int gan;
                                    int tong = 0;
                                    do
                                    {
                                        printf("\nNhap n: ");
                                        scanf("%d", &n);
                                    }while(n < 0 && printf("\nLoi: n >= 0 !"));
                                    gan = n;
                                    while(gan != 0)
                                    {
                                        if(gan%2==1)
                                        {
                                            tong = tong + gan%10;
                                        }
                                        gan = gan / 10;
                                    }
                                    printf("\nTong cac chu so le cua %d la %d",n, tong);
                            }break;
                            case 6:{
                                int a[100];
                                int n;
                                int dem = 0;
                                int ngto;
                                Nhap(a,n);
                                for(int i = 0; i < n; i++){
                                    printf("\nNhap a[%d] = ",i);
                                    scanf("%d", &a[i]);
                                }   
                                int sum=0;
                                printf("\n cac so nguyen to la: \n");
                                for(int i=0;i<n;i++)
                                {
                                    ngto=1;
                                    if(a[i]<2) ngto=0;
                                    for(int j=2;j<=sqrt(a[i]);j++)
                                    if(a[i]%j==0) ngto=0;
                                        if(ngto)
                                            {
                                                printf("%d",a[i]);
                                                dem++;
                                                sum += a[i];
                                            }
                                }
                                if(dem)
                                    printf("\n co %d so la so nguyen to \n tong = %d\n",dem,sum);
                                else
                                    printf("\n khong co phan tu nao \n");
                            
                            }break;
                            case 7:{
                                int n;
                                printf("\nNhap n: ");
                                scanf("%d", &n);
                                do
                                {
                                    if (n<0)
                                    {
                                        printf("\nNhap sai!! nhap lai(n>0): ");
                                        scanf("%d", &n);
                                    }
                                    
                                } while (n<0);
                                int S = 0;
                                for (int i = 1; i <= n; i++)
                                {
                                    bool flag = 0;
                                    for (int j = 1; j <= i; j++)
                                    {
                                        if (j*j == i)
                                        {
                                            flag = 1;
                                        }
                                    }
                                    if (flag)
                                    {
                                        S= S + i;
                                    } 
                                }
                                    printf("\nTong cac so chinh phuong tu [1, %d] la: %d", n, S);   
                            }break;
                            case 8:{}break;
                            }
                    } while (chon2<8);
            }break;
            case 3:{
                int chon3;
                    do
                    {
                        printf("\nBai tap 4 trang 156 chuong 9(cau lenh lap). Ham nhan vao mot so nguyen duong n va thuc hien:");
                        printf("\n1.S = 1 + 2 +...+ n");
                        printf("\n2.S = 1^2 + 2^2 +...+ n^2");
                        printf("\n3.S = 1+ 1/2 +...+ 1/n");
                        printf("\n4.S = 1 * 2 *...*n");
                        printf("\n5.S = 1! + 2! +...+ n!");
                        printf("\n6.Thoat");   
                        printf("\nChon cong viec: ");
                        scanf("%d",&chon3);
                            switch (chon3)
                            {
                            case 1:{
                                int a[max];
                                int n;
                                int S = 0;
                                Nhap(a,n);
                                for (int i = 1; i <= n; i++)
                                {
                                    S = S + i;
                                }
                                printf("\nTong cac so nguyen [1, %d] la : %d", n, S);
                                
                            }break;
                            case 2:{
                                int a[max];
                                int n;
                                int S = 0;
                                int b;
                                Nhap(a,n);
                                for (int i = 1; i <= n; i++)
                                {
                                    S = S + i*i;
                                }
                                printf("\nTong cac so nguyen tu [1, %d] la: %d", n, S);
                            }break;
                            case 3:{
                                int a[max];
                                int n;
                                float S = 0;
                                Nhap(a,n);
                                for (int i = 1; i <= n; i++)
                                {
                                    S = S + (float)1/i;
                                }
                                printf("\nTong cac so nguyen tu [1, 1/%d] la: %f", n, S);
                                
                            }break;
                            case 4:{
                                int a[max];
                                int n;
                                int S = 1;
                                Nhap(a,n);
                                for (int i = 1; i <= n; i++)
                                {
                                    S = S*i;
                                }
                                printf("\nTich cac so nguyen tu [1, %d] la: %d", n, S);
                            }break;
                            case 5:{
                                int a[max];
                                int n;
                                int S = 0;
                                int giaiThua;
                                Nhap(a,n);
                                for (int i = 1;i <= n; i++) S = S + gt(i);
                                printf("\nTong cac giai thua tu [1, %d] la: %d", n, S);
                            }break;
                            case 6:{}break;
                            }
                    } while (chon3<6);
            }break;
            case 4:{
            }break;
            }
    } while (chon<4);
    return 0;
}