#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int a[1010];

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int n, ms; cin >> n;
    double s = ms = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        s += a[i];
        if(ms < a[i]) ms = a[i];
    }
    cout << (s/ms*100)/n;
    return 0;
}