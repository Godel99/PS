#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1'000'000'007;

ll pow(ll x, ll r){
    ll ret = 1;
    while(r){
        if(r&1) ret = ret*x%MOD;
        x = x*x%MOD;
        r >>= 1;
    }
    return ret;
}

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    ll n, x;
    while(cin >> n >> x){
        vector<ll> a(n), b(n); 
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];
        ll xx = pow(x, n-1);
        for(int i = 0; i < n; i++) x = (x+a[i]*b[i]%MOD)%MOD;
        cout << xx*x%MOD << '\n';
    }
    return 0;
} 