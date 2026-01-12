#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
	int n; cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	int k; cin >> k;
	int maxl = a[n-1]+1;
	vector<vector<ll>> dp(k+1, vector<ll>(maxl+1, 0));
	dp[0][0] = 1;
	for(int i = 0; i < n; i++){
		for(int j = maxl; j >= 0; j--){
			if(j <= a[i]) break;
			dp[k][maxl] += dp[k-1][j];
		}
		for(int l = k-2; l >= 0; l--){
			for(int j = maxl; j >= 0; j--){
				dp[l+1][min(maxl, j+a[i])] += dp[l][j];
			}
		}
	}
	cout << dp[k][maxl];
}