#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int n; cin >> n;
    int r, c; cin >> r >> c;
    vector<int> mat = {r, c};
    for(int i = 1; i < n; i++){
        int r, c; cin >> r >> c;
        mat.push_back(c);
    }
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for(int l = 1; l < n; l++) for(int i = 0; i < n-l; i++){
        int j = i+l;
        dp[i][j] = INT32_MAX;
        for(int k = i; k < j; k++) dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]+mat[i]*mat[k+1]*mat[j+1]);
    }
    cout << dp[0][n-1];
    return 0;
}