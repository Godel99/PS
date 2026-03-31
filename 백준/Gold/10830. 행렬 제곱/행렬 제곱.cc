#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<ll>> mul(const vector<vector<ll>> &u, const vector<vector<ll>> &v, int n){
    vector<vector<ll>> ret(n, vector<ll>(n, 0));
    for(int i = 0; i < n; i++) for(int k = 0; k < n; k++) for(int j = 0; j < n; j++){
        ret[i][j] = (ret[i][j]+u[i][k]*v[k][j])%1000;
    }
    return ret;
}

vector<vector<ll>> pw(const vector<vector<ll>> &m, ll b, int n){
    if(b == 1){
        vector<vector<ll>> ret = m;
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) ret[i][j] %= 1000;
        return ret;
    }
    vector<vector<ll>> h = pw(m, b/2, n);
    if(b&1) return mul(mul(h, h, n), m , n);
    else return mul(h, h, n);
}

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int n; ll b; cin >> n >> b;
    vector<vector<ll>> m(n, vector<ll>(n));
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> m[i][j];
    vector<vector<ll>> ans = pw(m, b, n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) cout << ans[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}