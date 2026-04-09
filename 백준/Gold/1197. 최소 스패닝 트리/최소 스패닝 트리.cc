#include <bits/stdc++.h>
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

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int v, e; cin >> v >> e;
    vector<ai3> edge(e); par.assign(v+1, -1);
    for(int i = 0; i < e; i++){
        int x, y, z; cin >> x >> y >> z;
        edge[i] = {z, x, y};
    }
    sort(edge.begin(), edge.end());
    int ans, cnt; ans = cnt = 0;
    for(auto [z, x, y] : edge){
        if(find(x) != find(y)){
            unite(x, y);
            ans += z;
            cnt++;
            if(cnt == v-1) break;
        }
    }
    cout << ans;
    return 0;
}