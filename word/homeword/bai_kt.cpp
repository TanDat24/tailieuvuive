#include <stdio.h>
#define max 100



void nhapNgayLam(int a[max], int &n) {
	printf("\nNhap so ngay lam: ");
	scanf("%d", &n);
	do {
		if(n<1 || n>31) {
		printf("\nNhap sai!!Nhap lai: ");
		scanf("%d", &n);
		}
	} while(n<1 || n>31);
}

void nhapGioLam(int a[max], int &n) {
	int i;
	for(i=0;i<n; i++){
		printf("gio lam ngay thu %d: ",i+1);
		scanf("%d", &a[i]);
		do {
		if(a[i]<1 || a[i]>24) {
		printf("\nNhap sai!!Nhap lai: ");
		scanf("%d", &a[i]);
		}
	} while(a[i]<1 || a[i]>24);
	}
	
} 

void outputArr(int a[max], int &n) {
	for(int i = 0; i<n; i++) {
		printf("%d	", a[i]);
	}
}

int tongSoTien(int a[max], int &n) {
	int s = 0;
	for(int i = 0; i<n; i++) {
		s = s + a[i]*18000;
		
	} return s;
}

int soTienTrungBinhNgay(int a[max], int &n) {
	int t =0;
	for(int i = 0; i<n; i++) {
		t = t + (a[i]*18000)/n;
	} return t;
}

int main(int argc, char *argv[])
{
	int a[max];
	int n;
	int chon;
	int bai;
	do {
		printf("=======Menu=====");
		printf("\n1.Bai 1");
		printf("\n2.Bai 2");
		printf("\n3.Thoat");
		printf("\nChon bai lam: ");
		scanf("%d", &chon);
		switch(chon) {
			case 1: {
				int a[max];
				int n, i, b;
				do{
					printf("\n--====Menu bai 1=====--");
					printf("\n1.Nhap so ngay lam");
					printf("\n2.Nhap so gio lam");
					printf("\n3.In ra so gio lam");
					printf("\n4.Thong bao so tien");
					printf("\n5.Thoat");
					printf("\nChon cong viec: ");
					scanf("%d", &bai);
					switch(bai) {
						case 1: {
							nhapNgayLam(a,n);
						}break;
						case 2: {
							nhapGioLam(a,n);
						}break;
						case 3: {
							outputArr(a,n);
						}break;
						case 4: {
							printf("\nTrung binh moi ngay lam them: %d VND", soTienTrungBinhNgay(a,n));
							printf("\nTong so tien: %d VND", tongSoTien(a,n));
						}break;
					}
				} while(bai < 5);
			}break;
			
			case 2: {
				int a[max];
				int n, i, b;
				do{
					printf("--====Menu bai 2=====--");
					printf("\n1.");
					printf("\n2.");
					printf("\n3.");
					printf("\nChon cong viec: ");
					scanf("%d", &n);
					switch(bai){
						case 1:{
							
						}break;
						case 2:{
							
						}break;
						case 3:{
							
						}break;
					}
				}while(bai < 4);
			}break;
		}
	} while(chon<3);
	while (/* condition */)
	{
		/* code */
	}
	
	
	return 0;
}

