#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int INF = 1e9;

int n, m, x;
vector<int> dji(int start, vector<vector<pii>> e){
    vector<int> dist(n+1, INF);
    dist[start] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq; pq.push({0, start});
    while(pq.size()){
        auto [d, cur] = pq.top(); pq.pop();
        if(dist[cur] < d) continue;
        for(auto [nxt, nd] : e[cur]){
            if(dist[nxt] > d+nd){
                dist[nxt] = d+nd;
                pq.push({dist[nxt], nxt});
            }
        }
    }
    return dist;
}

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    cin >> n >> m >> x;
    vector<vector<pii>> e(n+1), re(n+1);
    for(int i = 0; i < m; i++){
        int u, v, w; cin >> u >> v >> w;
        e[u].push_back({v, w});
        re[v].push_back({u, w});
    }
    vector<int> go = dji(x, e), come = dji(x, re);
    int ans = 0;
    for(int i = 1; i <= n; i++) if(go[i] != INF && come[i] != INF) ans = max(ans, go[i]+come[i]);
    cout << ans;
    return 0;
}