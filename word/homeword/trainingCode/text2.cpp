#include<bits/stdc++.h>
using namespace std;
#define maxl 100000
int prime[100001];

struct Node{
    int data;
    Node *next;
};

typedef struct Node* node;

node makeNode(int x){
    node tmp = new Node();
    tmp->data = x;
    tmp->next = NULL;
    return tmp;
}
void in(node a){
    while (a != NULL)
    {
        cout<<a->data<<" ";
        a = a->next;
    }
}

node addElement(node &a, int x){
	node temp = makeNode(x);
	a->next = temp;
	return temp;
}

bool empty(node a){
    return a == NULL;
}

int Size(node a){
    int count = 0;
    while(a!=NULL){
        count++;
        a = a->next;
    }
    return count;
}

void insersFirs(node &a, int x){
    node tmp = makeNode(x);
    if(a == NULL){
        a = tmp;
    } else {
        tmp->next = a;
        a = tmp;
    }
}

void insersLast(node &a, int x){
    node tmp = makeNode(x);
    if(a == NULL){
        a = tmp;
    } else {
        node p = a;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = tmp;
    }
}
void insersMidle(node &a, int x, int pos ){
    node p = a;
    for(int i = 1; i<pos -1; i++){
        p = p->next;
    }
    node tmp = makeNode(x);
    tmp->data = x;
    tmp->next = p->next;
    p->next = tmp;
}

int main(){
    int n, x, pos;
    cin>>n;
    cin>>x;
    node head = makeNode(x);
    node p = head;
    for(int i = 1; i<n;i++){
        cin>>x;
        p = addElement(p,x);
    }
    cin>>pos>>x;
    if(pos == 0){
        insersFirs(head,x);
    } else if(pos == n){
        insersLast(head,x); 
    } else {
        insersMidle(head,x,pos);
    }
    in(head);
    return 0;
}