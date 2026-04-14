#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 998244353;
int k;
vector<ll> invf;

ll pw(ll n, ll r, ll MOD){
    n %= MOD;
    ll ret = 1;
    while(r){
        if(r&1) ret = ret*n%MOD;
        n = n*n%MOD;
        r >>= 1;
    }
    return ret;
}

ll Sd(int d){
    vector<ll> y(d+2, 0);
    for(int i = 1; i < d+2; i++) y[i] = (y[i-1]+pw(i, d, MOD))%MOD;
    if(k <= d+1) return y[k];
    vector<ll> pref(d+2, 1), suff(d+2, 1);
    pref[0] = k;
    for(int i = 1; i < d+2; i++) pref[i] = (pref[i-1]*(k-i+MOD))%MOD;
    suff[d+1] = k-d-1;
    for(int i = d; i > 0; i--) suff[i] = (suff[i+1]*(k-i+MOD))%MOD;
    ll ret = 0;
    for(int i = 0; i < d+2; i++){
        ll num = 1;
        if(i) num = (num*pref[i-1])%MOD;
        if(i < d+1) num = (num*suff[i+1])%MOD;
        ll den = (invf[i]*invf[d+1-i])%MOD;
        if((d+1-i)%2) den = MOD-den;
        ll term = y[i] * num % MOD;
        term = term * den % MOD;
        ret = (ret + term) % MOD;
    }
    return ret;
}

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int n, m; cin >> n >> m >> k;
    vector<int> deg(n+1, 0);
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        deg[y]++;
    }
    vector<int> vcnt(m+1, 0);
    int maxd = 0;
    for(int i = 2; i <= n; i++){
        if(deg[i]) vcnt[deg[i]]++;
        if(deg[i] > maxd) maxd = deg[i];
    }
    vector<ll> fact(maxd+3, 1); invf.assign(maxd+3, 1);
    for(int i = 1; i < maxd+3; i++) fact[i] = (fact[i-1]*i)%MOD;
    invf[maxd+2] = pw(fact[maxd+2], MOD-2, MOD);
    for(int i = maxd+1; i > 0; i--) invf[i] = (invf[i+1]*(i+1))%MOD;
    ll ans = 0;
    ll invk = pw(k, MOD-2, MOD);
    for(int d = 1; d <= maxd; d++){
        if(vcnt[d] == 0) continue;
        ll evmd = (Sd(d)*pw(invk, d, MOD))%MOD;
        ans = (ans+vcnt[d]*evmd)%MOD;
    }
    cout << ans;
    return 0;
}