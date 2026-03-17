#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) cin >> dp[i][j];
    for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) dp[i][j] += dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
    while(m--){
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        int s = dp[x2][y2]-dp[x1-1][y2]-dp[x2][y1-1]+dp[x1-1][y1-1];
        cout << s << '\n';
    }
    return 0;
}