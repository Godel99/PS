#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    vector<vector<int>> e(n+1);
    vector<int> deg(n+1, 0);
    while(m--){
        int u, v; cin >> u >> v;
        e[u].push_back(v);
        deg[v]++;
    }
    queue<int> q;
    for(int i = 1; i <= n; i++) if(deg[i] == 0) q.push(i);
    while(q.size()){
        int cur = q.front(); q.pop();
        cout << cur << ' ';
        for(auto nxt : e[cur]){
            deg[nxt]--;
            if(deg[nxt] == 0) q.push(nxt);
        }
    }
    return 0;
}