#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int dp[11];

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		dp[1] = 1, dp[2] = 2, dp[3] = 4;
		for(int i = 4; i <= n; i++) dp[i] = dp[i-1]+dp[i-2]+dp[i-3];
		cout << dp[n] << '\n';
	}	
    return 0;
}