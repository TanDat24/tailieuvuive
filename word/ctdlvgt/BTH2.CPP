#include <iostream>
#include "string.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int num = 0;
struct sinhVien
{
    int MSSV;
    char hoTen[50];
    char gioiTinh[5];
    char diachi[20];
    float DTB;
};

sinhVien nhapSinhVien(){
    sinhVien tmp;
    fflush(stdin);
    printf("Nhap ho va ten: ");gets(tmp.hoTen);
    printf("Nhap MSSV: ");scanf("%d",&tmp.MSSV);
    fflush(stdin);
    printf("Nhap gioi tinh: ");gets(tmp.gioiTinh);
    printf("Nhap dia chi: ");gets(tmp.diachi);
    fflush(stdin);
    printf("Nhap diem trung binh: ");scanf("%f",&tmp.DTB);
    return tmp;
}

void nhapListSinhVien(sinhVien a[], int &n){
    printf("So luong sinh vien can nhap: ");scanf("%d",&n);
    for (int i = num; i < num+n; i++)
    {   
        printf("Nhap sinh vien thu: %d\n",i+1);
        a[i] = nhapSinhVien();
    }
    num+=n;
}

void inSinhVien(sinhVien a[]){
    for (int i = 0; i < num; i++)
    {
        printf("Sinh vien thu: %d\n",i+1);
        printf("%s\t%20d\t%5s\t%5s\t%5f\n",a[i].hoTen,a[i].MSSV,a[i].gioiTinh,a[i].diachi,a[i].DTB); 
    }
}

bool PrintInformationByCode(sinhVien a[], int n, int maso){
    for (int i = 0; i < n; i++)
    {
        if(a[i].MSSV == maso){
            printf("Tim duoc sinh vien thu: %d\n",i+1);
            printf("%s\t%20d\t%5s\t%5s\t%5f\n",a[i].hoTen,a[i].MSSV,a[i].gioiTinh,a[i].diachi,a[i].DTB); 
            return true;
        }
    }
    return false;
}

void sortListSVByDTB(sinhVien a[], int n){
    for (int i = n-1; i > 0; i--){
        for (int j = 0; j < i; j++){
            if(a[j].DTB>a[j+1].DTB){
                sinhVien tmp = a[j];
                a[j]=a[j+1];
                a[j+1] = tmp;
            }
        }
    }
}

void sortListSVByName(sinhVien a[], int n){
    for (int i = n-1; i > 0; i--){
        for (int j = 0; j < i; j++){
            if(strcmp(a[j].hoTen,a[j+1].hoTen)>0){
                sinhVien tmp = a[j];
                a[j]=a[j+1];
                a[j+1] = tmp;
            }
        }
    }
}
void SVWithTheHighestDTB(sinhVien a[], int n){
    sortListSVByDTB(a,n);
    sinhVien tmp = a[n-1];

    printf("Sinh vien co diem cao nhat la: \n");
    printf("%s\t%20d\t%5s\t%5s\t%5f\n",tmp.hoTen,tmp.MSSV,tmp.gioiTinh,tmp.diachi,tmp.DTB); 
}

void writeFile(const char path[], sinhVien a[], int n){
	FILE *f = fopen(path,"wb");
	for (int i=0; i<n; i++){
		fwrite(&a[i], sizeof(a[i]), 1, f);
	}
	fclose(f);
}

void readFile(const char path[], sinhVien a[], int n){
	FILE *f = fopen(path,"rb");
	for (int i=0; i<n; i++){
		fread(&a[i], sizeof(a[i]), 1, f);
		printf("%s\t%20d\t%5s\t%5s\t%5f\n",a[i].hoTen,a[i].MSSV,a[i].gioiTinh,a[i].diachi,a[i].DTB); 
	}
	fclose(f);
}

bool updateSV(sinhVien a[], int n, int maso){
    for (int i = 0; i < n; i++)
    {
        if(a[i].MSSV == maso){
            printf("Nhap thong tin moi cua sinh vien: \n");
            fflush(stdin);
            printf("Nhap ho va ten: ");gets(a[i].hoTen);
            printf("Nhap MSSV: ");scanf("%d",&a[i].MSSV);
            fflush(stdin);
            printf("Nhap gioi tinh: ");gets(a[i].gioiTinh);
            printf("Nhap dia chi: ");gets(a[i].diachi);
            fflush(stdin);
            printf("Nhap diem trung binh: ");scanf("%f",&a[i].DTB);
            return true;
        }
    }
    return false;
}

void bubble_sort(sinhVien a[], int n)
{
    for(int i = n-1; i>0; i--){
        for(int j = 0; j<i;j++){
            if(a[j].MSSV > a[j+1].MSSV){
                sinhVien tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }
}

int BinSearch(sinhVien a[], int n, int ms) {
    bubble_sort(a,n);
    int l = 0, r = n - 1;
    while (l <= r) {
        int mid =(r + l)/2;
        if (a[mid].MSSV == ms) {
            return mid;
        } else if (a[mid].MSSV < ms) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return -1;
}

void Deleted(sinhVien a[],int &n, int ms){
    int pos = BinSearch(a,n,ms);
    if(pos != -1){
       for (int i = pos; i < n-1; i++)
       {
        a[i]=a[i+1];
       }
       n--;
    printf("Xoa thanh cong\n");
    } else {
        printf("Khong tim thay!\n");
    }
}

int main(int argc, char const *argv[])
{
    sinhVien listSV[256];
    int n = 0;
    int k;
    do {
        printf("\n===----menu----===\n");
        printf("1.Nhap sinh vien\n");
        printf("2.In sinh vien\n");
        printf("3.Xuat thong tin sinh vien co ma so x\n");
        printf("4.Sap xep tang theo DTB\n");
        printf("5.Sap xep tang theo ho va ten\n");
        printf("6.Ghi danh sach vao file\n");
        printf("7.Doc danh sach sinh vien tu file\n");
        printf("8.Sua thong tin sinh vien\n");
        printf("9.Xoa sinh vien\n");
        printf("10.Sinh vien co DTB cao nhat\n");
        printf("11.Thoat\n");
        
        printf("Nhap so can thuc hien: ");
        scanf("%d",&k);
        system("cls");
        switch (k)
        {
        case 1:{
                nhapListSinhVien(listSV,n);
            break;}
        case 2:{
                inSinhVien(listSV);
            break;}
        case 3:{
                int maso;
                    printf("Nhap ma so cua sinh vien can tim: ");
                    scanf("%d",&maso);
                    bool c = PrintInformationByCode(listSV,n,maso);
                    if (c == true)
                    {
                        printf("Tim thanh cong!");
                    } else {
                        printf("Khong tim thay sinh viet co ma so: %d", maso);
                    }
                    
            break;}
        case 4:{
                sortListSVByDTB(listSV,n);
                printf("Sap xep diem thanh cong!");
            break;}
        case 5:{
                sortListSVByName(listSV,n);
                printf("Sap xep ho va ten thanh cong!");
            break;}
        case 6:{
                writeFile("D:\\word\\ctdlvgt\\OUTPUT.txt",listSV,n); break;
            break;}
        case 7:{
                readFile("D:\\word\\ctdlvgt\\OUTPUT.txt",listSV,n);
            break;}
        case 8:{
                int m;
                printf("Nhap ma so sinh vien can thay doi: ");
                scanf("%d",&m);
                bool k = updateSV(listSV,n,m);
                if (k == true)
                {
                    printf("update thanh cong!");
                } else {
                    printf("Khong tim thay sinh vien co ma so: %d", m);
                }
            break;}
        case 9:{
                int ms;
                printf("Nhap ma so sinh vien can xoa: ");
                scanf("%d",&ms);
                Deleted(listSV,num,ms);
            break;}
        case 10:{
                SVWithTheHighestDTB(listSV,n);
            break;}
        case 11:{
            break;}
        }
    }while (k != 11);
    return 0;
}
