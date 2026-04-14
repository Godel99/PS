#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 998244353;
int k;
vector<ll> invf, pref, suff, invki;


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
    ll ret = 0;
    for(int i = 0; i < d+2; i++){
        ll num = (pref[d+1]*invki[i])%MOD;
        ll den = (invf[i]*invf[d+1-i])%MOD;
        if((d+1-i)%2) den = MOD-den;
        ret = (ret+y[i]*num%MOD*den)%MOD;
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
    int limit = min(k-1, maxd+1);
    pref.assign(limit+1, 0), suff.assign(limit+1, 0);
    pref[0] = k;
    for(int i = 1; i <= limit; i++) pref[i] = (pref[i-1]*(k-i))%MOD;
    suff[limit] = pw(pref[limit], MOD-2, MOD);
    for(int i = limit-1; i >= 0; i--) suff[i] = (suff[i+1]*(k-i-1))%MOD;
    invki.assign(limit+1, 0);
    invki[0] = suff[0];
    for(int i = 1; i <= limit; i++) invki[i] = (pref[i-1]*suff[i])%MOD;
    ll fact = 1; invf.assign(maxd+3, 1); 
    for(int i = 1; i < maxd+3; i++) fact = (fact*i)%MOD;
    invf[maxd+2] = pw(fact, MOD-2, MOD);
    for(int i = maxd+1; i > 0; i--) invf[i] = (invf[i+1]*(i+1))%MOD;
    ll ans = 0;
    ll invk = pw(k, MOD-2, MOD);
    vector<ll> invkp(maxd+1, 1);
    for(int i = 1; i <= maxd; i++) invkp[i] = (invkp[i-1]*invk)%MOD;
    for(int d = 1; d <= maxd; d++){
        if(vcnt[d] == 0) continue;
        ll evmd = (Sd(d)*invkp[d])%MOD;
        ans = (ans+vcnt[d]*evmd)%MOD;
    }
    cout << ans;
    return 0;
}