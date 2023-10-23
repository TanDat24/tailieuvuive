#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define db double
#define maxx 100

struct student{
    string ten, ma;
    int tk,gk,ck,th;
    db dtb;
};

db tinhDiem(student t){
    db dtb;
    dtb = ((((2*t.tk) + (3*t.gk) + (5*t.ck))/10.0)*2 + t.th)/3.0;
    return dtb;
}

void nhap( student &sv){
    fflush(stdin);
    cout<<"Nhap ten sinh vien: ";getline(cin, sv.ten);
    cout<<"Nhap ma sinh vien: ";getline(cin, sv.ma);
    fflush(stdin);
    cout<<"Nhap diem thuong ky: ";cin>>sv.tk;
    cout<<"Nhap diem giua ky: ";cin>>sv.gk;
    cout<<"Nhap diem cuoi ky: ";cin>>sv.ck;
    cout<<"Nhap diem thuc hanh: ";cin>>sv.th;
    sv.dtb=tinhDiem(sv);
}

void in(student st[], int n){
    for (int i = 0; i < n; i++)
    {
        //cout<<"+-----------------------+-----------------------+-----------------------+---------------+---------------+-----------------------+------------------+"<<endl;
        cout<<"| "<<st[i].ten<<"\t\t\t"<<st[i].ma<<"\t\t\t"<<st[i].tk<<"\t\t\t"<<st[i].gk<<"\t\t"<<st[i].ck<<"\t\t"<<st[i].th<<"\t\t\t"<<st[i].dtb<<"    |"<<endl;
        cout<<"+-----------------------+-----------------------+-----------------------+---------------+---------------+-----------------------+------------------+"<<endl;
    }
}

void timKiem(student tk[], int n){
    string s;
    fflush(stdin);
    getline(cin, s);
    cout<<"+-----------------------+-----------------------+-----------------------+---------------+---------------+-----------------------+------------------+"<<endl;
    cout<<"|"<<"ho ten"<<"\t\t\t|  "<<"ma sinh vien"<<"\t\t|  "<<"Diem thuong ky"<<"\t|  "<<"Diem giua ky"<<"\t|  "<<"Diem cuoi ky"<<"\t|  "<<"Diem thuc hanh"<<"\t|  "<<"Diem trung binh"<<" |"<<endl;
    cout<<"+-----------------------+-----------------------+-----------------------+---------------+---------------+-----------------------+------------------+"<<endl;
    for (int i = 0; i < n; i++)
    {
        if (tk[i].ma == s)
        {
            //cout<<"+-----------------------+-----------------------+-----------------------+---------------+---------------+-----------------------+------------------+"<<endl;
            cout<<"| "<<tk[i].ten<<"\t\t\t"<<tk[i].ma<<"\t\t\t"<<tk[i].tk<<"\t\t\t"<<tk[i].gk<<"\t\t"<<tk[i].ck<<"\t\t"<<tk[i].th<<"\t\t\t"<<tk[i].dtb<<"    |"<<endl;
            cout<<"+-----------------------+-----------------------+-----------------------+---------------+---------------+-----------------------+------------------+"<<endl;
            return;
        }
        
    }
    cout<<"Khong tim thay!!"<<endl;
    return;
}



void sx(student sx[], int n){
    student tmp[n];
    for(int i=0;i<n;i++) tmp[i]=sx[i];
    for(int i=n-1;i>0;i++){
        for(int j=0;j<i;j++){
            if((tmp[j].dtb)>(tmp[i].dtb)){
                student c=tmp[i];
                tmp[i]=tmp[j];
                tmp[j]=c;
            }
        }
    }
    in(tmp,n);
}

int main() {
    //freopen("INPUT.txt", "r", stdin);
    //freopen("OUTPUT.txt","w", stdout);
    int chon;
    int l=0;
    student sd[9999];
    do
    {
        cout<<"+-----+---------------------------------------------------+"<<endl;
        cout<<"|-----+----[                 MENU              ]----+-----|"<<endl;
        cout<<"|-----+---------------------------------------------------|"<<endl;
        cout<<"|-----+---->      1. Nhap sinh vien            <----------|"<<endl;
        cout<<"|-----+---->      2. In danh sach sinh vien    <----------|"<<endl;
        cout<<"|-----+---->      3. Tim kiem sinh vien        <----------|"<<endl;
        cout<<"|-----+---->      4. Sap xep                   <----------|"<<endl;
        cout<<"+-----+---------------------------------------------------+"<<endl;
        cout<<"Chon cong viec: ";cin>>chon;
        switch (chon)
        {
        case 1:{
 //           student sd[x];
            int x;
            cout<<"Nhap so luong sinh vien: ";
            cin>>x;
            for (int i = l; i < l+x; i++)
            {
                cout<<"Nhap thong tin sinh vien thu "<<i+1<<": "<<endl;
                nhap(sd[i]);
            }
            l+=x;
            system("cls");
             break;
        }
        case 2:{
            system("cls");
 //           student sd[x];
            cout<<"-----------------------------------------------===BANG DIEM SINH VIEN===-----------------------------------------------------------------"<<endl;
            cout<<"+-----------------------+-----------------------+-----------------------+---------------+---------------+-----------------------+------------------+"<<endl;
            cout<<"|"<<"ho ten"<<"\t\t\t|  "<<"ma sinh vien"<<"\t\t|  "<<"Diem thuong ky"<<"\t|  "<<"Diem giua ky"<<"\t|  "<<"Diem cuoi ky"<<"\t|  "<<"Diem thuc hanh"<<"\t|  "<<"Diem trung binh"<<" |"<<endl;
            cout<<"+-----------------------+-----------------------+-----------------------+---------------+---------------+-----------------------+------------------+"<<endl;
            in(sd,l);
            break;
        }
        case 3:{
            timKiem(sd,l);
        break;
        }
        case 4:{
            cout<<"+-----------------------+-----------------------+-----------------------+---------------+---------------+-----------------------+------------------+"<<endl;
            cout<<"|"<<"ho ten"<<"\t\t\t|  "<<"ma sinh vien"<<"\t\t|  "<<"Diem thuong ky"<<"\t|  "<<"Diem giua ky"<<"\t|  "<<"Diem cuoi ky"<<"\t|  "<<"Diem thuc hanh"<<"\t|  "<<"Diem trung binh"<<" |"<<endl;
            cout<<"+-----------------------+-----------------------+-----------------------+---------------+---------------+-----------------------+------------------+"<<endl;
            sx(sd, l);
        break;
        }
         case 5:{

        break;
        }
        }
    } while (chon<6);
    
}
