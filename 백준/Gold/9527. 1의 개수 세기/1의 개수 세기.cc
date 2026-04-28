#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    ll a, b; cin >> a >> b;
    unordered_map<ll, ll> memo;
    function<ll(ll)> bitcnt = [&](ll n) -> ll{
        if(n == 0) return 0;
        if(n == 1) return 1;
        if (memo.count(n)) return memo[n];
        ll k = 0;
        while(1LL << (k+1) <= n) k++;
        ll msb = 1LL<<k;
        return memo[n] = bitcnt(msb-1)+(n-msb+1)+bitcnt(n-msb);
    };
    cout << bitcnt(b) - bitcnt(a-1);
    return 0;
}