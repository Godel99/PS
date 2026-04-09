#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9;

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int c, n; cin >> c >> n;
    int dp[1101]; fill(dp, dp + 1101, INF);
    dp[0] = 0;
    while(n--){
        int cst, peo; cin >> cst >> peo;
        for(int i = peo; i <= 1100; i++){
            if(dp[i-peo] != INF) dp[i] = min(dp[i], dp[i-peo]+cst);
        }
    }
    int ans = INF;
    for(int i = c; i <= 1100; i++) if(dp[i] < ans) ans = dp[i];
    cout << ans;
    return 0;
}