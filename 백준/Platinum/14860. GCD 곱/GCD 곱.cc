#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1'000'000'007;

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

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    if(n > m) swap(n, m);
    bool isp[n+1]; memset(isp, 1, sizeof(isp));
    isp[0] = isp[1] = 0;
    vector<int> primes; primes.reserve(1000000);
    for(int i = 2; i <= n; i++){
        if(isp[i]) primes.push_back(i);
        for(auto p : primes){
            if(i*p > n) break;
            isp[i*p] = 0;
            if(i%p == 0) break;
        }
    }
    ll ans = 1;
    for(auto p : primes){
        ll pi = p, ex = 0;
        while(pi <= n){
            ex = (ex+(n/pi)*(m/pi));
            pi *= p;
        }
        ans = ans*pw(p, ex%(MOD-1), MOD)%MOD;
    }
    cout << ans;
    return 0;
}