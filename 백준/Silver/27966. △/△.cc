#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
	ll n; cin >> n;
	cout << (n-1)*(n-1) << '\n';
	for(int i = 2; i <= n; i++) cout << "1 " << i << '\n';
    return 0;
}