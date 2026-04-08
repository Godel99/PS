#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int l = 0, r = n-1;
    ll minx = LLONG_MAX;
    pll ans = {a[l], a[r]};
    while(l < r){
        ll x = abs(a[l]+a[r]);
        if(minx > x){
            minx = x;
            ans = {a[l], a[r]};
            if(minx == 0) break;
        }
        if(a[l]+a[r] < 0) l++;
        else r--;
    }
    cout << ans.first << ' ' << ans.second;
    return 0;
} 