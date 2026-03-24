#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int INF = 1e9;
vector<vector<pii>> e;
int n, m;

ll dij(int start, int end){
    vector<int> dist(n+1, INF);
    dist[start] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq; pq.push({0, start});
    while(pq.size()){
        auto [w, cur] = pq.top(); pq.pop();
        if(cur == end) return w;
        if(dist[cur] < w) continue;
        for(auto [nxt, nw]: e[cur]){
            if(dist[nxt] > w+nw){
                dist[nxt] = w+nw;
                pq.push({dist[nxt], nxt});
            }
        }
    }
    return INF;
}

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    cin >> n >> m; e.resize(n+1);
    for(int i = 0; i < m; i++){
        int u, v, w; cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }
    int v1, v2; cin >> v1 >> v2;
    ll ans = min(dij(1, v1)+dij(v2, n), dij(1, v2)+dij(v1, n))+dij(v1, v2);
    cout << (ans >= INF ? -1 : ans);
    return 0;
} 