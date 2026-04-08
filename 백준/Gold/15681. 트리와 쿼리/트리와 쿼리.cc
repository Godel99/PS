#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> e;
vector<int>subtsize;

void dfs(int cur, int pre){
    subtsize[cur] = 1;
    for(auto nxt : e[cur]){
        if(nxt == pre) continue;
        dfs(nxt, cur);
        subtsize[cur] += subtsize[nxt];
    }
}

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int n, r, q; cin >> n >> r >> q; 
    e.resize(n+1); subtsize.assign(n+1, 0);
    for(int i = 0; i < n-1; i++){
        int u, v; cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(r, 0);
    while(q--){
        int qry; cin >> qry;
        cout << subtsize[qry] << '\n';
    }
    return 0;
} 