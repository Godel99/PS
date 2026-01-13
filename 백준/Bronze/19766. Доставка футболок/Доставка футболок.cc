#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    ll n, k, t; cin >> n >> k >> t;
    vector<ll> s(n);
    for(int i = 0; i < n; i++) cin >> s[i];
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ll z; cin >> z;
        ans += s[i];
        if(ans+k >= z){
            ans = max(ans, z);
            ans += t;
        }
        else ans += k;
    }
    cout << ans;
    return 0;
}