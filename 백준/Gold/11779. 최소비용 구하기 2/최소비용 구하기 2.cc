#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int inf = 1e9;

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    vector<int> dp(n+1, inf), par(n+1, 0);
    vector<vector<pii>> e(n+1);
    for(int i = 0; i < m; i++){
        int u, v, w; cin >> u >> v >> w;
        e[u].push_back({v, w});
    }
    int start, end; cin >> start >> end;
    priority_queue<pii, vector<pii>, greater<pii>> pq; pq.push({0, start});
    dp[start] = 0;
    while(pq.size()){
        auto [cost, cur] = pq.top(); pq.pop();
        if(dp[cur] < cost) continue;
        for(auto [nxt, ncost] : e[cur]){
            if(dp[nxt] > cost+ncost){
                dp[nxt] = cost+ncost;
                par[nxt] = cur;
                pq.push({dp[nxt], nxt});
            }
        }
    }
    cout << dp[end] << '\n';
    int cur = end;
    vector<int> ans;
    while(cur){
        ans.push_back(cur);
        cur = par[cur];
    }
    reverse(ans.begin(), ans.end());
    cout << (int)ans.size() << '\n';
    for(int i = 0; i < ans.size(); i++) cout << ans[i] << ' ';
    return 0;
} 