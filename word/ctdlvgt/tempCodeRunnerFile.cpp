#include <iostream>
#include <string.h>
#include <bits/stdc++.h>

using namespace std;

struct QLSV{
    char tenSV[200];
    char mssv[256];
    int namsinh;
    int slhs;
};
struct Node{
    QLSV data;
    Node* next;
};

typedef struct Node* node;

struct List{
    node head,tail;
};

void init(List &l){
    l.head=l.tail=NULL;
}

node getNode(QLSV x){
    node p;
    p = new Node;
    if (p==NULL)
    {
        return NULL;
    }
    p->data = x;
    p->next = NULL;
    return p;
}

void addFirst(List &l, node x){
    if (l.head == NULL)
    {
        l.head = x;
        l.head = l.tail;
    } else {
        x->next = l.head;
        l.head = x;
    }
}

void inserFirst(List l , QLSV x){
    node ele = getNode(x);
    if (ele == NULL)
    {
        return;
    }
    addFirst(l,ele);
}

void addLast(List &l, node x){
    if (l.head==NULL)
    {
        l.head=l.tail=x;
    } else {
        l.tail->next = x;
        l.tail =x;
    }
}
void inserLast(List l,QLSV x){
    node p = getNode(x);
    if (p == NULL)
    {
        return;
    }
    addLast(l,p);
}

int menu(){
    int n;
    printf("1.");
    printf("1.");
    printf("1.");
    printf("1.");
    scanf("%d",&n);
    system("cls");
    return n;
}
int main(){
    List l;
    init(l);
    while (1)
    {
        int k = menu();
        switch (k)
        {
        case   1:
            {return 0;}
            break;
        
        default:
            break;
        }
    }
    
}