#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int a[50];
ll dp[11][501010];

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
	int n; cin >> n;
	dp[0][0] = 1;
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a, a+n);
	int k; cin >> k;
	for(int i = 0; i < n; i++){
		for(int j = 50000*(k-1); j >= 0; j--){
			if(j <= a[i]) break;
			dp[k][500010] += dp[k-1][j];
		}
		for(int l = k-2; l >= 0; l--){
			for(int j = 50000*l; j >= 0; j--){
				dp[l+1][j+a[i]] += dp[l][j];
			}
		}
	}
	cout << dp[k][500010];
}
