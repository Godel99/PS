#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> par;

int f(int x){
    if(par[x] < 0) return x;
    par[x] = f(par[x]);
    return par[x];
}

void u(int x, int y){
    x = f(x), y = f(y);
    if(x == y) return;
    if(par[x] > par[y]) swap(x, y);
    par[x] += par[y];
    par[y] = x;
}

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    vector<vector<int>> e(n+1);
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    vector<int> st(n);
    vector<bool> vis(n+1, 0);
    par.assign(n+1, -1);
    for(int i = 0; i < n; i++){
        cin >> st[i];
    }
    vector<bool> ans(n);
    for(int i = 1; i <= n; i++){
        int cur = st[n-i];
        vis[cur] = 1;
        for(int nxt: e[cur]) if(vis[nxt]) u(cur, nxt);
        ans[i-1] = par[f(cur)] == -i;
    }
    for(int i = n-1; i >= 0; i--) cout << (ans[i] ? "CONNECT\n" : "DISCONNECT\n");
    cout << "DISCONNECT\n";
    return 0;
}