#include <iostream>
#include "string.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    float data;
    Node *next;
};

struct stackk{
    Node *top;
};

typedef struct Node* node;

void init(stackk &s){
    s.top = NULL;
}

int Empty(stackk s){
    return s.top == NULL ? 1 : 0;
}

void Push(stackk &s, float x){
    node p;
    p = new Node;
    if (p != NULL)
    {
        p->data=x;
        p->next=s.top;
        s.top=p;
    }
}

float Pop(stackk &s){
    float x;
    if(!Empty(s)){
        node p = s.top;
        s.top = p->next;
        x = p->data;
        delete(p);
    }
    return x;
}

void DocTu(char s[], char tu[], int &vt){
    for (int i = 0; i < strlen(tu); i++) tu[i] = ' ';
    int i = 0;
    while (s[vt] != ' ')
    {
        tu[i] = s[vt];
        vt++;
        i++;
    }
}

int LaToanTu(char s[]){
    char c = s[0];
    if(c == '+' || c == '-' || c == '*' || c == '/') return 1;
    return 0;
}

float TinhToan(float toanHang1, float toanHang2, char toanTu){
    float kq;
    switch (toanTu)
    {
    case '+':
        kq = toanHang1 + toanHang2;
        break;
    case '-':
        kq = toanHang1 - toanHang2;
        break;
    case '*':
        kq = toanHang1 * toanHang2;
        break;
    case '/':
        kq = toanHang1 / toanHang2;
    }
    return kq;
}

float TinhBieuThuc(stackk &s, char bieuThuc[]){
    float kq;
    char t[10];
    int i = 0;
    do
    {
        DocTu(bieuThuc,t,i);
        if (LaToanTu(t))
        {
            char toanTu = t[0];
            float toanHang1 = Pop(s);
            float toanHang2 = Pop(s);
            kq = TinhToan(toanHang2,toanHang1,toanTu);
            Push(s,kq);
        } else {
            float toanHang = atof(t);
            Push(s,toanHang);
        }
        i++;
    } while (bieuThuc[i] != '#');
    cout<<Pop(s)<<endl;
    return Pop(s);
}



int main(){
    stackk s;
    init(s);
    char bieuThuc[100] = "";

    printf("\nNhap bieu thuc dang hau to: ");
    fflush(stdin);
    gets(bieuThuc);

   float kq;
   kq = TinhBieuThuc(s,bieuThuc);
   printf("\nGia tri cua bieu thuc la: ",kq);
}