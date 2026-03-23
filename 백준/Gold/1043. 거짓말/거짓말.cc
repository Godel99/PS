#include<bits/stdc++.h>
using namespace std;

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
    int n, m, k; cin >> n >> m >> k;
    if(k == 0) return !(cout << m);
    par.assign(n+1, -1);
    for(int i = 0; i < k; i++){
        int x; cin >> x;
        u(0, x);
    }
    vector<vector<int>> party(m);
    for(int i = 0; i < m; i++){
        int l; cin >> l;
        party[i].resize(l);
        for(int j = 0; j < l; j++) cin >> party[i][j];
        for(int j = 0; j < l; j++) u(party[i][0], party[i][j]);
    }
    int ans = 0;
    for(int i = 0; i < m; i++){
        for(auto j: party[i]) if(f(j) != f(0)){
            ans++;
            break;
        }
    }
    cout << ans;
    return 0;
} 