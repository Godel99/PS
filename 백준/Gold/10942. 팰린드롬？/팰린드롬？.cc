#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> a(n+1, 0);
    for(int i = 1; i <= n; i++) cin >> a[i];
    vector<vector<bool>> dp(n+1, vector<bool>(n+1, false));
    for(int i = 1; i <= n; i++) dp[i][i] = true;
    for(int i = 1; i < n; i++) if(a[i] == a[i+1]) dp[i][i+1] = true;
    for(int d = 2; d < n; d++) for(int s = 1; s <= n-d; s++){
        int e = s+d;
        if(a[s] == a[e] && dp[s+1][e-1]) dp[s][e] = true;
    }
    int m; cin >> m;
    while(m--){
        int s, e; cin >> s >> e;
        cout << (dp[s][e] ? 1 : 0) << '\n';
    }
    return 0;
}