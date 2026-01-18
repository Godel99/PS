#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll ans;

ll josephus(ll n, ll k){
	if(n < k) return ans;
    ll l = josephus(n-n/k, k) - n%k;
    if(l < 0) return l+n;
    return l+l/(k-1);
}

int main(){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
    ll n, k; cin >> n >> k;
	for(int i = 1; i < k; i++) ans = (ans+k)%i;
    if(k == 1) cout << n; else cout << josephus(n, k)+1;
	return 0;
}