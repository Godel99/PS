#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
	ll n, k; cin >> n >> k; ll sq = sqrt(k); ll ans = 0;
	for(ll i = 1; i <= min(k/sq, n); i++) ans += k%i;
	for(ll i = 1; i < sq; i++){
		ll l = k/(i+1)+1, r = min(k/i, n);
		if(l > r) continue;
		ans += k*(r-l+1)-(l+r)*(r-l+1)*i/2;
	}
	ans += k*max(0LL, n-k);
	cout << ans;
}