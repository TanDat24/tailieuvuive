#include <stdio.h>
#include <math.h>
#include <time.h>
#include<vector>
#define max 10000
// lãi kép
float x;
float lai_kep(float y, int n){
	if (n == 0)
		return y;
	return lai_kep(y+y*(x/100.0), n - 1);
}

//Nhap
void inputArr(int Q[], int &n) {
	srand(time(NULL));
	printf("Nhap so phan tu mang: "); scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			Q[i] = 1 + rand();
		}
}
//in 
void outputArr(int Q[], int n)  {
	printf("\nmang co cac gia tri la: ");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", Q[i]);
	}
}

//tính tổng
long sum_rec(int Q[], int n) {
	if (n == 0)
		return 0;
	return sum_rec(Q,n - 1) + Q[n - 1];
}
//tìm số lớn nhất trong mảng
int max_rec(int Q[], int n) {
	if (n == 1)
	 return Q[0];
	return max_rec(Q,n-1)<Q[n - 1]?Q[n - 1]:max_rec(Q,n - 1);
}
// tìm phần tử nhỏn nhất trong mang
int min_rec(int Q[], int n) {
	if (n == 1)
	 return Q[0];
	return min_rec(Q,n-1)<Q[n - 1]?min_rec(Q,n - 1):Q[n - 1];
}
//Tổng các phần tử theo cách tuần từ
long sum(int Q[], int n) {
	int tong = 0;
	for (int i = 0; i < n; i++) {
		tong += Q[i];
	}
	return tong;
}
//bản báo cáo
//vector stack queue deque set map pair 
void setTimeArr(int Q[], int n) {

}

int main(int argc, char *argv[])
{
	int chon;
	do {
		printf("\nMenu");
		printf("\n1.Bai thuc hanh so 2");
		printf("\n2.Thoat");
		printf("\nChon bai lam: ");
		scanf("%d", &chon);
		switch(chon){
			case 1: {
				int chon1;
				do
				{
					printf("\nMenu");
					printf("\n1.Tinh lai kep");
					printf("\n2.De quy tren mang");
					printf("\n3.Thoat");
					printf("\nChon bai lam: ");
					scanf("%d", &chon1);
					switch (chon1)
					{
					case 1:{
						float y;
						printf("\nnhap so tien gui: ");scanf("%f", &y);
						do
						{
							if (y<0)
							{
								printf("\nnhap sai!! nhap lai(tien>0): ");scanf("%f", &y);
							}
							
						} while (y<0);
						int n;
						printf("\nnhap so nam gui: ");scanf("%d", &n);
						do
						{
							if (n<0)
							{
								printf("\nnhap sai!! nhap lai(nam>0): ");scanf("%d", &n);
							}
							
						} while (n<0);

						printf("\nnhap so tien lai: ");scanf("%f", &x);
						do
						{
							if (x<0)
							{
								printf("\nnhap sai!! nhap lai(lai>0): ");scanf("%f", &x);
							}
							
						} while (x<0);

						printf("\nSo tien gui trong %d nam voi so lai %.2f la: %.2f", n, x, lai_kep(y,n));
					}
					break;
					case 2:{
						int Q[max];
						int chon2;
						int n;
						do
						{
							printf("\nVan de 5");
							printf("\n1.Tao day phan tu mang");
							printf("\n2.Hien thi day phan tu mang");
							printf("\n3.Tinh tong phan tung trong mang");
							printf("\n4.Tim phan tu lon nhat trong mang");
							printf("\n5.Tim phan tu nho nhat trong mang");
							printf("\n6.Tinh tong theo phuong phap tuan tu");
							printf("\n7.Ban bao cao thoi gian chay");
							printf("\n8.Thoat");
							printf("\nChon cong viec: ");
							scanf("%d", &chon2);
							switch (chon2)
							{
							case 1:
								{
									inputArr(Q,n);
								}
								break;
							case 2:
								{
									outputArr(Q,n);
								}
								break;
							case 3:
								{
									printf("\nTong cac phan tu trong mang la: %d", sum_rec(Q,n));
								}
								break;
							case 4:
								{
									printf("\nSo lon nhat trong day la: %d", max_rec(Q,n));
								}
								break;
							case 5:
								{
									printf("\nSo nho nhat trong day la: %d", min_rec(Q,n));
								}
								break;
							case 6:
								{
									printf("\nTinh tong theo phuong phap tuan tu: %d", sum(Q,n));
								}
								break;
							case 7:
								{
									printf("=====================================BANG BAO CAO THOI GIAN==========================================");
									printf("\n\t\tn=10^4\t\tn=10^5\t\t10^6\t\tn=10^7\t\tn=10^9");
									printf("\nSum\t\t...(s)\t\t...(s)\t\t...(s)\t\t...(s)\t\t...(s)");
									printf("\nSum_rec\t\t...(s)\t\t...(s)\t\t...(s)\t\t...(s)\t\t...(s)");

								}
								break;
							case 8:
								{
									
								}
								break;
							}
						} while (chon2<9);
						
					}
					break;
					case 3:{}
					break;
					}
				}while (chon1<3);
			}
			break;
			case 2: {
				
			}
			break;
		}
	}while(chon<2);
	return 0;
}