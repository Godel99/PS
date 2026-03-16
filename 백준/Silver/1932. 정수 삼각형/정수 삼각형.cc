#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<vector<int>> dp(n, vector<int>(n));
    for(int i = 0; i < n; i++) for(int j = 0; j <= i; j++) cin >> dp[i][j];
    for(int i = n-2; i >= 0; i--) for(int j = 0; j < i+1; j++) dp[i][j] += max(dp[i+1][j], dp[i+1][j+1]);
    cout << dp[0][0];
    return 0;
}