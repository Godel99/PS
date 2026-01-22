#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll a[5000001];

int main(){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
    int n, k; cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);
    cout << a[k-1];
	return 0;
}