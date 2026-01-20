#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
	ll n, k; cin >> n >> k; ll sq = sqrt(k); ll ans = 0;
	for(ll i = 1; i <= min(k/sq, n); i++) ans += k%i;
	for(ll i = 1; i < sq; i++){
		ll l = min(k/i, n), r = k/(i+1)+1;
		if(l < r) continue;
		ans += k*(l-r+1)-(l+r)*(l-r+1)*i/2;
	}
	ans += k*max(0LL, n-k);
	cout << ans;
}