#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1'000'000'007;

ll pw(ll n, ll r, ll MOD){
    ll ret = 1;
    while(r){
        if(r&1) ret = ret*n%MOD;
        n = n*n%MOD;
        r>>=1;
    }
    return ret;
}

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int m; cin >> m;
    ll ans = 0;
    while(m--){
        ll n, s; cin >> n >> s;
        ans = (ans+s*pw(n, MOD-2, MOD))%MOD;
    }
    cout << ans;
    return 0;
} 