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
    int size = n/3+1;
    vector<bool> isp(size, 1);
    isp[0] = 0;
    for(int i = 1; i*i <= size; i++){
        if(isp[i]){
            int p = 3*i+1|1;
            int d = p*2;
            int s = p*p;
            int j = p*(p+4-2*(i&1));
            for(int k = s/3; k < size; k += d) isp[k] = 0;
            for(int k = j/3; k < size; k += d) isp[k] = 0;
        }
    }
    vector<int> primes = {2, 3};
    for(int i = 1; i < size; i++) if(isp[i]) primes.push_back(3*i+1|1);
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