#include <iostream>
#include "string.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node
{
    int data;
    Node *next = NULL;
};

typedef struct Node* node;

struct List {
    node first,last;
};
void Init(List &l){
    l.first = l.last = NULL;
}

node getNode(int x){
    node p;
    p = new Node;
    if (p == NULL)
    {
        return NULL;
    }
    p->data = x;
    p->next = NULL;
    return p;
}
void addFirst(List &l,node new_node){
    if (l.first == NULL)
    {
        l.first = new_node;
        l.last = l.first;
    } else {
        new_node->next = l.first;
        l.first = new_node;
    }
}

void insertFirst(List &l, int x){
    node new_node = getNode(x);
    if (new_node == NULL)
    {
        return;
    }
    addFirst(l,new_node);
}

void createListFirst(List &l){
    int x;
    do
    {
        printf("\nBat dau nhap danh sach cac so nguyen, nhap -1 de ket thuc: \n");
        scanf("%d",&x);
        if (x == -1)
        {
            break;
        }
        insertFirst(l,x);
    } while (x != -1);
    printf("\nDa nhap du lieu xong: \n");
}

void printList(List l){
    node p;
    p = l.first;
    while (p!=NULL)
    {
        printf("%d ",p->data);
        p = p->next;
    }   
}

void Separating_List(List &L, List &L1, List &L2){
    printf("Nhap so can cat ra: ");       
    int x;
    scanf("%d",&x);
    node tmp = L.first;
    while (tmp != NULL)
    {
        if (tmp->data<=x)
        {
            insertFirst(L1,tmp->data);
            //printf("%d ",tmp->data);
        } else {
            insertFirst(L2,tmp->data);
        }
        tmp = tmp->next;
    }
    printList(L1);
    printf("\n");
    printList(L2);
}

int main(){
    List l;
    List l1;
    l1.first = NULL;
    List l2;
    l2.first = NULL;
    Init(l);
    createListFirst(l);
    printList(l);
    Separating_List(l,l1,l2);
}