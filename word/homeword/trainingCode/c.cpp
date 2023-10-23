#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define db double
#define maxl 10000

int a; 
int CT[10];
int n =4;
int GTTN[10]; int kq;
int Max1,Max2;
int Max1moi = 0, Max2moi = 0;
int A[5],B[5];

void taoQuanThe(int n){
    for (int i = 0; i < n; i++)
    {
        printf("Nhap ca the thu %d: ",i+1);
        scanf("%d",&CT[i]);
    }   
}

void giaTriThichNghi(int n){
    int gttn;
    for (int i = 0; i < n; i++)
    {
        gttn = (1000 - (CT[i]*CT[i]-64));
        GTTN[i]=gttn;
    }
}
int kiemTra(int n){
    for (int i = 0; i < n; i++)
    {
        if(GTTN[i] ==1000) return CT[i];
    }
    return 0;
}

void timCaTheLai(){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(GTTN[i]<GTTN[j]){
                int a = GTTN[j];
                GTTN[i]=GTTN[j];
                GTTN[j]=a;
            }
        }
        
    }
    Max1=sqrt(1064-GTTN[0]);
    Max2=sqrt(1064-GTTN[1]);
}

void laiCaThe(){
    for (int i = 0; i < 5; i++)
    {
        A[i]=0;
        B[i]=0;
    }
    while (Max1 != 0)
    {
        for (int j = 0; j < 5; j++)
        {
            A[j]=Max1%2;
            Max1=Max1/2;
        }
        
    }
    while (Max2 != 0)
    {
        for (int k = 0; k < 5; k++)
        {
            B[k]=Max2%2;
            Max2=Max2/2;
        }
        
    }
    for (int l = 4; l >1; l--)
    {
        int b = A[l];
        A[l]=B[l];
        B[l]=b;
    }
    for (int m = 4; m >=0; m--)
    {
        Max1moi=Max1moi+A[m]*pow(2,m);
        Max2moi=Max2moi+B[m]*pow(2,m);
    }  
}

void taoQuanTheMoi(){
    CT[0]=Max1;
    CT[1]=Max2;
    CT[2]=Max1moi;
    CT[4]=Max2moi;
}

int main() {
    //freopen("INPUT.txt", "r", stdin);
    //freopen("OUTPUT.txt","w", stdout);
    printf("Giai phuong trinh X*X=64,bang thua toan di truyen\n");
    printf("Tao quan the co 4 ca the\n");
    taoQuanThe(n);
    giaTriThichNghi(n);
    kq=kiemTra(n);
    while (kq ==0)
    {
        timCaTheLai();
        laiCaThe();
        taoQuanTheMoi();
        giaTriThichNghi(n);
        kq=kiemTra(n);
    }
    printf("Kq phuong trinh la: %d",kq);
}
