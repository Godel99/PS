#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pil = pair<int, ll>;

vector<vector<pil>> e;

pil dfs(int cur, int pre){
    int node = cur;
    ll d = 0;
    for(auto [nxt, nd] : e[cur]){
        if(nxt == pre) continue;
        auto [nnde, nnd] = dfs(nxt, cur);
        nnd += nd;
        if(nnd > d) d = nnd, node = nnde;
    }
    return {node, d};
}

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int v; cin >> v; e.resize(v+1);
    for(int i = 0; i < v; i++){
        int x, y; cin >> x;
        while(cin >> y && y != -1){
            int z; cin >> z;
            e[x].push_back({y, z});
        }
    }
    cout << dfs(dfs(1, 0).first, 0).second;
    return 0;
}