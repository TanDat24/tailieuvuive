#include <iostream>
#include "string.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int heSo;
    int soMu;
    Node *next = NULL;
};

typedef struct Node* node;

struct List
{
    node head,tail;
};

void init(List &l){
    l.head = l.tail =NULL;
}

node getNode(int heSo,int soMu){
    node p;
    p = new Node;
    if (p == NULL) return NULL;
    p->heSo = heSo;
    p->soMu = soMu;
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

void inSerLast (List &L,int heSo, int soMu){
    node new_ele = getNode(heSo,soMu);
    if (new_ele == NULL)
    {
        return;
    }
    addLast(L,new_ele);
}

void nhapDaThuc(List &L){
    int heSo;
    int soMu;
    printf("\nBat dau nhap da thuc (nhap he so 0 de ket thuc): \n");
    do
    {
        printf("Nhap he so: ");
        scanf("%d", &heSo);
        if (heSo == 0)
        {
            break;
        }
        printf("Nhap so mu: ");
        scanf("%d",&soMu);
        inSerLast(L,heSo,soMu);
    } while (heSo != 0);
    printf("\nDa nhap da thuc xong: \n");
}
void printList(List L){
    node p;
    p = L.head;
    printf("\n");
    while (p != NULL)
    {
        if (abs(p->heSo != 1) && abs(p->soMu != 1) && abs(p->soMu !=0)) printf("%dX^%d",p->heSo,p->soMu);
        else{
            if (abs(p->heSo == 1) && abs(p->soMu == 1)) printf("X");
            else if (abs(p->heSo) == 1) printf("X^%d",p->soMu);
            else if (abs(p->soMu) == 0) printf("%d",p->heSo);
            else printf("%dX",p->heSo);
        }        
        p = p->next;
        if (p != NULL) {
            if (p->heSo > 0) printf(" + ");
            else printf(" - ");
        }
    }
    printf("\n");
}

void xuatDanhSach(List l){
    node p;
    p = l.head;
    printf("\n");
    while (p != NULL)
    {
        printf("%dX^%d", p->heSo, p->soMu);
        p = p->next;
        if (p != NULL) {
            if (p->heSo > 0) printf(" + ");
            else printf(" - ");
        }
    }
}

void congDaThuc(List d1, List d2,List &d3){
    init(d3);
    node p = d1.head,q = d2.head;
    int suml;
    while (q!= NULL && p!=NULL)
    {
        if (p->soMu == q->soMu)
        {
            suml = p->heSo + q->heSo;
             if (suml != 0)
            {
                inSerLast(d3,suml,p->soMu);
                p = p->next;
                q = q->next;
            }
        } else {
            if (p->soMu > q->soMu)
            {
                inSerLast(d3,p->heSo,p->soMu);
                p = p->next;
            } 
            else
            {
                if (p->soMu < q->soMu)
                {
                    inSerLast(d3,q->heSo,q->soMu);
                    q = q->next;
                }
            }
        }
    }
    while (q)
    {
        inSerLast(d3,q->heSo,q->soMu);
        q = q->next;
    }
    while (p)
    {
        inSerLast(d3,p->heSo,p->soMu);
        p = p->next;
    }
}

void intSort(List &l){
    for (node p = l.head; p != l.tail; p = p->next)
    {
        for (node q = p->next; q != NULL; q = q->next)
        {
            if (p->soMu<q->soMu)
            {
                swap(p->heSo,q->heSo);
                swap(p->soMu,q->soMu);
            }
        }
    } 
}

void TruDaThuc(List d1, List d2, List &d3){
   init(d3);
    node p = d1.head,q = d2.head;
    int suml;
    while (q&&p)
    {
        if (p->soMu == q->soMu)
        {
            suml = (p->heSo) - (q->heSo);
            if (suml != 0)
            {
                inSerLast(d3,suml,p->soMu);
                p = p->next;
                q = q->next;
            }
        } else {
            if (p->soMu > q->soMu)
            {
                inSerLast(d3,p->heSo,p->soMu);
                p = p->next;
            } 
            else
            {
                if (p->soMu < q->soMu)
                {
                    inSerLast(d3,q->heSo,q->soMu);
                    q = q->next;
                }
            }
        }
    }
    while (q)
    {
        inSerLast(d3,q->heSo,q->soMu);
        q = q->next;
    }
    while (p)
    {
        inSerLast(d3,p->heSo,p->soMu);
        p = p->next;
    }
}
void TruDaThuc2(List d1, List d2, List &d3){
   init(d3);
    node p = d1.head,q = d2.head;
    int suml;
    while (q!=NULL && p!=NULL)
    {
        cout<<p->soMu<<" "<<q->soMu;
        if (p->soMu == q->soMu)
        {
            suml = (p->heSo) - (q->heSo);
            if (suml != 0)
            {
                inSerLast(d3,suml,p->soMu);
                p = p->next;
                q = q->next;
            } else {
                p = p->next;
                q = q->next;
            }
        } 
        else if (p->soMu > q->soMu)
        {
            inSerLast(d3,p->heSo,p->soMu);
            p = p->next;
        } 
        else
        {
            if (p->soMu < q->soMu)
            {
                inSerLast(d3,q->heSo,q->soMu);
                q = q->next;
            }
        }
    }
    while (q)
    {
        inSerLast(d3,q->heSo,q->soMu);
        q = q->next;
    }
    while (p)
    {
        inSerLast(d3,p->heSo,p->soMu);
        p = p->next;
    }
}
int main(){
    List d1 ,d2 ,d3;
    init(d1);
    init(d2);
    init(d3);
    nhapDaThuc(d1);
    printf("\nDanh sach d1: ");
    intSort(d1);
    printList(d1);
    nhapDaThuc(d2);
    printf("Danh sach d2: ");
    intSort(d2);
    printList(d2);

    congDaThuc(d1,d2,d3);
    printf("\nDanh sach bieu thuc da tinh tong va sap xep: ");
    intSort(d3);
    printList(d3);

    TruDaThuc2(d1,d2,d3);
    printf("\nDanh sach bieu thuc da tinh hieu va sap xep: ");
    intSort(d3);
    printList(d3);
}