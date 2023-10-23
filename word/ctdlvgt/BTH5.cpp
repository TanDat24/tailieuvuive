#include <iostream>
#include "string.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <bits/stdc++.h>

using namespace std;

struct QLTV
{
    char tenSach[255];
    char tacGia[5][255];
    char nhaXuatBan[255];
    int namXuatBan;
    int sltg;
};

struct Node
{
    QLTV data;
    Node *next = NULL;
};

typedef struct Node* node;

struct List
{
    node head,tail;
};

void init(List &l){
    l.head = l.tail = NULL;
}

node getNode(QLTV x){
    node p;
    p = new Node;
    if (p == NULL)
        return NULL;
    p->data = x;
    p->next = NULL;
    return p;
}

void addLast(List &l1, node new_ele){
    if (l1.head == NULL)
    {
        l1.head = l1.tail = new_ele;
    } else {
        l1.tail->next = new_ele;
        l1.tail = new_ele;
    }
}


void inserLast(List &l, QLTV x){
    node new_ele = getNode(x);
    if (new_ele == NULL)
    {
        return;
    }
    addLast(l,new_ele);
}
int menu(){
    int n;
    printf("\n1.Them sach");
    printf("\n2.Xuat danh sach sach");
    printf("\n3.Tim so luong sach cua mot tac gia nao do");
    printf("\n4.Tim nha xuat ban nao da phat hanh nhung quyen sach trong nam nao do");
    printf("\n5.Xoa tat ca sach cua 1 tac gia nao do");
    printf("\n6.Thong ke sach cua tac gia");
    printf("\n7.Doc du lieu tu file");
    printf("\n8.Thoat");
    printf("\nNhap so muon thuc hien: ");
    scanf("%d",&n);
    system("cls");
    return n;
}
void themSach(QLTV &x){
    printf("Nhap ten sach: ");
    fflush(stdin);
    gets(x.tenSach);
    printf("Nhap so luong tac gia cua 1 quyen sach: ");
    scanf("%d",&x.sltg);
    cin.ignore();
    for (int i = 0; i < x.sltg; i++)
    {
        printf("Nhap ten tac gia %d: ", i + 1);
        fflush(stdin);
        gets(x.tacGia[i]);
    }
    printf("Nhap nha xuat ban: ");
    fflush(stdin);
    gets(x.nhaXuatBan);
    printf("Nhap nam xuat ban: ");
    fflush(stdin);
    scanf("%d",&x.namXuatBan);
    cin.ignore();
}
void nhapDSSach(List &l){
    QLTV x;
    int n;
    printf("Nhap so luong sach muon them: ");
    scanf("%d",&n);
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        printf("\nNhap thong tin quyen sach: %d\n",i+1);
        themSach(x);
        inserLast(l,x);
    }
    printf("Nhap thanh cong!\n");
}

void xuatDSSach(List l)
{
    node p = l.head;
    printf("\n%-20s %-35s %-20s %15s", "Ten sach", "Ten tac gia", "Nha xuat ban", "Nam xuat ban");
    while (p != NULL)
    {
        printf("\n%-20s", p->data.tenSach);
        for (int i = 0; i < p->data.sltg; i++) 
        {
            if (p->data.tacGia[i][0] == '\0') 
                break;

            printf("%-5s", p->data.tacGia[i]);
        }
        printf("%20s %15d", p->data.nhaXuatBan, p->data.namXuatBan);
        p = p->next;
    }
}

void timSLtacGia(List l){
    char tentacGia[255];
    int count = 0;
    node p = l.head;
    printf("Nhap ten tac gia can tim: ");
    fflush(stdin);
    gets(tentacGia);
    while (p != NULL)
    {
        for (int i = 0; i < p->data.sltg; i++)
        {
            if (strcmp(p->data.tacGia[i],tentacGia)==0)
            {
                count++;
            }
        }
        p = p->next;
    }
    printf("So luong sach cua tac gia %s: %d\n", tentacGia, count);
}

void timSachTheoNam(List l){
    node p = l.head;
    bool found = false;
    int yyyy;
    char NXB[255];
    printf("Nhap nam va nha xuat ban can tim: ");
    scanf("%d",&yyyy);
    fflush(stdin);
    gets(NXB);

    printf("\nCac quyen sach phat hanh trong nam %d va boi nha xuat ban %s la:\n", yyyy, NXB);

    while (p != NULL)
    {
        if ((yyyy == p->data.namXuatBan) && (strcmp(p->data.nhaXuatBan,NXB)==0))
        {
            printf("\nTen sach: %s", p->data.tenSach);
            found = true;
        }
        p = p->next;
    }
    if (!found)
    {
        printf("Khong co quyen sach nao phat hanh trong nam %d va boi nha xuat ban %s.\n", yyyy, NXB);
    }
}

void xoaSach(List &l)
{
    node p = l.head;
    node q = NULL;
    char a[225];
    int found = 0; 
    printf("\nNhap ten tac gia can xoa: ");
    fflush(stdin);
    gets(a);

    while (p != NULL)
    {
        for (int i = 0; i < p->data.sltg; i++) {
            if (strcmp(a, p->data.tacGia[i]) == 0) {
                found = 1;
                break;
            }
        }

        if (found) {
            if (q != NULL) {
                if (p != NULL) {
                    if (p == l.head) {
                        l.head = p->next;
                    }
                    if (p == l.tail) {
                        l.tail = q;
                    }
                    q->next = p->next;
                    node toDelete = p;
                    p = p->next;
                    delete toDelete;
                } else {
                    q->next = p->next;
                    node toDelete = p;
                    p = p->next;
                    delete toDelete;
                }
            } else {
                if (p == l.head) {
                    l.head = p->next;
                }
                if (p == l.tail) {
                    l.tail = q;
                }
                node toDelete = p;
                p = p->next;
                delete toDelete;
            }
        } else {
            q = p;
            p = p->next;
        }
    }

    if (found) {
        printf("\nXoa thanh cong!\n");
    } else {
        printf("\nKhong co tac gia can xoa.\n");
    }
}

void xoaSach1(List l){
    node p = l.head;
    node prev = NULL;
    char tenTacGia[255];
    printf("Nhap ten tac gia can xoa: ");
    fflush(stdin);
    gets(tenTacGia);
    while (p != NULL)
    {
        bool ck = false;
        for (int i = 0; i < p->data.sltg; i++)
        {
            if (strcmp(p->data.tacGia[i],tenTacGia)==0)
            {
                ck =true;
                break;
            }
        }
    }
}

int main(){
    List l;
    init(l);
    while (1)
    {
        int k = menu();
        fflush(stdin);
        switch (k)
        {
        case 1:{
            nhapDSSach(l);
        }break;
        case 2:{
            xuatDSSach(l);
        }break;
        case 3:{
            timSLtacGia(l);
        }break;
        case 4:{
            timSachTheoNam(l);
        }break;
        case 5:{
            xoaSach(l);
        }break;
        case 6:{

        }break;
        case 7:{

        }break;
        case 8:{
            return 0;
            break;
        }
        }
    }
}