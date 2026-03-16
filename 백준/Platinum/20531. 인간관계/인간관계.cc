#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1'000'000'007;
int n, m;
vector<vector<ll>> dp;
vector<int> par;

int f(int x){
    if(par[x] < 0) return x;
    par[x] = f(par[x]);
    return par[x];
}

void u(int x, int y){
    x = f(x), y = f(y);
    if(x == y) return;
    n--;
    if(par[x] > par[y]) swap(x, y);
    par[x] += par[y];
    par[y] = x;
}

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    cin >> n >> m;
    dp.assign(n+1, vector<ll>(n+1, 0));
    par.assign(n+1, -1);
    for(int i = 1; i <= n; i++){
        dp[i][0] = dp[i][1] = 1;
        for(int j = 2; j <= i; j++){
            dp[i][j] = (dp[i-1][j]*j+dp[i-1][j-1])%MOD;
            dp[i][0] = (dp[i][0]+dp[i][j])%MOD;
        }
    }
    while(m--){
        int x, y; cin >> x >> y;
        u(x, y);
        cout << dp[n][0] << '\n';
    }
    return 0;
}