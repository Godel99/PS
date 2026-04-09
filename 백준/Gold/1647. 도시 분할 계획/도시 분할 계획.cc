#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ai3 = array<int, 3>;

vector<int> par;

int find(int x){
    if(par[x] < 0) return x;
    par[x] = find(par[x]);
    return par[x];
}

void unite(int x, int y){
    x = find(x), y = find(y);
    if(x == y) return;
    if(par[x] > par[y]) swap(x, y);
    par[x] += par[y];
    par[y] = x;
}

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    if(n==2) return !(cout << 0);
    vector<ai3> e(m); par.assign(n+1, -1);
    for(int i = 0; i < m; i++){
        int u, v, w; cin >> u >> v >> w;
        e.push_back({u, v, w});
    }
    sort(e.begin(), e.end(), [](const ai3& a, const ai3& b){
        return a[2] < b[2];
    });
    int ans, cnt; ans = cnt = 0;
    for(auto [u, v, w] : e){
        if(find(u) != find(v)){
            unite(u, v);
            ans += w;
            cnt++;
        }
        if(cnt == n-2) break;
    }
    cout << ans;
    return 0;
} 