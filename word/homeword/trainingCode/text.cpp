#include<bits/stdc++.h>
using namespace std;
#define maxl 100000
int prime[100001];

struct Node {
    int data;
    Node *next;
};
typedef struct Node* node;
//cấp phát động một node mới với dữ liệu là một số nguyên x
node makeNode(int x){
    node tmp = new Node();
    tmp->data = x;
    tmp->next = NULL;
    return tmp;
}
//kiểm tra rổng
bool empty(node a){
    return a == NULL;
}

int Size(node a){
    int cunt =0;
    while (a!=NULL)
    {
        cunt++;
        a=a->next;//gán địa chỉ tiếp theo cho node hiện tại
    }
    return cunt;
    
}
//thêm 1 phần tử vào đàu danh sách liên kết
void insersFirst(node &a, int x){
    node tmp = makeNode(x);
    if (a == NULL)
    {
        a = tmp;
    } else {
        tmp->next=a;
        a=tmp;
    }
}
//thêm 1 phần tử vào cuối danh sách
void insersLast(node &a, int x){
    node tmp = makeNode(x);
    if(a == NULL){
        a = tmp;
    } else {
      node p = a;
      while (p->next != NULL)
      {
        p = p->next;
      }
        p->next=tmp;
    }
}
//thêm 1 phần tử vào giữa
void insersMidle(node &a, int x, int pos){
    int n = Size(a);
    if (pos <= 0 || pos > n + 1)
    {
        cout<<"cc\n";
    } if(n==1) {
        insersFirst(a,x); return;
    } else if (n==pos+1)
    {
        insersLast(a,x); return;
    }
    node p = a;
    for (int i = 1; i < pos -1; i++)
    {
        p = p->next;
    }
    node tmp = makeNode(x);
    tmp->next = p->next;
    p->next = tmp;
}
//xóa phần tử đầu
void deleteFirs(node &a){
    if (a == NULL) return;
    a = a->next;
}
//xóa phần tử ở cuối
void deleteLast(node &a){
    if(a == NULL) return;
    node truoc = NULL, sau = a;
    while (sau->next != NULL)
    {
        truoc = sau;
        sau = sau->next;
    } if(truoc == NULL){
        a == NULL;
    } else {
        truoc->next == NULL;
    }
}
//xóa ở giữa
void deleteMidle(node &a, int pos){
    if (pos <= 0 || pos > Size(a)) return;
    node truoc = NULL, sau = a;
    for (int i = 1; i < pos; i++)
    {
        truoc=sau;
        sau=sau->next;
    }
    if (truoc == NULL)
    {
        a = a->next;
    } else {
         truoc->next = sau->next;
    }
}

//in 1 node
void in(node a){
    cout<<"----------------------\n";
    while (a != NULL)
    {
        cout<<a->data<<" ";
        a = a->next;
    }
    cout<<"----------------------\n";
}

int main() {
    //freopen("INPUT.txt", "r", stdin);
    //freopen("OUTPUT.txt","w", stdout);
    node head = NULL;
    while (1)
    {
        cout<<"--------------------\n";
        cout<<"1.dau\n";
        cout<<"2.cuoi\n";
        cout<<"3.giua\n";
        cout<<"4.xoa dau\n";
        cout<<"5.xoa cuoi\n";
        cout<<"6.xoa giua\n";
        cout<<"7.duyet\n";
        cout<<"--------------------\n";
        cout<<"Nhap lua chon: ";
        int lc; cin>>lc;
        if (lc == 1)
        {
            int x; cout<<"Nhap gia tri can chen x: ";cin>>x;
            insersFirst(head,x);
        } else if (lc == 2)
        {
            int x; cout<<"Nhap gia tri can chen x: ";cin>>x;
            insersLast(head,x);
        } else if (lc == 3)
        {
            int x; cout<<"Nhap gia tri can chen x: ";cin>>x;
            int pos; cout<<"Nhap vi tri can chen pos: ";cin>>pos;
            insersMidle(head,x,pos);
        } else if (lc == 4)
        {
            deleteFirs(head);
        } else if (lc == 5)
        {
            deleteLast(head);
        } else if (lc == 6)
        {
            int pos; cout<<"Nhap vi tri can xoa pos: ";cin>>pos;
            deleteMidle(head,pos);
        } else if (lc == 7)
        {
            in(head);
        } 
        
    }
    return 0;
}