#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    vector<int> deg(n+1, 0);
    vector<vector<int>> e(n+1);
    while(m--){
        int l, u; cin >> l >> u;
        for(int i = 1; i < l; i++){
            int v; cin >> v;
            e[u].push_back(v);
            deg[v]++;
            u = v;
        }
    }
    queue<int> q;
    for(int i = 1; i <= n; i++) if(deg[i] == 0) q.push(i);
    vector<int> ans;
    while(q.size()){
        int cur = q.front(); q.pop();
        ans.push_back(cur);
        for(int nxt : e[cur]){
            deg[nxt]--;
            if(deg[nxt] == 0) q.push(nxt);
        }
    }
    if(ans.size() == n){
        for(int i : ans) cout << i << '\n';
    }
    else cout << 0;
    return 0;
}