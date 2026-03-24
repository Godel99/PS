#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

vector<vector<pii>> e;

pii dfs(int cur, int pre){
    int node = cur, d = 0;
    for(auto [nxt, nd]: e[cur]){
        if(nxt == pre) continue;
        auto [nnode, nnd] = dfs(nxt, cur);
        nnd += nd;
        if(nnd > d){
            d = nnd;
            node = nnode;
        }
    }
    return {node, d};
}

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int n; cin >> n; e.resize(n+1);
    for(int i = 0; i < n-1; i++){
        int u, v, w; cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }
    cout << dfs(dfs(1, 0).first, 0).second;
    return 0;
} 