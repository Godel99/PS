#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ai3 = array<int, 3>;

const int INF = 1e9;

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<ai3> cost(n);
    for(int i = 0; i < n; i++) cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    int ans = INF;
    for(int c = 0; c < 3; c++){
        vector<vector<int>> dp(n, vector<int>(3, INF));
        dp[0][c] = cost[0][c];
        for(int i = 1; i < n; i++){
            dp[i][0] = min(dp[i-1][1], dp[i-1][2])+cost[i][0];
            dp[i][1] = min(dp[i-1][0], dp[i-1][2])+cost[i][1];
            dp[i][2] = min(dp[i-1][0], dp[i-1][1])+cost[i][2];
        }
        for(int i = 0; i < 3; i++) if(i != c) ans = min(ans, dp[n-1][i]);
    }
    cout << ans;
    return 0;
}