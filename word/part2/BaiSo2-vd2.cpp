#include <bits/stdc++.h>
using namespace std;
#define ll long long

 void input(long Q[], int &n){
	srand(time(NULL));
	for (int i=0; i<n; i++) Q[i] = rand();
 }

  void output(long Q[], int n){
	for (int i=0; i<n; i++) cout<<Q[i]<<" ";
		cout<<endl;
  }

   long sum_rec(long Q[], int n){
		if (n==0) return 0;
		return Q[n-1]+sum_rec(Q, n-1);
	}

	int max_rec(long Q[], int n){
		if (n==1) return Q[0];
		return (Q[n-1]>max_rec(Q, n-1)?Q[n-1]:max_rec(Q, n-1));
	}

	int min_rec(long Q[], int n){
		if (n==1) return Q[0];
		return (Q[n-1]<min_rec(Q, n-1)?Q[n-1]:min_rec(Q, n-1));
	}

	long sum(long Q[], int n){
		ll s=0;
		for (ll i=0; i<n; i++) s+=Q[i];
	return s;
	}

int n;
long a[99999999];
int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
		cout<<"Nhap so phan tu:"<<endl;
		do{
			cin>>n;
			if (n<0) cout<<"Nhap khongg hop le"<<endl;
		}while(n<0);

		input(a, n);
		input(a, n);
		cout<<"Danh sach phan tu trong mang: "<<endl;
		output(a,n);
		cout<<"Tong "<<n<<" phan tu mang:"<<endl;
		cout<<sum_rec(a, n)<<endl;
		cout<<"So lon nhat mang: "<<endl;
		cout<<max_rec(a, n)<<endl;
		cout<<"So be nhat mang: "<<endl;
		cout<<min_rec(a, n)<<endl;
		cout<<"Tong "<<n<<" phan tu mang (duyet tuan tu):"<<endl;
		cout<<sum(a, n)<<endl;

return 0;

}

