#include <stdio.h>
#include <math.h>
#define max 100

//Nhap
void Nhap(int &n){
	printf("Nhap n: ");
	scanf("%d", &n);
		do{
			if(n<0) {
				printf("\nNhap sai!!Nhap lai(n>0): ");
				scanf("%d", &n);
			}
		}while(n<0);
}
//Tong va tich
int Tong(int num) {
   int res;
   if (num == 1) {
      return (1);
   } else {
      res = num + Tong(num - 1);
   }
   return (res);
}
int Tich(int num) {
   int res;
   if (num == 1) {
      return (1);
   } else {
      res = num * Tich(num - 1);
   }
   return (res);
}
//mu
int mu(int a,int b)
{
     if(b==1)
     return a;
     else
     return mu(a,b-1)*a;
}
//cap so cong
int csc(int n,int a,int r)
{
      if (n==1) return a;
      return(r+csc(n-1,a,r));
}


//cap so nhan
int csn(int n,int a,int r)
{
      if (n==1) return a;
      return(r*csn(n-1,a,r));
}


//Bieu dien nhi phan
void xuatnhiphan(int n) {
	if(n>=0){
		if (n/2>0) xuatnhiphan(n/2);
		printf("%d",n%2);
	}
}

int main(int argc, char *argv[])
{
	int a[max];
	int n;
	int chon;
	do {
		printf("\nMenu");
		printf("\n1.Bai thuc hanh so 1");
		printf("\n2.Thoat");
		printf("\nChon bai lam: ");
		scanf("%d", &chon);
		switch(chon){
			case 1: {
				int chon1;
				do {
					printf("\nChon bai");
					printf("\n1.Tinh tong va tich");
					printf("\n2.Cap so cong va cap so nhan");
					printf("\n3.Xuat bieu dien nhi phan cua so duong n");
					printf("\n4.Thoat");
					printf("\nChon bai lam: ");
					scanf("%d",&chon1);
						switch(chon1){
						case 1: {
							int S = 0;
							int P = 1;
							int i, num, b;
				   			int result;
							printf("Nhap mot so bat ky: ");
							scanf("%d", &num);
							result = Tong(num);
							printf("\nTong cac so tu 1 toi %d la: %d", num, result);
							result = Tich(num);
							printf("\nTich cac so tu 1 toi %d la: %d\n", num, result);
							int n,x;
							printf("\nTinh mu\n");
						    printf("nhap co so a:  ");
						    scanf("%d",&n);
						    printf("Nhap so mu:   ");
						    scanf("%d",&x);
						    printf("%d",mu(n,x));
							
						}break;
						case 2: {
							int n, a, r, i, q;
								printf("nhap so hang dau a= "); scanf("%d",&a);
						      	printf("nhap cong sai r= "); scanf("%d",&r);
						      	printf("nhap cong boi q= "); scanf("%d",&q);
						      	printf("\nnhap so luong cac phan tu can xuat n= ");
						      	scanf("%d",&n);
						      	if (n<=0) printf("so luong cac phan tu can xuat ban nhap ko hop le!");
						      		for(i=1;i<=n;i++)
       									printf("tri thu %2d cua csc= %5d\n",i,csc(i,a,r));
       									printf("nhap so luong cac phan tu can xuat n= \n");
						      			scanf("%d",&n);
						      	if (n<=0) printf("so luong cac phan tu can xuat ban nhap ko hop le!");
						      		for(i=1;i<=n;i++)
       								printf("\n tri thu %2d cua csn= %5d",i,csn(i,a,q));
						}break;
						case 3: {
							int n;
							printf("\nNhap n = ");
							scanf("%d", &n);
							xuatnhiphan(n);
						}break;
						case 4: {}break;
					}
				}while(chon1<4);
			}break;
			case 3: {}break;
		}
	}while(chon<3);
	return 0;
}