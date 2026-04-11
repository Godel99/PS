#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    ll t, n; cin >> n; t = n; n <<= 1;
    stack<ll> ans;
    while(n){
        if(n&1) ans.push(t--);
        t--;
        n >>= 1;
    }
    cout << ans.size() << '\n';
    while(ans.size()){cout << ans.top() << ' '; ans.pop();}
    return 0;
}