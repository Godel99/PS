#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using al3 = array<ll, 3>;

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<vector<int>> board(n, vector<int>(n));
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> board[i][j];
    if(board[0][2] == 1) return !(cout << 0);
    vector<vector<al3>> dp(n, vector<al3>(n, {0, 0, 0}));
    dp[0][1][0] = 1;
    for(int i = 0; i < n; i++) for(int j = 2; j < n; j++){
        if(board[i][j]) continue;
        if(j > 0) dp[i][j][0] += dp[i][j-1][0]+dp[i][j-1][2];
        if(i > 0) dp[i][j][1] += dp[i-1][j][1]+dp[i-1][j][2];
        if(i > 0 && j > 0 && !board[i-1][j] && !board[i][j-1]) dp[i][j][2] += dp[i-1][j-1][0]+dp[i-1][j-1][1]+dp[i-1][j-1][2];
    }
    cout << dp[n-1][n-1][0]+dp[n-1][n-1][1]+dp[n-1][n-1][2];
    return 0;
} 