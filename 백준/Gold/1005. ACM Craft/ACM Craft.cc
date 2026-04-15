#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        vector<int> d(n+1, 0), deg(n+1, 0), dp(n+1, 0);
        for(int i = 1; i <= n; i++) cin >> d[i];
        vector<vector<int>> e(n+1);
        while(k--){
            int u, v; cin >> u >> v;
            e[u].push_back(v);
            deg[v]++;
        }
        int w; cin >> w;
        queue<int> q;
        for(int i = 1; i <= n; i++) if(deg[i] == 0){
            q.push(i); dp[i] = d[i];
        }
        while(q.size()){
            int cur = q.front(); q.pop();
            if(cur == w) break;
            for(int nxt : e[cur]){
                dp[nxt] = max(dp[nxt], dp[cur]+d[nxt]);
                deg[nxt]--;
                if(deg[nxt] == 0) q.push(nxt);
            }
        }
        cout << dp[w] << '\n';
    }
    return 0;
}