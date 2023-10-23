#include<bits/stdc++.h>
using namespace std;
#define maxl 100000
int prime[100001];

using namespace std;

int a[10000], b[10000];

int Max(int a[], int n) {
    int max = a[0];
    for (int i = 0; i < n; i++) {
        if (a[i] > max) max = a[i];
    }
    return max;
}

int sumGift(int a[], int n, int first) {
    int count = 1, sum = 0, temp;
    for (int i = first; i < n; i++) {
        if (count %2 != 0) {
            temp = a[i];
            sum += a[i];
            count++;
        } else {
            if (a[i] == temp) {
                sum += a[i];
                count++;
            }
        }
    }
    return sum;
}

int chooseGift(int a[], int n) {
    for (int i = 0; i < n; i++) {
        b[i] = sumGift(a, n, i);
    }
    return Max(b,n);
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << chooseGift(a, n);
    return 0;
}

