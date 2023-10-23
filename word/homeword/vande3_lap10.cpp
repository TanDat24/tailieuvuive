#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define max 100
void inputArr(int a[max], int &n) {
	printf("\nNhap so luong mang: ");
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		printf("\na[%d] = ", i+1);
		scanf("%d", &a[i]);
	} 
}

void outputArr(int a[max], int &n) {
	for(int i = 0; i<n; i++) {
		printf("%d ",a[i]);
	}
}

void appEnd(int a[max], int &n, int x) {
	printf("\nNhap phan tu can chen x: ");
	scanf("%d", &x);
	a[n] = x;
	n++;
}

void inSert(int a[max], int &n, int k, int x) {
	for(int i = n; i>k;i--) {
		a[i] = a[i - 1];
		a[k] = x;
		n++;
	}
}

/*void ramdomArr(int a[max], int &n) {
	srand(time(NULL));
	printf("\nNhap so luong phan tu trog mang: ");
	scanf("%d", &n);
	for(int i = 0; i <= n; i++) {
		a[i] = rand();
		printf("%d ", 1+rand()%101);
	}
}*/

int maxx(int a[max], int n) {
	int maxxx = a[0];
	for(int i = 0; i<n; i++) {
		if(maxxx < a[i])
			maxxx = a[i];
	} return maxxx;
}
int min(int a[max], int n) {
	int minn = a[0];
	for(int i = 0; i<n; i++) {
		if(minn > a[i])
			minn = a[i];
	} return minn;
}

int searchArr(int a[max], int n,int x){
	for(int i = 0; i<n; i++) {
		if(a[i] == x)
		return i;
	return -1;
	}
}

void deleteArr(int a[max], int &n, int k, int x) {
	for(int i = k;i<n; i++) {
		a[i] = a[i+1];
	}
		n--;
}

void sortArr(int a[max], int n) {
	int b, j;
	for(int i = 0; i<n-1; i++)
		for(j = i+1; j<n; j++)
			if(a[i] > a[j]) {
				b = a[i];
				a[i] = a[j];
				a[j] = b;
			}
}



int main(int argc, char *argv[])
{
	int chon;
	int a[max];
	int n, x, i, k;
	do {
		printf("\nMenu");
		printf("\n1.Tao mang");
		printf("\n2.In mang");
		printf("\n3.In ra so lon nhat va so nho nhat trong mang");
		printf("\n4.Tim x");
		printf("\n5.Them phan tu vao cuoi mang");
		printf("\n6.Them phan tu vao vi tri bat ki trong mang");
		printf("\n8.Xoa mang");
		printf("\n9.Sap xep mang");
		printf("\n10.thoat");
		printf("\nChon cong viec: ");
		scanf("%d", &chon);
		switch(chon){
			case 1:{
				inputArr(a,n);
			}break;
			case 2:{
				outputArr(a,n);
			}break;
			case 3:{
				printf("\nMax = %d", maxx(a,n));
				printf("\nMin = %d", min(a,n));
			}break;
			case 4:{
					int x;
					printf("\nNhap x can tim: ");
					scanf("%d", &x);
					int kt = searchArr(a,n,x);
					if(kt == -1)
					printf("\nKhong tim thay!!!");
				else
					printf("\n%d o vi tri so %d",x, kt + 1);
			}break;
			case 5:{
					appEnd(a,n,x);
			}break;
			case 6:{
					printf("\nNhap phan tu can chen: ");
					scanf("%d", &x);
					printf("\nNhap vi tri can chen: ");
					scanf("%d", &k);
					inSert(a,n,k,x);
			}break;
			
			case 8:{
					printf("\nNhap vi tri can xoa: ");
					scanf("%d", &k);
					deleteArr(a,n,k,x);
			}break;
			case 9:{
					sortArr(a,n);
			}break;
	}
}while(chon<11);
	return 0;
}
