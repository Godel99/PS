#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int inf = 1e9;

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    vector<int> dp(n+1, inf);
    vector<vector<pii>> e(n+1);
    for(int i = 0; i < m; i++){
        int u, v, w; cin >> u >> v >> w;
        e[u].push_back({v, w});
    }
    int start, end; cin >> start >> end;
    priority_queue<pii> pq; pq.push({0, start});
    dp[start] = 0;
    while(pq.size()){
        auto [cost, cur] = pq.top(); pq.pop();
        if(dp[cur] < cost) continue;
        for(auto [nxt, ncost] : e[cur]){
            if(dp[nxt] > cost+ncost){
                dp[nxt] = cost+ncost;
                pq.push({dp[nxt], nxt});
            }
        }
    }
    cout << dp[end];
    return 0;
} 