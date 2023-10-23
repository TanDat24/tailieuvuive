#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define YES cout<<"YES"<<endl;
#define NO cout<<"NO"<<endl;
#define ifor() for(int i=1; i<=n; i++)
#define jfor() for(int j=1; j<=m; j++)

float x;

float lai_kep(float y, int n){
	if (n==0) return y;
	return lai_kep(y+y*(x/100), n-1);
}

signed main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);

        float a;
		int n;

        do{
			cout<<"Nhap lai suat (%): "<<endl;
			cin>>x;
			if (x<0) cout<<"Khong hop le, moi nhap lai!"<<endl;
        }while(x<0);

		do{
			cout<<"Nhap so tien gui: "<<endl;
			cin>>a;
        	if (a<=0) cout<<"Khong hop le, moi nhap lai!"<<endl;
        }while(a<=0);

		do{
			cout<<"Nhap thoi han (nam): "<<endl;
			cin>>n;
			if (n<0) cout<<"Khong hop le, moi nhap lai!"<<endl;
        }while(n<0);

        cout<<"So tien sau "<<n<<" nam tiet kiem: "<<endl;
        cout<<lai_kep(a, n);

return 0;
}



