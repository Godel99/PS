#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> par;
int find(int x){
    if(par[x] < 0) return x;
    par[x] = find(par[x]);
    return par[x];
}

bool unite(int x, int y){
    x = find(x), y = find(y);
    if(x == y) return false;
    if(par[x] > par[y]) swap(x, y);
    par[x] += par[y];
    par[y] = x;
    return true;
}

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int n, m; cin >> n >> m; par.assign(n, -1);
    for(int i = 1; i <= m; i++){
        int s, e; cin >> s >> e;
        if(!unite(s, e)) return !(cout << i);
    }
    cout << 0;
    return 0;
}