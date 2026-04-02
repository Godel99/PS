#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int INF = 1e9;
int n, m, r;
vector<int> t;
vector<vector<pii>> e;

int dji(int start){
    vector<int> dist(n+1, INF);
    dist[start] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq; pq.push({0, start});
    while(pq.size()){
        auto [d, cur] = pq.top(); pq.pop();
        if(d > m) break;
        if(dist[cur] < d) continue;
        for(auto [nxt, nd] : e[cur]){
            int cost = d+nd;
            if(dist[nxt] > cost && m >= cost){
                dist[nxt] = cost;
                pq.push({cost, nxt});
            }
        }
    }
    int ret = 0;
    for(int i = 1; i <= n; i++) if(dist[i] <= m) ret += t[i-1];
    return ret;
}

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    cin >> n >> m >> r; e.resize(n+1); t.resize(n);
    for(int i = 0; i < n; i++) cin >> t[i];
    for(int i = 0; i < r; i++){
        int u, v, w; cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) ans = max(ans, dji(i));
    cout << ans;
    return 0;
}